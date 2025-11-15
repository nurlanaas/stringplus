#include "test_string.h"

START_TEST(strcspn_1) {
  char str[256] = "Hello, world!";
  char str1[256] = "world";
  ck_assert_uint_eq(strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_2) {
  char str[256] = "Hello, world!";
  char str1[256] = "Balatro";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_3) {
  char str[256] = "Hello, world!";
  char str1[256] = "hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_4) {
  char str[256] = "Hello, world!";
  char str1[256] = "123";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_5) {
  char str[256] = "Hello, world!";
  char str1[256] = "";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_6) {
  char str[256] = "Hello, world!";
  char str1[256] = "\0";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_7) {
  char str[256] = "1234321";
  char str1[256] = "89";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_8) {
  char str[256] = "123432156";
  char str1[256] = "123";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_9) {
  char str[256] = "1234321563217";
  char str1[256] = "321";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_10) {
  char str[256] = "";
  char str1[256] = "";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_11) {
  char str[256] = "";
  char str1[256] = "Hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);

  suite_add_tcase(s, tc);
  return s;
}