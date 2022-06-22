#include <check.h>
#include <stdlib.h>

#include "../s21_string.h"

// 1
void memchr_tester(const void *str, int c, unsigned long n) {
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(test_s21_memchr_simple) {
  memchr_tester("", 'c', 0);
  memchr_tester("string", 's', 4);
  memchr_tester("string", 'g', 4);
}
END_TEST

// s21_size_t s21_strspn(const char *str1, const char *str2);

void strspn_tester(const char *str1, const char *str2) {
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}

START_TEST(test_s21_strspn_simple) {
strspn_tester(" ", "      ");
strspn_tester("1234555555433", "0");
strspn_tester("строчка-строка", "стро");
strspn_tester("string", "@");
strspn_tester("@@@@@#@@###", "@");
strspn_tester("s▒tring▒", " ▒");
}
END_TEST

void memset_tester(void *str, int c, unsigned long n) {
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}


START_TEST(test_s21_memset_simple) {
  char str[7] = "string";
  memset_tester(str,'c', 0);
  memset_tester(str, 's', 1);
  memset_tester(str, 'g', 2);
  memset_tester(str, '1', 3);

  memset_tester(str, '@', 4);
  memset_tester(str, '?', 7);
  memset_tester(str, ' ', 7);
}
END_TEST


void memcpy_tester(void *dest, const void *src, unsigned long n) {
  ck_assert_ptr_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));
}

START_TEST(test_s21_memcpy_simple) {
char dest[15] = "string";
memcpy_tester(dest, "abcd", 5);
memcpy_tester(dest, "abcd", 4);
memcpy_tester(dest, "abcd", 0);

memcpy_tester(dest, "ABCD", 5);
memcpy_tester(dest, "ABCD", 4);
memcpy_tester(dest, "ABCD", 0);

memcpy_tester(dest, "123", 4);
memcpy_tester(dest, " ", 2);
memcpy_tester(dest, "▒▒", 7);
memcpy_tester(dest, "строка", 13);
memcpy_tester(dest, "строка", 13);
}
END_TEST

void memmove_tester(void *dest, const void *src, unsigned long n) {
  ck_assert_ptr_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}

START_TEST(test_s21_memmove_simple) {
char dest[15] = "string";
memmove_tester(dest, "abcd", 5);
memmove_tester(dest, "abcd", 4);
memmove_tester(dest, "abcd", 0);

memmove_tester(dest, "ABCD", 5);
memmove_tester(dest, "ABCD", 4);
memmove_tester(dest, "ABCD", 0);

memmove_tester(dest, "123", 4);
memmove_tester(dest, " ", 2);
memmove_tester(dest, "▒▒", 7);
memmove_tester(dest, "строка", 13);
memmove_tester(dest, "строка", 13);
}
END_TEST



// 2
void memcmp_tester(const void *str1, const void *str2, unsigned long n) {
  int r1 = s21_memcmp(str1, str2, n);
  int r2 = memcmp(str1, str2, n);

  ck_assert_msg((r1 != 0 && r2 != 0) || (r1 == 0 && r2 == 0),
                "First %lu bytes of str1: %s and str2: %s", n,
                (const char *)str1, (const char *)str2);
}

START_TEST(test_s21_memcmp_simple) {
  memcmp_tester("", "", 0);
  memcmp_tester("0", "", 1);
  memcmp_tester("", "0", 1);

  memcmp_tester("string", "streng", 3);
  memcmp_tester("string", "streng", 6);
}
END_TEST

// 6
void strcat_tester(char *to, const char *from, unsigned long _buffsize) {
  char *tocpy = malloc(_buffsize);

  memcpy(tocpy, to, _buffsize);
  s21_strcat(tocpy, from), strcat(to, from);
  ck_assert_str_eq(tocpy, to);

  free(tocpy);
}

START_TEST(test_s21_strcat_simple) {
  const int bufsize = 100;
  char *to = malloc(bufsize);
  strcpy(to, "string");

  strcat_tester(to, "", bufsize);
  strcat_tester(to, "0", bufsize);

  strcpy(to, "string");
  strcat_tester(to, " connected", bufsize);

  free(to);
}
END_TEST

