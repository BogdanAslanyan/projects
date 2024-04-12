#include "test_decimal.h"

START_TEST(greater_or_equal_test_1) {
  // float num1 = 1.375323....;
  // float num2 = 1.39;
  s21_decimal dec1 = {{952788803, 320, 0, 2148204544}, 0};
  s21_decimal dec2 = {{139, 0, 0, 131072}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(greater_or_equal_test_2) {
  int num1 = 2;
  int num2 = 1;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_3) {
  // float num1 = 1.39;
  // float num2 = -1.39;
  s21_decimal dec1 = {{139, 0, 0, 131072}, 0};
  s21_decimal dec2 = {{139, 0, 0, 2147614720}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(greater_or_equal_test_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_7) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_8) {
  // float num1 = 10423546.34534534;
  // float num2 = 3.34534534;

  s21_decimal dec1 = {{431533702, 242692, 0, 524288}, 0};
  s21_decimal dec2 = {{334534534, 0, 0, 524288}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_9) {
  // float num1 = -3.34534534;
  // float num2 = 3.34534534;
  s21_decimal dec1 = {{334534534, 0, 0, 2148007936}, 0};
  s21_decimal dec2 = {{334534534, 0, 0, 524288}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(greater_or_equal_test_10) {
  // float num1 = 1042634.34534534;
  // float num2 = 10424546.34534534;
  s21_decimal dec1 = {{3103424134, 24275, 0, 524288}, 0};
  s21_decimal dec2 = {{1647285894, 242715, 0, 524288}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(greater_or_equal_test_11) {
  // float num1 = 10426.34534534;
  // float num2 = 104234.345345;
  s21_decimal dec1 = {{3252448902, 242, 0, 524288}, 0};
  s21_decimal dec2 = {{1155130241, 24, 0, 393216}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

START_TEST(greater_or_equal_test_12) {
  // float num1 = 1042.5667777;
  // float num2 = 1042.345345;
  s21_decimal dec1 = {{1835733185, 2, 0, 458752}, 0};
  s21_decimal dec2 = {{1042345345, 0, 0, 393216}, 0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(greater_or_equal_test_13) {
  s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}, 0};  //
  ck_assert_int_eq(s21_is_greater_or_equal(dec5, dec6), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec6, dec5), 0);

  s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}, 0};
  ck_assert_int_eq(s21_is_greater_or_equal(dec7, dec8), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec8, dec7), 1);

  s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000},
                      0};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}, 0};
  ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 0);

  s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000},
                      0};  // -1.2345
  s21_decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000}, 0};  //

  ck_assert_int_eq(s21_is_greater_or_equal(dec3, dec4), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec4, dec3), 1);

  s21_decimal dec9 = {{12345, 0, 0, 0}, 0};
  s21_decimal dec10 = {{12345, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_greater_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec10, dec9), 1);

  s21_decimal dec11 = {{0, 0, 0, 0}, 0};
  s21_decimal dec12 = {{0, 0, 0, 0}, 0};
  ck_assert_int_eq(s21_is_greater_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec12, dec11), 1);
}
END_TEST

Suite *suite_is_greater_or_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_IS_GREATER_OR_EQUAL  \033[0m");
  tc = tcase_create("case_greater_or_equal");

  tcase_add_test(tc, greater_or_equal_test_1);
  tcase_add_test(tc, greater_or_equal_test_2);
  tcase_add_test(tc, greater_or_equal_test_3);
  tcase_add_test(tc, greater_or_equal_test_4);
  tcase_add_test(tc, greater_or_equal_test_5);
  tcase_add_test(tc, greater_or_equal_test_6);
  tcase_add_test(tc, greater_or_equal_test_7);
  tcase_add_test(tc, greater_or_equal_test_8);
  tcase_add_test(tc, greater_or_equal_test_9);
  tcase_add_test(tc, greater_or_equal_test_10);
  tcase_add_test(tc, greater_or_equal_test_11);
  tcase_add_test(tc, greater_or_equal_test_12);
  tcase_add_test(tc, greater_or_equal_test_13);
  suite_add_tcase(s, tc);
  return s;
}
