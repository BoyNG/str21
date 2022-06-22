#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

typedef long unsigned s21_size_t;
#define s21_NULL ((void*)0)
#define BUFF_SIZE 512

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void s21_itoa(int num, char* str);

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memmove(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
s21_size_t s21_strspn(const char* str1, const char* str2);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);
void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_trim(const char* src, const char* trim_chars);

typedef struct State {
  char* start;
  char* str;
  const char* fmt;
} State;

typedef struct Spec {
  char flag;
  char width_star;
  int width;
  char precision_star;
  int precision;
  char length;
  char type;
} Spec;

char s21_get_flag(const char** fmt);
char s21_get_width_star(const char** fmt);
int s21_get_width(const char** fmt);
int s21_get_precision(const char** fmt);
char s21_get_length(const char** fmt);
char s21_get_type(const char** fmt);
void s21_parse_spec(Spec* spec, const char** fmt);
void s21_revert(char* start, char* end);
void s21_print_symbol(char** str, char c);
void s21_print_number(long i, char** str);
void s21_print_space_or_zero(int delt, char c, char** str);
void s21_print_with_flag_plus_or_space(long i, int delt, char** str,
                                       Spec* spec);
void s21_print_with_flag_minus(long i, int delt, char** str, Spec* spec);
void s21_print_with_flag_zero(long i, int delt, char** str, Spec* spec,
                              int size);
void s21_print_int_without_precision(long i, int size, char** str, Spec* spec);
void s21_print_int_with_precision(long i, int size, char** str, Spec* spec);
int s21_int_get_size(long i);
void s21_print_int(long i, char** str, Spec* spec);
void s21_print_char(char** str, const char c, Spec* spec);
void s21_print_string_to_string(char** str, const char* s);
void s21_print_string_precision_zero(char** str, Spec* spec);
void s21_print_string_precision_more_string(char** str, int size, const char* s,
                                            Spec* spec);
void s21_print_string_precision_less_string(char** str, const char* s,
                                            Spec* spec);
void s21_print_string(char** str, const char* s, Spec* spec);
void s21_print_hex_all_less(char** str, const char* prefix, char* start,
                            Spec* spec);
void s21_print_hex_width_more(char** str, const char* prefix, char* start,
                              Spec* spec, int size, int size_prefix);
void s21_print_hex_precesion_more(char** str, const char* prefix, char* start,
                                  Spec* spec, int size);
void s21_print_hex_all_more(char** str, const char* prefix, char* start,
                            Spec* spec, int size, int size_prefix);
void s21_print_hex(unsigned i, char** str, Spec* spec);
void s21_spec_n(char** str, char** str_start, va_list arg);
char* flagToP(char* str, int wid, Spec* spec);
void s21_print_pointer(char* str, va_list arg, Spec* spec);
long s21_pow(int p);
void s21_print_double_to_string(long base, long mant, int size_mant, char** str,
                                Spec* spec);
void s21_print_double(long double f, char** str, Spec* spec);
void s21_param_star(Spec* spec, va_list arg);
void s21_print(char** str, char** start, Spec* spec, va_list arg);
void s21_parse_fmt(State* s, va_list arg);
int s21_vsprintf(char* str, const char* fmt, va_list arg);
int s21_sprintf(char* str, const char* fmt, ...);

#endif  // SRC_S21_STRING_H_
