#include "s21_string.h"
int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *dest = str;
  Flags flags[1000] = {0};
  int i = 0;
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      s21_parser_flags(&format, &flags[i]);
      s21_parser_width(&format, &args, &flags[i]);
      s21_parser_accuracy(&format, &args, &flags[i]);
      s21_parser_length(&format, &flags[i]);
      s21_parser_formats(format, &args, &dest, flags[i]);
      i++;
    } else {
      *dest++ = *format;
    }
    format++;
  }
  *dest = '\0';
  va_end(args);
  return dest - str;
}

void s21_parser_flags(const char **format, Flags *flags) {
  flags->flag_minus = 0;
  flags->flag_plus = 0;
  flags->flag_sharp = 0;
  flags->flag_0 = 0;
  flags->flag_space = 0;
  while ((**format != '-' && **format != '+' && **format != '#' &&
          **format != '0' && **format != ' ') != 1) {
    if (**format == '-') {
      flags->flag_minus = 1;
      *format += 1;
    }
    if (**format == '#') {
      flags->flag_sharp = 1;
      *format += 1;
    }
    if (**format == '+') {
      flags->flag_plus = 1;
      *format += 1;
    }
    if (**format == '0') {
      flags->flag_0 = 1;
      *format += 1;
    }
    if (**format == ' ') {
      flags->flag_space = 1;
      *format += 1;
    }
  }
}

void s21_parser_width(const char **format, va_list *args, Flags *flags) {
  if (**format == '*') {
    flags->width = va_arg(*args, int);
    *format += 1;
  } else {
    flags->width = 0;
    char str[30];
    int i = 0;
    while (48 <= **format && **format <= 57) {
      str[i] = **format;
      *format += 1;
      i++;
    }
    str[i] = '\0';
    flags->width = s21_atoi(str);
  }
}

int s21_atoi(char *str) {
  int res = 0;
  int i = 0;
  while (str[i] != '\0') {
    res = res * 10 + (str[i] - '0');
    i++;
  }
  return res;
}

void s21_parser_accuracy(const char **format, va_list *args, Flags *flags) {
  flags->accuracy = -1;
  if (**format == '.') {
    flags->accuracy = 0;
    *format += 1;
    if (**format == '*') {
      flags->accuracy = va_arg(*args, int);
      *format += 1;
    } else {
      char str[30];
      int i = 0;
      while (48 <= **format && **format <= 57) {
        str[i] = **format;
        *format += 1;
        i++;
      }
      str[i] = '\0';
      flags->accuracy = s21_atoi(str);
    }
  }
}

void s21_parser_length(const char **format, Flags *flags) {
  flags->length_l = 0;
  flags->length_L = 0;
  flags->length_h = 0;
  if (**format == 'l') {
    flags->length_l = 1;
    *format += 1;
  } else if (**format == 'h') {
    flags->length_h = 1;
    *format += 1;
  } else if (**format == 'L') {
    flags->length_L = 1;
    *format += 1;
  }
}

void s21_process_width_flags(char *buffer, Flags flags, char **dest, int sign,
                             int num_system) {
  int minus = 0, plus = 0, sharp = 0;
  if (num_system == 8 && buffer[0] == '0' && buffer[1] != '\0') sharp = 1;
  if (num_system == 16 && buffer[0] == '0' &&
      (buffer[1] == 'x' || buffer[1] == 'X'))
    sharp = 2;
  s21_size_t sum = s21_strlen(buffer) +
                   (flags.flag_plus == 1 && buffer[0] != '-' && sign == 1) +
                   (flags.flag_space == 1 && buffer[0] != '-' &&
                    flags.flag_plus == 0 && sign == 1);
  for (s21_size_t i = sum; i < flags.width && flags.flag_minus == 0; i++) {
    if (flags.flag_0 == 0 || (flags.accuracy != -1 && num_system != 1)) {
      **dest = ' ';
    } else {
      while (sharp != 0) {  // write 0x or 0 or 0X
        **dest = *buffer;
        buffer++;
        sharp--;
        *dest += 1;
      }
      if (*buffer == '-' && minus == 0) {
        **dest = '-';
        *dest += 1;
        minus = 1;
      }
      if (flags.flag_plus == 1 && *buffer != '-' && plus == 0) {
        **dest = '+';
        *dest += 1;
        plus = 1;
      }
      **dest = '0';
    }
    *dest += 1;
  }
  if (flags.flag_plus == 1 && buffer[0] != '-' && sign == 1 &&
      (flags.flag_0 == 0 || sum >= flags.width || flags.flag_minus == 1)) {
    **dest = '+';
    *dest += 1;
  }
  if (flags.flag_space == 1 && buffer[0] != '-' && flags.flag_plus == 0 &&
      sign == 1) {
    **dest = ' ';
    *dest += 1;
  }
  s21_strcpy(*dest, (buffer + minus));
  *dest += s21_strlen(buffer + minus);
  if (sum < flags.width && flags.flag_minus == 1) {
    for (s21_size_t i = sum; i < flags.width; i++) {
      **dest = ' ';
      *dest += 1;
    }
  }
}

