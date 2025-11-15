#include "test_string.h"

START_TEST(strcpy_1) {
  char str[256] = "Hello";
  char str1[256] = "world";
  ck_assert_str_eq(strcpy(str, str1), strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_2) {
  char str[256] = "Hello, world!";
  char str1[256] = "Goodbye, world!";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_3) {
  char str[256] = "Hello, world!";
  char str1[256] = "hello, world!";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_4) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, \0 world";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_5) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello,\n world";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_6) {
  char str[256] = "Hello, world!";
  char str1[256] = "World world!";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_7) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, gold";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_8) {
  char str[256] = "123454321";
  char str1[256] = "123454321";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_9) {
  char str[256] = "123454321";
  char str1[256] = "123454321";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_10) {
  char str[256] = "";
  char str1[256] = "Hello";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_11) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, world!\0";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_12) {
  char str[256] = "\0";
  char str1[256] = "Hello, world!\0";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(strcpy_13) {
  char str[256] = "Hello, world!";
  char str1[256] = "";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

Suite *test_strcpy(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("strcpy_tc");

  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strcpy_4);
  tcase_add_test(tc, strcpy_5);
  tcase_add_test(tc, strcpy_6);
  tcase_add_test(tc, strcpy_7);
  tcase_add_test(tc, strcpy_8);
  tcase_add_test(tc, strcpy_9);
  tcase_add_test(tc, strcpy_10);
  tcase_add_test(tc, strcpy_11);
  tcase_add_test(tc, strcpy_12);
  tcase_add_test(tc, strcpy_13);

  suite_add_tcase(s, tc);
  return s;
}