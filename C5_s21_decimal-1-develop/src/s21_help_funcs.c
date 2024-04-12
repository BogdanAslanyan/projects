#include "s21_decimal.h"

/*Initialization decimal*/

void s21_init_decimal(s21_decimal *src) {
  src->bits[LOW] = 0;
  src->bits[MID] = 0;
  src->bits[HIGH] = 0;
  src->bits[SCALE] = 0;
  src->value_type = NORMAL;
}

// int s21_get_sign(s21_decimal number) { return (number.bits[3] >> 31) & 1U; }

/*Getters and setters*/

int s21_get_bit(s21_decimal src, int index) {
  unsigned int result = 0;
  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    result = src.bits[index / 32] & mask;
  }
  return !!result;
}

bool s21_set_bit(s21_decimal *src, int index) {
  bool result = false;

  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    src->bits[index / 32] |= mask;
    result = true;
  }

  return result;
}

bool s21_clear_bit(s21_decimal *src, int index) {
  bool result = false;

  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    src->bits[index / 32] &= ~(mask);
    result = true;
  }

  return result;
}

int s21_get_scale(s21_decimal src) { return (src.bits[SCALE] >> 16) & 0xFF; }

void s21_set_scale(s21_decimal *src, int scale) {
  s21_clear_scale(src);
  unsigned int mask = scale << 16;
  src->bits[SCALE] |= mask;
}

void s21_clear_scale(s21_decimal *src) { src->bits[SCALE] &= 0xFFFF; }

int s21_get_sign(s21_decimal src) {
  return (src.bits[SCALE] & 1u << 31) != 0 ? 1 : 0;
}

void s21_set_positive_sign(s21_decimal *src) {
  src->bits[SCALE] &= ~(1u << 31);
}

void s21_set_negative_sign(s21_decimal *src) { src->bits[SCALE] |= 1u << 31; }

/*Zeros, NaN, Inf checks*/

int s21_is_mantissa_zeros(s21_decimal src) {
  int result = false;

  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0) result = true;

  return result;
}

int s21_is_decimal_zeros(s21_decimal src_1, s21_decimal src_2) {
  int result = -1;
  bool src_1_mantissa_zero = s21_is_mantissa_zeros(src_1);
  bool src_2_mantissa_zero = s21_is_mantissa_zeros(src_2);
  int sign_src_1 = s21_get_sign(src_1);
  int sign_src_2 = s21_get_sign(src_2);
  int scale_src_1 = s21_get_scale(src_1);
  int scale_src_2 = s21_get_scale(src_2);
  if (src_1_mantissa_zero == true && scale_src_1 == 0 && sign_src_1 == 0) {
    result = 1;
  } else if (src_2_mantissa_zero == true && scale_src_2 == 0 &&
             sign_src_2 == 0) {
    result = 2;
  } else if (src_1_mantissa_zero == true && scale_src_1 == 0 &&
             sign_src_1 == 0 && src_2_mantissa_zero == true &&
             scale_src_2 == 0 && sign_src_2 == 0) {
    result = 3;
  } else
    result = 0;

  return result;
}

int s21_is_decimal_inf(s21_decimal src_1, s21_decimal src_2) {
  int result = -1;
  if (src_1.bits[0] == 0 && src_1.bits[1] == 0 && src_1.bits[2] == 0 &&
      src_1.bits[3] == 2147483647) {
    src_1.value_type = INF;
  }

  if (src_2.bits[0] == 0 && src_2.bits[1] == 0 && src_2.bits[2] == 0 &&
      src_2.bits[3] == 2147483647) {
    src_2.value_type = INF;
  }

  if (src_1.value_type == INF && src_2.value_type == INF) {
    result = 2;
  } else if (src_1.value_type != INF && src_2.value_type == INF) {
    result = 1;
  } else if (src_1.value_type == INF && src_2.value_type != INF) {
    result = 0;
  }

  return result;
}

int s21_is_decimal_nan(s21_decimal src_1, s21_decimal src_2) {
  int result = -1;

  if ((src_1.bits[0] != 0 || src_1.bits[1] != 0 || src_1.bits[2] != 0) &&
      (src_1.bits[3] == 2147483647 || src_1.bits[3] == 4294967295)) {
    result = true;
    src_1.value_type = NaN;
  }
  if ((src_2.bits[0] != 0 || src_2.bits[1] != 0 || src_2.bits[2] != 0) &&
      (src_2.bits[3] == 2147483647 || src_2.bits[3] == 4294967295)) {
    result = true;
    src_2.value_type = NaN;
  }
  if (src_1.value_type == NaN && src_2.value_type == NaN) {
    result = 2;
  } else if (src_1.value_type != NaN && src_2.value_type == NaN) {
    result = 1;
  } else if (src_1.value_type == NaN && src_2.value_type != NaN) {
    result = 0;
  }
  return result;
}

