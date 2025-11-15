#include "test_string.h"

START_TEST(sscanf_c_1) {
  char buffer[] = "Hello world 123";
  char value;
  char value2;
  int result = sscanf(buffer, "%c", &value);
  int result2 = s21_sscanf(buffer, "%c", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_c_2) {
  char buffer[] = "12345";
  unsigned int value;
  unsigned int value2;
  int result = sscanf(buffer, "%u", &value);
  int result2 = s21_sscanf(buffer, "%u", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_c_3) {
  char buffer[] = "987";
  short unsigned int value;
  short unsigned int value2;
  int result = sscanf(buffer, "%hu", &value);
  int result2 = s21_sscanf(buffer, "%hu", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_uint_eq(value, value2);
}
END_TEST

START_TEST(sscanf_c_4) {
  char buffer[] = "";
  char value;
  char value2;
  int result = sscanf(buffer, "%c", &value);
  int result2 = s21_sscanf(buffer, "%c", &value2);
  ck_assert_int_eq(result, result2);
}
END_TEST

Suite *test_sscanf_c(void) {
  Suite *s = suite_create("s21_sscanf_c");
  TCase *tc = tcase_create("sscanf_tc");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, sscanf_c_1);
  tcase_add_test(tc, sscanf_c_2);
  tcase_add_test(tc, sscanf_c_3);
  tcase_add_test(tc, sscanf_c_4);

  suite_add_tcase(s, tc);
  return s;
}
