#include "test_decimal.h"

START_TEST(less_test_1) {
  // float num1 = 1.375342323523;
  // float num2 = 1.39;
  s21_decimal dec1 = {{952788803, 320, 0, 2148204544}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(less_test_2) {
  // float num1 = 1.39;
  // float num2 = 1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(less_test_3) {
  // float num1 = 1.39;
  // float num2 = -1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 2147614720}, 0};
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(less_test_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(less_test_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(less_test_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(less_test_7) {
  // float num1 = -34534534.232446543232446543;
  // float num2 = -3.232323233232323233;

  s21_decimal dec1 = {{889192447, 3659439603, 1872120, 2148663296}, 0};
  s21_decimal dec2 = {{3826123425, 752583898, 0, 2148663296}, 0};
  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(less_test_8) {
  s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000},
                      0};  // -1.2
  ck_assert_int_eq(s21_is_less(dec5, dec6), 0);
  ck_assert_int_eq(s21_is_less(dec6, dec5), 1);

  s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000},
                      0};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec7, dec8), 1);
  ck_assert_int_eq(s21_is_less(dec8, dec7), 0);

  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000},
                      0};  //  1.2;
  ck_assert_int_eq(s21_is_less(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less(dec2, dec1), 1);

  s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000},
                      0};  //  -1.2;
  ck_assert_int_eq(s21_is_less(dec3, dec4), 1);
  ck_assert_int_eq(s21_is_less(dec4, dec3), 0);

  s21_decimal dec9 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec10 = {{12345, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less(dec9, dec10), 0);
  ck_assert_int_eq(s21_is_less(dec10, dec9), 0);

  s21_decimal dec11 = {{0, 0, 0, 0}, 0};
  s21_decimal dec12 = {{0, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_less(dec11, dec12), 0);
  ck_assert_int_eq(s21_is_less(dec12, dec11), 0);
}
END_TEST

Suite *suite_is_less(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_IS_LESS  \033[0m");
  tc = tcase_create("case_is_less");

  tcase_add_test(tc, less_test_1);
  tcase_add_test(tc, less_test_2);
  tcase_add_test(tc, less_test_3);
  tcase_add_test(tc, less_test_4);
  tcase_add_test(tc, less_test_5);
  tcase_add_test(tc, less_test_6);
  tcase_add_test(tc, less_test_7);
  tcase_add_test(tc, less_test_8);

  suite_add_tcase(s, tc);
  return s;
}
