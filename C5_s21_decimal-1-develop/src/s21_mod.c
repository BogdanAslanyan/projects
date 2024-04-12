#include "s21_decimal.h"

static s21_decimal s21_mantisses_mod(s21_decimal value_1, s21_decimal value_2);

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int mod_result = 0;
  s21_init_decimal(result);

  if (!s21_is_decimal_zeros(value_1, value_2)) {
    int sign_decimal_1 = s21_get_sign(value_1);

    int scale_decimal_1 = s21_get_scale(value_1);
    int scale_decimal_2 = s21_get_scale(value_2);

    if (scale_decimal_1 != scale_decimal_2)
      s21_decimal_normalization(&value_1, &value_2);

    s21_set_scale(&value_1, 0);
    s21_set_scale(&value_2, 0);

    *result = s21_mantisses_mod(value_1, value_2);

    int bigger_scale =
        scale_decimal_1 > scale_decimal_2 ? scale_decimal_1 : scale_decimal_2;

    s21_set_scale(result, bigger_scale);

    if (sign_decimal_1)
      s21_set_negative_sign(result);
    else
      s21_set_positive_sign(result);

  } else
    mod_result = NaN;

  return mod_result;
}

static s21_decimal s21_mantisses_mod(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result = {0};
  s21_decimal pre_result = {0};
  s21_decimal temp_decimal = value_2;

  if (s21_is_less(value_1, value_2) == 1) {
    result = value_1;
  } else if (s21_is_equal(value_1, value_2) == 1) {
    result = pre_result;
  } else {
    while (s21_index_of_elder_significant_bit(value_1) >
           s21_index_of_elder_significant_bit(temp_decimal)) {
      s21_left_shift(&temp_decimal);
    }
    s21_sub(value_1, temp_decimal, &pre_result);

    result = s21_mantisses_mod(pre_result, value_2);
  }
  return result;
}
