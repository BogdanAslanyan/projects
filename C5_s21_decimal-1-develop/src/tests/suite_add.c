#include "test_decimal.h"

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal dec1, dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_12) {
  s21_decimal dec1, dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = -100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_13) {
  s21_decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_14) {
  s21_decimal dec1, dec2;
  dec1.bits[3] = 0x300000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xF;
  dec1.bits[0] = 0x67E4FEEF;
  dec2.bits[3] = 0x300000;
  dec2.bits[2] = 0;
  dec2.bits[1] = 0xFF;
  dec2.bits[0] = 0x67E4FFFF;
  s21_decimal res;
  res.bits[3] = 0x300000;
  res.bits[2] = 0;
  res.bits[1] = 0x10E;
  res.bits[0] = 0xCFC9FEEE;
  s21_decimal res1;
  s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(res.bits[3], res1.bits[3]);
  ck_assert_int_eq(res.bits[2], res1.bits[2]);
  ck_assert_int_eq(res.bits[1], res1.bits[1]);
  ck_assert_int_eq(res.bits[0], res1.bits[0]);
}
END_TEST

START_TEST(add_test_15) {
  s21_decimal dec1, dec2;
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_16) {
  int tmp1 = 4294967295;
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}, 0};
  s21_decimal dec2 = {{1, 0, 0, 0}, 0};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(add_test_17) {
  int tmp1 = 4294967295;
  float tmp2 = pow(2, 31);
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}, 0};
  s21_decimal dec2 = {{1, 0, 0, tmp2}, 0};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(add_test_18) {
  s21_decimal val1 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_19) {
  s21_decimal val1 = {{15, 0, 0, 0}, 0};
  s21_decimal val2 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_20) {
  s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal val2 = {{1, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_21) {
  s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_22) {
  s21_decimal val1 = {{8, 0, 0, 0}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_23) {
  s21_decimal val1 = {{2, 0, 0, 0}, 0};
  s21_decimal val2 = {{8, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_24) {
  s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{2, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_25) {
  s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{8, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_26) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_27) {
  s21_decimal val1 = {{4, 0, 0, 0}, 0};
  s21_decimal val2 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_28) {
  s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_29) {
  s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{4, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_30) {
  s21_decimal val1 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_31) {
  s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_32) {
  s21_decimal val1 = {{4, 0, 0, 0}, 0};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_33) {
  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_34) {
  s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal val2 = {
      {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_test_35) {
  s21_decimal c = {{5, 0, 0, 0}, 0};
  s21_decimal d = {{5, 0, 0, 0}, 0};
  s21_decimal etalon = {{10, 0, 0, 0}, 0};
  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;
  // 0 - OK 1 - число слишком велико или равно бесконечности
  // 2 - число слишком мало или равно отрицательной бесконечности
  // 3 - деление на 0
  int add = s21_add(c, d, p_res);
  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_36) {
  s21_decimal c = {{100, 0, 0, 0}, 0};
  s21_decimal d = {{100, 0, 0, 0}, 0};
  s21_decimal etalon = {{100, 0, 0, 0}, 0};
  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;
  // 0 - OK 1 - число слишком велико или равно бесконечности
  // 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(add_test_37) {
  s21_decimal c = {{2147483647, 0, 0, 0}, 0};
  s21_decimal d = {{2147483647, 0, 0, 0}, 0};
  s21_decimal etalon = {{4294967294, 0, 0, 0}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal* p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_38) {
  s21_decimal c = {{1000, 0, 0, 0}, 0};
  s21_decimal d = {{1000, 0, 0, 0}, 0};
  s21_decimal etalon = {{2000, 0, 0, 0}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal* p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_39) {
  s21_decimal c = {{1000, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1000, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, 0}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal* p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_40) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal* p_result = &result;
  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_41) {
  s21_decimal c = {{0, 0, 0, 0}, 0};
  s21_decimal d = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_42) {
  s21_decimal c = {{1, 0, 0, 0}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{2, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_43) {
  s21_decimal c = {{1000, 0, 0, 0}, 0};
  s21_decimal d = {{1000, 0, 0, 0}, 0};
  s21_decimal etalon = {{2000, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_44) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal d = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal etalon = {{4294967294, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_45) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal d = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_46) {
  s21_decimal c = {{UINT32_MAX, 0, 0, 0}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 1, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_47) {
  s21_decimal c = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  s21_decimal d = {{0, 1, 0, 0}, 0};
  s21_decimal etalon = {{0, S21_MAX_UINT, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_48) {
  s21_decimal c = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  s21_decimal d = {{0, 0, 1, 0}, 0};
  s21_decimal etalon = {{0, 0, S21_MAX_UINT, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_49) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_50) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_51) {  // -1 + (-1) = -2
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_52) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_53) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_54) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_55) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_56) {
  s21_decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_57) {
  s21_decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_58) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}, 0};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_59) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0},
                   0};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0},
                        0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_60) {
  s21_decimal c = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 1, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_61) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000},
      0};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}, 0};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000},
      0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_62) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;

  s21_decimal result = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &result;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(src1, src2, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = s21_is_equal(
      result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_63) {
  s21_decimal c = {{0, 0, 0, 0}, 0};
  s21_decimal d = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_64) {
  s21_decimal c = {{1, 0, 0, 0}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{2, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_65) {
  s21_decimal c = {{1000, 0, 0, 0}, 0};
  s21_decimal d = {{1000, 0, 0, 0}, 0};
  s21_decimal etalon = {{2000, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_66) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal d = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal etalon = {{4294967294, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_67) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal d = {{INT_MAX, 0, 0, 0}, 0};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_68) {
  s21_decimal c = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 1, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_69) {
  s21_decimal c = {{0, S21_MAX_UINT - 1, 0, 0}, 0};
  s21_decimal d = {{0, 1, 0, 0}, 0};
  s21_decimal etalon = {{0, S21_MAX_UINT, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_70) {
  s21_decimal c = {{0, 0, S21_MAX_UINT - 1, 0}, 0};
  s21_decimal d = {{0, 0, 1, 0}, 0};
  s21_decimal etalon = {{0, 0, S21_MAX_UINT, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_71) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_72) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_73) {  // -1 + (-1) = -2
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_74) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{11, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_75) {
  s21_decimal c = {{11, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{21, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_76) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_1}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};

  s21_decimal etalon = {{121, 0, 0, EXPONENT_PLUS_1}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_77) {
  s21_decimal c = {{111, 0, 0, EXPONENT_PLUS_2}, 0};
  s21_decimal d = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{1111, 0, 0, EXPONENT_PLUS_2}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_78) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}, 0};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_79) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0},
                   0};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0},
                        0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_80) {
  s21_decimal c = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}, 0};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 1, 0}, 0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_81) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000},
      0};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}, 0};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000},
      0};

  s21_decimal res = {{0, 0, 0, 0}, 0};
  s21_decimal* p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком
  // мало или равно отрицательной бесконечности 3 - деление на 0
  int equal =
      s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(add_test_82) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(add_test_83) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(add_test_84) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(add_test_85) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(add_test_86) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b00000000000000000000001111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000001111111111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b00000000000000000010101111110101;
  original_res.bits[1] = 0b00000000000000000000000000000000;
  original_res.bits[2] = 0b00000000000000000000000000000000;
  original_res.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

