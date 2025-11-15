#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int res = 0;
  int count = 0;
  int temp = 0;
  int end = 0;
  Flags flags[1000] = {0};
  int i = 0;
  if (*str == '\0') {
    res = -1;
  } else {
    while (*format != '\0' && end == 0) {
      if ((*str == ' ' || *str == '\n' || *str == '\t') &&
          (*format == ' ' || *format == '\n' || *format == '\t')) {
        s21_skip_spaces(&str, &count);
      } else if (*format == *str &&
                 (*format != ' ' && *format != '\n' && *format != '\t')) {
        str++;
        temp++;
      } else if (*format == '%') {
        format++;
        if (*format == '%') end = 1;
        s21_parser_width_sscanf(&format, &flags[i]);
        s21_parser_length(&format, &flags[i]);
        s21_parser_formats_sscanf(format, &args, &str, &res, &count, &temp,
                                  flags[i]);
        i++;
      } else if (*format != ' ' && *format != '\n' && *format != '\t') {
        end = 1;
      }
      format++;
    }
  }
  va_end(args);
  return res;
}

void s21_skip_spaces(const char **str, int *count) {
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *count += 1;
  }
}

void s21_parser_width_sscanf(const char **format, Flags *flags) {
  if (**format == '*') {
    flags->star = 1;
    *format += 1;
  }
  flags->width = 5000;
  char str[30];
  int i = 0;
  while (48 <= **format && **format <= 57) {
    str[i] = **format;
    *format += 1;
    i++;
  }
  str[i] = '\0';
  if (i > 0) flags->width = s21_atoi(str);
}

long int s21_atoi_sscanf(const char **str, int num_system, int sign, int *temp,
                         s21_size_t *case_width, Flags flags, int *increase) {
  long int res = 0;
  while (num_system == 10 && 48 <= **str && **str <= 57 &&
         *case_width < flags.width) {
    res = res * num_system + (**str - '0');
    *str += 1;
    *case_width += 1;
    *temp += 1;
    *increase = 1;
  }
  while (num_system == 16 &&
         ((48 <= **str && **str <= 57) || (97 <= **str && **str <= 102) ||
          (65 <= **str && **str <= 70)) &&
         *case_width < flags.width) {
    if (48 <= **str && **str <= 57) res = res * num_system + (**str - '0');
    if (97 <= **str && **str <= 102)
      res = res * num_system + (**str - 'a' + 10);
    if (65 <= **str && **str <= 70) res = res * num_system + (**str - 'A' + 10);
    *str += 1;
    *case_width += 1;
    *temp += 1;
    *increase = 1;
  }
  while (num_system == 8 && 48 <= **str && **str <= 55 &&
         *case_width < flags.width) {
    res = res * num_system + (**str - '0');
    *str += 1;
    *case_width += 1;
    *temp += 1;
    *increase = 1;
  }
  if (sign == 1) res = -res;
  return res;
}

int s21_read_prefix_sign(const char **str, int *sign, int *temp,
                         s21_size_t *case_width, Flags flags, int *increase) {
  int num_system = 10;
  if ((**str == '-' || **str == '+') && *case_width < flags.width) {
    if (**str == '-') *sign = 1;
    *str += 1;
    *case_width += 1;
    *temp += 1;
  }
  if (**str == '0' && *case_width < flags.width) {
    *str += 1;
    *increase = 1;
    *case_width += 1;
    if ((**str == 'x' || **str == 'X') && *case_width < flags.width) {
      num_system = 16;
      *str += 1;
      *case_width += 1;
      *temp += 1;
    } else {
      num_system = 8;
    }
  }
  return num_system;
}

long double s21_float_sscanf(const char **str, int sign, int *temp,
                             s21_size_t *case_width, Flags flags,
                             int *increase) {
  long double value = 0;
  while (48 <= **str && **str <= 57 && *case_width < flags.width) {
    *increase = 1;
    value = value * 10 + (**str - '0');
    *str += 1;
    *case_width += 1;
    *temp += 1;
  }
  int i = 0;
  if (**str == '.' && *case_width < flags.width) {
    *increase = 1;
    *str += 1;
    *case_width += 1;
    *temp += 1;
    while (48 <= **str && **str <= 57 && *case_width < flags.width) {
      i++;
      value = value * 10 + (**str - '0');
      *str += 1;
      *case_width += 1;
      *temp += 1;
    }
    if ((**str == 'e' || **str == 'E') && *case_width < flags.width) {
      *str += 1;
      *case_width += 1;
      *temp += 1;
      s21_processing_sign_e(str, temp, case_width, flags, &i);
    }
    value = value * pow(10, -i);
    if (sign == 1) value = -value;
  }
  return value;
}

