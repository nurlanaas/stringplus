#include "test_string.h"

int main(void) {
  int failed = 0;

  Suite *s21_string_test[] = {test_memchr(),          test_memcmp(),
                              test_memcpy(),          test_memset(),
                              test_strncat(),         test_strchr(),
                              test_strncmp(),         test_strncpy(),
                              test_strerror(),        test_strcspn(),
                              test_strlen(),          test_strpbrk(),
                              test_strrchr(),         test_strstr(),
                              test_strtok(),          test_strcpy(),
                              test_sprintf_c(),       test_sprintf_d(),
                              test_sprintf_e(),       test_sprintf_ebig(),
                              test_sprintf_f(),       test_sprintf_g(),
                              test_sprintf_gbig(),    test_sprintf_x(),
                              test_sprintf_xbig(),    test_sprintf_o(),
                              test_sprintf_percent(), test_sprintf_p(),
                              test_sprintf_s(),       test_sprintf_u(),
                              test_sscanf_c(),        test_sscanf_d(),
                              test_sscanf_e(),        test_sscanf_ebig(),
                              test_sscanf_f(),        test_sscanf_g(),
                              test_sscanf_gbig(),     test_sscanf_n(),
                              test_sscanf_o(),        test_sscanf_p(),
                              test_sscanf_s(),        test_sscanf_i(),
                              test_sscanf_u(),        test_sscanf_x(),
                              test_bonus(),           NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("FAILED: %d\n", failed);
  return failed == 0 ? 0 : 1;
}