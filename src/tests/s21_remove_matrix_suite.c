#include "s21_matrix_test.h"

START_TEST(s21_remove_matrix_1) {
  const int rows = 1;
  const int columns = 1;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  const int rows = 6;
  const int columns = 16;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  const int rows = 16;
  const int columns = 6;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  const int rows = 2;
  const int columns = 1;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, OK);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  const int rows = 0;
  const int columns = 6;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_6) {
  const int rows = 6;
  const int columns = 0;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_7) {
  const int rows = 0;
  const int columns = 0;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_8) {
  const int rows = 0;
  const int columns = -6;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_9) {
  const int rows = -6;
  const int columns = 0;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_remove_matrix_10) {
  const int rows = -6;
  const int columns = -6;
  matrix_t A = {0};

  int status = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);

  if (A.matrix != NULL) {
    status = MEMORY_ERROR;
  }

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("s21_remove_matrix_suite");
  TCase *tc = tcase_create("s21_remove_matrix_tc");

  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_2);
  tcase_add_test(tc, s21_remove_matrix_3);
  tcase_add_test(tc, s21_remove_matrix_4);
  tcase_add_test(tc, s21_remove_matrix_5);
  tcase_add_test(tc, s21_remove_matrix_6);
  tcase_add_test(tc, s21_remove_matrix_7);
  tcase_add_test(tc, s21_remove_matrix_8);
  tcase_add_test(tc, s21_remove_matrix_9);
  tcase_add_test(tc, s21_remove_matrix_10);

  suite_add_tcase(s, tc);

  return s;
}