#include "test_string.h"

START_TEST(strchr_1) {
  char str[256] = "Hello";
  char c = 'e';
  ck_assert_pstr_eq(strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[256] = "Hello, world!";
  char c = 'o';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[256] = "Hello, world!";
  char c = '1';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[256] = "Hello, world!";
  char c = 'H';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[256] = "Hello, world!";
  char c = 1;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  char str[256] = "Hello, world!";
  char c = 99;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  char str[256] = "Hello, world!";
  char c = 0;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_8) {
  char str[256] = "0123456789";
  char c = '\0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_9) {
  char str[256] = "0123456789";
  char c = '0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_10) {
  char str[256] = "0123456789";
  char c = ' ';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_11) {
  char str[256] = "\0";
  char c = 'w';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  tcase_add_test(tc, strchr_11);

  suite_add_tcase(s, tc);
  return s;
}