#include "../s21_matrix_test.h"

START_TEST(s21_determinant_1) {
  double result;

  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(result, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  double result;

  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(result, -2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq(result, -3);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  double result;

  matrix_t A = {0};
  s21_create_matrix(6, 3, &A);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  double result;

  matrix_t A = {0};
  s21_create_matrix(3, 6, &A);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  double result;

  int status = s21_determinant(NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t A = {0};
  s21_create_matrix(6, 3, &A);

  int status = s21_determinant(&A, NULL);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_8) {
  double result;
  matrix_t A = {0};

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_9) {
  const int size = 5;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) A.matrix[i][j] = j;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10) {
  const int size = 4;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) A.matrix[i][j] = j + i;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_11) {
  const int size = 5;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][1] = 6;
  A.matrix[0][2] = -2;
  A.matrix[0][3] = -1;
  A.matrix[0][4] = 5;
  A.matrix[1][3] = -9;
  A.matrix[1][4] = -7;
  A.matrix[2][1] = 15;
  A.matrix[2][2] = 35;
  A.matrix[3][1] = -1;
  A.matrix[3][2] = -11;
  A.matrix[3][3] = -2;
  A.matrix[3][4] = 1;
  A.matrix[4][0] = -2;
  A.matrix[4][1] = -2;
  A.matrix[4][2] = 3;
  A.matrix[4][4] = -2;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, 2480);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_12) {
  const int size = 3;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 1;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, -32);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_13) {
  const int size = 2;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = -5;
  A.matrix[0][1] = -4;
  A.matrix[1][0] = -2;
  A.matrix[1][1] = -3;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, 7);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_14) {
  const int size = 1;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = -5;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, -5);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_15) {
  const int size = rand() % 100 + 1;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(-size, -size, &A);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_16) {
  const int rows = 4;
  const int cols = 5;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(rows, cols, &A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX) + 1;
    }
  }

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_17) {
  const int size = 3;
  double result = 0;

  matrix_t A = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = -4;
  A.matrix[1][0] = -2;
  A.matrix[1][1] = -3;
  A.matrix[1][2] = -4;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 5;

  int status = s21_determinant(&A, &result);
  ck_assert_double_eq(result, 30);
  ck_assert_int_eq(status, OK);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("s21_determinant_suite");
  TCase *tc = tcase_create("s21_determinant_tc");

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);
  tcase_add_test(tc, s21_determinant_11);
  tcase_add_test(tc, s21_determinant_12);
  tcase_add_test(tc, s21_determinant_13);
  tcase_add_test(tc, s21_determinant_14);
  tcase_add_test(tc, s21_determinant_15);
  tcase_add_test(tc, s21_determinant_16);
  tcase_add_test(tc, s21_determinant_17);

  suite_add_tcase(s, tc);

  return s;
}