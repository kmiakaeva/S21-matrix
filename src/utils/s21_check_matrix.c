#include "../s21_matrix.h"

/**
 * @brief Проверяет корректность матрицы.
 * @param A Указатель на матрицу, которую нужно проверить.
 * @return SUCCESS (1), если матрица корректна, иначе FAILURE (0).
 */
int s21_check_matrix(matrix_t *A) {
  int status = SUCCESS;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    status = FAILURE;
  }

  return status;
}