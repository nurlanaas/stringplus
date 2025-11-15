#include "test_string.h"

START_TEST(sscanf_x_1) {
  char buffer[] = "1234";
  int value;
  int value2;
  int result = sscanf(buffer, "%x", &value);
  int result2 = s21_sscanf(buffer, "%x", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_x_2) {
  char buffer[] = "-1234";
  int value;
  int value2;
  int result = sscanf(buffer, "%x", &value);
  int result2 = s21_sscanf(buffer, "%x", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_x_3) {
  char buffer[] = "0x12ab";
  int value;
  int value2;
  int result = sscanf(buffer, "%x", &value);
  int result2 = s21_sscanf(buffer, "%x", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_x_4) {
  char buffer[] = " 0X12AB\t";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%X", &value);
  int result2 = s21_sscanf(buffer, "%X", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

Suite *test_sscanf_x(void) {
  Suite *s = suite_create("s21_sscanf_x");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_x_1);
  tcase_add_test(tc, sscanf_x_2);
  tcase_add_test(tc, sscanf_x_3);
  tcase_add_test(tc, sscanf_x_4);

  suite_add_tcase(s, tc);
  return s;
}
