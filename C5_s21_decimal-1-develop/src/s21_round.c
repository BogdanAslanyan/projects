#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int func_res = ERROR;

  if (result != NULL) {
    s21_init_decimal(result);

    int sign_value = s21_get_sign(value);
    int scale_value = s21_get_scale(value);
    s21_decimal work_decimal = value;

    work_decimal.bits[3] = 0;

    if (scale_value == 0) {
      for (int iter = 0; iter < 4; iter++)
        result->bits[iter] = value.bits[iter];
      func_res = SUCCESS;
    } else {
      func_res = SUCCESS;
      for (int iter = 0; iter < scale_value - 1; iter++) {
        unsigned long long float_num = work_decimal.bits[2];

        for (int j = 2; j >= 0; j--) {
          work_decimal.bits[j] = float_num / 10;
          float_num = (float_num % 10) * 4294967296 + work_decimal.bits[j - 1];
        }
      }

      if (work_decimal.bits[0] % 10 < 5) {
        s21_truncate(value, result);
      } else {
        s21_truncate(value, result);
        result->bits[0] += 1;
      }

      s21_set_scale(&value, (s21_get_scale(value) - scale_value));

      if (sign_value == 1)
        s21_set_negative_sign(result);
      else
        s21_set_positive_sign(result);
    }
  }
  return func_res;
}