void s21_accuracy_int(char *buffer, Flags flags,
                      int num_system) {  // ставит перед числом нули
  int flag = 1;
  int sharp = 0;
  if (num_system == 8 && buffer[0] == '0' && buffer[1] != '\0') sharp = 1;
  if (num_system == 16 && buffer[0] == '0' &&
      (buffer[1] == 'x' || buffer[1] == 'X'))
    sharp = 2;
  if (flags.accuracy == 0) {
    flag = s21_check_zero(buffer);
  }
  if (flag == 1) {
    int len = s21_strlen(buffer);
    char res[1000];
    int i = 0;
    int j = 0;
    if (*buffer == '-') {
      res[i] = '-';
      i++;
      j++;
      len--;
      buffer += 1;
    }
    while (j < sharp) {
      res[i] = *buffer;
      buffer++;
      i++;
      j++;
    }
    if (num_system == 16) len -= sharp;
    while (len < flags.accuracy) {
      res[i] = '0';
      len++;
      i++;
    }
    while (*buffer != '\0') {
      res[i] = *buffer;
      buffer += 1;
      i++;
      j++;
    }
    res[i] = '\0';
    for (; j > 0; j--) buffer--;
    s21_strcpy(buffer, res);
  } else {
    char *res = "\0";
    s21_strcpy(buffer, res);
  }
}

void s21_accuracy_string(char *buffer, Flags flags) {
  if (flags.accuracy != -1) {
    buffer[flags.accuracy] = '\0';
  }
}

int s21_check_zero(char *buffer) {
  int check = 0;
  char *digits = "123456789abcdefABCDEF";
  int flag = 0;
  while (buffer[check] != '\0') {
    for (int i = 0; i < 21; i++) {
      if (buffer[check] == digits[i]) {
        flag = 1;
      }
    }
    check++;
  }
  return flag;
}

void s21_g(char *buffer) {  // функция убирает лишние нули из числа
  int i;
  for (i = 0; buffer[i] != '.' && buffer[i] != '\0'; i++);
  if (buffer[i] == '.') {
    int last_not_zero = i - 1;
    i++;
    char *digits = "123456789";
    while (buffer[i] != 'e' && buffer[i] != 'E' && buffer[i] != '\0') {
      for (int j = 0; j < 10; j++) {
        if (buffer[i] == digits[j]) last_not_zero = i;
      }
      i++;
    }
    for (int m = last_not_zero + 1; buffer[m] != '\0'; m++) {
      buffer[m] = buffer[i];
      i++;
    }
  }
}

void s21_format_c(va_list *args, char **dest, Flags flags) {
  int c = va_arg(*args, int);
  char buffer[2];
  buffer[0] = c;
  buffer[1] = '\0';
  s21_process_width_flags(buffer, flags, dest, 0, 0);
}

void s21_format_d(va_list *args, char **dest, Flags flags) {
  int value;
  long int value_1;
  if (flags.length_l == 0) {
    value = va_arg(*args, int);
  } else {
    value_1 = va_arg(*args, long int);
  }
  char buffer[32];
  if (flags.length_h == 1) {
    s21_itoa(buffer, (short)value, 10, 0, flags.flag_sharp);
  } else if (flags.length_l == 1) {
    s21_itoa(buffer, value_1, 10, 0, flags.flag_sharp);
  } else {
    s21_itoa(buffer, value, 10, 0, flags.flag_sharp);
  }
  s21_accuracy_int(buffer, flags, 0);
  s21_process_width_flags(buffer, flags, dest, 1, 0);
}

