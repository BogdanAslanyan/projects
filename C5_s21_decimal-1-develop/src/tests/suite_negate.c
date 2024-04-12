#include "test_decimal.h"

START_TEST(negate_test_1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(negate_test_2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(negate_test_3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(negate_test_4) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(negate_test_5) {  // 0 * -1 = 0
  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}, 0};
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  // int equal = s21_is_equal(b, etalon);
  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(negate_test_6) {  // 1 * -1 = -1
  s21_decimal a = {{1, 0, 0, 0}, 0};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_7) {  // -1 * -1 = 1
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{1, 0, 0, 0}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_8) {  // 100 * -1 = -100
  s21_decimal a = {{100, 0, 0, 0}, 0};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_9) {  //
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{100, 0, 0, 0}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_10) {  //
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}, 0};
  s21_decimal etalon = {{S21_MAX_UINT, 0, 0, ~(INT_MAX)}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_11) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(negate_test_12) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)},
                        0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_13) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}, 0};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}, 0};

  s21_decimal b = {{0, 0, 0, 0}, 0};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_test_14) {
  s21_decimal val = {{2, 0, 0, 0}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_test_15) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_test_16) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}, 0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_test_17) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

Suite* suite_negate(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("\033[42m  S21_NEGATE  \033[0m");
  tc = tcase_create("case_negate");

  tcase_add_test(tc, negate_test_1);
  tcase_add_test(tc, negate_test_2);
  tcase_add_test(tc, negate_test_3);
  tcase_add_test(tc, negate_test_4);
  tcase_add_test(tc, negate_test_5);
  tcase_add_test(tc, negate_test_6);
  tcase_add_test(tc, negate_test_7);
  tcase_add_test(tc, negate_test_8);
  tcase_add_test(tc, negate_test_9);
  tcase_add_test(tc, negate_test_10);
  tcase_add_test(tc, negate_test_11);
  tcase_add_test(tc, negate_test_12);
  tcase_add_test(tc, negate_test_13);
  tcase_add_test(tc, negate_test_14);
  tcase_add_test(tc, negate_test_15);
  tcase_add_test(tc, negate_test_16);
  tcase_add_test(tc, negate_test_17);

  suite_add_tcase(s, tc);
  return s;
}
