#include "test_decimal.h"

int main() {
  int failed = 0;
  Suite *s21_decimal_test[] = {suite_add(),
                               suite_sub(),
                               suite_mul(),
                               suite_div(),
                               suite_mod(),
                               suite_is_less(),
                               suite_is_less_or_equal(),
                               suite_is_greater(),
                               suite_is_greater_or_equal(),
                               suite_is_equal(),
                               suite_is_not_equal(),
                               suite_from_int_to_decimal(),
                               suite_from_float_to_decimal(),
                               suite_from_decimal_to_int(),
                               suite_from_decimal_to_float(),
                               suite_floor(),
                               suite_round(),
                               suite_truncate(),
                               suite_negate(),
                               NULL};

  for (size_t i = 0; s21_decimal_test[i] != NULL; i++) {
    SRunner *runner = srunner_create(s21_decimal_test[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);

    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 1 : 0;
}