void s21_format_f(va_list *args, char **dest, Flags flags) {
  double value;
  long double value_1;
  char buffer[1000];
  int digits = 6;
  if (flags.accuracy != -1) digits = flags.accuracy;
  if (flags.length_L == 0) {
    value = va_arg(*args, double);
    s21_ftoa(value, buffer, digits, flags.flag_sharp);
  } else {
    value_1 = va_arg(*args, long double);
    s21_ftoa(value_1, buffer, digits, flags.flag_sharp);
  }
  s21_process_width_flags(buffer, flags, dest, 1, 1);
}

void s21_format_e(va_list *args, char **dest, Flags flags) {
  double value;
  long double value_1;
  char buffer[1000];
  int digits = 6;
  if (flags.accuracy != -1) digits = flags.accuracy;
  if (flags.length_L == 0) {
    value = va_arg(*args, double);
    s21_e(value, buffer, digits, 'e', flags.flag_sharp);
  } else {
    value_1 = va_arg(*args, long double);
    s21_e(value_1, buffer, digits, 'e', flags.flag_sharp);
  }
  s21_process_width_flags(buffer, flags, dest, 1, 1);
}

void s21_format_E(va_list *args, char **dest, Flags flags) {
  double value;
  long double value_1;
  char buffer[1000];
  int digits = 6;
  if (flags.accuracy != -1) digits = flags.accuracy;
  if (flags.length_L == 0) {
    value = va_arg(*args, double);
    s21_e(value, buffer, digits, 'E', flags.flag_sharp);
  } else {
    value_1 = va_arg(*args, long double);
    s21_e(value_1, buffer, digits, 'E', flags.flag_sharp);
  }
  s21_process_width_flags(buffer, flags, dest, 1, 1);
}

void s21_format_G(va_list *args, char **dest, Flags flags) {
  double value;
  long double value_1;
  int digits = 6;
  if (flags.accuracy != -1) digits = flags.accuracy;
  if (digits == 0) digits = 1;
  int x;
  char buffer_e[1000], buffer_f[1000];
  if (flags.length_L == 0) {
    value = va_arg(*args, double);
    s21_e(value, buffer_e, digits, 'E', flags.flag_sharp);
    s21_size_t len_e = s21_strlen(buffer_e);
    x = s21_atoi(buffer_e + len_e - 2);
    if (buffer_e[len_e - 3] == '-') x = -x;
    if (digits > x && x >= -4) {
      digits -= x + 1;
      s21_ftoa(value, buffer_f, digits, flags.flag_sharp);
      if (flags.flag_sharp == 0)
        s21_g(buffer_f);  // фунция убирает последние нули из числа
      s21_process_width_flags(buffer_f, flags, dest, 1, 1);
    } else {
      digits--;
      s21_e(value, buffer_e, digits, 'E', flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_e);
      s21_process_width_flags(buffer_e, flags, dest, 1, 1);
    }
  } else {
    value_1 = va_arg(*args, long double);
    s21_e(value_1, buffer_e, digits, 'E', flags.flag_sharp);
    s21_size_t len_e = s21_strlen(buffer_e);
    x = s21_atoi(buffer_e + len_e - 2);
    if (buffer_e[len_e - 3] == '-') x = -x;
    if (digits > x && x >= -4) {
      digits -= x + 1;
      s21_ftoa(value_1, buffer_f, digits, flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_f);
      s21_process_width_flags(buffer_f, flags, dest, 1, 1);
    } else {
      digits--;
      s21_e(value_1, buffer_e, digits, 'E', flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_e);
      s21_process_width_flags(buffer_e, flags, dest, 1, 1);
    }
  }
}

