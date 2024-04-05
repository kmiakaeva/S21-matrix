#include "../s21_matrix_test.h"

START_TEST(s21_mult_matrix_1) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = s21_get_random_value(10e-7, 10e7);
    }
  }

  matrix_t B = {0};
  s21_create_matrix(columns, rows, &B);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      B.matrix[i][j] = s21_get_random_value(10e-7, 10e7);
    }
  }

  matrix_t C = {0};
  s21_create_matrix(A.rows, B.columns, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      C.matrix[i][j] = 0;
      for (int k = 0; k < A.columns; k++) {
        C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  const int rows = 1;
  const int columns = 1;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;

  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);
  C.matrix[0][0] = A.matrix[0][0] * B.matrix[0][0];

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  const int rows = 2;
  const int columns = 2;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;
  A.matrix[0][1] = 42;
  A.matrix[1][0] = 1.35;
  A.matrix[1][1] = -0.27;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;
  B.matrix[0][1] = -6;
  B.matrix[1][0] = 966.32;
  B.matrix[1][1] = -42;

  matrix_t C = {0};
  s21_create_matrix(A.rows, B.columns, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      C.matrix[i][j] = 0;
      for (int k = 0; k < A.columns; k++) {
        C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(1, 0, &A);

  matrix_t B = {0};
  s21_create_matrix(0, 2, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);

  matrix_t B = {0};
  s21_create_matrix(1, 3, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s = suite_create("s21_mult_matrix_suite");
  TCase *tc = tcase_create("s21_mult_matrix_tc");

  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);

  suite_add_tcase(s, tc);

  return s;
}