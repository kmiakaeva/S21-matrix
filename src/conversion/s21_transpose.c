#include "../s21_matrix.h"

/**
 * @brief Транспонирует матрицу A и сохраняет результат в матрицу result.
 * @param A Указатель на исходную матрицу, которую нужно транспонировать.
 * @param result Указатель на матрицу, в которую будет сохранен результат
 * транспонирования.
 * @return OK, если транспонирование выполнено успешно.
 */
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