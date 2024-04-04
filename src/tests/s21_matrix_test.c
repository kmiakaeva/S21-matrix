#include "s21_matrix_test.h"

int main(void) {
  Suite *s21_suites[] = {
      s21_create_matrix_suite(),  s21_remove_matrix_suite(),
      s21_eq_matrix_suite(),      s21_sum_matrix_suite(),
      s21_sub_matrix_suite(),     s21_mult_number_suite(),
      s21_mult_matrix_suite(),    s21_transpose_suite(),
      s21_determinant_suite(),    s21_calc_complements_suite(),
      s21_inverse_matrix_suite(), NULL};

  for (int i = 0; s21_suites[i] != NULL; i++) {
    run_s21_matrix_test(s21_suites[i]);
  }

  return 0;
}

int run_s21_matrix_test(Suite *s21_suite) {
  SRunner *sr = srunner_create(s21_suite);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  printf("\n");

  return 0;
}