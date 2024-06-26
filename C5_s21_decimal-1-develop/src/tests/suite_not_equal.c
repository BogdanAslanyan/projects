#include "test_decimal.h"

START_TEST(not_equal_test_1) {
  // float num1 = 1.375342323523;
  // float num2 = 1.39;
  s21_decimal dec1 = {{952788803, 320, 0, 2148204544}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_test_2) {
  // float num1 = 1.39;
  // float num2 = 1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(not_equal_test_3) {
  // float num1 = 1.39;
  // float num2 = -1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 2147614720}, 0};
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_test_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(not_equal_test_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(not_equal_test_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(not_equal_test_7) {
  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000},
                      0};  // -1.2;
  ck_assert_int_eq(s21_is_not_equal(dec1, dec2), 1);

  s21_decimal dec3 = {{120000, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  12.0000
  s21_decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}, 0};  //
  ck_assert_int_eq(s21_is_not_equal(dec3, dec4), 0);

  s21_decimal dec5 = {{0, 0, 0, 0b00000000000000000000000000000000}, 0};  //  0
  s21_decimal dec6 = {{0, 0, 0, 0b00000000000000010000000000000000}, 0};  //
  ck_assert_int_eq(s21_is_not_equal(dec5, dec6), 0);

  s21_decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}, 0};  //   0
  s21_decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000},
                      0};  //  -0;
  ck_assert_int_eq(s21_is_not_equal(dec7, dec8), 1);
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_IS_NOT_EQUAL  \033[0m");
  tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, not_equal_test_1);
  tcase_add_test(tc, not_equal_test_2);
  tcase_add_test(tc, not_equal_test_3);
  tcase_add_test(tc, not_equal_test_4);
  tcase_add_test(tc, not_equal_test_5);
  tcase_add_test(tc, not_equal_test_6);
  tcase_add_test(tc, not_equal_test_7);

  suite_add_tcase(s, tc);
  return s;
}
