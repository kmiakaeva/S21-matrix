#ifndef S21_UTILS_H
#define S21_UTILS_H

#include <time.h>

#include "s21_matrix.h"

int s21_calloc_matrix(int rows, int columns, matrix_t *result);
void s21_print_matrix(matrix_t A);
int s21_check_matrix(matrix_t *A);
double s21_get_random_value(double min, double max);

#endif