# Documentación Almacenamiento

## Resumen
1 solo SSD físico de 1TB dividido en 3 particiones principales:
- **C:** partición del sistema, aquí viven las apps que si o si deben estar en la misma partición que el sistema
- **D:** partición para todo lo demás
- **P:** partición exclusiva para la universidad

| Unidad | Etiqueta | Tamaño | Libre | Uso |
|--------|----------|--------|-------|-----|
| C: | OS | 250 GB | 146 GB | Sistema y apps que deben estar en la partición del sistema |
| D: | LOCAL | 671 GB | 602 GB | Programas, proyectos, WSL, datos |
| P: | PUCP | 5 GB | 5 GB | Exclusivo para documentos de la universidad |

> El espacio restante va a particiones no importantes
> Medido con WizTree el 20/10/2026 (tamaños como los muestra el Explorador)

La finalidad es mantener la unidad C lo más libre posible

### Estructura de D

```
D:\
├── Desktop\            Escritorio (en el Explorador se ve en español)
├── Documents\          Documentos
├── Downloads\          Descargas (borrar los instaladores después de usarlos)
├── Pictures\           Imágenes
├── Programs\           Programas divididos por tipo
│   ├── Apps\           Uso general (SumatraPDF)
│   ├── Games\          Riot Games (Valorant), Steam, Modrinth
│   └── Tools\          Técnicos o de sistema (Git, JetBrains, Python,
│                       Sublime Text, Powertoys, GeekUninstaller, WizTree,
│                       CrystalDiskInfo, Logisim_Evolution, Oracle)
├── Proyectos\          Proyectos de código
└── WSL\                Distros de WSL
    └── Ubuntu\         Ubuntu
```

## Reglas para lo nuevo

1. Programas: instalarlos en `D:\Programs\<tipoDePrograma>\<nombre>`, cambiando la ruta en el instalador. Cada programa va en su propia carpeta, nunca suelto.
2. Tipo de programa: `Tools` si es técnico o de sistema, `Apps` si es de uso general, `Games` si es un juego o launcher.
3. No renombrar ni mover un programa ya instalado: se desinstala y se reinstala en la ruta correcta (los portables sí se pueden mover).
4. Proyectos: en `D:\Proyectos`, con sus entornos virtuales y dependencias dentro.
5. Cachés de herramientas (pip, Gradle, Maven, etc.): redirigirlas a D: al instalarlas.
6. Documentos de la universidad: solo en P:.
7. Después de instalar algo, comprobar que no creó una carpeta grande en `%LOCALAPPDATA%`.
8. Borrar de `D:\Downloads` los instaladores y zips una vez instalado el programa.

## Qué se queda en C: a propósito

- Perfil de usuario y `AppData` (~18 GB): configuración y cachés de apps, navegador (Brave), etc. De esos, ~11 GB son la máquina virtual local de Claude (`Local\Claude-Data\...\vm_bundles`), que la app no deja mover. (Steam solo deja ~0.06 GB de datos de usuario; el cliente y los juegos están en D:).
- `%TEMP%`: temporales de instalaciones y compilaciones.
- `%APPDATA%\pip\pip.ini` (unos KB) y el `py launcher`.
- Configuración y plugins de JetBrains; configuración de SQL Developer (`%APPDATA%\SQL Developer`).
- Archivos del sistema: `pagefile.sys` (~10 GB), `hiberfil.sys` (~6.6 GB), restauración del sistema (~4.5 GB) y caché de Windows Update y Delivery Optimization.
- Software del fabricante (ASUS): `C:\eSupport` (~8 GB, paquete de drivers) y `C:\Recovery` (~3 GB).
- Microsoft Office (`C:\Program Files\Microsoft Office`, ~4.8 GB) y Edge/WebView (~2 GB): no se pueden mover.
- Programas cuyo instalador no deja elegir ruta: Discord, Zoom, Granola y Riot Vanguard (anti-cheat de Valorant), ~2 GB en total. Lo mismo pasará con Roblox, WhatsApp y Apple TV cuando se instalen.
- Las apps de Microsoft Store van a C: por defecto; se puede cambiar en *Configuración > Sistema > Almacenamiento > Dónde se guardan los nuevos contenidos*.

## Configuración que mueve datos a D:

### JetBrains (IntelliJ IDEA y CLion)
- Cachés, índices y logs en `D:\Programs\Tools\JetBrains\Data\IntelliJIdea\` y `D:\Programs\Tools\JetBrains\Data\CLion\` (carpetas `system` y `log`, distintas para cada IDE).
- Se configura con `idea.system.path` e `idea.log.path` en *Help > Edit Custom Properties*, con barras normales `/`.
- La configuración (`config`) y los plugins se quedan en `%APPDATA%\JetBrains\` (C:).
- Al actualizar a una versión mayor (por ejemplo 2026.3), hay que volver a añadir las dos propiedades; si no, el IDE crea sus carpetas de nuevo en `%LOCALAPPDATA%\JetBrains\`.

### Python 3.15.0
- Instalado en `D:\Programs\Tools\Python`; los paquetes globales van a `Lib\site-packages` dentro de esa carpeta.
- Caché de pip en `D:/Programs/Tools/Python/pip-cache` (`pip config set global.cache-dir`).
- Entornos virtuales dentro de cada proyecto en D: (`python -m venv .venv`).
- No usar `pip install --user`, porque guardaría paquetes en `%APPDATA%\Python` (C:).
- Verificar: `py -0p`, `python -c "import sys; print(sys.executable)"` y `pip config list`. En PowerShell usar `where.exe`, no `where`.

### Oracle Database 21c XE
- Instalado en `D:\Programs\Tools\Oracle` (~10 GB): software en `product\21c\dbhomeXE` y datos en `product\21c\oradata` (~4.6 GB, crece con el uso).
- SQL Developer en `D:\Programs\Tools\Oracle\sqldeveloper` (portable, sin instalador).

### Valorant
- Riot Client y Valorant en `D:\Programs\Games\Riot Games` (~38 GB, el programa más grande del equipo).
- Solo Riot Vanguard queda en C: (`C:\Program Files\Riot Vanguard`, ~0.3 GB).
