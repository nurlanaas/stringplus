#include "test_string.h"

START_TEST(sscanf_g_1) {
  char buffer[] = "-1.234e-05";
  float value;
  float value2;
  int result = sscanf(buffer, "%g", &value);
  int result2 = s21_sscanf(buffer, "%g", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_g_2) {
  char buffer[] = "1";
  float value;
  float value2;
  int result = sscanf(buffer, "%g", &value);
  int result2 = s21_sscanf(buffer, "%g", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_g_3) {
  char buffer[] = "1234.567891";
  float value;
  float value2;
  int result = sscanf(buffer, "%g", &value);
  int result2 = s21_sscanf(buffer, "%g", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_g_4) {
  char buffer[] = "1234.567898";
  double value;
  double value2;
  int result = sscanf(buffer, "%lg", &value);
  int result2 = sscanf(buffer, "%lg", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

START_TEST(sscanf_g_5) {
  char buffer[] = "1234.567898";
  long double value;
  long double value2;
  int result = sscanf(buffer, "%Lg", &value);
  int result2 = sscanf(buffer, "%Lg", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

Suite *test_sscanf_g(void) {
  Suite *s = suite_create("s21_sscanf_g");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_g_1);
  tcase_add_test(tc, sscanf_g_2);
  tcase_add_test(tc, sscanf_g_3);
  tcase_add_test(tc, sscanf_g_4);
  tcase_add_test(tc, sscanf_g_5);

  suite_add_tcase(s, tc);
  return s;
}