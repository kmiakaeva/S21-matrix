#include "../s21_matrix.h"

int s21_check_matrix(matrix_t *A) {
  int status = SUCCESS;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    status = FAILURE;
  }

  return status;
}