// 9
void strcmp_tester(const char *s1, const char *s2) {
  int r1 = s21_strcmp(s1, s2);
  int r2 = strcmp(s1, s2);
  
  ck_assert_msg((r1 == 0 && r2 == 0) || (r1 ^ r2 == 0),
                "Different answers: %d and %d strings: %s and %s", r1, r2, s1,
                s2);
}

START_TEST(test_s21_strcmp_simple) {
  strcmp_tester("", "");
  strcmp_tester("", "a");
  strcmp_tester("a", "");

  strcmp_tester("b", "a");
  strcmp_tester("a", "b");

  strcmp_tester("A", "a");
  strcmp_tester("a", "A");

  strcmp_tester("ABC", "AB");
  strcmp_tester("ABA", "ABZ");

  strcmp_tester("A", "ABZ");

  char unsigned_str[] = {'\201', '\0'};
  strcmp_tester(unsigned_str, "A");
}
END_TEST

// 10
void strncmp_tester(const char *s1, const char *s2, unsigned long long n) {
  int r1 = s21_strncmp(s1, s2, n);
  int r2 = strncmp(s1, s2, n);

  ck_assert_msg((r1 == 0 && r2 == 0) || (r1 ^ r2 == 0),
                "Different answers: %d and %d strings: %s and %s", r1, r2, s1,
                s2);
}

START_TEST(test_s21_strncmp_simple) {
  strncmp_tester("", "", 0);
  strncmp_tester("", "", 1);
  strncmp_tester("", "", 3);

  strncmp_tester("", "a", 0);
  strncmp_tester("", "a", 1);
  strncmp_tester("", "a", 4);

  strncmp_tester("b", "a", 0);
  strncmp_tester("a", "b", 1);

  strncmp_tester("A", "a", 3);

  strncmp_tester("ABC", "AB", 10);
  strncmp_tester("ABA", "ABZ", 10);

  strncmp_tester("A", "ABZ", 10);

  char unsigned_str[] = {'\201', '\0'};
  strncmp_tester(unsigned_str, "A", 1);
}
END_TEST

// 14
void strerror_tester(int errnum) {
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
START_TEST(test_s21_strerror_simple) {
  strerror_tester(1);
  strerror_tester(5);
  strerror_tester(12);
  strerror_tester(100);
}
END_TEST

START_TEST(test_s21_strerror_abnormal) {
  strerror_tester(0);
  strerror_tester(-1);
  strerror_tester(-23);
  strerror_tester(800);
}
END_TEST

// 15
void strlen_tester(const char *s) {
  ck_assert_uint_eq(s21_strlen(s), strlen(s));
}

START_TEST(test_s21_strlen_simple) {
  strlen_tester("");
  strlen_tester("a");
  strlen_tester("length");
}
END_TEST

Suite *string_test_suit(void) {
  // штука которую можно запускать и можно добавлять
  Suite *s = suite_create("StringTests");
  // штука в которую можно добавлять
  TCase *s21_string_simple_case = tcase_create("StringSimple");

  tcase_add_test(s21_string_simple_case, test_s21_memchr_simple);
  tcase_add_test(s21_string_simple_case, test_s21_memcmp_simple);
  tcase_add_test(s21_string_simple_case, test_s21_memcpy_simple);
  tcase_add_test(s21_string_simple_case, test_s21_memmove_simple); 
  tcase_add_test(s21_string_simple_case, test_s21_memset_simple);

  tcase_add_test(s21_string_simple_case, test_s21_strspn_simple);

  tcase_add_test(s21_string_simple_case, test_s21_strcat_simple);
  tcase_add_test(s21_string_simple_case, test_s21_strcmp_simple);
  tcase_add_test(s21_string_simple_case, test_s21_strncmp_simple);
  tcase_add_test(s21_string_simple_case, test_s21_strerror_simple);
  tcase_add_test(s21_string_simple_case, test_s21_strlen_simple);

  suite_add_tcase(s, s21_string_simple_case);

  TCase *s21_string_abnormal_case = tcase_create("StringAbnormal");
  tcase_add_test(s21_string_abnormal_case, test_s21_strerror_abnormal);

  suite_add_tcase(s, s21_string_abnormal_case);

  return s;
}
