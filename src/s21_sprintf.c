#include "s21_string.h"

char s21_get_flag(const char** fmt) {
  char flag = 0;
  switch (**fmt) {
    case '-':
    case '+':
    case ' ':
    case '#':
    case '0':
      flag = **fmt;
      (*fmt)++;
  }
  return flag;
}

char s21_get_width_star(const char** fmt) {
  char res = 0;
  if (**fmt == '*') {
    (*fmt)++;
    res = '*';
  }
  return res;
}

int s21_get_width(const char** fmt) {
  int width = 0;
  for (; '0' <= **fmt && **fmt <= '9'; (*fmt)++) {
    char c = **fmt;
    width = width * 10 + (c - '0');
  }
  return width;
}

int s21_get_precision(const char** fmt) {
  int precision = 0;
  for (; '0' <= **fmt && **fmt <= '9'; (*fmt)++) {
    char c = **fmt;
    precision = precision * 10 + (c - '0');
  }
  return precision;
}

char s21_get_length(const char** fmt) {
  char length = 0;
  switch (**fmt) {
    case 'h':
    case 'l':
    case 'L':
      length = **fmt;
      (*fmt)++;
  }
  return length;
}

char s21_get_type(const char** fmt) {
  char type = 0;
  switch (**fmt) {
    case 'c':
    case 'd':
    case 'i':
    case 'f':
    case 's':
    case 'x':
    case 'X':
    case 'u':
    case 'n':
    case 'o':
    case 'p':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      type = **fmt;
      (*fmt)++;
  }
  return type;
}

void s21_parse_spec(Spec* spec, const char** fmt) {
  spec->flag = 0;
  spec->width_star = 0;
  spec->width = 0;
  spec->precision = -1;
  spec->precision_star = 0;
  spec->length = 0;
  spec->type = 0;

  spec->flag = s21_get_flag(fmt);
  spec->width_star = s21_get_width_star(fmt);
  if (!spec->width_star) spec->width = s21_get_width(fmt);
  if (**fmt == '.') {
    (*fmt)++;
    if (**fmt == '*') {
      (*fmt)++;
      spec->precision_star = '*';
    } else {
      spec->precision = s21_get_precision(fmt);
    }
  }
  spec->length = s21_get_length(fmt);
  spec->type = s21_get_type(fmt);
  if ((spec->type == 'f' || spec->type == 'e' || spec->type == 'E' ||
       spec->type == 'g' || spec->type == 'G') &&
      spec->precision == -1)
    spec->precision = 6;
}

void s21_revert(char* start, char* end) {
  for (; start < end; start++, end--) {
    char c = *start;
    *start = *end;
    *end = c;
  }
}

void s21_print_symbol(char** str, char c) {
  **str = c;
  (*str)++;
}

void s21_print_number(long i, char** str) {
  if (i < 0) {
    i = -i;
  }
  if (!i) {
    s21_print_symbol(str, '0');
  } else {
    char* start = *str;
    for (; i; i = i / 10) {
      s21_print_symbol(str, (i % 10) + '0');
    }
    s21_revert(start, *str - 1);
  }
}

void s21_print_space_or_zero(int delt, char c, char** str) {
  for (; delt-- > 0; (*str)++) {
    **str = c;
  }
}

void s21_print_with_flag_plus_or_space(long i, int delt, char** str,
                                       Spec* spec) {
  s21_print_space_or_zero(delt, ' ', str);
  if (spec->type != 'u') s21_print_symbol(str, (i < 0 ? '-' : spec->flag));
  s21_print_number(i, str);
}

void s21_print_with_flag_minus(long i, int delt, char** str, Spec* spec) {
  if (i < 0 && spec->type != 'u') s21_print_symbol(str, '-');
  s21_print_number(i, str);
  s21_print_space_or_zero(delt, ' ', str);
}

void s21_print_with_flag_zero(long i, int delt, char** str, Spec* spec,
                              int size) {
  if (i < 0 && spec->type != 'u') s21_print_symbol(str, '-');
  if (spec->precision < size && spec->precision != -1)
    s21_print_space_or_zero(delt, ' ', str);
  else
    s21_print_space_or_zero(delt, spec->flag, str);
  s21_print_number(i, str);
}

