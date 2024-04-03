#include "../s21_matrix.h"

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