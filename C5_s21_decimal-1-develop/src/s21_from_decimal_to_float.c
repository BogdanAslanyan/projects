#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = SUCCESS;

  if (dst != NULL) {
    int sign_src = s21_get_sign(src);
    int scale_src = s21_get_scale(src);
    long double result = 0;

    for (int iter = 0; iter < 96; iter++)
      result += pow(2, iter) * s21_get_bit(src, iter);

    for (; scale_src > 0; scale_src--) result /= 10.0;

    if (sign_src == 1) result *= -1.0;

    *dst = result;
  } else
    result = ERROR;

  return result;
}