void s21_print_int_without_precision(long i, int size, char** str, Spec* spec) {
  int delt = spec->width - size;
  if ((spec->flag == '+' || spec->flag == ' ' || i < 0) && spec->type != 'u')
    delt--;
  if (spec->flag == '+' || spec->flag == ' ') {
    s21_print_with_flag_plus_or_space(i, delt, str, spec);
  } else if (spec->flag == '-') {
    s21_print_with_flag_minus(i, delt, str, spec);
  } else if (spec->flag == '0') {
    s21_print_with_flag_zero(i, delt, str, spec, size);
  } else {
    s21_print_space_or_zero(delt, ' ', str);
    if (i < 0 && spec->type != 'u') s21_print_symbol(str, '-');
    s21_print_number(i, str);
  }
}

void s21_print_int_with_precision(long i, int size, char** str, Spec* spec) {
  int delt = spec->precision - size;
  if ((spec->flag == '+' || spec->flag == ' ' || i < 0) && spec->type != 'u')
    s21_print_symbol(str, (i < 0 ? '-' : spec->flag));
  s21_print_space_or_zero(delt, '0', str);
  s21_print_number(i, str);
}

int s21_int_get_size(long i) {
  int size = 1;
  for (; i /= 10; size++) {
  }
  return size;
}

void s21_print_int(long i, char** str, Spec* spec) {
  int size = s21_int_get_size(i);
  if (size >= spec->precision) {
    s21_print_int_without_precision(i, size, str, spec);
  } else if (spec->precision >= spec->width) {
    s21_print_int_with_precision(i, size, str, spec);
  } else {
    int delt = spec->width - spec->precision;
    if ((spec->flag == '+' || spec->flag == ' ' || i < 0) && spec->type != 'u')
      delt--;
    if (spec->flag == '-') {
      s21_print_int_with_precision(i, size, str, spec);
      s21_print_space_or_zero(delt, ' ', str);
    } else {
      s21_print_space_or_zero(delt, ' ', str);
      s21_print_int_with_precision(i, size, str, spec);
    }
  }
}

void s21_print_char(char** str, const char c, Spec* spec) {
  if (!spec->width) {
    s21_print_symbol(str, c);
  } else {
    if (spec->flag == '-') {
      s21_print_symbol(str, c);
      s21_print_space_or_zero(spec->width - 1, ' ', str);
    } else {
      s21_print_space_or_zero(spec->width - 1, ' ', str);
      s21_print_symbol(str, c);
    }
  }
}

void s21_print_string_to_string(char** str, const char* s) {
  for (; *s; s++, (*str)++) **str = *s;
}

void s21_print_string_precision_zero(char** str, Spec* spec) {
  if (!spec->width) {
  } else {
    s21_print_space_or_zero(spec->width, ' ', str);
  }
}

void s21_print_string_precision_more_string(char** str, int size, const char* s,
                                            Spec* spec) {
  if (spec->width <= size) {
    s21_print_string_to_string(str, s);
  } else {
    if (spec->flag == '-') {
      s21_print_string_to_string(str, s);
      s21_print_space_or_zero(spec->width - size, ' ', str);
    } else {
      s21_print_space_or_zero(spec->width - size, ' ', str);
      s21_print_string_to_string(str, s);
    }
  }
}

void s21_print_string_precision_less_string(char** str, const char* s,
                                            Spec* spec) {
  if (spec->width <= spec->precision) {
    for (; spec->precision--; s++, (*str)++) **str = *s;
  } else {
    if (spec->flag == '-') {
      int temp = spec->precision;
      for (; temp--; s++, (*str)++) **str = *s;
      s21_print_space_or_zero(spec->width - spec->precision, ' ', str);
    } else {
      s21_print_space_or_zero(spec->width - spec->precision, ' ', str);
      for (; spec->precision--; s++, (*str)++) **str = *s;
    }
  }
}

void s21_print_string(char** str, const char* s, Spec* spec) {
  if (!spec->precision) {
    s21_print_string_precision_zero(str, spec);
  } else {
    int size = s21_strlen(s);
    if (spec->precision >= size || spec->precision == -1) {
      s21_print_string_precision_more_string(str, size, s, spec);
    } else if (spec->precision < size && spec->precision != -1) {
      s21_print_string_precision_less_string(str, s, spec);
    }
  }
}

