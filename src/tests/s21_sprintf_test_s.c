#include "test_string.h"

START_TEST(sprintf_s_1) {
  char str1[1000] = "";
  char str2[1000] = "";
  char *str3 = "Hello %sworld";
  char *val = "Goodbye cruel";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1000];
  char str2[1000];
  char *str3 = "%s Hello %s Hello %s";
  char *val = "Say";
  char *val2 = "to";
  char *val3 = "World";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1000];
  char str2[1000];
  char *str3 = "%s Hello %s Hello %s";
  char *val = "asjdashdjkk";
  char *val2 = "asfjklsdjkl ksd ";
  char *val3 = "as kfjlsd";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%3s Hello %5s Hello %10s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%6.5s Hello %.23s Hello %3.s Hello %.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%-10.5s Hello %-.8s Hello %-7s Hello %-.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_7) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%0s Hello %0.s Hello %0.0s Hello %0s Hello %.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  char *val5 = "Hello WORLD";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%+s Hello %+3.s Hello %5.7s Hello %10s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "abcd";
  char *val4 = "1234576890qwertyuiop";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_9) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%s Hello %3.s Hello %5.7s Hello %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_10) {
  char str1[2000];
  char str2[2000];
  char *str3 = "% s Hello % 3.s Hello % 5.7s Hello % 10s Hello %.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  char *val5 = "Hello WORLD";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_11) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%+s Hello %+3.s Hello %+5.7s Hello %+10s Hello %+.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  char *val5 = "Hello WORLD";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_12) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%#s Hello %#3s Hello %#5.7s Hello %#.7s Oof %#.s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
  char *val5 = "Hello WORLD";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_13) {
  char str1[2000];
  char str2[2000];
  char *str3 = "%*s Hello %-*s Hello %*.*s Hello %.*s";
  char *val = "Hi Hi HI HI Hi hI hI HI";
  char *val2 = "world world world world";
  char *val3 = "1319278457hfX121[]aZ!";
  char *val4 = "1234576890qwertyuiop";
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

Suite *test_sprintf_s(void) {
  Suite *s = suite_create("s21_sprintf_s");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_s_1);
  tcase_add_test(tc, sprintf_s_2);
  tcase_add_test(tc, sprintf_s_3);
  tcase_add_test(tc, sprintf_s_4);
  tcase_add_test(tc, sprintf_s_5);
  tcase_add_test(tc, sprintf_s_6);
  tcase_add_test(tc, sprintf_s_7);
  tcase_add_test(tc, sprintf_s_8);
  tcase_add_test(tc, sprintf_s_9);
  tcase_add_test(tc, sprintf_s_10);
  tcase_add_test(tc, sprintf_s_11);
  tcase_add_test(tc, sprintf_s_12);
  tcase_add_test(tc, sprintf_s_13);
  suite_add_tcase(s, tc);
  return s;
}