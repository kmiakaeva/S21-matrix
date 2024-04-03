#include "s21_matrix.h"

#include "s21_utils.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows <= 0 || columns <= 0) {
    status = INCORRECT_MATRIX;
  } else {
    status = s21_calloc_matrix(rows, columns, result);
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if (A->rows != B->rows || A->columns != B->columns || !s21_check_matrix(A) ||
      !s21_check_matrix(B)) {
    status = FAILURE;
  } else {
    status = s21_compare_matrix(*A, *B);
  }

  return status;
}

int s21_compare_matrix(matrix_t A, matrix_t B) {
  int status = SUCCESS;

  for (int i = 0; i < A.rows && status; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (A.matrix[i][j] != B.matrix[i][j]) {
        status = FAILURE;
      }
    }
  }

  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!s21_check_matrix(A)) {
    status = INCORRECT_MATRIX;
  } else {
    status = s21_create_matrix(A->columns, A->rows, result);
  }

  if (status == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return status;
}