void s21_format_g(va_list *args, char **dest, Flags flags) {
  double value;
  long double value_1;
  int digits = 6;
  if (flags.accuracy != -1) digits = flags.accuracy;
  if (digits == 0) digits = 1;
  int x;
  char buffer_e[1000], buffer_f[1000];
  if (flags.length_L == 0) {
    value = va_arg(*args, double);
    s21_e(value, buffer_e, digits, 'e', flags.flag_sharp);
    s21_size_t len_e = s21_strlen(buffer_e);
    x = s21_atoi(buffer_e + len_e - 2);
    if (buffer_e[len_e - 3] == '-') x = -x;
    if (digits > x && x >= -4) {
      digits -= x + 1;
      s21_ftoa(value, buffer_f, digits, flags.flag_sharp);
      if (flags.flag_sharp == 0)
        s21_g(buffer_f);  // фунция убирает последние нули из числа
      s21_process_width_flags(buffer_f, flags, dest, 1, 1);
    } else {
      digits--;
      s21_e(value, buffer_e, digits, 'e', flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_e);
      s21_process_width_flags(buffer_e, flags, dest, 1, 1);
    }
  } else {
    value_1 = va_arg(*args, long double);
    s21_e(value_1, buffer_e, digits, 'e', flags.flag_sharp);
    s21_size_t len_e = s21_strlen(buffer_e);
    x = s21_atoi(buffer_e + len_e - 2);
    if (buffer_e[len_e - 3] == '-') x = -x;
    if (digits > x && x >= -4) {
      digits -= x + 1;
      s21_ftoa(value_1, buffer_f, digits, flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_f);
      s21_process_width_flags(buffer_f, flags, dest, 1, 1);
    } else {
      digits--;
      s21_e(value_1, buffer_e, digits, 'e', flags.flag_sharp);
      if (flags.flag_sharp == 0) s21_g(buffer_e);
      s21_process_width_flags(buffer_e, flags, dest, 1, 1);
    }
  }
}

void s21_format_s(va_list *args, char **dest, Flags flags) {
  char *s = va_arg(*args, char *);
  if (s == S21_NULL) s = "(null)";
  char buffer[10000];
  s21_strcpy(buffer, s);
  s21_accuracy_string(buffer, flags);
  s21_process_width_flags(buffer, flags, dest, 0, 0);
}

void s21_format_u(va_list *args, char **dest, Flags flags) {
  unsigned int value;
  unsigned long int value_1;
  if (flags.length_l == 0) {
    value = va_arg(*args, unsigned int);
  } else {
    value_1 = va_arg(*args, unsigned long int);
  }
  char buffer[32];
  if (flags.length_h == 1) {
    s21_itoa(buffer, (unsigned short)value, 10, 1, flags.flag_sharp);
  } else if (flags.length_l == 1) {
    s21_itoa(buffer, value_1, 10, 1, flags.flag_sharp);
  } else {
    s21_itoa(buffer, value, 10, 1, flags.flag_sharp);
  }
  s21_accuracy_int(buffer, flags, 0);
  s21_process_width_flags(buffer, flags, dest, 0, 0);
}

void s21_format_o(va_list *args, char **dest, Flags flags) {
  unsigned int value;
  unsigned long int value_1;
  if (flags.length_l == 0) {
    value = va_arg(*args, unsigned int);
  } else {
    value_1 = va_arg(*args, unsigned long int);
  }
  char buffer[32];
  if (flags.length_h == 1) {
    s21_itoa(buffer, (unsigned short)value, 8, 1, flags.flag_sharp);
  } else if (flags.length_l == 1) {
    s21_itoa(buffer, value_1, 8, 1, flags.flag_sharp);
  } else {
    s21_itoa(buffer, value, 8, 1, flags.flag_sharp);
  }
  s21_accuracy_int(buffer, flags, 8);
  s21_process_width_flags(buffer, flags, dest, 0, 8);
}

void s21_format_x(va_list *args, char **dest, Flags flags) {
  unsigned int value;
  unsigned long int value_1;
  if (flags.length_l == 0) {
    value = va_arg(*args, unsigned int);
  } else {
    value_1 = va_arg(*args, unsigned long int);
  }
  char buffer[32];
  if (flags.length_h == 1) {
    s21_itoa(buffer, (unsigned short)value, 16, 1, flags.flag_sharp);
  } else if (flags.length_l == 1) {
    s21_itoa(buffer, value_1, 16, 1, flags.flag_sharp);
  } else {
    s21_itoa(buffer, value, 16, 1, flags.flag_sharp);
  }
  s21_accuracy_int(buffer, flags, 16);
  s21_process_width_flags(buffer, flags, dest, 0, 16);
}

