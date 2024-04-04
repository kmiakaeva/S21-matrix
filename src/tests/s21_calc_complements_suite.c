#include "s21_matrix_test.h"

START_TEST(s21_calc_complements_1) {
  const int size = 3;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  matrix_t C = {0};
  s21_create_matrix(size, size, &C);
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 10;
  C.matrix[0][2] = -20;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = -14;
  C.matrix[1][2] = 8;
  C.matrix[2][0] = -8;
  C.matrix[2][1] = -2;
  C.matrix[2][2] = 4;

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(4, 6, &A);

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(6, 4, &A);

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t A = {0};
  s21_create_matrix(3, 2, &A);

  int status = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t result = {0};

  int status = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t A = {0};
  matrix_t result = {0};

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(6, 6, &A);

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  const int size = 2;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = -4;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 3;

  matrix_t C = {0};
  s21_create_matrix(size, size, &C);
  C.matrix[0][0] = 3;
  C.matrix[0][1] = 1;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 6;

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_9) {
  const int size = 1;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 6;

  matrix_t C = {0};
  s21_create_matrix(size, size, &C);
  C.matrix[0][0] = 1;

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s = suite_create("s21_calc_complements_suite");
  TCase *tc = tcase_create("s21_calc_complements_tc");

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);
  tcase_add_test(tc, s21_calc_complements_7);
  tcase_add_test(tc, s21_calc_complements_8);
  tcase_add_test(tc, s21_calc_complements_9);

  suite_add_tcase(s, tc);

  return s;
}