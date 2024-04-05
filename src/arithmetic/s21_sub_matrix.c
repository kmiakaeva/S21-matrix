#include "../s21_matrix.h"

/**
 * @brief Вычитает одну матрицу из другой и сохраняет результат в матрице
 * result.
 * @param A Указатель на первую матрицу для вычитания.
 * @param B Указатель на вторую матрицу, которую нужно вычесть из первой.
 * @param result Указатель на матрицу, в которую будет сохранен результат
 * вычитания.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!s21_check_matrix(A) || !s21_check_matrix(B)) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = CALC_ERROR;
  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
  }

  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status;
}