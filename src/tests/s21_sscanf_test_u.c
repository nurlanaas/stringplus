#include "test_string.h"

START_TEST(sscanf_u_1) {
  char buffer[] = "1234";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%u", &value);
  int result2 = s21_sscanf(buffer, "%u", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_u_2) {
  char buffer[] = "0123";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%u", &value);
  int result2 = s21_sscanf(buffer, "%u", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_u_3) {
  char buffer[] = "\t0xa\tbcd";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%u", &value);
  int result2 = s21_sscanf(buffer, "%u", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_u_4) {
  char buffer[] = "+123";
  long unsigned int value;
  long unsigned int value2;
  int result = sscanf(buffer, "%lu", &value);
  int result2 = s21_sscanf(buffer, "%lu", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_u_5) {
  char buffer[] = "-1";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%u", &value);
  int result2 = s21_sscanf(buffer, "%u", &value2);
  ck_assert_uint_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

Suite *test_sscanf_u(void) {
  Suite *s = suite_create("s21_sscanf_u");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_u_1);
  tcase_add_test(tc, sscanf_u_2);
  tcase_add_test(tc, sscanf_u_3);
  tcase_add_test(tc, sscanf_u_4);
  tcase_add_test(tc, sscanf_u_5);

  suite_add_tcase(s, tc);
  return s;
}
