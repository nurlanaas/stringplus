#include "test_string.h"

START_TEST(sscanf_f_1) {
  char buffer[] = "-1.23.4e-05";
  float value;
  float value2;
  int result = sscanf(buffer, "%f", &value);
  int result2 = s21_sscanf(buffer, "%f", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_f_2) {
  char buffer[] = "\n .1";
  float value;
  float value2;
  int result = sscanf(buffer, "%f", &value);
  int result2 = s21_sscanf(buffer, "%f", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_f_3) {
  char buffer[] = "1234.567891";
  float value;
  float value2;
  int result = sscanf(buffer, "%f", &value);
  int result2 = s21_sscanf(buffer, "%f", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_f_4) {
  char buffer[] = "1234.567898";
  double value;
  double value2;
  int result = sscanf(buffer, "%lf", &value);
  int result2 = sscanf(buffer, "%lf", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

START_TEST(sscanf_f_5) {
  char buffer[] = "1234.56.78\t9   8";
  long double value;
  long double value2;
  int result = sscanf(buffer, "%Lf", &value);
  int result2 = sscanf(buffer, "%Lf", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

START_TEST(sscanf_f_6) {
  char buffer[] = "\t  123\t4";
  long double value;
  long double value2;
  int result = sscanf(buffer, "%Lf", &value);
  int result2 = sscanf(buffer, "%Lf", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

Suite *test_sscanf_f(void) {
  Suite *s = suite_create("s21_sscanf_f");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_f_1);
  tcase_add_test(tc, sscanf_f_2);
  tcase_add_test(tc, sscanf_f_3);
  tcase_add_test(tc, sscanf_f_4);
  tcase_add_test(tc, sscanf_f_5);
  tcase_add_test(tc, sscanf_f_6);

  suite_add_tcase(s, tc);
  return s;
}