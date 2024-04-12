#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int func_res = SUCCESS;
  int value_sign = s21_get_sign(value);
  s21_init_decimal(result);

  if (s21_get_scale(value) > 28) {
    func_res = ERROR;
  } else {
    while (s21_get_scale(value) > 0) {
      uint64_t p_rest = 0;
      int value_scale = s21_get_scale(value) - 1;
      int ten_divider = 10, rest_of_division = 0;

      for (int i = 2; i >= 0; i--) {
        p_rest = rest_of_division * 4294967296 + value.bits[i];
        value.bits[i] = p_rest / ten_divider;
        rest_of_division = p_rest - ten_divider * value.bits[i];
      }
      s21_set_scale(&value, value_scale);
    }

    result->bits[LOW] = value.bits[LOW];
    result->bits[MID] = value.bits[MID];
    result->bits[HIGH] = value.bits[HIGH];
    result->bits[SCALE] = value.bits[SCALE];

    if (value_sign == 1) s21_set_negative_sign(result);
  }
  return func_res;
}
