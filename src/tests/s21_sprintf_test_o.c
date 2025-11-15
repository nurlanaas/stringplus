#include "test_string.h"

START_TEST(sprintf_o_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello %o Hello";
  int val = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Hello %o Hello %o";
  int val = 0123;
  int val2 = 012;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Hello %o Hello %o";
  int val = 4321;
  int val2 = 789;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Hello %lo Hello %ho Hello %ho";
  long int val = 3089675747373656;
  unsigned long int val2 = 34030030403;
  unsigned short int val3 = 23456;
  unsigned short val4 = 123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Hello %5o Hello %10o";
  int val = 4321;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Hello %.23o Hello %3.o Hello %.o";
  int val = 4321;
  int val2 = 789;
  int val3 = 99;
  int val4 = 34;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Hello %-.8o Hello %-7o Hello %-.o";
  int val = 4321;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2323;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Hello %0.o Hello %0.0o Hello %0o Hello %.o";
  int val = 4321;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2323;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Hello %+3.o Hello %+5.7o Hello %+10o";
  int val = 4321;
  int val2 = 789;
  int val3 = 99;
  int val4 = 2323;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_10) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Hello %3.o Hello %5.7o Hello %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_11) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Hello % 3.o Hello % 5.7o Hello % 10o Hello %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Hello %+3.o Hello %+5.7o Hello %+10o Hello %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Hello %#3o Hello %#5.7o Hello %#.7o Hello %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Hello %06o Hello %05.7o Hello %0.7o Hello %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Hello %-*o Hello %*.*o Hello %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
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

START_TEST(sprintf_o_16) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_17) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Hello %- 15o Hello %- 15o Hello %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_18) {
  char str1[200];
  char str2[200];
  char *str3 = "Hello %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_o(void) {
  Suite *s = suite_create("s21_sprintf_o");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_o_1);
  tcase_add_test(tc, sprintf_o_2);
  tcase_add_test(tc, sprintf_o_3);
  tcase_add_test(tc, sprintf_o_4);
  tcase_add_test(tc, sprintf_o_5);
  tcase_add_test(tc, sprintf_o_6);
  tcase_add_test(tc, sprintf_o_7);
  tcase_add_test(tc, sprintf_o_8);
  tcase_add_test(tc, sprintf_o_9);
  tcase_add_test(tc, sprintf_o_10);
  tcase_add_test(tc, sprintf_o_11);
  tcase_add_test(tc, sprintf_o_12);
  tcase_add_test(tc, sprintf_o_13);
  tcase_add_test(tc, sprintf_o_14);
  tcase_add_test(tc, sprintf_o_15);
  tcase_add_test(tc, sprintf_o_16);
  tcase_add_test(tc, sprintf_o_17);
  tcase_add_test(tc, sprintf_o_18);

  suite_add_tcase(s, tc);
  return s;
}
