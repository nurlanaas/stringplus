#include "test_string.h"

START_TEST(sscanf_d_1) {
  char buffer[] = "1 12345";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%*d %d", &value);
  int result2 = s21_sscanf(buffer, "%*d %d", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_2) {
  char buffer[] = "-12345";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%d", &value);
  int result2 = s21_sscanf(buffer, "%d", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_3) {
  char buffer[] = "\t \n   12385898765431";
  long int value = 0;
  long int value2 = 0;
  int result = sscanf(buffer, "%11ld", &value);
  int result2 = s21_sscanf(buffer, "%11ld", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_4) {
  char buffer[] = "123.789";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%d", &value);
  int result2 = s21_sscanf(buffer, "%d", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_5) {
  char buffer[] = "-987";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%X", &value);
  int result2 = s21_sscanf(buffer, "%X", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_6) {
  char buffer[] = "987";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%o", &value);
  int result2 = s21_sscanf(buffer, "%o", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(sscanf_d_7) {
  char buffer[] = "-asfs";
  int value = 0;
  int value2 = 0;
  int result = sscanf(buffer, "%X", &value);
  int result2 = s21_sscanf(buffer, "%X", &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

Suite *test_sscanf_d(void) {
  Suite *s = suite_create("s21_sscanf_d");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_d_1);
  tcase_add_test(tc, sscanf_d_2);
  tcase_add_test(tc, sscanf_d_3);
  tcase_add_test(tc, sscanf_d_4);
  tcase_add_test(tc, sscanf_d_5);
  tcase_add_test(tc, sscanf_d_6);
  tcase_add_test(tc, sscanf_d_7);

  suite_add_tcase(s, tc);
  return s;
}
