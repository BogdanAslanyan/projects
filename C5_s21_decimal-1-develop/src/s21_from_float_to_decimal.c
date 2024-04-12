#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int func_res = ERROR;
  if (dst != NULL) {
    s21_init_decimal(dst);
    long double float_number = src;
    int sign = 0;
    if (float_number < 0) {
      sign = 1;
      float_number *= -1;
    }
    if (float_number < 1e-28) {
      s21_from_int_to_decimal(0, dst);
      if (float_number == 0.0) func_res = SUCCESS;
    } else if (float_number <= (long double)MAX_CONVERT &&
               !isinf(float_number)) {
      func_res = SUCCESS;
      int scale_float = 0;
      long double left_part = 0;
      while (float_number > PRECISION) {
        float_number /= 10;
        scale_float -= 1;
      }
      while (float_number < PRECISION && modfl(float_number, &left_part) > 0 &&
             scale_float < 28) {
        float_number *= 10;
        scale_float += 1;
      }
      float_number = roundl(float_number);
      if (scale_float < 0) {
        float_number *= powl(10, -scale_float);
        scale_float = 0;
      }
      s21_set_scale(dst, scale_float);
      if (sign)
        s21_set_negative_sign(dst);
      else
        s21_set_positive_sign(dst);
      for (int i = 0; i < 96; i++, float_number = floorl(float_number / 2)) {
        if (fmodl(float_number, 2))
          s21_set_bit(dst, i);
        else
          s21_clear_bit(dst, i);
      }
    }
  }
  return func_res;
}
