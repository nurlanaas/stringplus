#include "test_string.h"

START_TEST(sscanf_o_1) {
  char buffer[] = "12345";
  int value;
  int value2;
  int result = sscanf(buffer, "%o", &value);
  int result2 = s21_sscanf(buffer, "%o", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_o_2) {
  char buffer[] = "-12345";
  int value;
  int value2;
  int result = sscanf(buffer, "%o", &value);
  int result2 = s21_sscanf(buffer, "%o", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_o_3) {
  char buffer[] = "012345";
  int value = 0;
  int value2 = 0;
  int result2 = s21_sscanf(buffer, "%o", &value2);
  int result = sscanf(buffer, "%o", &value);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_o_4) {
  char buffer[] = "  123\t.4\n56";
  int value;
  int value2;
  int result = sscanf(buffer, "%o", &value);
  int result2 = s21_sscanf(buffer, "%o", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

Suite *test_sscanf_o(void) {
  Suite *s = suite_create("s21_sscanf_o");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_o_1);
  tcase_add_test(tc, sscanf_o_2);
  tcase_add_test(tc, sscanf_o_3);
  tcase_add_test(tc, sscanf_o_4);

  suite_add_tcase(s, tc);
  return s;
}