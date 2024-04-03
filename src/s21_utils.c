#include "s21_utils.h"

int s21_calloc_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (result->matrix == NULL) {
    status = MEMORY_ERROR;
  } else {
    for (int i = 0; i < rows && status == OK; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));

      if (result->matrix[i] == NULL) {
        status = MEMORY_ERROR;
      }
    }

    result->rows = rows;
    result->columns = columns;
  }

  return status;
}

void s21_print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%f ", A.matrix[i][j]);
    }
    printf("\n");
  }
}

int s21_check_matrix(matrix_t *A) {
  int status = SUCCESS;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    status = FAILURE;
  }

  return status;
}

double s21_get_random_value(double min, double max) {
  static int is_init = 0;

  if (!is_init) {
    srand(time(NULL));
    is_init = 1;
  }

  double random_number = (double)rand() / RAND_MAX;

  return min + random_number * (max - min);
}