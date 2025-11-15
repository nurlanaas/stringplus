#ifndef SRC_TEST_STRING_H_
#define SRC_TEST_STRING_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memset(void);
Suite *test_strncat(void);
Suite *test_strchr(void);
Suite *test_strncmp(void);
Suite *test_strncpy(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strstr(void);
Suite *test_strtok(void);
Suite *test_strcpy(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_d(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_ebig(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_g(void);
Suite *test_sprintf_gbig(void);
Suite *test_sprintf_x(void);
Suite *test_sprintf_xbig(void);
Suite *test_sprintf_o(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_p(void);
Suite *test_sprintf_s(void);
Suite *test_sprintf_u(void);
Suite *test_sscanf_c(void);
Suite *test_sscanf_d(void);
Suite *test_sscanf_e(void);
Suite *test_sscanf_ebig(void);
Suite *test_sscanf_f(void);
Suite *test_sscanf_g(void);
Suite *test_sscanf_gbig(void);
Suite *test_sscanf_o(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_p(void);
Suite *test_sscanf_s(void);
Suite *test_sscanf_i(void);
Suite *test_sscanf_u(void);
Suite *test_sscanf_x(void);
Suite *test_bonus(void);

#endif  // SRC_TEST_STRING_H_