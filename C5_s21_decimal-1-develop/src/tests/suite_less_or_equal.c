#include "test_decimal.h"

START_TEST(test_is_less_or_equal_1) {
  // float num1 = 1.375342323523;
  // float num2 = 1.39;
  s21_decimal dec1 = {{952788803, 320, 0, 2148204544}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
  // float num1 = 1.39;
  // float num2 = 1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
  // float num1 = 1.39;
  // float num2 = -1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 2147614720}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_7) {
  // float num1 = -3453434.232446543232446543;
  // float num2 = -3.232323233232323233;
  s21_decimal dec1 = {{3796893695, 192705379, 187211, 2148663296}, 0};
  s21_decimal dec2 = {{3826123425, 752583898, 0, 2148663296}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_8) {
  // float num1 = -34534553434.232446543232446543;
  // float num2 = 34534553434.232446543232446543;

  s21_decimal dec1 = {{4294967295, 4125650346, 1872121892, 2148663296}, 0};
  s21_decimal dec2 = {{4294967295, 4125650346, 1872121892, 1179648}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_9) {
  // float num1 = 1.78;
  // float num2 = 1.39;
  s21_decimal dec1 = {{178, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_10) {
  // float num1 = -3453453452.0;
  // float num2 = -34.0;
  s21_decimal dec1 = {{174796152, 8, 0, 2147549184}, 0};
  s21_decimal dec2 = {{340, 0, 0, 2147549184}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST
START_TEST(test_is_less_or_equal_11) {
  // float num1 = 104235454634.34534534;
  // float num2 = 1042354546.34534534;

  s21_decimal dec1 = {{1747345031, 2426920799, 0, 524288}, 0};
  s21_decimal dec2 = {{4269680262, 24269207, 0, 524288}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_12) {
  // float num1 = 1042354546.34534534;
  // float num2 = 104235454634.345345;

  s21_decimal dec1 = {{4269680262, 24269207, 0, 524288}, 0};
  s21_decimal dec2 = {{4269491073, 24269207, 0, 393216}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_13) {
  // float num1 = 1042.5667777;
  // float num2 = 1042.345345;
  s21_decimal dec1 = {{1835733185, 2, 0, 458752}, 0};
  s21_decimal dec2 = {{1042345345, 0, 0, 393216}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_17) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_18) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_19) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_20) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_21) {
  // float num1 = 104232346.34534534;
  // float num2 = 3.3453453234;

  s21_decimal dec1 = {{4269680262, 24269207, 0, 524288}, 0};
  s21_decimal dec2 = {{3388682162, 7, 0, 655360}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(test_is_less_or_equal_22) {
  // float num1 = -3.34534534;
  // float num2 = 3.34534534;
  s21_decimal dec1 = {{334534534, 7, 0, 2148007936}, 0};
  s21_decimal dec2 = {{334534534, 7, 0, 524288}, 0};
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_23) {
  s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000},
                      0};  // -1.2;
  ck_assert_int_eq(s21_is_less_or_equal(dec5, dec6), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dec6, dec5), 1);

  s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000},
                      0};  //  1.2;
  ck_assert_int_eq(s21_is_less_or_equal(dec7, dec8), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec8, dec7), 0);

  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000},
                      0};  //  1.2;
  ck_assert_int_eq(s21_is_less_or_equal(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dec2, dec1), 1);

  s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000},
                      0};  //  -1.2;
  ck_assert_int_eq(s21_is_less_or_equal(dec3, dec4), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec4, dec3), 0);

  s21_decimal dec9 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec10 = {{12345, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec10, dec9), 1);

  s21_decimal dec11 = {{0, 0, 0, 0}, 0};
  s21_decimal dec12 = {{0, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec12, dec11), 1);
}
END_TEST

START_TEST(test_is_less_or_equal_24) {
  s21_decimal a = {{1, 0, 0, 0}, 0};
  s21_decimal b = {{1, 0, 0, 0}, 0};
  ck_assert_int_eq(
      s21_is_less_or_equal(a, b),
      S21_TRUE);  // Возвращаемое значение : 0 - FALSE   1 - S21_TRUE
}
END_TEST