void s21_processing_sign_e(const char **str, int *temp, s21_size_t *case_width,
                           Flags flags, int *i) {
  if (**str == '+' && *case_width < flags.width) {
    *str += 1;
    *case_width += 1;
    *temp += 1;
    if (*case_width + 1 < flags.width) {
      *i -= (**str - '0') * 10;
      *str += 1;
      *case_width += 1;
      *temp += 1;
      *i -= (**str - '0');
      *str += 1;
      *case_width += 1;
      *temp += 1;
    } else if (*case_width < flags.width) {
      *i -= (**str - '0');
      *str += 1;
      *case_width += 1;
      *temp += 1;
    }
  } else if (**str == '-' && *case_width < flags.width) {
    *str += 1;
    *case_width += 1;
    *temp += 1;
    if (*case_width + 1 < flags.width) {
      *i += (**str - '0') * 10;
      *str += 1;
      *case_width += 1;
      *temp += 1;
      *i += (**str - '0');
      *str += 1;
      *case_width += 1;
      *temp += 1;
    } else if (*case_width < flags.width) {
      *i += (**str - '0');
      *str += 1;
      *case_width += 1;
      *temp += 1;
    }
  }
}

void s21_sscanf_process_c(va_list *args, const char **str, int *res, int *count,
                          int *temp) {
  char *value = va_arg(*args, char *);
  *value = **str;
  *str += 1;
  *res += 1;
  *temp += 1;
  *count += *temp;
  *temp = 0;
}

