#include "test_string.h"

START_TEST(sprintf_d_1) {
  char str1[100];
  char str2[100];
  char *str3 = "Hello %d Hello";
  int val = 1234;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Hello %d Hello %d";
  int val = 1234;
  int val2 = -12345;
  int val3 = 012345;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Hello %d Hello %d";
  int val = 1234;
  int val2 = 123;
  int val3 = 12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_d_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Hello %ld Hello %hd Hello %hd";
  long int val = 1234567890123456;
  long val2 = 12345678901;
  short int val3 = 32767;
  short val4 = -12345;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Hello %6d Hello %12d";
  int val = -1234;
  int val2 = -12345;
  int val3 = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Hello %.23d Hello %3.d Hello %.d %.6d";
  int val = -1234;
  int val2 = -123;
  int val3 = -12;
  int val4 = -12;
  int val5 = -123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Hello %-.8d Hello %-7d Hello %-.d";
  int val = -1234;
  int val2 = -123;
  int val3 = -12;
  int val4 = -1234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Hello %0.d Hello %0.0d Hello %0d  Hello  %.d";
  int val = -1234;
  int val2 = -123;
  int val3 = -12;
  int val4 = -12345;
  int val5 = -12345;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Hello %+3.d Hello %+5.7d Hello %+10d";
  int val = -12345;
  int val2 = -1234;
  int val3 = -12;
  int val4 = -4321;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Hello %3.d Hello %5.7d Hello %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_11) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Hello % 3.d Hello % 5.7d Hello % 10d  Hello  %.d";
  int val = -12;
  int val2 = -1234;
  int val3 = -123456;
  int val4 = -12345;
  int val5 = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Hello %+3.d Hello %+5.7d Hello %+10d  Hello  %+.d";
  int val = -12;
  int val2 = -1234;
  int val3 = -123456;
  int val4 = -12345;
  int val5 = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d Hello %#3d Hello %#5.7d Hello %#.7d Oof %#.d";
  int val = -12;
  int val2 = -1234;
  int val3 = -123456;
  int val4 = -12345;
  int val5 = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Hello %06d Hello %05.7d Hello %0.7d Oof %0.d";
  int val = -12;
  int val2 = -1234;
  int val3 = -12345;
  int val4 = -12345;
  int val5 = -12;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Hello %-*d Hello %*.*d Hello %.*d";
  int val = 12;
  int val2 = 1234;
  int val3 = -123;
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

START_TEST(sprintf_d_16) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 15;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hello %d %023d", val, val);
  s21_sprintf(str2, "Hello %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_18) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Hello %ld Hello %hd  Hello  %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN + 1;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_19) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test1 %- 15d Test2 %- 15d Test3 %- d";
  int val = -1234;
  int val2 = -1234;
  int val3 = 1234;
  int val4 = 12345;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_d(void) {
  Suite *s = suite_create("s21_sprintf_d");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_d_1);
  tcase_add_test(tc, sprintf_d_2);
  tcase_add_test(tc, sprintf_d_3);
  tcase_add_test(tc, sprintf_d_4);
  tcase_add_test(tc, sprintf_d_5);
  tcase_add_test(tc, sprintf_d_6);
  tcase_add_test(tc, sprintf_d_7);
  tcase_add_test(tc, sprintf_d_8);
  tcase_add_test(tc, sprintf_d_9);
  tcase_add_test(tc, sprintf_d_10);
  tcase_add_test(tc, sprintf_d_11);
  tcase_add_test(tc, sprintf_d_12);
  tcase_add_test(tc, sprintf_d_13);
  tcase_add_test(tc, sprintf_d_14);
  tcase_add_test(tc, sprintf_d_15);
  tcase_add_test(tc, sprintf_d_16);
  tcase_add_test(tc, sprintf_d_17);
  tcase_add_test(tc, sprintf_d_18);
  tcase_add_test(tc, sprintf_d_19);

  suite_add_tcase(s, tc);
  return s;
}