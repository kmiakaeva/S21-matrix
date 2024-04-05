#include "../s21_matrix.h"

/**
 * @brief Функция для вычисления алгебраических дополнений для матрицы A и
 * сохранения их в матрицу result.
 *
 * Алгебраическим дополнением элемента матрицы является значение минора
 * умноженное на -1^(i+j).
 *
 * @param A Указатель на матрицу, для которой необходимо вычислить
 * алгебраические дополнения.
 * @param result Указатель на матрицу, в которую будут сохранены алгебраические
 * дополнения.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!s21_check_matrix(A)) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;
  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
  }

  if (status == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      status = s21_calc_complements_matrix(A, result, A->rows);
    }
  }

  return status;
}

/**
 * @brief Функция для заполнения матрицы алгебраических дополнений для матрицы
 * A.
 * @param A Указатель на исходную матрицу.
 * @param result Указатель на матрицу, в которую будут сохранены алгебраические
 * дополнения.
 * @param size Размерность матрицы.
 * @return Статус операции (OK в случае успешного выполнения).
 */
int s21_calc_complements_matrix(matrix_t *A, matrix_t *result, int size) {
  int status = OK;

  matrix_t minor = {0};
  s21_create_matrix(size, size, &minor);

  if (minor.matrix == NULL) {
    status = MEMORY_ERROR;
  }

  for (int i = 0; i < size && status == OK; i++) {
    for (int j = 0; j < size; j++) {
      s21_get_minor(*A, &minor, i, j);
      result->matrix[i][j] =
          pow((-1), i + j) * s21_determinant_matrix(&minor, size - 1);
    }
  }

  s21_remove_matrix(&minor);

  return status;
}