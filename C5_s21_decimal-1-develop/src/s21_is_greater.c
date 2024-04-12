#include "s21_decimal.h"

int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2) {
  int result = false;

  int sign_decimal_1 = s21_get_sign(decimal_1);
  int sign_decimal_2 = s21_get_sign(decimal_2);
  int scale_decimal_1 = s21_get_scale(decimal_1);
  int scale_decimal_2 = s21_get_scale(decimal_2);

  if (s21_is_decimal_zeros(decimal_1, decimal_2) == 3)
    result = false;
  else if (sign_decimal_1 && !sign_decimal_2)
    result = false;
  else if (!sign_decimal_1 && sign_decimal_2)
    result = true;
  else if (sign_decimal_1 && sign_decimal_2) {
    s21_clear_bit(&decimal_1, 127);
    s21_clear_bit(&decimal_2, 127);

    if (scale_decimal_1 != scale_decimal_2)
      s21_decimal_normalization(&decimal_1, &decimal_2);

    result = s21_comparison_value_bits(decimal_1, decimal_2);
    if (result == -1) result = false;
  } else {
    if (scale_decimal_1 != scale_decimal_2)
      s21_decimal_normalization(&decimal_1, &decimal_2);
    result = s21_comparison_value_bits(decimal_1, decimal_2);
    if (result != 0)
      result = false;
    else
      result = true;
  }

  return result;
}

// int main() {
//   s21_decimal src1;
//   s21_decimal src2;
//   src1.bits[0] = 0b00001011000011110111000010001101;
//   src1.bits[1] = 0b10010110101100000101100101010001;
//   src1.bits[2] = 0b00010001101000010111101110000001;
//   src1.bits[3] = 0b00000000000111000000000000000000;
//   src2.bits[0] = 0b00010111001001010100110000000010;
//   src2.bits[1] = 0b00000000111101010001010110011011;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000100010000000000000000;
//   int result = s21_is_greater(src1, src2);
//   printf("%d", result);
//   return 0;
// }