void s21_print_hex_all_less(char** str, const char* prefix, char* start,
                            Spec* spec) {
  switch (spec->flag) {
    case '-':
    case '0':
    case 0:
      s21_print_string_to_string(str, start);
      break;
    case '#':
      s21_print_string_to_string(str, prefix);
      s21_print_string_to_string(str, start);
      break;
  }
}

void s21_print_hex_width_more(char** str, const char* prefix, char* start,
                              Spec* spec, int size, int size_prefix) {
  switch (spec->flag) {
    case '-':
      s21_print_string_to_string(str, start);
      s21_print_space_or_zero(spec->width - size, ' ', str);
      break;
    case '0':
    case 0:
      s21_print_space_or_zero(spec->width - size, ' ', str);
      s21_print_string_to_string(str, start);
      break;
    case '#':
      s21_print_space_or_zero(spec->width - size - size_prefix, ' ', str);
      s21_print_string_to_string(str, prefix);
      s21_print_string_to_string(str, start);
      break;
  }
}

void s21_print_hex_precesion_more(char** str, const char* prefix, char* start,
                                  Spec* spec, int size) {
  switch (spec->flag) {
    case '-':
    case '0':
    case 0:
      s21_print_space_or_zero(spec->precision - size, '0', str);
      s21_print_string_to_string(str, start);
      break;
    case '#': {
      s21_print_string_to_string(str, prefix);
      s21_print_space_or_zero(spec->precision - size, '0', str);
      s21_print_string_to_string(str, start);
    } break;
  }
}

void s21_print_hex_all_more(char** str, const char* prefix, char* start,
                            Spec* spec, int size, int size_prefix) {
  switch (spec->flag) {
    case '-':
      s21_print_space_or_zero(spec->precision - size, '0', str);
      s21_print_string_to_string(str, start);
      s21_print_space_or_zero(spec->width - spec->precision, ' ', str);
      break;
    case '0':
    case 0:
      s21_print_space_or_zero(spec->width - spec->precision, ' ', str);
      s21_print_space_or_zero(spec->precision - size, '0', str);
      s21_print_string_to_string(str, start);
      break;
    case '#':
      s21_print_space_or_zero(spec->width - spec->precision - size_prefix, ' ',
                              str);
      s21_print_string_to_string(str, prefix);
      s21_print_space_or_zero(spec->precision - size, '0', str);
      s21_print_string_to_string(str, start);
      break;
  }
}

void s21_print_hex(unsigned i, char** str, Spec* spec) {
  if (!i) {
    s21_print_symbol(str, '0');
  } else {
    const char* hexTable_x = "0123456789abcdef";
    const char* hexTable_X = "0123456789ABCDEF";
    char buf[100] = {0};
    int size = 0;
    char* start = buf;
    char* end = buf;
    if (spec->type == 'x') {
      for (; i; i = i / 16) {
        *end++ = hexTable_x[(i % 16)];
        size++;
      }
    } else if (spec->type == 'X') {
      for (; i; i = i / 16) {
        *end++ = hexTable_X[(i % 16)];
        size++;
      }
    } else if (spec->type == 'o') {
      for (; i; i = i / 8) {
        *end++ = hexTable_X[(i % 8)];
        size++;
      }
    }
    buf[size + 1] = '\0';
    s21_revert(start, end - 1);

    char* prefix;
    int size_prefix = 0;
    switch (spec->type) {
      case 'x':
        prefix = "0x";
        size_prefix = 2;
        break;
      case 'X':
        prefix = "0X";
        size_prefix = 2;
        break;
      case 'o':
        if (spec->precision > size) {
          prefix = "";
          size_prefix = 0;
        } else {
          prefix = "0";
          size_prefix = 1;
        }
        break;
    }
    if (spec->width <= size && spec->precision <= size) {
      s21_print_hex_all_less(str, prefix, start, spec);
    } else if (spec->width > size && spec->precision <= size) {
      s21_print_hex_width_more(str, prefix, start, spec, size, size_prefix);
    } else if ((spec->width <= size || spec->width <= spec->precision) &&
               spec->precision > size) {
      s21_print_hex_precesion_more(str, prefix, start, spec, size);
    } else {
      s21_print_hex_all_more(str, prefix, start, spec, size, size_prefix);
    }
  }
}

