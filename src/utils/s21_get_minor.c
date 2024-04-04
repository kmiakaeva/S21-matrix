#include "../s21_matrix.h"

/**
 * @brief Получает минор матрицы A с пропуском строки skip_row и столбца
 * skip_col и сохраняет его в матрицу minor.
 *
 * Миноры матрицы - это определители всех её подматриц, получаемых путем
 * вычеркивания i строки и j столбца из исходной матрицы. Минор имеет размер
 * (size - 1) x (size - 1).
 *
 * @param A Матрица, из которой получается минор.
 * @param minor Указатель на матрицу, в которую будет сохранен минор.
 * @param skip_row Номер строки, которую нужно пропустить при формировании
 * минора.
 * @param skip_col Номер столбца, который нужно пропустить при формировании
 * минора.
 */
void s21_get_minor(matrix_t A, matrix_t *minor, int skip_row, int skip_col) {
  int minor_row = 0, minor_col = 0;

  for (int rows = 0; rows < A.rows; rows++) {
    if (rows == skip_row) continue;

    minor_col = 0;  // Сбрасываем счетчик столбцов для каждой строки минора

    for (int columns = 0; columns < A.columns; columns++) {
      if (columns == skip_col) continue;

      minor->matrix[minor_row][minor_col++] = A.matrix[rows][columns];
    }

    minor_row++;  // Переходим к следующей строке минора
  }
}