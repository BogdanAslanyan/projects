#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  return !s21_is_equal(decimal_1, decimal_2);
}