s21_decimal decimal_to_infinity(void) {
  s21_decimal inf_decimal = {{0, 0, 0, 0x7FFFFFFF}, INF};
  return inf_decimal;
}

int s21_index_of_elder_significant_bit(s21_decimal src) {
  int index_of_last_bit = 95;

  while (index_of_last_bit >= 0 && s21_get_bit(src, index_of_last_bit) == 0) {
    index_of_last_bit--;
  }

  return index_of_last_bit;
}

int s21_left_shift_n(s21_decimal *src, int shift_index) {
  int last_significant_bit = s21_index_of_elder_significant_bit(*src);
  int result = 0;
  if (last_significant_bit + shift_index > 95) {
    src->value_type = INF;
    result = INF;
  } else
    for (int iter = 0; iter < shift_index; iter++) {
      bool last_low_bit = s21_get_bit(*src, 31);
      bool last_mid_bit = s21_get_bit(*src, 63);
      src->bits[LOW] = src->bits[LOW] << 1;
      src->bits[MID] = src->bits[MID] << 1;
      src->bits[HIGH] = src->bits[HIGH] << 1;
      if (last_low_bit == true) s21_set_bit(src, 32);
      if (last_mid_bit == true) s21_set_bit(src, 64);
    }
  return result;
}
int s21_left_shift(s21_decimal *value) {
  int is_over = s21_get_bit(*value, 95);
  value->bits[2] <<= 1U;
  if (s21_get_bit(*value, 63)) {
    s21_set_bit(value, 64);
  }
  value->bits[1] <<= 1U;
  if (s21_get_bit(*value, 31)) {
    s21_set_bit(value, 32);
  }
  value->bits[0] <<= 1U;
  return is_over;
}

void s21_decimal_normalization(s21_decimal *src_1, s21_decimal *src_2) {
  int bigger_scale = 0, smaller_scale = 0;

  int scale_src_1 = s21_get_scale(*src_1);
  int scale_src_2 = s21_get_scale(*src_2);

  if (scale_src_1 != scale_src_2) {
    s21_decimal *larger_decimal = {0};
    s21_decimal *smaller_decimal = {0};
    s21_decimal buffer_decimal = {{0, 0, 0, 0}, 0};
    if (scale_src_1 > scale_src_2) {
      larger_decimal = src_1;
      smaller_decimal = src_2;
    } else if (scale_src_1 < scale_src_2) {
      larger_decimal = src_2;
      smaller_decimal = src_1;
    }

    while (s21_get_scale(*src_1) != s21_get_scale(*src_2)) {
      if (buffer_decimal.value_type == NORMAL) {
        s21_decimal decimal_x_8 = *smaller_decimal;
        s21_decimal decimal_x_2 = *smaller_decimal;
        smaller_scale = s21_get_scale(*smaller_decimal);

        s21_left_shift_n(&decimal_x_8, 3);
        s21_left_shift_n(&decimal_x_2, 1);

        buffer_decimal = s21_mantisses_addition(&decimal_x_8, &decimal_x_2);
        smaller_decimal->bits[LOW] = buffer_decimal.bits[LOW];
        smaller_decimal->bits[MID] = buffer_decimal.bits[MID];
        smaller_decimal->bits[HIGH] = buffer_decimal.bits[HIGH];
        s21_set_scale(smaller_decimal, smaller_scale + 1);

      } else {
        s21_decimal rest_decimal = {{0, 0, 0, 0}, 0};
        s21_decimal zero_decimal = {{0, 0, 0, 0}, 0};
        s21_decimal denary_decimal = {{10, 0, 0, 0}, NORMAL};

        s21_decimal devided_decimal = s21_mantisses_division(
            *larger_decimal, denary_decimal, &rest_decimal);
        if (s21_is_decimal_zeros(devided_decimal, zero_decimal) == 3) {
          larger_decimal->bits[LOW] = devided_decimal.bits[LOW];
          larger_decimal->bits[MID] = devided_decimal.bits[MID];
          larger_decimal->bits[HIGH] = devided_decimal.bits[HIGH];
        } else {
          larger_decimal->bits[LOW] = rest_decimal.bits[LOW];
          larger_decimal->bits[MID] = rest_decimal.bits[MID];
          larger_decimal->bits[HIGH] = rest_decimal.bits[HIGH];
        }

        bigger_scale = s21_get_scale(*larger_decimal);
        s21_set_scale(larger_decimal, bigger_scale - 1);
      }
    }
  }
}

