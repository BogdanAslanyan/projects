#include "s21_decimal.h"

int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2) {
  return s21_is_greater(decimal_2, decimal_1);
}