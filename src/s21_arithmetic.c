#include "s21_matrix.h"
#include "s21_utils.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
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
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return status;
}

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

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!s21_check_matrix(A) || !s21_check_matrix(B)) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != B->columns) {
    status = CALC_ERROR;
  } else {
    status = s21_create_matrix(A->rows, B->columns, result);

    if (status == OK) {
      s21_multiply_matrix(A, B, result);
    }
  }

  return status;
}

void s21_multiply_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}