# CódigoPUCP

Código que resolví como práctica para los laboratorios, prácticas calificadas y exámenes de los cursos con programación de Ingeniería Informática en la PUCP. Cada carpeta corresponde a un curso y, dentro de ella, a un tema o a una evaluación de ciclos anteriores.

> Este repositorio es material de estudio personal. Los enunciados pertenecen a los cursos; si eres estudiante, úsalo como referencia para practicar, no para copiar en evaluaciones.

## Estructura

```
CodigoPUCP/
├── EEGGCC/                     # Estudios Generales Ciencias
│   ├── FundaProg/
│   └── TP/
├── 5toCiclo/
│   ├── Algoritmia/
│   ├── Programacion2/
│   └── BaseDeDatos/
├── AlgoritmosAvanzados/        # 6.º ciclo
│   ├── Backtracking/
│   ├── PD/
│   └── Heuristicas/
└── ArquitecturaComputadoras/   # 6.º ciclo
```

Las carpetas con nombres como `Lab3_2025-1` o `Ex2_2024-2` son laboratorios o exámenes de ciclos anteriores resueltos como práctica.

## Contenido

| Curso | Carpeta | Lenguaje / herramienta | Temas |
| --- | --- | --- | --- |
| Fundamentos de Programación | `EEGGCC/FundaProg` | PSeInt, C | Estructuras de control, funciones, arreglos |
| Técnicas de Programación | `EEGGCC/TP` | C++ | Arreglos, cadenas, estructuras, archivos CSV/TXT, memoria dinámica, bibliotecas propias, listas |
| Programación 2 | `5toCiclo/Programacion2` | C++, Java | Punteros y memoria dinámica, POO (herencia, polimorfismo, sobrecarga de operadores), plantillas y STL, introducción a Java |
| Algoritmia y Estructura de Datos | `5toCiclo/Algoritmia` | C++ | Fuerza bruta, recursión, divide y vencerás, TADs (pilas, colas, listas), árboles binarios de búsqueda |
| Base de Datos | `5toCiclo/BaseDeDatos` | Oracle SQL | Creación de tablas, restricciones de integridad, consultas |
| Algoritmos Avanzados | `AlgoritmosAvanzados` | C++ | Backtracking, programación dinámica, algoritmos voraces y heurísticas |
| Arquitectura de Computadoras | `ArquitecturaComputadoras` | Logisim Evolution | Computadora de 8 bits construida en clase (GRIDHO), ROMs, periféricos |

## Cómo ejecutar

- **C / C++:** la mayoría de proyectos incluye `CMakeLists.txt`; se abren directamente en CLion o se compilan con:
  ```bash
  cmake -S . -B build && cmake --build build
  ```
  Algunos leen archivos `.txt` o `.csv` que están en la misma carpeta; colócalos en el directorio de trabajo antes de ejecutar.
- **Java:** proyectos de IntelliJ IDEA (archivos `.iml`, código en `src/`).
- **SQL:** scripts para Oracle SQL Developer.
- **Logisim:** archivos `.circ`, se abren con [Logisim Evolution](https://github.com/logisim-evolution/logisim-evolution).

## Autor

Carlos Gabriel Florian Silva — estudiante de Ingeniería Informática, PUCP
[LinkedIn](https://linkedin.com/in/carlos-florian-silva)