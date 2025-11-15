#include "test_string.h"

START_TEST(sprintf_u_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello %u World";
  unsigned int val = 123;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Hello %u Hello %u";
  unsigned int val = 123;
  unsigned int val2 = 045;
  unsigned int val3 = 01234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Hello %u Hello %u";
  unsigned int val = 3456;
  unsigned int val2 = 789;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Hello %lu Hello %hu Hello %hu";
  long unsigned int val = 1234565747376789;
  long unsigned val2 = 32130030123;
  unsigned short val3 = 12345;
  unsigned short val4 = 123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Hello %5u Hello %10u";
  unsigned int val = 3456;
  unsigned int val2 = 12334;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Hello %.23u Hello %3.u Hello %.u";
  unsigned int val = 3456;
  unsigned int val2 = 789;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Hello %-.8u Hello %-7u Hello %-.u";
  unsigned int val = 3456;
  unsigned int val2 = 789;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Hello %0.u Hello %0.0u Hello %0u Hello %.u";
  unsigned int val = 3456;
  unsigned int val2 = 789;
  unsigned int val3 = 99;
  unsigned int val4 = 2897;
  unsigned int val5 = 1234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Hello %+3.u Hello %+5.7u Hello %+10u";
  unsigned int val = 3456;
  unsigned int val2 = 789;
  unsigned int val3 = 99;
  unsigned int val4 = 2897;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_10) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Hello %3.u Hello %5.7u Hello %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_11) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Hello % 3.u Hello % 5.7u Hello % 10u Hello %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 98765;
  unsigned int val4 = 54321;
  unsigned int val5 = 12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Hello %+3.u Hello %+5.7u Hello %+10u Hello %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 98765;
  unsigned int val4 = 54321;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Hello %#3u Hello %#5.7u Hello %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 98765;
  unsigned int val4 = 54321;
  unsigned int val5 = 9876;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Hello %06u Hello %05.7u Hello %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 98765;
  unsigned int val4 = 54321;
  unsigned int val5 = 9876;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Hello %-*u Hello %*.*u Hello %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 54321;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_16) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_17) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Hello %- 15u Hello %- 15u Hello %- u";
  unsigned int val = -4321;
  unsigned int val2 = -4321;
  unsigned int val3 = 4321;
  unsigned int val4 = 4321;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_u(void) {
  Suite *s = suite_create("s21_sprintf_u");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_u_1);
  tcase_add_test(tc, sprintf_u_2);
  tcase_add_test(tc, sprintf_u_3);
  tcase_add_test(tc, sprintf_u_4);
  tcase_add_test(tc, sprintf_u_5);
  tcase_add_test(tc, sprintf_u_6);
  tcase_add_test(tc, sprintf_u_7);
  tcase_add_test(tc, sprintf_u_8);
  tcase_add_test(tc, sprintf_u_9);
  tcase_add_test(tc, sprintf_u_10);
  tcase_add_test(tc, sprintf_u_11);
  tcase_add_test(tc, sprintf_u_12);
  tcase_add_test(tc, sprintf_u_13);
  tcase_add_test(tc, sprintf_u_14);
  tcase_add_test(tc, sprintf_u_15);
  tcase_add_test(tc, sprintf_u_16);
  tcase_add_test(tc, sprintf_u_17);

  suite_add_tcase(s, tc);
  return s;
}
