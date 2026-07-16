# CMakeLists.txt — configuración de build de MathLib
# ---------------------------------------------------
# CMake es un generador de sistemas de compilación multiplataforma:
# a partir de este archivo genera los proyectos/Makefiles adecuados
# para tu compilador (g++, MSVC, clang, etc.) sin que tengas que
# escribir comandos de compilación manualmente.

cmake_minimum_required(VERSION 3.10)   # Versión mínima de CMake requerida

project(MathLib VERSION 1.0.0 LANGUAGES CXX)  # Nombre del proyecto + SemVer

set(CMAKE_CXX_STANDARD 17)             # Usamos C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # Obligamos a que el compilador lo soporte

# -----------------------------------------------------------------
# 1. Librería MathLib (estática)
# -----------------------------------------------------------------
# add_library crea una librería llamada "MathLib" a partir del código
# fuente en src/Matrix.cpp. Al no indicar STATIC/SHARED explícitamente
# arriba, por defecto CMake genera una librería estática (.a / .lib).
add_library(MathLib STATIC
    src/Matrix.cpp
)

# target_include_directories indica dónde están los .h públicos de la
# librería, para que cualquier proyecto que la use (o el propio test)
# pueda hacer #include "Matrix.h" sin rutas relativas complicadas.
target_include_directories(MathLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# -----------------------------------------------------------------
# 2. Ejecutable de prueba (test_matrix)
# -----------------------------------------------------------------
add_executable(test_matrix
    test/test_matrix.cpp
)

# Enlazamos el ejecutable de prueba contra la librería MathLib para
# que pueda usar la clase Matrix.
target_link_libraries(test_matrix PRIVATE MathLib)

# -----------------------------------------------------------------
# Mensaje informativo al configurar el proyecto
# -----------------------------------------------------------------
message(STATUS "MathLib v${PROJECT_VERSION} configurado correctamente.")
