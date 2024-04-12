#include "s21_decimal.h"

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  int result = 0;

  if (s21_is_decimal_zeros(decimal_1, decimal_2) == 3)
    result = true;
  else if (s21_get_sign(decimal_1) != s21_get_sign(decimal_2))
    result = false;
  else {
    int scale_decimal_1 = s21_get_scale(decimal_1);
    int scale_decimal_2 = s21_get_scale(decimal_2);

    if (scale_decimal_1 != scale_decimal_2) {
      s21_decimal_normalization(&decimal_1, &decimal_2);
    }

    if (s21_comparison_value_bits(decimal_1, decimal_2) >= 0)
      result = false;
    else
      result = true;
  }
  return result;
}