#include "test_string.h"

START_TEST(strstr_1) {
  char str[256] = "Hello world HeLlo WORLD hello WOrld";
  char str1[256] = "hello";
  ck_assert_pstr_eq(strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(strstr_2) {
  char str[256] = "Hello hello Hello";
  char str1[256] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_3) {
  char str[256] = "Hello hello Hello";
  char str1[256] = "12";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_4) {
  char str[256] = "Hello, world!\0";
  char str1[256] = "\0";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_5) {
  char str[256] = "Hello, world!";
  char str1[256] = "l";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_6) {
  char str[256] = "Hello, world!";
  char str1[256] = "A";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_7) {
  char str[256] = "12341234124";
  char str1[256] = "12";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_8) {
  char str[256] = "123456789";
  char str1[256] = "4568";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_9) {
  char str[256] = "123456789";
  char str1[256] = "345";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_10) {
  char str[256] = "Hello";
  char str1[256] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_11) {
  char str[256] = "Hello, world!";
  char str1[256] = "Hello, world!\0";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_12) {
  char str[256] = "Hello, world!";
  char str1[256] = "";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);
  tcase_add_test(tc, strstr_12);

  suite_add_tcase(s, tc);
  return s;
}