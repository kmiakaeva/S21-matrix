#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix_1) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double random_value = s21_get_random_value(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = random_value;
      B.matrix[i][j] = random_value;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  const int rows = 1;
  const int columns = 1;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  const int rows = 1;
  const int columns = 1;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 6;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 6;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  const int rows = 2;
  const int columns = 2;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.6;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1.35;
  A.matrix[1][1] = -0.27;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 1.35;
  B.matrix[1][1] = -0.27;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  const int rows = 1;
  const int columns = 1;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -0.6;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  const int rows = 1;
  const int columns = 1;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 6;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = -6;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  const int rows = 2;
  const int columns = 2;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -0.6;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1.35;
  A.matrix[1][1] = -0.27;

  matrix_t B = {0};
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 0.6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 1.35;
  B.matrix[1][1] = -0.27;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0.6;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1.35;
  A.matrix[1][1] = -0.27;

  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 0.6;
  B.matrix[0][1] = 0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s = suite_create("s21_eq_matrix_suite");
  TCase *tc = tcase_create("s21_eq_matrix_tc");

  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);
  tcase_add_test(tc, s21_eq_matrix_7);
  tcase_add_test(tc, s21_eq_matrix_8);

  suite_add_tcase(s, tc);

  return s;
}