void s21_spec_n(char** str, char** str_start, va_list arg) {
  int* index = va_arg(arg, int*);
  *index = (*str - *str_start);
}

char* widtEnterSymbolInt(char* str, char* symbol, int widthLen) {
  if (widthLen > 0) {
    while (widthLen > 0) {
      s21_strcat(str, symbol);
      widthLen--;
    }
  }
  return str;
}

char* flagToP(char* str, int wid, Spec* spec) {
  char str1[256] = "";
  char* pointer = str;
  int Lenwidth = spec->width - s21_strlen(str);
  if (wid != 0) {
    Lenwidth = wid - s21_strlen(str);
  }
  if (spec->flag == 1) {
    s21_strcat(str1, str);
    if (Lenwidth == 0) Lenwidth -= 1;
    widtEnterSymbolInt(str1, " ", Lenwidth);
    s21_strcpy(pointer, str1);
  } else if (spec->flag == 0) {
    if (Lenwidth == 0) Lenwidth -= 1;
    widtEnterSymbolInt(str1, " ", Lenwidth);
    s21_strcat(str1, str);
    s21_strcpy(pointer, str1);
  }
  return pointer;
}

char* intChar(long long num) {
  static char charNumInvert[256] = "";
  int rankNumber = 0;
  long int number = num;
  if (number < 0) {
    num *= -1;
  }
  while (num > 9) {
    charNumInvert[rankNumber++] = (num % 10) + '0';
    num = num / 10;
  }
  if (number < 0) {
    charNumInvert[rankNumber++] = num + '0';
    charNumInvert[rankNumber++] = '-';
  } else {
    charNumInvert[rankNumber++] = num + '0';
  }
  for (int i = 0; i < rankNumber / 2; i++) {
    char t = charNumInvert[i];
    charNumInvert[i] = charNumInvert[rankNumber - 1 - i];
    charNumInvert[rankNumber - 1 - i] = t;
  }
  charNumInvert[rankNumber] = '\0';
  char* ret = charNumInvert;
  return ret;
}

char convert(long int num) {
  char* d = intChar(num);
  char r = *d;
  if (num == 10) {
    r = 'a';
  } else if (num == 11) {
    r = 'b';
  } else if (num == 12) {
    r = 'c';
  } else if (num == 13) {
    r = 'd';
  } else if (num == 14) {
    r = 'e';
  } else if (num == 15) {
    r = 'f';
  }
  return r;
}

void oChar(char* result, long long number, int sys) {
  int i = 0;
  char resultf[256] = "";
  while (number >= sys) {
    resultf[i] = convert(number % sys);
    i++;
    number = number / sys;
  }
  resultf[i] = convert(number % sys);
  s21_size_t l = s21_strlen(resultf);
  for (int j = 0; j < (int)l; j++) {
    result[j] = resultf[l - 1 - j];
  }
}

void s21_print_pointer(char* str, va_list arg, Spec* spec) {
  int wid = 0;
  if (spec->width == -2) {
    spec->width = va_arg(arg, int);
  }
  void* pointer = (void*)va_arg(arg, int*);
  s21_size_t ptr_int = (s21_size_t)pointer;
  char buf[256] = "";
  char buf1[256] = "";
  s21_strcat(buf1, "0x");
  for (; ptr_int > 0;) {
    int perevod = ptr_int - ((ptr_int / 16) * 16);
    char r[256] = "";
    oChar(&r[0], (long long)perevod, 16);
    s21_strcat(buf, r);
    ptr_int /= 16;
  }
  int j = 0;
  for (int i = s21_strlen(buf) - 1; i >= 0; i--) {
    buf1[j + 2] = buf[i];
    j++;
  }
  char* ptr = buf1;
  s21_strcat(str, flagToP(ptr, wid, spec));
}

long s21_pow(int p) {
  long res = 1;
  for (; p--; res *= 10) {
  }
  return res;
}

