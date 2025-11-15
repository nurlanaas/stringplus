#include "test_string.h"

START_TEST(sprintf_percent_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Hello world";

  ck_assert_int_eq(sprintf(str1, "%s", str3), s21_sprintf(str2, "%s", str3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello wo%%%%rld";
  ck_assert_int_eq(sprintf(str1, "%s", str3), s21_sprintf(str2, "%s", str3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = " Hel%%lo %% WORLD %%";
  ck_assert_int_eq(sprintf(str1, "%s", str3), s21_sprintf(str2, "%s", str3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_percent(void) {
  Suite *s = suite_create("s21_sprintf_percent");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_percent_1);
  tcase_add_test(tc, sprintf_percent_2);
  tcase_add_test(tc, sprintf_percent_3);

  suite_add_tcase(s, tc);
  return s;
}