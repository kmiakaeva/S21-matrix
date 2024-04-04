#include "../s21_matrix.h"

/**
 * @brief Генерирует случайное число в заданном диапазоне.
 * @param min Минимальное значение диапазона.
 * @param max Максимальное значение диапазона.
 * @return Случайное число в заданном диапазоне [min, max].
 */
double s21_get_random_value(double min, double max) {
  static int is_init = 0;

  // Проводим инициализацию генератора случайных чисел, если это ещё не сделано
  if (!is_init) {
    srand(time(NULL));
    is_init = 1;
  }

  // Генерируем случайное число в диапазоне [0, 1] и масштабируем его
  // до диапазона [min, max]
  double random_number = (double)rand() / RAND_MAX;

  return min + random_number * (max - min);
}