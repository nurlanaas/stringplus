#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

typedef struct Flags {
  int flag_minus;
  int flag_plus;
  int flag_sharp;
  int flag_0;
  int flag_space;
  s21_size_t width;
  int star;  // для ширины sscanf
  int accuracy;
  int length_l;
  int length_h;
  int length_L;

} Flags;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcpy(char *dest, const char *src);

int s21_sprintf(char *str, const char *format, ...);
void s21_parser_formats(const char *format, va_list *args, char **dest,
                        Flags flags);
void s21_itoa(char *buffer, long int value, int num_system, int un_signed,
              int flag_sharp);
void s21_tostring(char *buffer, long long int value, int *i);
void s21_ftoa(long double value, char *buffer, int accuracy, int flag_sharp);
void s21_parser_flags(const char **format, Flags *flags);
void s21_parser_width(const char **format, va_list *args, Flags *flags);
int s21_atoi(char *str);
void s21_parser_accuracy(const char **format, va_list *args, Flags *flags);
void s21_process_width_flags(char *buffer, Flags flags, char **dest, int sign,
                             int num_system);

void s21_accuracy_int(char *buffer, Flags flags, int num_system);
int s21_check_zero(char *buffer);
void s21_accuracy_string(char *buffer, Flags flags);
void s21_parser_length(const char **format, Flags *flags);

void s21_e(double value, char *buffer, int accuracy, char flag, int flag_sharp);
void s21_g(char *buffer);

void s21_to_buffer(long long int int_digit_afterpoint, int accuracy, int *i,
                   char *buffer);
void s21_tostring_double(char *buffer, long double digit_afterpoint, int *i,
                         int accuracy);
void s21_sharp_atoi(int flag_sharp, int num_system, char *buffer, int *i,
                    long int value);

void s21_format_c(va_list *args, char **dest, Flags flags);
void s21_format_d(va_list *args, char **dest, Flags flags);
void s21_format_f(va_list *args, char **dest, Flags flags);
void s21_format_e(va_list *args, char **dest, Flags flags);
void s21_format_E(va_list *args, char **dest, Flags flags);
void s21_format_g(va_list *args, char **dest, Flags flags);
void s21_format_G(va_list *args, char **dest, Flags flags);
void s21_format_p(va_list *args, char **dest, Flags flags);
void s21_format_u(va_list *args, char **dest, Flags flags);
void s21_format_o(va_list *args, char **dest, Flags flags);
void s21_format_X(va_list *args, char **dest, Flags flags);
void s21_format_x(va_list *args, char **dest, Flags flags);
void s21_format_s(va_list *args, char **dest, Flags flags);

int s21_sscanf(const char *str, const char *format, ...);
void s21_parser_formats_sscanf(const char *format, va_list *args,
                               const char **str, int *res, int *count,
                               int *temp, Flags flags);
long int s21_atoi_sscanf(const char **str, int num_system, int sign, int *temp,
                         s21_size_t *case_width, Flags flags, int *increase);
int s21_read_prefix_sign(const char **str, int *sign, int *temp,
                         s21_size_t *case_width, Flags flags, int *increase);
void s21_parser_width_sscanf(const char **format, Flags *flags);
long double s21_float_sscanf(const char **str, int sign, int *temp,
                             s21_size_t *case_width, Flags flags,
                             int *increase);
void s21_processing_sign_e(const char **str, int *temp, s21_size_t *case_width,
                           Flags flags, int *i);

void s21_sscanf_process_d(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_i(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_x(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_o(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_u(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_float(va_list *args, const char **str, int *res,
                              int *count, int *temp, Flags flags);
void s21_sscanf_process_p(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_s(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags);
void s21_sscanf_process_n(va_list *args, int *count);
void s21_sscanf_process_c(va_list *args, const char **str, int *res, int *count,
                          int *temp);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void s21_skip_spaces(const char **str, int *count);
#endif  // S21_STRING_H_