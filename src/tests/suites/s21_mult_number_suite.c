#include "../s21_matrix_test.h"

START_TEST(s21_mult_number_1) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  const double random_value = s21_get_random_value(10e-7, 10e7);
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
      C.matrix[i][j] = A.matrix[i][j] * random_value;
    }
  }

  ck_assert_int_eq(s21_mult_number(&A, random_value, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_2) {
  const int rows = 1;
  const int columns = 1;
  const double random_value = s21_get_random_value(10e-7, 10e7);
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;

  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);
  C.matrix[0][0] = A.matrix[0][0] * random_value;

  ck_assert_int_eq(s21_mult_number(&A, random_value, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_3) {
  const int rows = 2;
  const int columns = 2;
  const double random_value = s21_get_random_value(10e-7, 10e7);
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;
  A.matrix[0][1] = 42;
  A.matrix[1][0] = 1.35;
  A.matrix[1][1] = -0.27;

  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);
  C.matrix[0][0] = A.matrix[0][0] * random_value;
  C.matrix[0][1] = A.matrix[0][1] * random_value;
  C.matrix[1][0] = A.matrix[1][0] * random_value;
  C.matrix[1][1] = A.matrix[1][1] * random_value;

  ck_assert_int_eq(s21_mult_number(&A, random_value, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_4) {
  const double random_value = s21_get_random_value(10e-7, 10e7);
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(0, -1, &A);

  ck_assert_int_eq(s21_mult_number(&A, random_value, &result),
                   INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_5) {
  const double random_value = s21_get_random_value(10e-7, 10e7);
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(-1, 0, &A);

  ck_assert_int_eq(s21_mult_number(&A, random_value, &result),
                   INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s = suite_create("s21_mult_number_suite");
  TCase *tc = tcase_create("s21_mult_number_tc");

  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);
  tcase_add_test(tc, s21_mult_number_3);
  tcase_add_test(tc, s21_mult_number_4);
  tcase_add_test(tc, s21_mult_number_5);

  suite_add_tcase(s, tc);

  return s;
}