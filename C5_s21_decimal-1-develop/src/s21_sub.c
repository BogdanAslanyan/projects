#include "s21_decimal.h"

int s21_sub(s21_decimal decimal_1, s21_decimal decimal_2, s21_decimal* result) {
  int return_value = SUCCESS;
  int sign_decimal_1 = s21_get_sign(decimal_1);
  int sign_decimal_2 = s21_get_sign(decimal_2);
  int resultSign = 0;
  s21_init_decimal(result);
  if (s21_is_decimal_nan(decimal_1, decimal_2) >= 0) {
    return_value = ERROR;
  } else if (s21_is_decimal_inf(decimal_1, decimal_2) >= 0) {
    *result = decimal_to_infinity();

    if (sign_decimal_1 || sign_decimal_2) s21_set_negative_sign(result);

  } else if (sign_decimal_1 == 0 && sign_decimal_2 == 1) {
    resultSign = s21_get_sign(decimal_1);
    s21_set_positive_sign(&decimal_2);

    return_value = s21_add(decimal_1, decimal_2, result);
    if (return_value == INF) {
      return_value = INF;
      result->value_type = INF;
    }
    s21_set_positive_sign(result);
  } else if (sign_decimal_1 == 1 && sign_decimal_2 == 0) {
    resultSign = s21_get_sign(decimal_1);
    s21_set_positive_sign(&decimal_1);

    return_value = s21_add(decimal_1, decimal_2, result);
    if (return_value == NEG_INF) {
      return_value = INF;
      result->value_type = INF;
    } else if (return_value == INF) {
      return_value = NEG_INF;
      result->value_type = NEG_INF;
    }
    s21_set_negative_sign(result);
  } else if (s21_is_equal(decimal_1, decimal_2) == 0) {
    s21_set_positive_sign(&decimal_1);
    s21_set_positive_sign(&decimal_2);
    s21_decimal *smaller_decimal, *bigger_decimal;
    if (s21_get_scale(decimal_1) != s21_get_scale(decimal_2))
      s21_decimal_normalization(&decimal_1, &decimal_2);
    if (s21_is_less(decimal_1, decimal_2)) {
      smaller_decimal = &decimal_1;
      bigger_decimal = &decimal_2;
      resultSign = !sign_decimal_2;
    } else {
      smaller_decimal = &decimal_2;
      bigger_decimal = &decimal_1;
      resultSign = sign_decimal_1;
    }

    s21_mantisses_subtraction(*bigger_decimal, *smaller_decimal, result);
    int result_scale = s21_get_scale(decimal_1);
    s21_set_scale(result, result_scale);
    if (resultSign)
      s21_set_negative_sign(result);
    else
      s21_set_positive_sign(result);
  }
  return return_value;
}