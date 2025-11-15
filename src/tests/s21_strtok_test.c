#include "test_string.h"

START_TEST(strtok_1) {
  char str[256] = "Hello world HeLlo WORLD hello WOrld";
  char str1[256] = "hello";
  ck_assert_pstr_eq(strtok(str, str1), strtok(str, str1));
}
END_TEST

START_TEST(strtok_2) {
  char str[256] = "Hello hello Hello";
  char str1[256] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_3) {
  char str[256] = "helloHellohelloHello";
  char str1[256] = "h";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_4) {
  char str[256] = "Hello, \0 world!\0";
  char str1[256] = "\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_5) {
  char str[256] = "Hello, world!";
  char str1[256] = "l";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_6) {
  char str[256] = "Hello, world!";
  char str1[256] = "A";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_7) {
  char str[256] = "12341234124";
  char str1[256] = "12";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_8) {
  char str[256] = "123456789";
  char str1[256] = "4568";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_9) {
  char str[256] = "Hello, w o r  l    d,!";
  char str1[256] = " ";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_10) {
  char str[256] = "H  ello ";
  char str1[256] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_11) {
  char str[256] = "world! ";
  char str1[256] = "world!";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_12) {
  char str[256] = "";
  char str1[256] = "world! ";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_13) {
  char str[256] = "world! ";
  char str1[256] = "";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_14) {
  char *str = S21_NULL;
  char str1[256] = "";
  ck_assert_ptr_null(s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_15) {
  char str[256] = "Hello, wo,rld,";
  char str1[256] = ",";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);

  suite_add_tcase(s, tc);
  return s;
}