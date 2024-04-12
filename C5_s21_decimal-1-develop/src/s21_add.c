#include "s21_decimal.h"

int s21_add(s21_decimal decimal_1, s21_decimal decimal_2, s21_decimal *result) {
  s21_init_decimal(result);
  int return_value = SUCCESS;

  int sign_decimal_1 = s21_get_sign(decimal_1);
  int sign_decimal_2 = s21_get_sign(decimal_2);

  if (sign_decimal_1 == 0 && sign_decimal_2 == 0) {
    if (s21_get_scale(decimal_1) != s21_get_scale(decimal_2))
      s21_decimal_normalization(&decimal_1, &decimal_2);
    s21_decimal decimal_tmp = s21_mantisses_addition(&decimal_1, &decimal_2);
    if (decimal_tmp.value_type == INF) {
      return_value = INF;
    } else {
      *result = decimal_tmp;
      result->bits[3] = decimal_1.bits[3];
    }
  } else if (sign_decimal_1 == 1 && sign_decimal_2 == 0) {
    s21_set_positive_sign(&decimal_1);
    return_value = s21_sub(decimal_2, decimal_1, result);
  } else if (sign_decimal_1 == 0 && sign_decimal_2 == 1) {
    s21_set_positive_sign(&decimal_2);
    return_value = s21_sub(decimal_1, decimal_2, result);
  } else {
    s21_set_positive_sign(&decimal_1);
    s21_set_positive_sign(&decimal_2);
    return_value = s21_add(decimal_1, decimal_2, result);
    if (return_value == INF)
      return_value = NEG_INF;
    else
      s21_set_negative_sign(result);
  }
  return return_value;
}
