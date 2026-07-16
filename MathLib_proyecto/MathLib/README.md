# MathLib

Librería reutilizable en C++ orientada a objetos que implementa operaciones
matemáticas sobre matrices. Desarrollada como parte de la **Práctica N.° 11**
del curso de Programación Orientada a Objetos (SIS206), Universidad Nacional
del Altiplano - Puno, a cargo del Mg. Aldo Hernán Zanabria Gálvez.

## Objetivo

Desarrollar una librería modular en C++ que implemente funciones matemáticas
avanzadas (matrices), integrarla con Git/GitHub aplicando versionado
semántico (SemVer) y documentarla simulando un entorno de distribución tipo
vcpkg/NuGet.

## Características

- Clase `Matrix` con encapsulamiento completo (atributos privados, acceso
  vía `get`/`set`).
- Operaciones: suma (`add`), multiplicación (`multiply`) e impresión
  (`print`).
- Manejo de errores mediante excepciones (`std::out_of_range`,
  `std::invalid_argument`).
- Compilación mediante CMake (multiplataforma) o `g++` directo.
- Cumple principios SOLID: responsabilidad única, interfaz mínima y
  encapsulamiento de datos.

## Estructura del proyecto

```
MathLib/
├── include/
│   └── Matrix.h          # Interfaz pública de la clase Matrix
├── src/
│   └── Matrix.cpp        # Implementación de la clase Matrix
├── test/
│   └── test_matrix.cpp   # Programa de prueba / demo
├── README.md
├── LICENSE
└── CMakeLists.txt
```

## Requisitos

- Compilador compatible con C++17 (g++ 9+, clang 10+, MSVC 2019+)
- CMake 3.10 o superior (opcional si compilas con g++ directo)

## Compilación

### Opción A: usando CMake

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

El ejecutable de prueba quedará en `build/test_matrix` (o
`build/Debug/test_matrix.exe` en Windows con Visual Studio).

### Opción B: usando g++ directo

```bash
g++ -std=c++17 -Iinclude src/Matrix.cpp test/test_matrix.cpp -o test_matrix
```

## Ejecución

```bash
./test_matrix
```

Salida esperada:

```
Suma:
6 8
10 12
Multiplicación:
19 22
43 50
```

## Ejemplo de uso

```cpp
#include "Matrix.h"

Matrix A(2, 2);
A.set(0, 0, 1);
A.set(0, 1, 2);
A.set(1, 0, 3);
A.set(1, 1, 4);

Matrix B(2, 2);
B.set(0, 0, 5);
B.set(0, 1, 6);
B.set(1, 0, 7);
B.set(1, 1, 8);

Matrix suma = A.add(B);
Matrix producto = A.multiply(B);

suma.print();
producto.print();
```

## Versionado

Este proyecto sigue [Versionado Semántico 2.0.0](https://semver.org/):
`MAJOR.MINOR.PATCH`.

- **v1.0.0** — Primera versión estable: operaciones `add`, `multiply`,
  `get`, `set`, `print`.

## Autora

Estefany — Ingeniería de Sistemas, UNAP Puno.

## Licencia

Este proyecto se distribuye bajo la licencia MIT. Ver el archivo
[LICENSE](LICENSE) para más detalles.
