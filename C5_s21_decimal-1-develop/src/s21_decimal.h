#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;
typedef enum { LOW, MID, HIGH, SCALE, AMOUNT } bits;
typedef enum { NORMAL, INF, NEG_INF, NaN, ADD_CODE } value_type_t;
typedef enum { SUCCESS, ERROR } exit_func_status;

typedef struct {
  unsigned int bits[AMOUNT];
  value_type_t value_type;
} s21_decimal;

#define MAX_CONVERT 7.9228162514264337593543950335e28F
#define MIN_CONVERT 1.000000003e-28F
#define PRECISION 1000000.0
#define EXC_INF 1.0 / 0.0

/* Arithmetic operations */

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/* Converters */

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/* Comparative functions */

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_not_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_less_or_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_greater_or_equal(s21_decimal decimal_1, s21_decimal decimal_2);

/* Other functions */

int s21_negate(s21_decimal src, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
/* SECONDARY FUNCTIONS */

void s21_init_decimal(s21_decimal *src);

/* bit operations */
int s21_get_bit(s21_decimal src, int index);
bool s21_set_bit(s21_decimal *src, int index);
bool s21_clear_bit(s21_decimal *src, int index);
int s21_get_scale(s21_decimal src);
void s21_set_scale(s21_decimal *src, int scale);
void s21_clear_scale(s21_decimal *src);
int s21_get_sign(s21_decimal src);
void s21_set_positive_sign(s21_decimal *src);
void s21_set_negative_sign(s21_decimal *src);

/* check decimal status */
int s21_is_mantissa_zeros(s21_decimal src);
int s21_is_decimal_zeros(s21_decimal src_1, s21_decimal src_2);

/* other functions */
int s21_is_correct_decimal(s21_decimal decimal);
int s21_index_of_elder_significant_bit(s21_decimal src);
int s21_left_shift(s21_decimal *value);
int s21_left_shift_n(s21_decimal *src, int shift_index);

void s21_decimal_normalization(s21_decimal *src_1, s21_decimal *src_2);
s21_decimal s21_mantisses_addition(s21_decimal *src_1, s21_decimal *src_2);
void s21_mantisses_subtraction(s21_decimal src_1, s21_decimal src_2,
                               s21_decimal *result);
s21_decimal s21_mantisses_division(s21_decimal src_1, s21_decimal src_2,
                                   s21_decimal *rest_decimal);
int s21_mantisses_multi(s21_decimal decimal_1, s21_decimal decimal_2,
                        s21_decimal *result);

int s21_comparison_value_bits(s21_decimal value1, s21_decimal value2);

s21_decimal decimal_to_infinity(void);

int s21_is_decimal_inf(s21_decimal src_1, s21_decimal src_2);
int s21_is_decimal_nan(s21_decimal src_1, s21_decimal src_2);
#endif  // SRC_S21_DECIMAL_H_