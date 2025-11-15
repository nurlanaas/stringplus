#include "test_string.h"

START_TEST(sprintf_p_1) {
  char str1[100];
  char str2[100];
  char *str3 = "Hello %pworld";
  int val = 0xabcdef;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Hello %p world %p";
  int val = 12;
  int val2 = 1234;
  int val3 = 012345;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Hello %p world %p";
  int val = 3456;
  int val2 = 987;
  int val3 = -1;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_p(void) {
  Suite *s = suite_create("s21_sprintf_p");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_p_1);
  tcase_add_test(tc, sprintf_p_2);
  tcase_add_test(tc, sprintf_p_3);

  suite_add_tcase(s, tc);
  return s;
}
