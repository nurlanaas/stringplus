#include "test_string.h"

START_TEST(sscanf_i_1) {
  char buffer[] = "1234";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%i", &value);
  int result2 = s21_sscanf(buffer, "%i", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_i_2) {
  char buffer[] = "0123";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%i", &value);
  int result2 = s21_sscanf(buffer, "%i", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_i_3) {
  char buffer[] = "0xabcd";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%i", &value);
  int result2 = s21_sscanf(buffer, "%i", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_i_4) {
  char buffer[] = "\t   12\t  3";
  long unsigned int value;
  long unsigned int value2;
  int result = sscanf(buffer, "%li", &value);
  int result2 = s21_sscanf(buffer, "%li", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_i_5) {
  char buffer[] = "-1";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%i", &value);
  int result2 = s21_sscanf(buffer, "%i", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

Suite *test_sscanf_i(void) {
  Suite *s = suite_create("s21_sscanf_i");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_i_1);
  tcase_add_test(tc, sscanf_i_2);
  tcase_add_test(tc, sscanf_i_3);
  tcase_add_test(tc, sscanf_i_4);
  tcase_add_test(tc, sscanf_i_5);

  suite_add_tcase(s, tc);
  return s;
}
