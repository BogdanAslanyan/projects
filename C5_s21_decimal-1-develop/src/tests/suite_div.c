#include "test_decimal.h"

START_TEST(div_test_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}, 0};
  s21_decimal dec2 = {{0, 0, 0, 0}, 0};
  s21_decimal res1 = {{0, 0, 0, 0}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};

  s21_div(dec1, dec2, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_div(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_DIV  \033[0m");
  tc = tcase_create("case_div");
  tcase_add_test(tc, div_test_1);
  suite_add_tcase(s, tc);
  return s;
}
