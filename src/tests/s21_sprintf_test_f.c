#include "test_string.h"

START_TEST(sprintf_f_1) {
  char str1[200];
  char str2[200];
  char *str3 = "%f Hello%.f Hello%4f Hello%4.f Hello%5.10f!";
  double num = 12.345678936;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[200];
  char str2[200];
  char *str3 = "%f Hello%.f Hello%3f Hello%4.f Hello%5.10f!";
  double num = -12.345678936;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[400];
  char str2[400];
  char *str3 = "%g\n%G!";
  double num_long = -0.107756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %5f\nhello: %6.1f\nhello: %8.2f!";
  double num = 12.345678;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_7) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %10.5f\nhello: %12.4f!";
  double num = 12.345678;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_8) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %15.1f\nhello: %16.2f\nhello: %20.3f!";
  double num = -9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %10.4f\nhello: %25.5f!";
  double num = -9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_10) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+15.f\nhello: %+#16.f\nhello: %+#20.0f!";
  double num = 9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_11) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+ 20.0f\nhello: %+10.f\nhello: %+25.f!";
  double num = 9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_12) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %-26.1f\nhello: %-20.0f\nhello: %#-10.f!";
  double num = 9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_13) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %-#15.f\nhello: %-+25.f!";
  double num = 9876543210.123456;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_14) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %-15.4f!\nhello: %-26.1f!\nhello: %-20.0f!";
  double num = -123456.7891234567;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_15) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %#-10.9f!\nhello: %-+25.15f!";
  double num = -123456.7891234567;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %15.13f!\nhello: %26.15f!";
  double num = -123456.78912345673789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_17) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %20.7f!\nhello: %10.15f!\nhello: %25.15f!";
  double num = -123456.78912345673789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_18) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %15.13f!\nhello: %26.15f!";
  double num = 123456.78912345673789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_19) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %20.7f!\nhello: %10.15f!";
  double num = 123456.78912345673789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_20) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %- 24.14f!\nhello: %+ 25.15f!";
  double num = 123456.78912345673789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_21) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: % 15f!\nhello: % -27f!\nhello: %- 18f!";
  double num = -123456.78;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_22) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+- 14f!\nhello: %+ 10f!\nhello: % +25f!";
  double num = -123456.78;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_23) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: % 14f!\nhello: % -27f!\nhello: %- 19f!";
  double num = 123456.78;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_24) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+- 16f!\nhello: %+ 44f!\nhello: % +35f!";
  double num = 123456.78;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_30) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %021f!\nhello: %-021f!\nhello: %+025f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_31) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %-+ 025.5f!\nhello: %- 021.4f\nhello: %+ 016.6f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_32) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %015f!\nhello: %-027f!\nhello: %+018f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_33) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+- 010.2f!\nhello: %- 025.7f\nhello: %+- 20.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_34) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: % 15.1Lf!\nhello: % -26.15Lf!\nhello: %- 30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_35) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+ 51.15Lf!\nhello: % +45.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_36) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: % 15.1Lf!\nhello: % -26.13Lf!\nhello: %- 30.8Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_37) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+ 51.14Lf!\nhello: % +45.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_38) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %.1Lf!\nhello: %.2Lf!\nhello: %.3Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_39) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %.10Lf!\nhello: %.6Lf!\nhello: %.Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_40) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %.1Lf!\nhello: %.2Lf!\nhello: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_41) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %.6Lf!\nhello: %.Lf\nhello: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_44) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %.1Lf!\nhello: %.2Lf!\nhello: %.3Lf!";
  long double num = -236312853.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_45) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %+ 0Lf!\nhello: %.6Lf!\nhello: %.15Lf!";
  long double num = -236312853.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_52) {
  char str1[400];
  char str2[400];
  char *str3 = "hello: %-+.1Lf!\nhello: %- .2Lf!\nhello: %-0.3Lf!";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_53) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.6f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_f(void) {
  Suite *s = suite_create("s21_sprintf_f");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_f_1);
  tcase_add_test(tc, sprintf_f_2);
  tcase_add_test(tc, sprintf_f_5);
  tcase_add_test(tc, sprintf_f_6);
  tcase_add_test(tc, sprintf_f_7);
  tcase_add_test(tc, sprintf_f_8);
  tcase_add_test(tc, sprintf_f_9);
  tcase_add_test(tc, sprintf_f_10);
  tcase_add_test(tc, sprintf_f_11);
  tcase_add_test(tc, sprintf_f_12);
  tcase_add_test(tc, sprintf_f_13);
  tcase_add_test(tc, sprintf_f_14);
  tcase_add_test(tc, sprintf_f_15);
  tcase_add_test(tc, sprintf_f_16);
  tcase_add_test(tc, sprintf_f_17);
  tcase_add_test(tc, sprintf_f_18);
  tcase_add_test(tc, sprintf_f_19);
  tcase_add_test(tc, sprintf_f_20);
  tcase_add_test(tc, sprintf_f_21);
  tcase_add_test(tc, sprintf_f_22);
  tcase_add_test(tc, sprintf_f_23);
  tcase_add_test(tc, sprintf_f_24);
  tcase_add_test(tc, sprintf_f_30);
  tcase_add_test(tc, sprintf_f_31);
  tcase_add_test(tc, sprintf_f_32);
  tcase_add_test(tc, sprintf_f_33);
  tcase_add_test(tc, sprintf_f_34);
  tcase_add_test(tc, sprintf_f_35);
  tcase_add_test(tc, sprintf_f_36);
  tcase_add_test(tc, sprintf_f_37);
  tcase_add_test(tc, sprintf_f_38);
  tcase_add_test(tc, sprintf_f_39);
  tcase_add_test(tc, sprintf_f_40);
  tcase_add_test(tc, sprintf_f_41);
  tcase_add_test(tc, sprintf_f_44);
  tcase_add_test(tc, sprintf_f_45);
  tcase_add_test(tc, sprintf_f_52);
  tcase_add_test(tc, sprintf_f_53);

  suite_add_tcase(s, tc);
  return s;
}