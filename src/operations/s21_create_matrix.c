#include "../s21_matrix.h"

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