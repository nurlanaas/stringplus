#include "test_string.h"

START_TEST(strerror_1) {
  int errnum = 1;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_2) {
  int errnum = -1;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_3) {
  int errnum = 134;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_4) {
  int errnum = 24;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_5) {
  int errnum = 0;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_6) {
  int errnum = 2;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_7) {
  int errnum = 50;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_8) {
  int errnum = 25;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(strerror_9) {
  for (int errnum = -1; errnum < 136; errnum++) {
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
  }
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);
  tcase_add_test(tc, strerror_7);
  tcase_add_test(tc, strerror_8);
  tcase_add_test(tc, strerror_9);

  suite_add_tcase(s, tc);
  return s;
}