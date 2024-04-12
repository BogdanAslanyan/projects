#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  bool result_func;
  if (result) {
    int sign_of_decimal = s21_get_sign(value);
    if (sign_of_decimal)
      s21_set_positive_sign(&value);
    else
      s21_set_negative_sign(&value);
    *result = value;
    result_func = 0;
  } else {
    result_func = 1;
  }
  return result_func;
}