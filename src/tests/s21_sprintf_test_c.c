#include "test_string.h"

START_TEST(sprintf_c_1) {
  char str1[100];
  char str2[100];
  char *str3 = "%lc Test %c Test %c Test %c Test %c";
  wchar_t a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_4) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_c_5) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%010c Test % -10c Test %-c";
//   int a = 65;
//   int b = 66;
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b),
//                    s21_sprintf(str2, str3, a, a, b));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_c_6) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10c Test %-4.10c Test %-0c";
  int a = 10;
  int b = 10;
  int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_7) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10c Test %-4.10c Test %-0c";
  int a = -10;
  int b = 10;
  int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_8) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_9) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_10) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_11) {
  char str1[100];
  char str2[100];  //%lc Test %llc Test %hc Test %hhc
  char *str3 = "%c Test %c Test %c";
  int a = 3;
  int b = 103;
  int e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("s21_sprintf_c");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_c_1);
  tcase_add_test(tc, sprintf_c_2);
  tcase_add_test(tc, sprintf_c_3);
  tcase_add_test(tc, sprintf_c_4);
  // tcase_add_test(tc, sprintf_c_5);
  tcase_add_test(tc, sprintf_c_6);
  tcase_add_test(tc, sprintf_c_7);
  tcase_add_test(tc, sprintf_c_8);
  tcase_add_test(tc, sprintf_c_9);
  tcase_add_test(tc, sprintf_c_10);
  tcase_add_test(tc, sprintf_c_11);

  suite_add_tcase(s, tc);
  return s;
}
