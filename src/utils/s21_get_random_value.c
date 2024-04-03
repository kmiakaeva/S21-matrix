#include "../s21_matrix.h"

double s21_get_random_value(double min, double max) {
  static int is_init = 0;

  if (!is_init) {
    srand(time(NULL));
    is_init = 1;
  }

  double random_number = (double)rand() / RAND_MAX;

  return min + random_number * (max - min);
}