#include "test_string.h"

START_TEST(lower_1) {
  char value1[] = "HELLO WORLD";
  char *check = s21_to_lower(value1);
  ck_assert_str_eq(check, "hello world");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(lower_2) {
  char value1[] = "LOWeR yOuR HEllo WOrlD";
  char *check = s21_to_lower(value1);
  ck_assert_str_eq(check, "lower your hello world");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(lower_3) {
  char value1[] = "HeLL0";
  char *check = s21_to_lower(value1);
  ck_assert_str_eq(check, "hell0");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(lower_4) {
  char value1[] = "HelL.12345O";
  char *check = s21_to_lower(value1);
  ck_assert_str_eq(check, "hell.12345o");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(lower_5) {
  char value1[] = "Hel\0LO";
  char *check = s21_to_lower(value1);
  ck_assert_str_eq(check, "hel");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(upper_1) {
  char value1[] = "hello world";
  char *check = s21_to_upper(value1);
  ck_assert_str_eq(check, "HELLO WORLD");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(upper_2) {
  char value1[] = "uPpeR yOuR heLLO worLD";
  char *check = s21_to_upper(value1);
  ck_assert_str_eq(check, "UPPER YOUR HELLO WORLD");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(upper_3) {
  char value1[] = "helL0";
  char *check = s21_to_upper(value1);
  ck_assert_str_eq(check, "HELL0");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(upper_4) {
  char value1[] = "@!HelL/12345O";
  char *check = s21_to_upper(value1);
  ck_assert_str_eq(check, "@!HELL/12345O");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(upper_5) {
  char value1[] = "hel\0lo";
  char *check = s21_to_upper(value1);
  ck_assert_str_eq(check, "HEL");
  if (check != NULL) free(check);
}
END_TEST

START_TEST(insert_1) {
  char src[] = "hello";
  char str[] = "hello";
  int n = 5;
  char *res = s21_insert(src, str, n);
  ck_assert_str_eq(res, "hellohello");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(insert_2) {
  char src[] = "hello world";
  char str[] = "hello ";
  int n = 6;
  char *res = s21_insert(src, str, n);
  ck_assert_str_eq(res, "hello hello world");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(insert_3) {
  char src[] = "hello";
  char str[] = "12345";
  int n = 3;
  char *res = s21_insert(src, str, n);
  ck_assert_str_eq(res, "hel12345lo");
  if (res != NULL) free(res);
}
END_TEST

START_TEST(trim_1) {
  char src[] = "hello";
  char trim[] = "loeh";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_2) {
  char src[] = "123456789";
  char trim[] = "124789";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "3456");
  free(res);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "";
  char trim[] = "123456789";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_4) {
  char src[] = "helloworld";
  char trim[] = "HELLO WORLD";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "helloworld");
  free(res);
}
END_TEST

START_TEST(trim_5) {
  char src[] = "The quick brown fox jumps over a lazy dog";
  char trim[] = " The quick";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "brown fox jumps over a lazy dog");
  free(res);
}
END_TEST

START_TEST(trim_6) {
  char src[] = "helloworld";
  char trim[] = "";
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "helloworld");
  free(res);
}
END_TEST

START_TEST(bonus_20) {
  char src[] = "helloworld";
  char *trim = S21_NULL;
  char *res = s21_trim(src, trim);
  ck_assert_str_eq(res, "helloworld");
  free(res);
}
END_TEST

Suite *test_bonus(void) {
  Suite *s = suite_create("s21_bonus");
  TCase *tc = tcase_create("bonus_tc");

  tcase_add_test(tc, lower_1);
  tcase_add_test(tc, lower_2);
  tcase_add_test(tc, lower_3);
  tcase_add_test(tc, lower_4);
  tcase_add_test(tc, lower_5);
  tcase_add_test(tc, upper_1);
  tcase_add_test(tc, upper_2);
  tcase_add_test(tc, upper_3);
  tcase_add_test(tc, upper_4);
  tcase_add_test(tc, upper_5);
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, bonus_20);

  suite_add_tcase(s, tc);
  return s;
}