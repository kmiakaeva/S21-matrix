#include "s21_matrix.h"

/**
 * 1. Определитель матрицы равен сумме произведений элементов строки (столбца)
 * на соответствующие алгебраические дополнения
 * 2. Определитель существует только для квадратных матриц [n * n]
 * 3. Миноры матрицы - это определители всех её подматриц, получаемых путем
 * вычеркивания i строк и j столбцов из исходной матрицы
 * 4. Минор имеет размер (size - 1) x (size - 1)
 */
int s21_determinant(matrix_t *A, double *result) {
  int status = OK;

  if (!s21_check_matrix(A)) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;  // пункт 2
  } else {
    *result = s21_determinant_matrix(A, A->rows);
  }

  return status;
}

double s21_determinant_matrix(matrix_t *A, int size) {
  int status = OK;
  double D = 0;  // Определитель

  if (size == 1) {
    D = A->matrix[0][0];
  } else if (size == 2) {
    D = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    // Для вычисления определителя используется разложениe по первой строке
    for (int i = 0; i < size && status == OK; i++) {
      matrix_t minor = {0};
      s21_create_matrix(size, size, &minor);

      if (minor.matrix == NULL) {
        status = MEMORY_ERROR;
      }

      if (status == OK) {
        // Рассчет минора матрицы A с пропуском первой строки и i столбца
        s21_get_minor(*A, &minor, 0, i);
        // Вычисление элемента определителя матрицы A со знаком (чет '+', нечет
        // '-') и аккумулирование с текущим определителем
        D += pow((-1), i) * A->matrix[0][i] *
             s21_determinant_matrix(&minor, size - 1);  // size - 1 (пункт 4)
      }

      s21_remove_matrix(&minor);
    }
  }

  return D;
}

void s21_get_minor(matrix_t A, matrix_t *minor, int skip_row, int skip_col) {
  int minor_row = 0, minor_col = 0;

  for (int rows = 0; rows < A.rows; rows++) {
    if (rows == skip_row) continue;  // Пропускаем строку

    minor_col = 0;  // Сбрасываем счетчик столбцов для каждой строки минора

    for (int columns = 0; columns < A.columns; columns++) {
      if (columns == skip_col) continue;  // Пропускаем столбец

      minor->matrix[minor_row][minor_col++] = A.matrix[rows][columns];
    }

    minor_row++;  // Переходим к следующей строке минора
  }
}