START_TEST(test_is_less_or_equal_25) {
  s21_decimal a = {{1, 0, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_26) {
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_27) {
  s21_decimal a = {{S21_MAX_UINT - 1, 0, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_28) {
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, 1, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_29) {
  s21_decimal a = {{S21_MAX_UINT, 1, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, 1, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_30) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT - 1, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_31) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_32) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_33) {
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT - 1, 0}, 0};
  s21_decimal b = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_34) {
  s21_decimal a = {{0, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal b = {{0, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_35) {
  s21_decimal a = {{0, 0, S21_MAX_UINT, 0}, 0};
  s21_decimal b = {{0, 0, S21_MAX_UINT, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_36) {
  s21_decimal a = {{0, 0, 0, 0}, 0};
  s21_decimal b = {{0, 0, S21_MAX_UINT, 0}, 0};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), S21_TRUE);
}
END_TEST

START_TEST(test_is_less_or_equal_37) {
  // 2596
  s21_decimal src1, src2;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_38) {
  // 3172
  s21_decimal src1, src2;
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_39) {
  // 3190
  s21_decimal src1, src2;
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_40) {
  // 3208
  s21_decimal src1, src2;
  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_41) {
  // 3226
  s21_decimal src1, src2;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_42) {
  // 3244
  s21_decimal src1, src2;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_43) {
  // 3262
  s21_decimal src1, src2;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_44) {
  // 3280
  s21_decimal src1, src2;
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_45) {
  // 3298
  s21_decimal src1, src2;
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_46) {
  // 3316
  s21_decimal src1, src2;
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_47) {
  // 3334
  s21_decimal src1, src2;
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_48) {
  // 3352
  s21_decimal src1, src2;
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_49) {
  // 3370
  s21_decimal src1, src2;
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_50) {
  // 3388
  s21_decimal src1, src2;
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_51) {
  // 3406
  s21_decimal src1, src2;
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_52) {
  // 3424
  s21_decimal src1, src2;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_53) {
  // 3442
  s21_decimal src1, src2;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_54) {
  // 3478
  s21_decimal src1, src2;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_55) {
  // 3496
  s21_decimal src1, src2;
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_56) {
  // 3514
  s21_decimal src1, src2;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_57) {
  // 3532
  s21_decimal src1, src2;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_58) {
  // 3550
  s21_decimal src1, src2;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_59) {
  // 3568
  s21_decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_60) {
  // 3586
  s21_decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_61) {
  // 3604
  s21_decimal src1, src2;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_62) {
  // 3622
  s21_decimal src1, src2;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_63) {
  // 3640
  s21_decimal src1, src2;
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_64) {
  // 3658
  s21_decimal src1, src2;
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_65) {
  // 3676
  s21_decimal src1, src2;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_66) {
  // 3694
  s21_decimal src1, src2;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_67) {
  // 3712
  s21_decimal src1, src2;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_68) {
  // 3730
  s21_decimal src1, src2;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_69) {
  // 3748
  s21_decimal src1, src2;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_70) {
  // 3766
  s21_decimal src1, src2;
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_71) {
  // 3784
  s21_decimal src1, src2;
  // src1 = -784515454.7989898652154545652;
  // src2 = -579895323215489956.67897455465;

  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(test_is_less_or_equal_72) {
  // 3802
  s21_decimal src1, src2;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_IS_LESS_OR_EQUAL  \033[0m");
  tc = tcase_create("case_less_or_equal");

  tcase_add_test(tc, test_is_less_or_equal_1);
  tcase_add_test(tc, test_is_less_or_equal_2);
  tcase_add_test(tc, test_is_less_or_equal_3);
  tcase_add_test(tc, test_is_less_or_equal_4);
  tcase_add_test(tc, test_is_less_or_equal_5);
  tcase_add_test(tc, test_is_less_or_equal_6);
  tcase_add_test(tc, test_is_less_or_equal_7);
  tcase_add_test(tc, test_is_less_or_equal_8);
  tcase_add_test(tc, test_is_less_or_equal_9);
  tcase_add_test(tc, test_is_less_or_equal_10);
  tcase_add_test(tc, test_is_less_or_equal_11);
  tcase_add_test(tc, test_is_less_or_equal_12);
  tcase_add_test(tc, test_is_less_or_equal_13);
  tcase_add_test(tc, test_is_less_or_equal_17);
  tcase_add_test(tc, test_is_less_or_equal_18);
  tcase_add_test(tc, test_is_less_or_equal_19);
  tcase_add_test(tc, test_is_less_or_equal_20);
  tcase_add_test(tc, test_is_less_or_equal_21);
  tcase_add_test(tc, test_is_less_or_equal_22);
  tcase_add_test(tc, test_is_less_or_equal_23);
  tcase_add_test(tc, test_is_less_or_equal_24);
  tcase_add_test(tc, test_is_less_or_equal_25);
  tcase_add_test(tc, test_is_less_or_equal_26);
  tcase_add_test(tc, test_is_less_or_equal_27);
  tcase_add_test(tc, test_is_less_or_equal_28);
  tcase_add_test(tc, test_is_less_or_equal_29);
  tcase_add_test(tc, test_is_less_or_equal_30);
  tcase_add_test(tc, test_is_less_or_equal_31);
  tcase_add_test(tc, test_is_less_or_equal_32);
  tcase_add_test(tc, test_is_less_or_equal_33);
  tcase_add_test(tc, test_is_less_or_equal_34);
  tcase_add_test(tc, test_is_less_or_equal_35);
  tcase_add_test(tc, test_is_less_or_equal_36);
  tcase_add_test(tc, test_is_less_or_equal_37);
  tcase_add_test(tc, test_is_less_or_equal_38);
  tcase_add_test(tc, test_is_less_or_equal_39);
  tcase_add_test(tc, test_is_less_or_equal_40);
  tcase_add_test(tc, test_is_less_or_equal_41);
  tcase_add_test(tc, test_is_less_or_equal_42);
  tcase_add_test(tc, test_is_less_or_equal_43);
  tcase_add_test(tc, test_is_less_or_equal_44);
  tcase_add_test(tc, test_is_less_or_equal_45);
  tcase_add_test(tc, test_is_less_or_equal_46);
  tcase_add_test(tc, test_is_less_or_equal_47);
  tcase_add_test(tc, test_is_less_or_equal_48);
  tcase_add_test(tc, test_is_less_or_equal_49);
  tcase_add_test(tc, test_is_less_or_equal_50);
  tcase_add_test(tc, test_is_less_or_equal_51);
  tcase_add_test(tc, test_is_less_or_equal_52);
  tcase_add_test(tc, test_is_less_or_equal_53);
  tcase_add_test(tc, test_is_less_or_equal_54);
  tcase_add_test(tc, test_is_less_or_equal_55);
  tcase_add_test(tc, test_is_less_or_equal_56);
  tcase_add_test(tc, test_is_less_or_equal_57);
  tcase_add_test(tc, test_is_less_or_equal_58);
  tcase_add_test(tc, test_is_less_or_equal_59);
  tcase_add_test(tc, test_is_less_or_equal_60);
  tcase_add_test(tc, test_is_less_or_equal_61);
  tcase_add_test(tc, test_is_less_or_equal_62);
  tcase_add_test(tc, test_is_less_or_equal_63);
  tcase_add_test(tc, test_is_less_or_equal_64);
  tcase_add_test(tc, test_is_less_or_equal_65);
  tcase_add_test(tc, test_is_less_or_equal_66);
  tcase_add_test(tc, test_is_less_or_equal_67);
  tcase_add_test(tc, test_is_less_or_equal_68);
  tcase_add_test(tc, test_is_less_or_equal_69);
  tcase_add_test(tc, test_is_less_or_equal_70);
  tcase_add_test(tc, test_is_less_or_equal_71);
  tcase_add_test(tc, test_is_less_or_equal_72);

  suite_add_tcase(s, tc);
  return s;
}
