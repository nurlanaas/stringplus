#include "test_string.h"

START_TEST(sscanf_n_1) {
  int n1 = 0, n2 = 0;
  int a, b;
  const char str[20] = "gg1\n   2";

  int res1 = s21_sscanf(str, "gg%d  %n", &a, &n1);
  int res2 = sscanf(str, "gg%d %n", &b, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_2) {
  int a1 = 0, a2 = 0;
  int b1 = 0, b2 = 0;
  int c1 = 0, c2 = 0;
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  const char str[1024] = "dd12 334 2 56 57";
  const char str1[1024] = "ff%i %i %n %i %i";

  int res1 = s21_sscanf(str, str1, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, str1, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n_3) {
  int n1 = 1, n2 = 5;

  char s1[1024] = {0};
  char s2[1024] = {0};
  char s3[1024] = {0};
  char s5[1024] = {0};
  char s6[1024] = {0};
  char s7[1024] = {0};

  const char str[] = "Hello world Goodbye World Hello again 12345";
  const char str1[] = "%s %s %n %s";

  int res1 = s21_sscanf(str, str1, s1, s2, &n1, s3);
  int res2 = sscanf(str, str1, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_n_4) {
  int n1 = 0, n2 = 5;

  const char str[1024] = "12 34 56 78";
  const char str1[1024] = "%n";

  int res1 = s21_sscanf(str, str1, &n1);
  int res2 = sscanf(str, str1, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_5) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "12 34 56 78 90 1";
  const char str1[] = "%d %d %n %d %d";

  int res1 = s21_sscanf(str, str1, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, str1, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n_6) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "12 34 56 78 90";
  const char str1[] = "%d %d %n %d %d";

  int res1 = s21_sscanf(str, str1, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, str1, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *test_sscanf_n(void) {
  Suite *s = suite_create("s21_sscanf_n");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_n_1);
  tcase_add_test(tc, sscanf_n_2);
  tcase_add_test(tc, sscanf_n_3);
  tcase_add_test(tc, sscanf_n_4);
  tcase_add_test(tc, sscanf_n_5);
  tcase_add_test(tc, sscanf_n_6);

  suite_add_tcase(s, tc);
  return s;
}