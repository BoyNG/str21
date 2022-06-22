#include <check.h>
#include <stdlib.h>

#include "check_s21_string.h"
#include "check_utils.h"

int main(void) {
  int number_failed;

  Suite *main_suit = string_test_suit();
  Suite *util_suit = util_test_suit();

  SRunner *main_suit_runner = srunner_create(main_suit);
  srunner_add_suite(main_suit_runner, util_suit);

  srunner_run_all(main_suit_runner, CK_VERBOSE);
  number_failed = srunner_ntests_failed(main_suit_runner);
  srunner_free(main_suit_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  return 0;
}