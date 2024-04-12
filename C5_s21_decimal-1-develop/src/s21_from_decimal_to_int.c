#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = 0;
  s21_decimal buffer_decimal;
  s21_init_decimal(&buffer_decimal);

  int result = s21_truncate(src, &buffer_decimal);

  if (result != SUCCESS || buffer_decimal.bits[1] || buffer_decimal.bits[2]) {
    result = ERROR;
  } else {
    *dst = buffer_decimal.bits[0];
    if (s21_get_sign(src) == 1) *dst *= -1;
  }

  return result;
}
