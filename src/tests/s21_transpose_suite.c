#include "s21_matrix_test.h"

START_TEST(s21_transpose_1) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t C = {0};
  s21_create_matrix(columns, rows, &C);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      C.matrix[i][j] = A.matrix[j][i];
    }
  }

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_2) {
  const int rows = 2;
  const int columns = 2;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);
  C.matrix[0][0] = A.matrix[0][0];
  C.matrix[0][1] = A.matrix[1][0];
  C.matrix[1][0] = A.matrix[0][1];
  C.matrix[1][1] = A.matrix[1][1];

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
  const int rows = 2;
  const int columns = 3;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  matrix_t C = {0};
  s21_create_matrix(columns, rows, &C);
  C.matrix[0][0] = A.matrix[0][0];
  C.matrix[0][1] = A.matrix[1][0];
  C.matrix[1][0] = A.matrix[0][1];
  C.matrix[1][1] = A.matrix[1][1];
  C.matrix[2][0] = A.matrix[0][2];
  C.matrix[2][1] = A.matrix[1][2];

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(-1, 0, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s = suite_create("s21_transpose_suite");
  TCase *tc = tcase_create("s21_transpose_tc");

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);

  suite_add_tcase(s, tc);

  return s;
}