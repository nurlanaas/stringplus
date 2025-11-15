#include "test_string.h"

START_TEST(sscanf_p_1) {
  char buffer[] = "0x0";
  void *value;
  void *value2;
  int result = sscanf(buffer, "%p", &value);
  int result2 = s21_sscanf(buffer, "%p", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_ptr_eq(value, value2);
}
END_TEST

START_TEST(sscanf_p_2) {
  char buffer[] = "\t\t0XABCD\n";
  void *value;
  void *value2;
  int result = sscanf(buffer, "%p", &value);
  int result2 = s21_sscanf(buffer, "%p", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_ptr_eq(value, value2);
}
END_TEST

START_TEST(sscanf_p_3) {
  char buffer[] = "0xabcd";
  void *value;
  void *value2;
  int result = sscanf(buffer, "%p", &value);
  int result2 = s21_sscanf(buffer, "%p", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_ptr_eq(value, value2);
}
END_TEST

Suite *test_sscanf_p(void) {
  Suite *s = suite_create("s21_sscanf_p");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_p_1);
  tcase_add_test(tc, sscanf_p_2);
  tcase_add_test(tc, sscanf_p_3);

  suite_add_tcase(s, tc);
  return s;
}