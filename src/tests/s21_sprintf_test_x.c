#include "test_string.h"

START_TEST(sprintf_x_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello %x Hello";
  int val = 0x365;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Hello %x Hello %x";
  int val = 0x7a5;
  int val2 = 0x91ba456f;
  int val3 = 0x3456;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Hello %#x Hello %x";
  int val = 0x3456;
  int val2 = 0x987;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Hello %lx Hello %hx Hello %hx";
  long int val = 3089775747373646;
  long val2 = 345030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Hello %5x Hello %10x";
  int val = 3456;
  int val2 = 04564;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Hello %.23x Hello %3.x Hello %.x";
  int val = 3456;
  int val2 = 789;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Hello %-.8x Hello %-7x Hello %-.x";
  int val = 3456;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Hello %0.x Hello %0.0x Hello %0x Hello %.x";
  int val = 3456;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0456;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Hello %+3.x Hello %+5.7x Hello %+10x";
  int val = 3456;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_10) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Hello %3.x Hello %5.7x Hello %10x %#x %-x %+x %.x % .x";
  int val = 255;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_11) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Hello % 3.x Hello % 5.7x Hello % 10x Hello %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 98765;
  int val4 = 12345;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Hello %+3.x Hello %+5.7x Hello %+10x Hello %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 98765;
  int val4 = 12345;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Hello %#3x Hello %#5.7x Hello %#.7x Hello %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 98765;
  int val4 = 12345;
  int val5 = 9876;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Hello %06x Hello %05.7x Hello %0.7x Hello %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 98765;
  int val4 = 12345;
  int val5 = 9876;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Hello %-*x Hello %*.*x Hello %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 12345;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_16) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Hello %- 15x Hello %- 15x Hello %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_17) {
  char str1[200];
  char str2[200];
  char *str3 = "Hello %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_x(void) {
  Suite *s = suite_create("s21_sprintf_x");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_x_1);
  tcase_add_test(tc, sprintf_x_2);
  tcase_add_test(tc, sprintf_x_3);
  tcase_add_test(tc, sprintf_x_4);
  tcase_add_test(tc, sprintf_x_5);
  tcase_add_test(tc, sprintf_x_6);
  tcase_add_test(tc, sprintf_x_7);
  tcase_add_test(tc, sprintf_x_8);
  tcase_add_test(tc, sprintf_x_9);
  tcase_add_test(tc, sprintf_x_10);
  tcase_add_test(tc, sprintf_x_11);
  tcase_add_test(tc, sprintf_x_12);
  tcase_add_test(tc, sprintf_x_13);
  tcase_add_test(tc, sprintf_x_14);
  tcase_add_test(tc, sprintf_x_15);
  tcase_add_test(tc, sprintf_x_16);
  tcase_add_test(tc, sprintf_x_17);

  suite_add_tcase(s, tc);
  return s;
}
