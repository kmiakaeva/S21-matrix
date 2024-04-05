#include "../s21_matrix.h"

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