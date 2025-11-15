#include "test_string.h"

START_TEST(sscanf_e_1) {
  char buffer[] = "-1.234e+05";
  float value;
  float value2;
  int result = sscanf(buffer, "%9e", &value);
  int result2 = s21_sscanf(buffer, "%9e", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_e_2) {
  char buffer[] = "1.e-05";
  float value;
  float value2;
  int result = sscanf(buffer, "%5e", &value);
  int result2 = s21_sscanf(buffer, "%5e", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_e_3) {
  char buffer[] = "-1.234e+05";
  float value;
  float value2;
  int result = sscanf(buffer, "%e", &value);
  int result2 = s21_sscanf(buffer, "%e", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq(value, value2);
}
END_TEST

START_TEST(sscanf_e_4) {
  char buffer[] = "1234.567898";
  double value;
  double value2;
  int result = sscanf(buffer, "%le", &value);
  int result2 = sscanf(buffer, "%le", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

START_TEST(sscanf_e_5) {
  char buffer[] = "+1234.567898";
  long double value;
  long double value2;
  int result = sscanf(buffer, "%30Le", &value);
  int result2 = sscanf(buffer, "%30Le", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_double_eq(value, value2);
}
END_TEST

Suite *test_sscanf_e(void) {
  Suite *s = suite_create("s21_sscanf_e");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_e_1);
  tcase_add_test(tc, sscanf_e_2);
  tcase_add_test(tc, sscanf_e_3);
  tcase_add_test(tc, sscanf_e_4);
  tcase_add_test(tc, sscanf_e_5);

  suite_add_tcase(s, tc);
  return s;
}