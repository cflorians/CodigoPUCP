# Documentación computadora Gridho
- Computadora hecha en Logisim evolution
- Procesador de 8 bits con arquitectura Von Neumann
- Instrucciones y datos comparten una sola RAM de 256x8
- Tiene 8 registros de propósito general (R0 a R7) de los cuales 2 pueden ser leídos a la vez (RA y RB), un program counter y un registro de instrucciones
- Cada instrucción ocupa un byte y se ejecuta en 2 fases, cada una durando 1 flanco de reloj (2 por instrucción):
  - Fetch and decode (lee instrucción de RAM[PC], la carga en IR y la decodifica)
  - exec (la ejecuta)
- El PC se actualiza al final de exec

## Mapa de la RAM
|Rango|Uso|
|---:|:---|
|0x00 a 0x7F|Instrucciones|
|0x80 a 0xFE|Datos|
|0xFF|Dirección de retorno `CALL`/`RET`|

> Este mapa es una convención, el hardware no impide que se infrinja ninguna de estas reglas
> Los periféricos (`RIO`/`WIO`) no forman parte de este mapa: se acceden por instrucciones propias, sin usar direcciones de la RAM

## Formato de la instrucción
En el byte de la instrucción están contenidos los siguientes bits, donde los bits con números más altos son los más significativos:
- 2 bits para `op` (`op1` y `op0`)
- 3 bits para `a` (`a2`, `a1` y `a0`)
- 3 bits para `b` (`b2`, `b1` y `b0`)

- a: siempre indica el registro RA.
- b: según la instrucción, es el registro RB, un inmediato (`LOAD`) o un sub-opcode (`op = 11`)

## Conjunto de instrucciones

> Las siguientes tablas usan orden lógico y la posición real está en **Sintaxis Gridho**

|Operación:|op1|op0|a2|a1|a0|b2|b1|b0|Descripción|
|----------|:---:|:---:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|00: WRITE [RB], RA|0|0|a2|a1|a0|0|b1|b0|RAM[RB] = RA|
|00: READ RA, [RB]|0|0|a2|a1|a0|1|b1|b0|RA = RAM[RB]|
|01: SUM RA, RB|0|1|a2|a1|a0|b2|b1|b0|RA = RA + RB, el acarreo se descarta|
|10: LOAD RA, inm|1|0|a2|a1|a0|inm2|inm1|inm0|RA = inm|
|11: ope arg1|1|1|a2|a1|a0|b2|b1|b0|abre las sub-op|

**Roles por instrucción**
- `WRITE`: `a` = dato, `b` = puntero
- `READ`: `a` = destino, `b` = puntero
- `SUM`: `a` = destino y primer operando, `b` = segundo operando
- `LOAD`: `a` = destino, `b` = inmediato
- `RIO`: `a` = selecciona el periférico de entrada y el registro destino (R1 a R3), `b` = sub-opcode (001)
- `WIO`: `a` = selecciona el periférico de salida y el registro que se envía (R4 a R7), `b` = sub-opcode (001)

### Operaciones con 1 operando (op = 11)
|Operación|op1|op0|a2|a1|a0|b2|b1|b0|Descripción|
|----------|:---:|:---:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|000: NOT|1|1|a2|a1|a0|0|0|0|Niega los bits de RA|
|001: RET (a = 000)|1|1|0|0|0|0|0|1|Regresa el PC a lo que marque RAM[0xFF], los bits de `a` deben ser siempre 0, porque con `a` distinto de 000 y b = 001 se ejecuta `RIO`/`WIO` (ver sección siguiente)|
|010: CALL|1|1|a2|a1|a0|0|1|0|Guarda PC+1 en RAM[0xFF] y luego PC = RA|
|011: JUMPR|1|1|a2|a1|a0|0|1|1|PC = PC + RA, RA en complemento a 2, contado desde la dirección del propio `JUMPR`, con RA=1 equivale a un NOP y con RA=0 equivale a un HALT|
|100: LSL|1|1|a2|a1|a0|1|0|0|Desplaza los bits de RA a la izquierda, añadiendo 1 bit 0 a la derecha, el bit que sale se descarta|
|101: LSR|1|1|a2|a1|a0|1|0|1|Desplaza los bits de RA a la derecha, añadiendo 1 bit 0 a la izquierda, el bit que sale se descarta|
|110: SER6|1|1|a2|a1|a0|1|1|0|Si RA = valor de R6, entonces PC = PC+2 (un JUMPR 2)|
|111: SRZ|1|1|a2|a1|a0|1|1|1|Si RA = 0, entonces PC = PC+2 (un JUMPR 2)|

> Aclaración: el salto de `CALL` y `RET` es absoluto, mientras que el de `JUMPR` es relativo
> Para `RET` los bits de A siempre deben ser 000
> `SER6` funciona porque su sub-opcode es 110, osea RB = R6
> El `RET` siempre saltará a donde indique RAM[0xFF], tenga el valor que tenga

### Operaciones con op = 11 y b = 001
Como el `RET` tiene los bits de a = 000, sobran otras 7 posibles combinaciones. Estas se usan para manejar periféricos, mediante las instrucciones
`RIO` (Read Input-Output) y `WIO` (Write Input-Output).
Están repartidas de la siguiente manera:

