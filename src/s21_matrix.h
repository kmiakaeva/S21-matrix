#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/*
 0 - OK
 1 - Ошибка, некорректная матрица
 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 нельзя провести вычисления и т.д.)
 3 - Ошибка выделения памяти
*/
enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2, MEMORY_ERROR = 3 };

#define SUCCESS 1
#define FAILURE 0

// s21
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
// int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// !s21
int s21_compare_matrix(matrix_t A, matrix_t B);
void s21_multiply_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
double s21_determinant_matrix(matrix_t *A, int size);
void s21_get_minor(matrix_t A, matrix_t *minor, int skip_row, int skip_col);

#endif