void s21_format_X(va_list *args, char **dest, Flags flags) {
  unsigned int value;
  unsigned long int value_1;
  if (flags.length_l == 0) {
    value = va_arg(*args, unsigned int);
  } else {
    value_1 = va_arg(*args, unsigned long int);
  }
  char buffer[32];
  if (flags.length_h == 1) {
    s21_itoa(buffer, (unsigned short)value, 'X', 1, flags.flag_sharp);
  } else if (flags.length_l == 1) {
    s21_itoa(buffer, value_1, 'X', 1, flags.flag_sharp);
  } else {
    s21_itoa(buffer, value, 'X', 1, flags.flag_sharp);
  }
  s21_accuracy_int(buffer, flags, 16);
  s21_process_width_flags(buffer, flags, dest, 0, 16);
}

void s21_format_p(va_list *args, char **dest, Flags flags) {
  long int value = va_arg(*args, long int);
  char buffer[100];
  s21_itoa(buffer, value, 16, 1, 1);
  s21_process_width_flags(buffer, flags, dest, 0, 0);
}

void s21_parser_formats(const char *format, va_list *args, char **dest,
                        Flags flags) {
  switch (*format) {
    case 'c':
      s21_format_c(args, dest, flags);
      break;
    case 'd':
      s21_format_d(args, dest, flags);
      break;
    case 'f':
      s21_format_f(args, dest, flags);
      break;
    case 'e':
      s21_format_e(args, dest, flags);
      break;
    case 'E':
      s21_format_E(args, dest, flags);
      break;
    case 'g':
      s21_format_g(args, dest, flags);
      break;
    case 'G':
      s21_format_G(args, dest, flags);
      break;
    case 's':
      s21_format_s(args, dest, flags);
      break;
    case 'u':
      s21_format_u(args, dest, flags);
      break;
    case 'o':
      s21_format_o(args, dest, flags);
      break;
    case 'x':
      s21_format_x(args, dest, flags);
      break;
    case 'X':
      s21_format_X(args, dest, flags);
      break;
    case 'p':
      s21_format_p(args, dest, flags);
      break;
    case '%':
      **dest = '%';
      *dest += 1;
      break;
  }
}

void s21_e(double value, char *buffer, int accuracy, char flag,
           int flag_sharp) {
  int negative = 0;
  if (value < 0) {
    negative = 1;
    value = -value;
  }
  int e = 0;
  while ((value >= 1. && value < 10.) != 1 && value != 0.0) {
    if (value < 1) {
      value *= 10;
      e++;
    } else {
      value /= 10;
      e--;
    }
  }
  double scale = pow(10, accuracy);
  if (round(value * (scale)) / scale >= 10) {
    value /= 10;
    e--;
  }
  if (negative == 1) value = -value;
  s21_ftoa(value, buffer, accuracy,
           flag_sharp);  // в буфере лежит правильное число
  s21_size_t count = s21_strlen(buffer);
  buffer[count] = flag;
  if (e <= 0) {
    buffer[count + 1] = '+';
    e = -e;
  } else {
    buffer[count + 1] = '-';
  }
  if (e < 10) {
    buffer[count + 2] = '0';
    buffer[count + 3] = e + '0';
    buffer[count + 4] = '\0';
  } else if (e < 100) {
    buffer[count + 2] = e / 10 + '0';
    buffer[count + 3] = (e % 10) + '0';
    buffer[count + 4] = '\0';
  } else if (e <= 308) {
    buffer[count + 2] = e / 100 + '0';
    buffer[count + 3] = ((e / 10) % 10) + '0';
    buffer[count + 4] = (e % 10) + '0';
    buffer[count + 5] = '\0';
  }
}
// записывает дробное число в буфер
void s21_ftoa(long double value, char *buffer, int accuracy, int flag_sharp) {
  int negative = 0;
  if (value < 0) {
    negative = 1;
    value = -value;
  }
  long double scale = pow(10, accuracy);
  long double copy = value;
  copy = round(value * (scale)) / scale;
  int i = 0;
  if (negative == 1) {
    buffer[i] = '-';
    i++;
  }
  s21_tostring(buffer, (long long int)copy, &i);
  if (accuracy > 0) {
    buffer[i] = '.';
    i++;
  }
  double digit_afterpoint =
      value - (long long int)value;  // повторно округляем дробную часть value
                                     // чтобы записать в буфер
  long long int int_digit_afterpoint = digit_afterpoint * pow(10, accuracy + 1);
  int last_afterpoint = int_digit_afterpoint % 10;
  int_digit_afterpoint /= 10;
  if (last_afterpoint >= 5) int_digit_afterpoint += 1;
  if (int_digit_afterpoint / pow(10, accuracy) == 1) {
    int_digit_afterpoint = 0;
  }

  s21_to_buffer(int_digit_afterpoint, accuracy, &i,
                buffer);  // дописываются нули перед числом
  if (int_digit_afterpoint != 0) s21_tostring(buffer, int_digit_afterpoint, &i);
  if (accuracy == 0 && flag_sharp == 1) {
    buffer[i] = '.';
    i++;
  }
  buffer[i] = '\0';
}

