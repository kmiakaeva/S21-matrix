#include "../s21_matrix.h"

/**
 * @brief Вычисляет обратную матрицу для заданной квадратной матрицы.
 *
 * Обратной матрицы не существует, если определитель равен 0.
 *
 * @param A Указатель на квадратную матрицу.
 * @param result Указатель на матрицу, в которую будет записан результат -
 * обратная матрица.
 * @return OK, если операция выполнена успешно и обратная матрица успешно
 * записана в `result`.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;

  double D = 0;
  const int size = A->rows;
  int status = s21_determinant(A, &D);  // Поиск определителя

  if (status != OK || fabs(D) < S21_EPS) {
    status = CALC_ERROR;
  } else {
    status = s21_create_matrix(size, size, result);
  }

  if (status == OK) {
    matrix_t minor = {0}, minor_transpose = {0};
    s21_calc_complements(A, &minor);  // Матрица алгебраических дополнений (M.)
    // Транспонированная матрица алгебраических дополнений (M^T)
    s21_transpose(&minor, &minor_transpose);

    // Построение обратной матрицы
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        // A^(-1) = (1 / D) * (M^T)
        result->matrix[i][j] = minor_transpose.matrix[i][j] / D;
      }
    }

    s21_remove_matrix(&minor_transpose);
    s21_remove_matrix(&minor);
  }

  return status;
}