#include "test_string.h"

START_TEST(memcmp_1) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_2) {
  char str[] = "Hello, world!";
  char str1[] = "Goodbye";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_3) {
  char str[] = "Hello, world!";
  char str1[] = "hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_4) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world\0";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_5) {
  char str[] = "Hello, world!";
  char str1[] = "Hello,\n world";
  s21_size_t len = 10;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_6) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, friend!";
  s21_size_t len = 5;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_7) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, worm";
  s21_size_t len = 7;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_8) {
  char str[] = "1234321";
  char str1[] = "1234321";
  s21_size_t len = 0;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_9) {
  char str[] = "1234321";
  char str1[] = "1234321";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_10) {
  char str[] = "Hello";
  char str1[] = "Hello";
  s21_size_t len = 0;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_11) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str) + 1;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_12) {
  char str[] = "Hello, world!\0";
  char str1[] = "Hello, world";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp_13) {
  char str[] = "Hell\0o, world!";
  char str1[] = "Hello, world";
  s21_size_t len = 4;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);
  tcase_add_test(tc, memcmp_13);

  suite_add_tcase(s, tc);
  return s;
}