#include "../s21_matrix.h"

/**
 * @brief Умножает две матрицы и сохраняет результат в
 * матрице result.
 * @param A Указатель на первую матрицу для умножения.
 * @param B Указатель на вторую матрицу для умножения.
 * @param result Указатель на матрицу, в которую будет сохранен результат
 * умножения.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;

  int status = s21_create_matrix(A->rows, B->columns, result);

  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return status;
}