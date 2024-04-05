#include "../s21_matrix.h"

/**
 * @brief Функция для вычисления определителя квадратной матрицы A и сохранения
 * результата в переменную result.
 *
 * Определитель матрицы равен сумме произведений элементов строки (столбца)
 * на соответствующие алгебраические дополнения.
 *
 * @param A Указатель на матрицу.
 * @param result Указатель на переменную, в которую будет сохранен определитель.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_determinant(matrix_t *A, double *result) {
  int status = OK;

  if (!s21_check_matrix(A)) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;
  } else {
    *result = s21_determinant_matrix(A, A->rows);
  }

  return status;
}

/**
 * @brief Вычисляет определитель квадратной матрицы A через разложениe по первой
 * строке.
 * @param A Указатель на квадратную матрицу.
 * @param size Размерность матрицы.
 * @return Определитель матрицы.
 */
double s21_determinant_matrix(matrix_t *A, int size) {
  int status = OK;
  double D = 0;

  matrix_t minor = {0};
  s21_create_matrix(size, size, &minor);

  if (minor.matrix == NULL) {
    status = MEMORY_ERROR;
  }

  if (size == 1) {
    D = A->matrix[0][0];
  } else if (size == 2) {
    D = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    for (int i = 0; i < size && status == OK; i++) {
      // Рассчет минора матрицы A с пропуском первой строки и i столбца
      s21_get_minor(*A, &minor, 0, i);

      // Вычисление определителя матрицы A со знаком (чет '+', нечет '-') и
      // аккумулирование с текущим определителем
      D += pow((-1), i) * A->matrix[0][i] *
           s21_determinant_matrix(&minor, size - 1);
    }
  }

  s21_remove_matrix(&minor);

  return D;
}