void s21_tostring(char *buffer, long long int value, int *i) {
  char *digits = "0123456789";
  char res[1000];
  int j = 0;
  if (value == 0) {
    res[j] = '0';
    j++;
  }
  while (value > 0) {
    res[j] = digits[value % 10];
    value /= 10;
    j++;
  }
  j--;
  for (; j >= 0; j--) {
    buffer[*i] = res[j];
    (*i) += 1;
  }
}

void s21_to_buffer(long long int int_digit_afterpoint, int accuracy, int *i,
                   char *buffer) {
  long long int copy = int_digit_afterpoint;
  int len = 0;
  while (copy > 0) {
    copy /= 10;
    len++;
  }
  for (int j = len; j < accuracy;
       j++) {  // если в дробной части 0 - запишет их в буфер
    buffer[*i] = '0';
    *i += 1;
  }
}
// записывает в буфер число в нужной системе счисления (из 10сс в 16сс)
void s21_itoa(char *buffer, long int value, int num_system, int un_signed,
              int flag_sharp) {
  int i = 0;  // buffer
  s21_sharp_atoi(flag_sharp, num_system, buffer, &i, value);
  const char *digits;
  if ((char)num_system == 'X') {
    digits = "0123456789ABCDEF";
    num_system = 16;
  } else {
    digits = "0123456789abcdef";
  }
  int temp[100];
  int j = 0;  // temp
  if (value < 0) {
    if (num_system == 10 && un_signed == 0) {
      buffer[i] = '-';
      i++;
      value = -value;
      while (value > 0) {
        temp[j] = digits[value % num_system];
        value = value / num_system;
        j++;
      }
    } else {
      unsigned long int temporary = (unsigned long int)value;
      while (temporary > 0) {
        temp[j] = digits[temporary % num_system];
        temporary = temporary / num_system;
        j++;
      }
    }
  } else if (value > 0) {
    while (value > 0) {
      temp[j] = digits[value % num_system];
      value = value / num_system;
      j++;
    }
  } else if (value == 0) {
    temp[j] = '0';
    j++;
  }
  j--;
  while (j >= 0) {
    buffer[i] = temp[j];
    i++;
    j--;
  }
  buffer[i] = '\0';
}

void s21_sharp_atoi(int flag_sharp, int num_system, char *buffer, int *i,
                    long int value) {
  if (flag_sharp == 1 && num_system == 8 && value != 0) {
    buffer[*i] = '0';
    *i += 1;
  }
  if (flag_sharp == 1 && (char)num_system == 'X' && value != 0) {
    buffer[*i] = '0';
    buffer[*i + 1] = 'X';
    *i += 2;
  }
  if (flag_sharp == 1 && num_system == 16 && value != 0) {
    buffer[*i] = '0';
    buffer[*i + 1] = 'x';
    *i += 2;
  }
}