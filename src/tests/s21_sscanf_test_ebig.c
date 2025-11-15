#include "test_string.h"

START_TEST(sscanf_ebig_1) {
  char buffer[] = "-1.234e-05";
  float value;
  float value2;
  int result = sscanf(buffer, "%E", &value);
  int result2 = s21_sscanf(buffer, "%E", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_ebig_2) {
  char buffer[] = "1";
  float value;
  float value2;
  int result = sscanf(buffer, "%E", &value);
  int result2 = s21_sscanf(buffer, "%E", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_ebig_3) {
  char buffer[] = "1234.567891";
  float value;
  float value2;
  int result = sscanf(buffer, "%E", &value);
  int result2 = s21_sscanf(buffer, "%E", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_ebig_4) {
  char buffer[] = "1234.567898";
  double value;
  double value2;
  int result = sscanf(buffer, "%lE", &value);
  int result2 = sscanf(buffer, "%lE", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

START_TEST(sscanf_ebig_5) {
  char buffer[] = "1234.567898";
  long double value;
  long double value2;
  int result = sscanf(buffer, "%LE", &value);
  int result2 = sscanf(buffer, "%LE", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

Suite *test_sscanf_ebig(void) {
  Suite *s = suite_create("s21_sscanf_E");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_ebig_1);
  tcase_add_test(tc, sscanf_ebig_2);
  tcase_add_test(tc, sscanf_ebig_3);
  tcase_add_test(tc, sscanf_ebig_4);
  tcase_add_test(tc, sscanf_ebig_5);

  suite_add_tcase(s, tc);
  return s;
}