s21_decimal s21_mantisses_addition(s21_decimal *src_1, s21_decimal *src_2) {
  s21_decimal result;
  int remembered_bit = 0;

  s21_init_decimal(&result);

  for (int iter = 0; iter < 96; iter++) {
    bool bit_src_1 = s21_get_bit(*src_1, iter);
    bool bit_src_2 = s21_get_bit(*src_2, iter);

    if (bit_src_1 == 0 && bit_src_2 == 0) {
      if (remembered_bit == 1) {
        s21_set_bit(&result, iter);
        remembered_bit = 0;
      } else {
        s21_clear_bit(&result, iter);
      }
    } else if (bit_src_1 != bit_src_2) {
      if (remembered_bit == 1) {
        s21_clear_bit(&result, iter);
        remembered_bit = 1;
      } else {
        s21_set_bit(&result, iter);
      }
    } else {
      if (remembered_bit == 1) {
        s21_set_bit(&result, iter);
        remembered_bit = 1;
      } else {
        s21_clear_bit(&result, iter);
        remembered_bit = 1;
      }
    }

    if (iter == 95 && remembered_bit == 1) result.value_type = INF;
  }

  return result;
}

void s21_mantisses_subtraction(s21_decimal src_1, s21_decimal src_2,
                               s21_decimal *result) {
  s21_init_decimal(result);

  if (s21_is_equal(src_1, src_2) == 0) {
    int src_1_last_bit = s21_index_of_elder_significant_bit(src_1);
    int remembered_bit = 0;
    for (int iter = 0; iter <= src_1_last_bit; iter++) {
      int src_1_bit = s21_get_bit(src_1, iter);
      int src_2_bit = s21_get_bit(src_2, iter);

      if (src_1_bit == 0 && src_2_bit == 0) {
        if (remembered_bit == 1) {
          remembered_bit = 1;
          s21_set_bit(result, iter);
        } else {
          s21_clear_bit(result, iter);
        }
      } else if (src_1_bit == 1 && src_2_bit == 0) {
        if (remembered_bit == 1) {
          remembered_bit = 0;
          s21_clear_bit(result, iter);
        } else {
          s21_set_bit(result, iter);
        }
      } else if (src_1_bit == 0 && src_2_bit == 1) {
        if (remembered_bit == 1) {
          remembered_bit = 1;
          s21_clear_bit(result, iter);
        } else {
          remembered_bit = 1;
          s21_set_bit(result, iter);
        }
      } else if (src_1_bit == 1 && src_2_bit == 1) {
        if (remembered_bit == 1) {
          remembered_bit = 1;
          s21_set_bit(result, iter);
        } else {
          s21_clear_bit(result, iter);
        }
      }
    }
  }
}

s21_decimal s21_mantisses_division(s21_decimal src_1, s21_decimal src_2,
                                   s21_decimal *rest_decimal) {
  s21_decimal result;
  s21_init_decimal(rest_decimal);
  s21_init_decimal(&result);
  int iter = s21_index_of_elder_significant_bit(src_1);
  for (; iter >= 0; iter--) {
    if (s21_get_bit(src_1, iter)) s21_set_bit(rest_decimal, 0);
    if (s21_is_greater_or_equal(*rest_decimal, src_2) == true) {
      s21_mantisses_subtraction(*rest_decimal, src_2, rest_decimal);
      if (iter != 0) s21_left_shift(rest_decimal);
      if (s21_get_bit(src_1, iter - 1)) s21_set_bit(rest_decimal, 0);
      s21_left_shift(&result);
      s21_set_bit(&result, 0);
    } else {
      s21_left_shift(&result);
      if (iter != 0) s21_left_shift(rest_decimal);
      if ((iter - 1) >= 0 && s21_get_bit(src_1, iter - 1))
        s21_set_bit(rest_decimal, 0);
    }
  }
  return result;
}

int s21_comparison_value_bits(s21_decimal decimal_1, s21_decimal decimal_2) {
  int result = -1;
  for (int iter = 95, break_flag = 1; iter >= 0 && break_flag != 0; iter--) {
    int bit_decimal_1 = s21_get_bit(decimal_1, iter);
    int bit_decimal_2 = s21_get_bit(decimal_2, iter);
    if (!bit_decimal_1 && bit_decimal_2) {
      result = true;
      break_flag = 0;
    } else if (bit_decimal_1 && !bit_decimal_2) {
      result = false;
      break_flag = 0;
    } else
      continue;
  }
  return result;
}

int s21_is_correct_decimal(s21_decimal decimal) {
  int error = 1;
  int scale_decimal = s21_get_scale(decimal);

  if (s21_get_bit(decimal, 102) != 0 || s21_get_bit(decimal, 111) != 0)
    error = 0;
  else if (scale_decimal < 0 || scale_decimal > 28)
    error = 0;

  return error;
}