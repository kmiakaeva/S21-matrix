#include "../s21_matrix.h"

/**
 * @brief Сравнивает две матрицы на равенство с учетом погрешности S21_EPS.
 * @param A Указатель на первую матрицу.
 * @param B Указатель на вторую матрицу.
 * @return Статус операции (SUCCESS в случае равенства матриц, FAILURE в
 * противном случае).
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if (A->rows != B->rows || A->columns != B->columns || !s21_check_matrix(A) ||
      !s21_check_matrix(B)) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows && status; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > S21_EPS) {
        status = FAILURE;
      }
    }
  }

  return status;
}