void s21_print_double_to_string(long base, long mant, int size_mant, char** str,
                                Spec* spec) {
  s21_print_number(base, str);
  if (spec->precision) {
    s21_print_symbol(str, '.');
    if (mant) {
      if (size_mant < spec->precision)
        s21_print_space_or_zero(spec->precision - size_mant, '0', str);
      s21_print_number(mant, str);

    } else {
      s21_print_space_or_zero(spec->precision, '0', str);
    }
  } else if (spec->flag == '#') {
    s21_print_symbol(str, '.');
  }
}

void s21_print_double(long double f, char** str, Spec* spec) {
  int negative = 0;
  if (f < 0) {
    f = -f;
    negative = -1;
  }
  long base = 0, mant = 0;
  base = (long)f;
  if (spec->precision)
    mant = (long)((f - (int)f) * s21_pow(spec->precision) + 0.5);
  int size_base = s21_int_get_size(base);
  int size_our_double = size_base;
  int size_mant = 0;
  if (mant) {
    size_mant = s21_int_get_size(mant);
    size_our_double += (spec->precision + 1);
  } else {
    if (spec->precision) size_our_double += (spec->precision + 1);
  }
  if (negative || spec->flag == '+' || spec->flag == ' ') size_our_double++;
  if (!spec->precision && spec->flag == '#') size_our_double++;
  if (spec->type == 'e' || spec->type == 'E' || spec->type == 'g' ||
      spec->type == 'G')
    size_our_double += 4;
  if (spec->width <= size_our_double) {
    switch (spec->flag) {
      case '+':
      case ' ':
        if (negative)
          s21_print_symbol(str, '-');
        else
          s21_print_symbol(str, spec->flag);
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        break;
      case '-':
      case '0':
      case '#':
      case 0:
        if (negative) s21_print_symbol(str, '-');
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        break;
    }
  } else {
    switch (spec->flag) {
      case '+':
      case ' ':
        s21_print_space_or_zero(spec->width - size_our_double, ' ', str);
        if (negative)
          s21_print_symbol(str, '-');
        else
          s21_print_symbol(str, spec->flag);
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        break;
      case '-':
        if (negative) s21_print_symbol(str, '-');
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        if (spec->type == 'f' || spec->type == 'g' || spec->type == 'G')
          s21_print_space_or_zero(spec->width - size_our_double, ' ', str);
        break;
      case '0':
        if (negative) s21_print_symbol(str, '-');
        s21_print_space_or_zero(spec->width - size_our_double, '0', str);
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        break;
      case '#':
      case 0:
        s21_print_space_or_zero(spec->width - size_our_double, ' ', str);
        if (negative) s21_print_symbol(str, '-');
        s21_print_double_to_string(base, mant, size_mant, str, spec);
        break;
    }
  }
}

void s21_print_eE(long double f, char** str, Spec* spec) {
  int shift = 0;
  int flag = 1;
  if (!spec->precision) f = f + (f < 0 ? -0.5 : 0.5);
  while (f >= 10 || f <= -10) {
    shift++;
    f /= 10;
  }
  if ((f < 1 && f > -1) && f) {
    while (!(int)f) {
      shift++;
      f *= 10;
      flag = 0;
    }
  }
  s21_print_double(f, str, spec);
  char sym = '\0';
  if (spec->type == 'e' || spec->type == 'E')
    sym = (spec->type == 'e' ? 'e' : 'E');
  else if (spec->type == 'g' || spec->type == 'G')
    sym = (spec->type == 'g' ? 'e' : 'E');
  s21_print_symbol(str, sym);
  s21_print_symbol(str, (flag ? '+' : '-'));
  if (shift < 10) s21_print_symbol(str, '0');
  s21_print_number(shift, str);
  int size_our_double = spec->precision + 6;
  if (f < 0) size_our_double++;
  if (spec->width > size_our_double && spec->flag == '-')
    s21_print_space_or_zero(spec->width - size_our_double, ' ', str);
}

