#include "test_string.h"

START_TEST(strncpy_1) {
  char str[256] = "Hello";
  char str1[256] = "world";
  ck_assert_str_eq(strncpy(str, str1, 4), strncpy(str, str1, 4));
}
END_TEST

START_TEST(strncpy_2) {
  char str[256] = "Hello, world!";
  char str1[256] = "Goodbye, world!";
  ck_assert_str_eq(strncpy(str, str1, strlen(str1)),
                   s21_strncpy(str, str1, strlen(str1)));
}
END_TEST

START_TEST(strncpy_3) {
  char str[256] = "Hello, world!";
  char str1[256] = "hello, world!";
  ck_assert_str_eq(strncpy(str, str1, 13), s21_strncpy(str, str1, 13));
}
END_TEST

START_TEST(strncpy_4) {
  char str[256] = "Hello, world!";
  char str1[256] = "hello, \0 world!";
  ck_assert_str_eq(strncpy(str, str1, 15), s21_strncpy(str, str1, 15));
}
END_TEST

START_TEST(strncpy_5) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello,\n world";
  ck_assert_str_eq(strncpy(str, str1, 10), s21_strncpy(str, str1, 10));
}
END_TEST

START_TEST(strncpy_6) {
  char str[256] = "Hello, world!";
  char str1[256] = "World world!";
  ck_assert_str_eq(strncpy(str, str1, 1), s21_strncpy(str, str1, 1));
}
END_TEST

START_TEST(strncpy_7) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, gold";
  ck_assert_str_eq(strncpy(str, str1, 5), s21_strncpy(str, str1, 5));
}
END_TEST

START_TEST(strncpy_8) {
  char str[256] = "123454321";
  char str1[256] = "123454321";
  ck_assert_str_eq(strncpy(str, str1, 9), s21_strncpy(str, str1, 9));
}
END_TEST

START_TEST(strncpy_9) {
  char str[256] = "123454321";
  char str1[256] = "123454321";
  ck_assert_str_eq(strncpy(str, str1, 4), s21_strncpy(str, str1, 4));
}
END_TEST

START_TEST(strncpy_10) {
  char str[256] = "";
  char str1[256] = "Hello";
  ck_assert_str_eq(strncpy(str, str1, 6), s21_strncpy(str, str1, 6));
}
END_TEST

START_TEST(strncpy_11) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, world!\0";
  ck_assert_str_eq(strncpy(str, str1, 71), s21_strncpy(str, str1, 71));
}
END_TEST

START_TEST(strncpy_12) {
  char str[256] = "\0";
  char str1[256] = "Hello, world!\0";
  ck_assert_str_eq(strncpy(str, str1, 20), s21_strncpy(str, str1, 20));
}
END_TEST

START_TEST(strncpy_13) {
  char str[256] = "Hello, world!";
  char str1[256] = "";
  ck_assert_str_eq(strncpy(str, str1, 20), s21_strncpy(str, str1, 20));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("strncpy_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);
  tcase_add_test(tc, strncpy_11);
  tcase_add_test(tc, strncpy_12);
  tcase_add_test(tc, strncpy_13);

  suite_add_tcase(s, tc);
  return s;
}