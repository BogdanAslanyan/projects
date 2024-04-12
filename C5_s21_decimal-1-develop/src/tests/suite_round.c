#include "test_decimal.h"

START_TEST(round_test_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
  dec1.bits[1] = 0b00000000001111111111111111111111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal result;

  result.bits[0] = 0b01001101110100101111000110101001;  // 18014398509481
  result.bits[1] = 0b00000000000000000001000001100010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000011110111001001110100;  // -10123.40
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000110000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000001111110100;  // -1012
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_3) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
  dec1.bits[1] = 0b00000000000001000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_5) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01100011000011111111111111111111;
  dec1.bits[1] = 0b01101011110001110101111000101101;
  dec1.bits[2] = 0b00000000000000000000000000000101;
  dec1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b01010100000010111110010000000000;
  result.bits[1] = 0b00000000000000000000000000000010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_6) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11001101110001110111110001000000;
  dec1.bits[1] = 0b00111110001001010000001001100000;
  dec1.bits[2] = 0b00100000010011111100111001011110;
  dec1.bits[3] = 0b10000000000001000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10100000111111100100111000000100;
  result.bits[1] = 0b00011011110011101100110011101101;
  result.bits[2] = 0b00000000000000001101001111000010;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_7) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_8) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round_test_9) {
  s21_decimal a = {{15, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{2, 0, 0, 0}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_round(a, ptr_b);  // a записываем в b по
  ck_assert_int_eq(add, CONVERTERS_S21_TRUE);  // выходное

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
}
END_TEST

START_TEST(round_test_10) {
  s21_decimal a = {{111111, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{11111, 0, 0, 0}, 0};  // ожидаемое значение
  s21_decimal* ptr_etalon = &etalon;
  s21_set_scale(ptr_etalon, 0);  // ставим степень

  s21_decimal b = {{0, 0, 0, 0}, 0};  // записываем сюда результат
  s21_decimal* ptr_b = &b;

  s21_round(a, ptr_b);
  // ck_assert_int_eq(add, S21_TRUE);  // выходное значение s21_round - 0

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
}
END_TEST

START_TEST(round_test_11) {
  s21_decimal a = {{111111, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{11111, 0, 0, 0}, 0};  // ожидаемое значение
  s21_decimal* ptr_etalon = &etalon;
  s21_set_scale(ptr_etalon, 0);  // ставим степень

  s21_decimal b = {{0, 0, 0, 0}, 0};  // записываем сюда результат
  s21_decimal* ptr_b = &b;

  s21_round(a, ptr_b);
  // ck_assert_int_eq(add, S21_TRUE);  // выходное значение s21_round - 0

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(round_test_12) {
  s21_decimal num = {{149, 0, 0, 131072}, NORMAL};
  s21_decimal res = {{1, 0, 0, 0}, NORMAL};
  int error = 0;
  error = s21_round(num, &num);
  ck_assert_int_eq(num.bits[0], res.bits[0]);
  ck_assert_int_eq(num.bits[1], res.bits[1]);
  ck_assert_int_eq(num.bits[2], res.bits[2]);
  ck_assert_int_eq(num.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(round_test_13) {
  s21_decimal a = {{111111, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{11111, 0, 0, 0}, 0};  // ожидаемое значение
  s21_decimal* ptr_etalon = &etalon;
  s21_set_scale(ptr_etalon, 0);  // ставим степень

  s21_decimal b = {{0, 0, 0, 0}, 0};  // записываем сюда результат
  s21_decimal* ptr_b = &b;

  s21_round(a, ptr_b);
  // ck_assert_int_eq(add, S21_TRUE);  // выходное значение s21_round - 0

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(round_test_14) {
  s21_decimal a = {{111111, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{11111, 0, 0, 0}, 0};  // ожидаемое значение
  s21_decimal* ptr_etalon = &etalon;
  s21_set_scale(ptr_etalon, 0);  // ставим степень

  s21_decimal b = {{0, 0, 0, 0}, 0};  // записываем сюда результат
  s21_decimal* ptr_b = &b;

  s21_round(a, ptr_b);
  // ck_assert_int_eq(add, S21_TRUE);  // выходное значение s21_round - 0

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(round_test_15) {
  s21_decimal a = {{111111, 0, 0, 0}, 0};
  s21_decimal* ptr_a = &a;
  s21_set_scale(ptr_a, 1);  // ставим степень

  s21_decimal etalon = {{11111, 0, 0, 0}, 0};  // ожидаемое значение
  s21_decimal* ptr_etalon = &etalon;
  s21_set_scale(ptr_etalon, 0);  // ставим степень

  s21_decimal b = {{0, 0, 0, 0}, 0};  // записываем сюда результат
  s21_decimal* ptr_b = &b;

  s21_round(a, ptr_b);
  // ck_assert_int_eq(add, S21_TRUE);  // выходное значение s21_round - 0

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(b.bits[0], etalon.bits[0]);
  ck_assert_int_eq(b.bits[1], etalon.bits[1]);
  ck_assert_int_eq(b.bits[2], etalon.bits[2]);
  ck_assert_int_eq(b.bits[3], etalon.bits[3]);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(round_test_16) {
  s21_decimal val = {{7, 7, 7, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_17) {
  s21_decimal val = {{3, 3, 3, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_18) {
  s21_decimal val = {{3, 3, 3, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_19) {
  s21_decimal val = {{7, 7, 7, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_20) {
  s21_decimal val = {{25, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_21) {
  s21_decimal val = {{26, 0, 0, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_22) {
  s21_decimal val = {{115, 0, 0, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_23) {
  s21_decimal val = {{118, 0, 0, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_24) {
  s21_decimal val = {{125, 0, 0, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_25) {
  s21_decimal val = {{128, 0, 0, 0}, 0};
  s21_decimal res = {0};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_test_26) {
  // 8053
  s21_decimal src1, origin;
  // src1 = 2;

  src1.bits[0] = 2;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 2;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_27) {
  // 8074
  s21_decimal src1, origin;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_28) {
  // 8095
  s21_decimal src1, origin;
  // src1 = -3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_29) {
  // 8116
  s21_decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_30) {
  // 8137
  s21_decimal src1, origin;
  // src1 = -9878798789;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_31) {
  // 8158
  s21_decimal src1, origin;
  // src1 = -545454512454545.35265;

  src1.bits[0] = 0b11011110101101001010101001100001;
  src1.bits[1] = 0b11110100111110000101111011101001;
  src1.bits[2] = 0b00000000000000000000000000000010;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_32) {
  // 8179
  s21_decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[0] = 0b00000111100110110001111110011000;
  src1.bits[1] = 0b01100110010010001001000110100011;
  src1.bits[2] = 0b00000000000001001000101100011101;
  src1.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_33) {
  // 8221
  s21_decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[0] = 0b01111000100010101111010011001010;
  src1.bits[1] = 0b01100010000010101110010010000111;
  src1.bits[2] = 0b00100111111001000001101011010101;
  src1.bits[3] = 0b10000000000101010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(round_test_34) {
  // 8263
  s21_decimal src1, origin;
  // src1 = 1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_round(src1, &result);
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite* suite_round(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("\033[42m  S21_ROUND  \033[0m");
  tc = tcase_create("case_round");

  tcase_add_test(tc, round_test_1);
  tcase_add_test(tc, round_test_2);
  tcase_add_test(tc, round_test_3);
  tcase_add_test(tc, round_test_4);
  tcase_add_test(tc, round_test_5);
  tcase_add_test(tc, round_test_6);
  tcase_add_test(tc, round_test_7);
  tcase_add_test(tc, round_test_8);
  tcase_add_test(tc, round_test_9);
  tcase_add_test(tc, round_test_10);
  tcase_add_test(tc, round_test_11);
  tcase_add_test(tc, round_test_12);
  tcase_add_test(tc, round_test_13);
  tcase_add_test(tc, round_test_14);
  tcase_add_test(tc, round_test_15);
  tcase_add_test(tc, round_test_16);
  tcase_add_test(tc, round_test_17);
  tcase_add_test(tc, round_test_18);
  tcase_add_test(tc, round_test_19);
  tcase_add_test(tc, round_test_20);
  tcase_add_test(tc, round_test_21);
  tcase_add_test(tc, round_test_22);
  tcase_add_test(tc, round_test_23);
  tcase_add_test(tc, round_test_24);
  tcase_add_test(tc, round_test_25);
  tcase_add_test(tc, round_test_26);
  tcase_add_test(tc, round_test_27);
  tcase_add_test(tc, round_test_28);
  tcase_add_test(tc, round_test_29);
  tcase_add_test(tc, round_test_30);
  tcase_add_test(tc, round_test_31);
  tcase_add_test(tc, round_test_32);
  tcase_add_test(tc, round_test_33);
  tcase_add_test(tc, round_test_34);

  suite_add_tcase(s, tc);
  return s;
}
