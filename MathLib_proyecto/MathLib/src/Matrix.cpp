/**
 * @file Matrix.cpp
 * @brief Implementación de los métodos declarados en Matrix.h
 *
 * Aquí vive la lógica real de la clase Matrix. Separar la declaración
 * (Matrix.h) de la implementación (Matrix.cpp) es una práctica estándar
 * en C++ que permite compilar la librería una sola vez y reutilizarla
 * en distintos proyectos sin volver a compilar su código fuente.
 */

#include "Matrix.h" // Traemos la definición de la clase que vamos a implementar
#include <iostream> // Para std::cout, usado en print()

// ---------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------
// Lista de inicialización "rows(r), cols(c)" asigna directamente los
// atributos rows y cols con los parámetros recibidos (más eficiente que
// asignarlos dentro del cuerpo del constructor).
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    // data.resize(rows, ...) redimensiona el vector externo para que
    // tenga "rows" elementos. Cada uno de esos elementos es, a su vez,
    // un std::vector<double>(cols, 0.0): un vector de "cols" columnas
    // inicializado en 0.0. Así obtenemos una matriz rows x cols llena
    // de ceros, lista para usarse.
    data.resize(rows, std::vector<double>(cols, 0.0));
}

// ---------------------------------------------------------------------
// get(): lectura segura de un elemento
// ---------------------------------------------------------------------
double Matrix::get(int r, int c) const {
    // Validamos que los índices no se salgan de los límites de la matriz.
    // Nota: solo se valida el límite superior (>= rows / >= cols) porque
    // r y c son int; en una versión más estricta también se validaría
    // que no sean negativos.
    if (r >= rows || c >= cols) throw std::out_of_range("Índice fuera de rango");
    return data[r][c]; // Accedemos a la fila r, columna c
}

// ---------------------------------------------------------------------
// set(): escritura segura de un elemento
// ---------------------------------------------------------------------
void Matrix::set(int r, int c, double value) {
    if (r >= rows || c >= cols) throw std::out_of_range("Índice fuera de rango");
    data[r][c] = value; // Sobrescribimos el valor en la posición indicada
}

// ---------------------------------------------------------------------
// add(): suma matricial elemento a elemento
// ---------------------------------------------------------------------
Matrix Matrix::add(const Matrix& other) const {
    // La suma de matrices solo está definida cuando ambas tienen
    // exactamente las mismas dimensiones.
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Las matrices deben tener el mismo tamaño");

    Matrix result(rows, cols); // Matriz resultado, del mismo tamaño

    // Recorremos cada posición (i, j) y sumamos los valores
    // correspondientes de "this" y "other".
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.set(i, j, get(i, j) + other.get(i, j));

    return result; // Se devuelve por valor (move semantics en C++ moderno)
}

// ---------------------------------------------------------------------
// multiply(): producto matricial (no es elemento a elemento)
// ---------------------------------------------------------------------
Matrix Matrix::multiply(const Matrix& other) const {
    // El producto A(m x n) * B(n x p) solo es válido si el número de
    // columnas de A coincide con el número de filas de B.
    if (cols != other.rows)
        throw std::invalid_argument("Dimensiones incompatibles para multiplicación");

    Matrix result(rows, other.cols); // Resultado será de tamaño rows x other.cols

    // Triple bucle clásico del producto matricial:
    //   i recorre las filas del resultado
    //   j recorre las columnas del resultado
    //   k recorre la dimensión "compartida" (columnas de A / filas de B)
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                // Acumulamos el producto punto de la fila i de A
                // con la columna j de B.
                result.set(i, j, result.get(i, j) + get(i, k) * other.get(k, j));

    return result;
}

// ---------------------------------------------------------------------
// print(): impresión legible de la matriz
// ---------------------------------------------------------------------
void Matrix::print() const {
    // Recorremos cada fila del vector de datos...
    for (const auto& row : data) {
        // ...e imprimimos cada valor de esa fila separado por espacio.
        for (double val : row) std::cout << val << " ";
        std::cout << "\n"; // Salto de línea al terminar la fila
    }
}
