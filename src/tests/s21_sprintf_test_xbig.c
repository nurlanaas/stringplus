#include "test_string.h"

START_TEST(sprintf_xbig_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello %X Hello";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Hello %X Hello %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Hello %X Hello %X";
  int val = 0X4321;
  int val2 = 0X987;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Hello %lX Hello %hX Hello %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Hello %5X Hello %10X";
  int val = 4321;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Hello %.23X Hello %3.X Hello %.X";
  int val = 4321;
  int val2 = 987;
  int val3 = 99;
  int val4 = 35;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Hello %-.8X Hello %-7X Hello %-.X";
  int val = 4321;
  int val2 = 987;
  int val3 = 99;
  int val4 = 4545;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Hello %0.X Hello %0.0X Hello %0X Hello %.X";
  int val = 4321;
  int val2 = 987;
  int val3 = 99;
  int val4 = 4545;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Hello %+3.X Hello %+5.7X Hello %+10X";
  int val = 4321;
  int val2 = 987;
  int val3 = 99;
  int val4 = 4545;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_10) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Hello %3.X Hello %5.7X Hello %10X %#020X %-X %+X %.X % .X";
  int val = 3;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_11) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Hello % 3.X Hello % 5.7X Hello % 10X Hello %.X";
  int val = 32;
  int val2 = 9876;
  int val3 = 98765;
  int val4 = 12341;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Hello %+3.X Hello %+5.7X Hello %+10X Hello %+.X";
  int val = 32;
  int val2 = 9876;
  int val3 = 98765;
  int val4 = 12341;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Hello %#3X Hello %#5.7X Hello %#.7X Hello %#.X";
  int val = 32;
  int val2 = 9876;
  int val3 = 98765;
  int val4 = 12341;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Hello %06X Hello %05.7X Hello %0.7X Hello %0.X";
  int val = 32;
  int val2 = 9876;
  int val3 = 98765;
  int val4 = 12341;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_xbig_15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Hello %-*X Hello %*.*X Hello %.*X";
  int val = 32;
  int val2 = 9876;
  int val3 = 919;
  int val4 = 12341;
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

START_TEST(sprintf_xbig_16) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Hello %- 15X Hello %- 15X Hello %- X";
  int val = -1234;
  int val2 = -1234;
  int val3 = 1234;
  int val4 = 1234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_xbig(void) {
  Suite *s = suite_create("s21_sprintf_x");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_xbig_1);
  tcase_add_test(tc, sprintf_xbig_2);
  tcase_add_test(tc, sprintf_xbig_3);
  tcase_add_test(tc, sprintf_xbig_4);
  tcase_add_test(tc, sprintf_xbig_5);
  tcase_add_test(tc, sprintf_xbig_6);
  tcase_add_test(tc, sprintf_xbig_7);
  tcase_add_test(tc, sprintf_xbig_8);
  tcase_add_test(tc, sprintf_xbig_9);
  tcase_add_test(tc, sprintf_xbig_10);
  tcase_add_test(tc, sprintf_xbig_11);
  tcase_add_test(tc, sprintf_xbig_12);
  tcase_add_test(tc, sprintf_xbig_13);
  tcase_add_test(tc, sprintf_xbig_14);
  tcase_add_test(tc, sprintf_xbig_15);
  tcase_add_test(tc, sprintf_xbig_16);

  suite_add_tcase(s, tc);
  return s;
}