Suite* suite_add(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("\033[42m  S21_ADD  \033[0m");
  tc = tcase_create("case_add");

  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_4);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_12);
  tcase_add_test(tc, add_test_13);
  tcase_add_test(tc, add_test_14);
  tcase_add_test(tc, add_test_15);
  tcase_add_test(tc, add_test_16);
  tcase_add_test(tc, add_test_17);
  tcase_add_test(tc, add_test_18);
  tcase_add_test(tc, add_test_19);
  tcase_add_test(tc, add_test_20);
  tcase_add_test(tc, add_test_21);
  tcase_add_test(tc, add_test_22);
  tcase_add_test(tc, add_test_23);
  tcase_add_test(tc, add_test_24);
  tcase_add_test(tc, add_test_25);
  tcase_add_test(tc, add_test_26);
  tcase_add_test(tc, add_test_27);
  tcase_add_test(tc, add_test_28);
  tcase_add_test(tc, add_test_29);
  tcase_add_test(tc, add_test_30);
  tcase_add_test(tc, add_test_31);
  tcase_add_test(tc, add_test_32);
  tcase_add_test(tc, add_test_33);
  tcase_add_test(tc, add_test_34);
  tcase_add_test(tc, add_test_35);
  tcase_add_test(tc, add_test_36);
  tcase_add_test(tc, add_test_37);
  tcase_add_test(tc, add_test_38);
  tcase_add_test(tc, add_test_39);
  tcase_add_test(tc, add_test_40);
  tcase_add_test(tc, add_test_41);
  tcase_add_test(tc, add_test_42);
  tcase_add_test(tc, add_test_43);
  tcase_add_test(tc, add_test_44);
  tcase_add_test(tc, add_test_45);
  tcase_add_test(tc, add_test_46);
  tcase_add_test(tc, add_test_47);
  tcase_add_test(tc, add_test_48);
  tcase_add_test(tc, add_test_49);
  tcase_add_test(tc, add_test_50);
  tcase_add_test(tc, add_test_51);
  tcase_add_test(tc, add_test_52);
  tcase_add_test(tc, add_test_53);
  tcase_add_test(tc, add_test_54);
  tcase_add_test(tc, add_test_55);
  tcase_add_test(tc, add_test_56);
  tcase_add_test(tc, add_test_57);
  tcase_add_test(tc, add_test_58);
  tcase_add_test(tc, add_test_59);
  tcase_add_test(tc, add_test_60);
  tcase_add_test(tc, add_test_61);
  tcase_add_test(tc, add_test_62);
  tcase_add_test(tc, add_test_63);
  tcase_add_test(tc, add_test_64);
  tcase_add_test(tc, add_test_65);
  tcase_add_test(tc, add_test_66);
  tcase_add_test(tc, add_test_67);
  tcase_add_test(tc, add_test_68);
  tcase_add_test(tc, add_test_69);
  tcase_add_test(tc, add_test_70);
  tcase_add_test(tc, add_test_71);
  tcase_add_test(tc, add_test_72);
  tcase_add_test(tc, add_test_73);
  tcase_add_test(tc, add_test_74);
  tcase_add_test(tc, add_test_75);
  tcase_add_test(tc, add_test_76);
  tcase_add_test(tc, add_test_77);
  tcase_add_test(tc, add_test_78);
  tcase_add_test(tc, add_test_79);
  tcase_add_test(tc, add_test_80);
  tcase_add_test(tc, add_test_81);
  tcase_add_test(tc, add_test_82);
  tcase_add_test(tc, add_test_83);
  tcase_add_test(tc, add_test_84);
  tcase_add_test(tc, add_test_85);
  tcase_add_test(tc, add_test_86);

  suite_add_tcase(s, tc);
  return s;
}
