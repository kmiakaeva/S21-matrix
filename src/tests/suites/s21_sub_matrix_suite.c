#include "../s21_matrix_test.h"

START_TEST(s21_sub_matrix_1) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
      B.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
      C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
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
  C.matrix[0][0] = A.matrix[0][0] - B.matrix[0][0];

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
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
  B.matrix[0][0] = 78;
  B.matrix[0][1] = 0.42;
  B.matrix[1][0] = 0.0075;
  B.matrix[1][1] = -0.891;

  matrix_t C = {0};
  s21_create_matrix(rows, columns, &C);
  C.matrix[0][0] = A.matrix[0][0] - B.matrix[0][0];
  C.matrix[0][1] = A.matrix[0][1] - B.matrix[0][1];
  C.matrix[1][0] = A.matrix[1][0] - B.matrix[1][0];
  C.matrix[1][1] = A.matrix[1][1] - B.matrix[1][1];

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(6, 66, &A);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 66; j++) {
      A.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t B = {0};
  s21_create_matrix(66, 6, &B);
  for (int i = 0; i < 66; i++) {
    for (int j = 0; j < 6; j++) {
      B.matrix[i][j] = s21_get_random_value(DBL_MIN, DBL_MAX);
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t result = {0};

  matrix_t A = {0};
  s21_create_matrix(-6, 66, &A);

  matrix_t B = {0};
  s21_create_matrix(-6, 66, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *s = suite_create("s21_sub_matrix_suite");
  TCase *tc = tcase_create("s21_sub_matrix_tc");

  tcase_add_test(tc, s21_sub_matrix_1);
  tcase_add_test(tc, s21_sub_matrix_2);
  tcase_add_test(tc, s21_sub_matrix_3);
  tcase_add_test(tc, s21_sub_matrix_4);
  tcase_add_test(tc, s21_sub_matrix_5);

  suite_add_tcase(s, tc);

  return s;
}