void s21_sscanf_process_d(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  s21_size_t case_width = 0;
  int *value;
  short *value_1;
  long int *value_2;
  if (flags.star == 0) {
    if (flags.length_l == 1) value_2 = va_arg(*args, long int *);
    if (flags.length_h == 1) value_1 = va_arg(*args, short *);
    if (flags.length_l == 0 && flags.length_h == 0)
      value = va_arg(*args, int *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if ((48 <= **str && **str <= 57) == 1 || **str == '-' || **str == '+') {
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    long int copy =
        s21_atoi_sscanf(str, 10, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_l == 1) *value_2 = copy;
      if (flags.length_h == 1) *value_1 = (short)copy;
      if (flags.length_l == 0 && flags.length_h == 0) *value = (int)copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_i(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  s21_size_t case_width = 0;
  int *value;
  short *value_1;
  long int *value_2;
  if (flags.star == 0) {
    if (flags.length_l == 1) value_2 = va_arg(*args, long int *);
    if (flags.length_h == 1) value_1 = va_arg(*args, short *);
    if (flags.length_l == 0 && flags.length_h == 0)
      value = va_arg(*args, int *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  // первый символ всегда цифра так как 16, 8 числа
  // начинаются с префикса 0, 0x
  if ((48 <= **str && **str <= 57) == 1 || **str == '-' || **str == '+') {
    int sign = 0;
    int increase = 0;
    int num_system =
        s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    long int copy = s21_atoi_sscanf(str, num_system, sign, temp, &case_width,
                                    flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_l == 1) *value_2 = copy;
      if (flags.length_h == 1) *value_1 = (short)copy;
      if (flags.length_l == 0 && flags.length_h == 0) *value = (int)copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_float(va_list *args, const char **str, int *res,
                              int *count, int *temp, Flags flags) {
  float *value;
  long double *value_1;
  s21_size_t case_width = 0;
  if (flags.star == 0) {
    if (flags.length_L == 0) value = va_arg(*args, float *);
    if (flags.length_L == 1) value_1 = va_arg(*args, long double *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if ((48 <= **str && **str <= 57) == 1 || **str == '-' || **str == '+' ||
      **str == '.') {
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    long double copy =
        s21_float_sscanf(str, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_L == 0) *value = (float)copy;
      if (flags.length_L == 1) *value_1 = copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_s(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  s21_size_t case_width = 0;
  char *value;
  if (flags.star == 0) value = va_arg(*args, char *);
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  for (; **str != '\0' && **str != ' ' && case_width < flags.width; (*str)++) {
    *temp += 1;
    case_width++;
    if (flags.star == 0) {
      *value = **str;
      value += 1;
    }
  }
  if (flags.star == 0) {
    *value = '\0';
    *res += 1;
  }
  *count += *temp;
  *temp = 0;
}

void s21_sscanf_process_u(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  unsigned int *value;
  unsigned short *value_1;
  unsigned long int *value_2;
  s21_size_t case_width = 0;
  if (flags.star == 0) {
    if (flags.length_l == 1) value_2 = va_arg(*args, unsigned long int *);
    if (flags.length_h == 1) value_1 = va_arg(*args, unsigned short *);
    if (flags.length_l == 0 && flags.length_h == 0)
      value = va_arg(*args, unsigned int *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if ((48 <= **str && **str <= 57) || **str == '-' ||
      **str == '+') {  // проверка что символ подходящий
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    unsigned long int copy =
        s21_atoi_sscanf(str, 10, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_l == 1) *value_2 = copy;
      if (flags.length_h == 1) *value_1 = (unsigned short)copy;
      if (flags.length_l == 0 && flags.length_h == 0)
        *value = (unsigned int)copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_o(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  unsigned int *value;
  unsigned short *value_1;
  unsigned long int *value_2;
  s21_size_t case_width = 0;
  if (flags.star == 0) {
    if (flags.length_l == 1) value_2 = va_arg(*args, unsigned long int *);
    if (flags.length_h == 1) value_1 = va_arg(*args, unsigned short *);
    if (flags.length_l == 0 && flags.length_h == 0)
      value = va_arg(*args, unsigned int *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if ((48 <= **str && **str <= 55) || **str == '-' ||
      **str == '+') {  // проверка что символ подходящий
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    unsigned long int copy =
        s21_atoi_sscanf(str, 8, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_l == 1) *value_2 = copy;
      if (flags.length_h == 1) *value_1 = (unsigned short)copy;
      if (flags.length_l == 0 && flags.length_h == 0)
        *value = (unsigned int)copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_x(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  unsigned int *value;
  unsigned short *value_1;
  unsigned long int *value_2;
  s21_size_t case_width = 0;
  if (flags.star == 0) {
    if (flags.length_l == 1) value_2 = va_arg(*args, unsigned long int *);
    if (flags.length_h == 1) value_1 = va_arg(*args, unsigned short *);
    if (flags.length_l == 0 && flags.length_h == 0)
      value = va_arg(*args, unsigned int *);
  }
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if ((48 <= **str && **str <= 57) == 1 || (97 <= **str && **str <= 102) == 1 ||
      (65 <= **str && **str <= 70) == 1 || **str == '-' || **str == '+') {
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    unsigned long int copy =
        s21_atoi_sscanf(str, 16, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      if (flags.length_l == 1) *value_2 = copy;
      if (flags.length_h == 1) *value_1 = (unsigned short)copy;
      if (flags.length_l == 0 && flags.length_h == 0)
        *value = (unsigned int)copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_p(va_list *args, const char **str, int *res, int *count,
                          int *temp, Flags flags) {
  void *value;
  s21_size_t case_width = 0;
  if (flags.star == 0) value = va_arg(*args, void *);
  // *str = s21_to_lower(*str);
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    *str += 1;
    *temp += 1;
  }
  if (**str == '0') {
    int sign = 0;
    int increase = 0;
    s21_read_prefix_sign(str, &sign, temp, &case_width, flags, &increase);
    long int copy;
    copy = s21_atoi_sscanf(str, 16, sign, temp, &case_width, flags, &increase);
    if (flags.star == 0 && increase == 1) {
      *(long int *)value = copy;
      *res += 1;
    }
    *count += *temp;
    *temp = 0;
  }
}

void s21_sscanf_process_n(va_list *args, int *count) {
  int *n = va_arg(*args, int *);
  if (*count != 0) {
    *n = *count;
  }
}

void s21_parser_formats_sscanf(const char *format, va_list *args,
                               const char **str, int *res, int *count,
                               int *temp, Flags flags) {
  switch (*format) {
    case 'c': {
      s21_sscanf_process_c(args, str, res, count, temp);
      break;
    }
    case 'd': {
      s21_sscanf_process_d(args, str, res, count, temp, flags);
      break;
    }
    case 'i': {
      s21_sscanf_process_i(args, str, res, count, temp, flags);
      break;
    }
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G': {
      s21_sscanf_process_float(args, str, res, count, temp, flags);
      break;
    }
    case 's': {
      s21_sscanf_process_s(args, str, res, count, temp, flags);
      break;
    }
    case 'u': {
      s21_sscanf_process_u(args, str, res, count, temp, flags);
      break;
    }
    case 'o': {
      s21_sscanf_process_o(args, str, res, count, temp, flags);
      break;
    }
    case 'x':
    case 'X': {
      s21_sscanf_process_x(args, str, res, count, temp, flags);
      break;
    }
    case 'p': {
      s21_sscanf_process_p(args, str, res, count, temp, flags);
      break;
    }
    case 'n': {
      s21_sscanf_process_n(args, count);
      break;
    }
  }
}