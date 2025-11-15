#include "test_string.h"

START_TEST(sprintf_g_1) {
  char str1[200] = "";
  char str2[200] = "";
  float x = 54321.542;
  char *str3 = "|%g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_2) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.0;
  char *str3 = "|%8.2g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_3) {
  char str1[200] = "";
  char str2[200] = "";
  double x = -1234.56785665;
  char *str3 = "|%+-10.1g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_4) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%+-25.13g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_5) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%- 25.13g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_6) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%0.13g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_7) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;
  char *str3 = "|%#.0g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_8) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;
  char *str3 = "|%*.*g|\n";
  int res1 = s21_sprintf(str1, str3, 1, 1, x);
  int res2 = sprintf(str2, str3, 1, 1, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_9) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 9999999999;
  char *str3 = "|%g|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_10) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e+38;
  char *str3 = "|%Lg|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_11) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e-258;
  char *str3 = "|%Lg|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_12) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 1234567898765.12345678987654;
  char *str3 = "|%28.8Lg|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_13) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 0.0;
  char *str3 = "|%25.8Lg|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_g(void) {
  Suite *s = suite_create("s21_sprintf_g");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_g_1);
  tcase_add_test(tc, sprintf_g_2);
  tcase_add_test(tc, sprintf_g_3);
  tcase_add_test(tc, sprintf_g_4);
  tcase_add_test(tc, sprintf_g_5);
  tcase_add_test(tc, sprintf_g_6);
  tcase_add_test(tc, sprintf_g_7);
  tcase_add_test(tc, sprintf_g_8);
  tcase_add_test(tc, sprintf_g_9);
  tcase_add_test(tc, sprintf_g_10);
  tcase_add_test(tc, sprintf_g_11);
  tcase_add_test(tc, sprintf_g_12);
  tcase_add_test(tc, sprintf_g_13);

  suite_add_tcase(s, tc);
  return s;
}