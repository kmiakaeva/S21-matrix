#ifndef S21_TEST_MATRIX_H
#define S21_TEST_MATRIX_H

#include <check.h>
#include <float.h>

#include "../s21_matrix.h"
#include "../s21_utils.h"

/**
 * s21 suites
 */
Suite *s21_create_matrix_suite(void);
Suite *s21_remove_matrix_suite(void);
Suite *s21_eq_matrix_suite(void);
Suite *s21_sum_matrix_suite(void);
Suite *s21_sub_matrix_suite(void);
Suite *s21_mult_number_suite(void);
Suite *s21_mult_matrix_suite(void);
Suite *s21_transpose_suite(void);
// Suite * s21_calc_complements_suite(void);
Suite *s21_determinant_suite(void);
// Suite * s21_inverse_matrix_suite(void);

/**
 * s21 matrix test
 */
int run_s21_matrix_test(Suite *s21_suite);

#endif