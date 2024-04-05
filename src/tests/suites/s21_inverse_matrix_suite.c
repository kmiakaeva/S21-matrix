#include "../s21_matrix_test.h"

START_TEST(s21_inverse_matrix_1) {
  const int size = 3;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  matrix_t C = {0};
  s21_create_matrix(size, size, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);                      // !
  ck_assert_int_eq(s21_eq_matrix(&result, &C), 1);  //!

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t result = {0};

  int status = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(status, 1);  //!

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t result;
  matrix_t A = {0};

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 1);  //!

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *suite = suite_create("s21_inverse_matrix_suite");
  TCase *tc = tcase_create("s21_inverse_matrix_tc");

  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);

  suite_add_tcase(suite, tc);

  return suite;
}