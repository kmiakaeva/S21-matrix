#include "s21_matrix.h"

/**
 * @brief Создает новую матрицу с заданным количеством строк и столбцов,
 * выделяет память для ее элементов.
 * @param rows Количество строк новой матрицы.
 * @param columns Количество столбцов новой матрицы.
 * @param result Указатель на структуру, в которую будет сохранена созданная
 * матрица.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows <= 0 || columns <= 0) {
    return INCORRECT_MATRIX;
  }

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

/**
 * @brief Освобождает память, занятую матрицей, удаляя все ее строки и
 * освобождая массив указателей на строки.
 * @param A Указатель на матрицу, которую необходимо удалить.
 */
void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

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