#include "test_string.h"

START_TEST(sscanf_s_1) {
  char buffer[] = "sdgssdfg%%djglsj123213!%&$*@&$!";
  char value[200];
  char value2[200];
  int result = sscanf(buffer, "%s", value);
  int result2 = s21_sscanf(buffer, "%s", value2);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq(value, value2);
}
END_TEST

START_TEST(sscanf_s_2) {
  char buffer[] = "1%%1.5456ABF";
  char value[200];
  char value2[200];
  int result = sscanf(buffer, "%s", value);
  int result2 = s21_sscanf(buffer, "%s", value2);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq(value, value2);
}
END_TEST

START_TEST(sscanf_s_3) {
  char buffer[] =
      "1238skdjfhlgasdiugasudgasdfuuiu43h25nn%%23985.63452all_eyes_on_me(2Pac)";
  char value[200];
  char value2[200];
  int result = sscanf(buffer, "%s", value);
  int result2 = s21_sscanf(buffer, "%s", value2);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq((char *)value, (char *)value2);
}
END_TEST

START_TEST(sscanf_s_4) {
  char buffer[] = "\t sd;lfgjlhsdfgklsdhgkhshk1h2h21h///1";
  char value[200];
  char value2[200];
  int result = sscanf(buffer, "%s", value);
  int result2 = s21_sscanf(buffer, "%s", value2);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq((char *)value, (char *)value2);
}
END_TEST

START_TEST(sscanf_s_5) {
  char buffer[] = "Hello world!";
  char value[200];
  char value2[200];
  int result = sscanf(buffer, "%s", value);
  int result2 = s21_sscanf(buffer, "%s", value2);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq((char *)value, (char *)value2);
}
END_TEST

Suite *test_sscanf_s(void) {
  Suite *s = suite_create("s21_sscanf_s");
  TCase *tc = tcase_create("sscanf_tc");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, sscanf_s_1);
  tcase_add_test(tc, sscanf_s_2);
  tcase_add_test(tc, sscanf_s_3);
  tcase_add_test(tc, sscanf_s_4);
  tcase_add_test(tc, sscanf_s_5);

  suite_add_tcase(s, tc);
  return s;
}