void s21_print_gG(long double f, char** str, Spec* spec) {
  if (!f) {
    spec->precision = 1;
    s21_print_int(0, str, spec);
  } else {
    long double ftemp = f;
    long base = 0, mant = 0, size_base = 0, size_mant = 0,
         temp = spec->precision;
    base = (long)ftemp;
    size_base = s21_int_get_size(base);
    if (base) temp -= size_base;
    if (ftemp < 0) ftemp = -ftemp;
    mant = (long)((ftemp - (int)ftemp) * s21_pow(temp) + 0.5);
    if (mant) {
      size_mant = s21_int_get_size(mant);

      while (!(mant % 10)) {
        mant /= 10;
        size_mant--;
        temp--;
      }
    }
    if (spec->precision == size_base) {
      f = f + (f < 0 ? -0.5 : 0.5);
      spec->precision -= size_base;
      spec->type = 'f';
      s21_print_double(f, str, spec);
    } else if (spec->precision > size_base &&
               (temp >= size_mant || temp <= 4)) {
      if (!size_mant)
        spec->precision = 0;
      else
        spec->precision = temp;
      spec->type = 'f';
      s21_print_double(f, str, spec);
    } else {
      spec->precision--;
      s21_print_eE(f, str, spec);
    }
  }
}

void s21_param_star(Spec* spec, va_list arg) {
  if (spec->width_star) {
    spec->width = va_arg(arg, int);
  }
  if (spec->precision_star) {
    spec->precision = va_arg(arg, int);
  }
}

void s21_print(char** str, char** start, Spec* spec, va_list arg) {
  switch (spec->type) {
    case 'c':
      s21_print_char(str, va_arg(arg, int), spec);
      break;
    case 's':
      s21_print_string(str, va_arg(arg, char*), spec);
      break;
    case 'd':
    case 'i':
    case 'u':
      s21_param_star(spec, arg);
      switch (spec->length) {
        case 'l':
          s21_print_int(va_arg(arg, long int), str, spec);
          break;
        default:
          s21_print_int(va_arg(arg, int), str, spec);
          break;
      }
      break;
    case 'f':
      s21_param_star(spec, arg);
      switch (spec->length) {
        case 'L':
          s21_print_double(va_arg(arg, long double), str, spec);
          break;
        default:
          s21_print_double(va_arg(arg, double), str, spec);
          break;
      }
      break;
    case 'x':
    case 'X':
    case 'o':
      s21_param_star(spec, arg);
      s21_print_hex(va_arg(arg, unsigned), str, spec);
      break;
    case 'n':
      s21_spec_n(str, start, arg);
      break;
    case 'p':
      s21_print_pointer(*str - 0, arg, spec);
      break;
    case 'e':
    case 'E':
      s21_param_star(spec, arg);
      switch (spec->length) {
        case 'L':
          s21_print_eE(va_arg(arg, long double), str, spec);
          break;
        default:
          s21_print_eE(va_arg(arg, double), str, spec);
          break;
      }
      break;
    case 'g':
    case 'G':
      s21_param_star(spec, arg);
      switch (spec->length) {
        case 'L':
          s21_print_gG(va_arg(arg, long double), str, spec);
          break;
        default:
          s21_print_gG(va_arg(arg, double), str, spec);
          break;
      }
      break;
  }
}

void s21_parse_fmt(State* s, va_list arg) {
  ++s->fmt;  // skip %
  Spec spec;
  switch (*s->fmt) {
    case 0:
      *s->str++ = '%';
      break;
    case '%':
      *s->str++ = '%';
      ++s->fmt;
      break;
    default:
      s21_parse_spec(&spec, &s->fmt);
      s21_print(&s->str, &s->start, &spec, arg);
  }
}

int s21_vsprintf(char* str, const char* fmt, va_list arg) {
  State s;
  s.str = str;
  s.fmt = fmt;
  s.start = str;
  while (*s.fmt) {
    if (*s.fmt == '%')
      s21_parse_fmt(&s, arg);
    else
      *(s.str)++ = *(s.fmt)++;
  }
  if (str != s.str) *s.str = 0;
  return s.str - str;
}

int s21_sprintf(char* str, const char* fmt, ...) {
  va_list arg;
  va_start(arg, fmt);
  int res = s21_vsprintf(str, fmt, arg);
  va_end(arg);
  return res;
}

// int main() {
//   char test[1000];
//   test[0] = '\0';
//   int x = 10;
//   int* p = &x;
//   int res = s21_sprintf(test, "-%p", p);
//   printf("%s\n%d\n", test, res);
//   int res1 = sprintf(test, "-%p", p);
//   printf("%s\n%d\n", test, res1);

//   return 0;
// }
