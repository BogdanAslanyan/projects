#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int converting_status = SUCCESS;
  if (dst) {
    s21_init_decimal(dst);
    if (src < 0) {
      src *= -1;
      s21_set_negative_sign(dst);
    }
    dst->bits[LOW] = src;
  } else
    converting_status = ERROR;
  return converting_status;
}