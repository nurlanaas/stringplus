#include "test_string.h"

START_TEST(sprintf_e_1) {
  char str1[200] = "";
  char str2[200] = "";
  float x = 54321.542;
  char *str3 = "|%e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_2) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.0;
  char *str3 = "|%8.2e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_3) {
  char str1[200] = "";
  char str2[200] = "";
  double x = -1234.56785665;
  char *str3 = "|%+-10.1e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_4) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%+-30.13e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_5) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%- 30.13e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_6) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%0.13e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_7) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;
  char *str3 = "|%#.0e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_8) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;  // 1.23
  char *str3 = "|%*.*e|\n";
  int res1 = s21_sprintf(str1, str3, 1, 1, x);
  int res2 = sprintf(str2, str3, 1, 1, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_9) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 9999999999;
  char *str3 = "|%e|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_10) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e+38;
  char *str3 = "|%Le|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_11) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e-308;
  char *str3 = "|%Le|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_12) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 1234567898765.12345678987654;
  char *str3 = "|%30.8Le|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_13) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 0.0;
  char *str3 = "|%30.8Le|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_e(void) {
  Suite *s = suite_create("s21_sprintf_e");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_e_1);
  tcase_add_test(tc, sprintf_e_2);
  tcase_add_test(tc, sprintf_e_3);
  tcase_add_test(tc, sprintf_e_4);
  tcase_add_test(tc, sprintf_e_5);
  tcase_add_test(tc, sprintf_e_6);
  tcase_add_test(tc, sprintf_e_7);
  tcase_add_test(tc, sprintf_e_8);
  tcase_add_test(tc, sprintf_e_9);
  tcase_add_test(tc, sprintf_e_10);
  tcase_add_test(tc, sprintf_e_11);
  tcase_add_test(tc, sprintf_e_12);
  tcase_add_test(tc, sprintf_e_13);

  suite_add_tcase(s, tc);
  return s;
}