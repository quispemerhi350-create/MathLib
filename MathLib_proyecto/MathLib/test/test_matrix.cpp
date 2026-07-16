/**
 * @file test_matrix.cpp
 * @brief Programa de prueba (driver) que valida el funcionamiento de la
 *        librería MathLib usando la clase Matrix.
 *
 * Este archivo NO forma parte de la librería en sí; es un ejecutable de
 * prueba/demo que consume la librería igual que lo haría cualquier otro
 * proyecto externo, confirmando que las operaciones add() y multiply()
 * funcionan correctamente.
 */

#include "Matrix.h"
#include <iostream> // Necesario para std::cout, ya que aquí también lo usamos

int main() {
    // Creamos dos matrices 2x2 (inicializadas en 0.0 por el constructor)
    Matrix A(2, 2), B(2, 2);

    // Llenamos la matriz A:
    // A = | 1  2 |
    //     | 3  4 |
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    // Llenamos la matriz B:
    // B = | 5  6 |
    //     | 7  8 |
    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    // Probamos la suma: C = A + B
    Matrix C = A.add(B);

    // Probamos la multiplicación: D = A * B
    Matrix D = A.multiply(B);

    // Mostramos los resultados por consola para verificación visual
    std::cout << "Suma:\n";
    C.print();
    // Resultado esperado:
    // 6 8
    // 10 12

    std::cout << "Multiplicación:\n";
    D.print();
    // Resultado esperado:
    // 19 22
    // 43 50

    return 0; // 0 indica que el programa terminó sin errores
}
