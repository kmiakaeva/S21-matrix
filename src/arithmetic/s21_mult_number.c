#include "../s21_matrix.h"

/**
 * Умножает каждый элемент матрицы на заданное число и сохраняет результат в
 * матрице result.
 * @param A Указатель на матрицу, элементы которой нужно умножить на число.
 * @param number Число, на которое нужно умножить каждый элемент матрицы.
 * @param result Указатель на матрицу, в которую будет сохранен результат
 * умножения.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;

  if (!s21_check_matrix(A)) {
    status = INCORRECT_MATRIX;
  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
  }

  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return status;
}