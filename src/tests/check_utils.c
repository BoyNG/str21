#include <check.h>
#include <stdlib.h>

#include "../utils/write_int_into_str_buffer.h"

START_TEST(test_ten_pow_positive) {
  ck_assert_int_eq(ten_pow_positive(0), 1);
  ck_assert_int_eq(ten_pow_positive(1), 10);
  ck_assert_int_eq(ten_pow_positive(5), 100000);
}
END_TEST

START_TEST(test_cont_digits_positive) {
  ck_assert_int_eq(cont_digits_positive(0), 1);
  ck_assert_int_eq(cont_digits_positive(1), 1);
  ck_assert_int_eq(cont_digits_positive(9), 1);
  ck_assert_int_eq(cont_digits_positive(10), 2);
  ck_assert_int_eq(cont_digits_positive(923), 3);
}
END_TEST

START_TEST(test_write_int) {
  char buff1[10] = {"one"};
  write_int(buff1, 1);
  ck_assert_str_eq(buff1, "1");

  write_int(buff1, -1);
  ck_assert_str_eq(buff1, "-1");

  char buff2[20] = "two";
  write_int(buff2 + 3, -1);
  ck_assert_str_eq(buff2, "two-1");
}
END_TEST

Suite *util_test_suit(void) {
  Suite *s = suite_create("UtilTests");
  TCase *utils_tcase = tcase_create("Utils");

  tcase_add_test(utils_tcase, test_ten_pow_positive);
  tcase_add_test(utils_tcase, test_cont_digits_positive);
  tcase_add_test(utils_tcase, test_write_int);

  suite_add_tcase(s, utils_tcase);
  return s;
}
