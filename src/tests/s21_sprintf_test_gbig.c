#include "test_string.h"

START_TEST(sprintf_gbig_1) {
  char str1[200] = "";
  char str2[200] = "";
  float x = 54321.542;
  char *str3 = "|%G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_2) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.0;
  char *str3 = "|%8.2G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_3) {
  char str1[200] = "";
  char str2[200] = "";
  double x = -1234.56785665;
  char *str3 = "|%+-10.1G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_4) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%+-25.13G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_5) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%- 25.13G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_6) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 0.12345678;
  char *str3 = "|%0.13G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_7) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;
  char *str3 = "|%#.0G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_8) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 123;
  char *str3 = "|%*.*G|\n";
  int res1 = s21_sprintf(str1, str3, 1, 1, x);
  int res2 = sprintf(str2, str3, 1, 1, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_9) {
  char str1[200] = "";
  char str2[200] = "";
  double x = 9999999999;
  char *str3 = "|%G|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_10) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e+38;
  char *str3 = "|%LG|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_11) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 123e-258;
  char *str3 = "|%LG|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_12) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 1234567898765.12345678987654;
  char *str3 = "|%%28.8LG|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_gbig_13) {
  char str1[200] = "";
  char str2[200] = "";
  long double x = 0.0;
  char *str3 = "|%25.8LG|\n";
  int res1 = s21_sprintf(str1, str3, x);
  int res2 = sprintf(str2, str3, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_gbig(void) {
  Suite *s = suite_create("s21_sprintf_G");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_gbig_1);
  tcase_add_test(tc, sprintf_gbig_2);
  tcase_add_test(tc, sprintf_gbig_3);
  tcase_add_test(tc, sprintf_gbig_4);
  tcase_add_test(tc, sprintf_gbig_5);
  tcase_add_test(tc, sprintf_gbig_6);
  tcase_add_test(tc, sprintf_gbig_7);
  tcase_add_test(tc, sprintf_gbig_8);
  tcase_add_test(tc, sprintf_gbig_9);
  tcase_add_test(tc, sprintf_gbig_10);
  tcase_add_test(tc, sprintf_gbig_11);
  tcase_add_test(tc, sprintf_gbig_12);
  tcase_add_test(tc, sprintf_gbig_13);

  suite_add_tcase(s, tc);
  return s;
}