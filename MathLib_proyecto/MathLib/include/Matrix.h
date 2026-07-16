/**
 * @file Matrix.h
 * @brief Declaración de la clase Matrix, componente central de la librería MathLib.
 *
 * MathLib es una librería reutilizable en C++ orientada a objetos que
 * implementa operaciones matemáticas sobre matrices. Este archivo de
 * cabecera define la INTERFAZ pública de la clase Matrix, separando el
 * "qué hace" (aquí) del "cómo lo hace" (implementado en Matrix.cpp).
 *
 * Principios SOLID aplicados:
 *  - SRP (Single Responsibility Principle): la clase Matrix se encarga
 *    únicamente de representar y operar sobre una matriz numérica.
 *  - ISP (Interface Segregation Principle): la interfaz expone solo los
 *    métodos que un consumidor de la librería realmente necesita.
 *
 * @author Estefany
 * @course Programación Orientada a Objetos II (SIS206) - UNAP Puno
 */

#ifndef MATRIX_H   // Guarda de inclusión: evita que el archivo se procese
#define MATRIX_H   // más de una vez si es incluido desde varios .cpp

#include <vector>     // Usamos std::vector para almacenar los datos de la matriz
#include <stdexcept>  // Usamos std::out_of_range y std::invalid_argument para errores

/**
 * @class Matrix
 * @brief Representa una matriz de números reales (double) de tamaño r x c.
 *
 * Internamente, los datos se guardan como un vector de vectores
 * (std::vector<std::vector<double>>), donde data[i][j] es el elemento
 * ubicado en la fila i, columna j.
 */
class Matrix {
private:
    // Almacén interno de los valores de la matriz.
    // Es privado porque, según el principio de encapsulamiento de la POO,
    // nadie fuera de la clase debe modificar los datos directamente:
    // deben hacerlo a través de get()/set().
    std::vector<std::vector<double>> data;

    int rows; // Número de filas de la matriz
    int cols; // Número de columnas de la matriz

public:
    /**
     * @brief Constructor. Crea una matriz de r filas por c columnas,
     *        inicializada en ceros.
     * @param r número de filas
     * @param c número de columnas
     */
    Matrix(int r, int c);

    /**
     * @brief Obtiene el valor almacenado en la posición (r, c).
     * @throws std::out_of_range si los índices están fuera de rango.
     */
    double get(int r, int c) const;

    /**
     * @brief Asigna un valor en la posición (r, c).
     * @throws std::out_of_range si los índices están fuera de rango.
     */
    void set(int r, int c, double value);

    /**
     * @brief Suma esta matriz con "other" y devuelve una nueva matriz resultado.
     * @throws std::invalid_argument si las dimensiones no coinciden.
     */
    Matrix add(const Matrix& other) const;

    /**
     * @brief Multiplica esta matriz con "other" (producto matricial) y
     *        devuelve una nueva matriz resultado.
     * @throws std::invalid_argument si las dimensiones son incompatibles.
     */
    Matrix multiply(const Matrix& other) const;

    /**
     * @brief Imprime la matriz por consola, fila por fila.
     */
    void print() const;
};

#endif // MATRIX_H
