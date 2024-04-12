#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int code_result = SUCCESS;

  // Если указатель на decimal является NULL.
  if (!result) {
    code_result = ERROR;
    // Проверяем, что value является корректным decimal.
  } else if (!s21_is_correct_decimal(value)) {
    code_result = ERROR;
    s21_init_decimal(result);
    // В остальных случаях производим округление.
  } else {
    s21_decimal one = {{1, 0, 0, 0}, NORMAL};
    s21_init_decimal(result);
    int value_sign = s21_get_sign(value);

    if (value_sign) {
      s21_negate(value, &value);
    }
    s21_truncate(value, result);
    if (value_sign && s21_is_not_equal(value, *result)) {
      s21_add(*result, one, result);
    }
    if (value_sign) {
      s21_negate(*result, result);
    }
  }
  return code_result;
}