|Operación|op1|op0|a2|a1|a0|b2|b1|b0|Descripción|
|---------|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|RIO1|1|1|0|0|1|0|0|1|R1 = valor del periférico de entrada 1|
|RIO2|1|1|0|1|0|0|0|1|R2 = valor del periférico de entrada 2|
|RIO3|1|1|0|1|1|0|0|1|R3 = valor del periférico de entrada 3|
|WIO0|1|1|1|0|0|0|0|1|Envía R4 al periférico de salida 0|
|WIO1|1|1|1|0|1|0|0|1|Envía R5 al periférico de salida 1|
|WIO2|1|1|1|1|0|0|0|1|Envía R6 al periférico de salida 2|
|WIO3|1|1|1|1|1|0|0|1|Envía R7 al periférico de salida 3|

> En la tabla anterior se tiene en cuenta que op = 11 y b = 001 y a != 000, ya que a = 000 es para el `RET`
> Notar que para `RIO`, a2 siempre va a ser 0 y para `WIO`, a2 siempre sera 1
> En assembly `RIO#` y `WIO#` se escriben sin operandos: el número del mnemónico determina tanto el registro como el periférico

#### Las limitaciones para estas instrucciones son
1. `RIO` solamente puede guardar los datos leídos en los registros R1, R2 o R3, dependiendo del valor de a que se le dé (no existe `RIO0`, ya que a = 000 es `RET`)
2. `WIO` solamente puede escribir en los periféricos desde los registros R4, R5, R6 o R7, dependiendo del valor de a que se le dé
3. Los datos de `RIO` y `WIO` son siempre de 8 bits
4. `RIO` solo modifica su registro destino, `WIO` no modifica ningún registro
5. Ambas se ejecutan en la fase exec, como el resto de instrucciones

**Ejemplos**
- `RIO#`, lee el valor de un periférico y lo guarda en R#, con 1 <= # <= 3
- `WIO#`, toma el valor que hay en R(4+#) y lo manda al periférico con 0 <= # <= 3

**Ejemplo de configuración de periféricos**

> Los periféricos pueden variar según el montaje. Lo único fijo es lo que define el hardware de la CPU: hay hasta 3 entradas (`RIO1` a `RIO3`) y hasta 4 salidas (`WIO0` a `WIO3`), cada una de 8 bits. Qué dispositivo hay detrás de cada número depende de cómo se conecte
>
> Configuración usada actualmente, solo como referencia:
> - Entradas: 3 DIP switch de 8 bits (`input_1`, `input_2`, `input_3`), leídos con `RIO1`, `RIO2` y `RIO3`
> - Salidas: 4 registros de 8 bits que reciben el dato con `WIO0` a `WIO3` y mantienen el valor hasta la siguiente escritura o un reset

> Los periféricos son independientes de la RAM, no ocupan direcciones

### Sintaxis Gridho
Para guardar las instrucciones en la RAM, se usa la siguiente estructura y los bits se distribuyen de la siguiente manera:

byte instrucción = op1<<7 | b1<<6 | b0<<5 | a1<<4 | a0<<3 | b2<<2 | a2<<1 | op0

Donde:
- Operación: [op1] [op0]
- 1er argumento: [a2] [a1] [a0]
- 2do argumento: [b2] [b1] [b0]

> 1er y 2do elemento se refiere a los campos a/b, no al orden en el que se escribe en assembly

Ejemplos:
- `WRITE [R0], R7` = 0x1a
- `READ R6, [R4]` = 0x16
- `LOAD R1, 1`  = 0xa8
- `LSL R3` = 0x9d
- `CALL R6` = 0xd3
- `RET` = 0xa1
- `RIO1` = 0xa9
- `RIO2` = 0xb1
- `RIO3` = 0xb9
- `WIO0` = 0xa3
- `WIO1` = 0xab
- `WIO2` = 0xb3
- `WIO3` = 0xbb

> Al transformar assembly a código hexadecimal, siempre colocar las letras en minúsculas

## Comportamiento inicial
- Todos los registros y PC empiezan en 0, además la computadora empieza en fetch and decode
- El PC es de 8 bits
- 0x00 no es un NOP. Se decodifica como WRITE [R0], R0
- La RAM se carga antes de arrancar

## Limitaciones
- **Sin pila:** Solo se admite 1 subrutina simultánea, `CALL` sobrescribe RAM[0xFF]
- **Inmediatos del 0 al 7:** los valores mayores se construyen con `LSL` y `SUM`
- **Punteros restringidos:** `WRITE` solo direcciona con R0-R3 y `READ` solo con R4-R7, porque `b2`, aparte de ser parte de `RB`, es usado como selector de lectura/escritura
- **Periféricos restringidos:** `RIO` solo usa R1-R3 (3 entradas) y `WIO` solo usa R4-R7 (4 salidas)
- **Sin resta, copia ni halt:** -1 se obtiene con `NOT` de un registro en 0, `HALT` se obtiene con un `JUMPR` sobre un registro en 0 y `COPY` se emula haciendo `SUM RA, RB` donde RA es el registro destino y debe estar en 0 (puede lograrse con un `LOAD RA, 0`) y RB es el registro que se quiere copiar
- **Receta para restar:** se consigue primero el valor positivo el cual se quiere restar, luego se le aplica complemento a 2, primero un `NOT` sobre el registro y luego se le suma 1 (requiere registro auxiliar). Con eso tenemos el número negativo que queremos como segundo operando para restar

  **Ejemplo**
  Para `R2 = R2 - R3` con R1 = 1 y R3 > 0

```
  NOT R3
  SUM R3, R1
  SUM R2, R3
```