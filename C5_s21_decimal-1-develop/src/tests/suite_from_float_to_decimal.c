#include "test_decimal.h"

START_TEST(from_float_to_decimal_test_1) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);

  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_test_2) {
  float src = 56.986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "5698600 0 0 327680";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_4) {
  float src = 124.4;
  int error = 0;
  error = s21_from_float_to_decimal(src, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_6) {
  float src = 1.0 / 0.0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_7) {
  float src = -1.596;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596000 0 0 2147876864";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_8) {
  float src = 1 / 0.0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_10) {
  float src = 0.000000986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "9860000 0 0 851968";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_11) {
  float src = 1612354.986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1612355 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_12) {
  s21_decimal dec;
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_test_13) {
  float src = 124.4;
  int error = 0;
  error = s21_from_float_to_decimal(src, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_14) {
  s21_decimal dec;
  s21_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_test_15) {
  s21_decimal dec;
  s21_from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_test_16) {
  s21_decimal dec;
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_test_17) {
  s21_decimal dec;
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_18) {
  float src = 0.000000986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "9860000 0 0 851968";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_19) {
  float src = 56.986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "5698600 0 0 327680";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_20) {
  float src = 1.0 / 0.0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_21) {
  float src = -1.596;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596000 0 0 2147876864";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_22) {
  float src = 1 / 0.0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_23) {
  double src = 0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_24) {
  long double src = 0;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_25) {
  float src = 1612354.986;
  s21_decimal z = {{0, 0, 0, 0}, NORMAL};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1612355 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[42m  S21_FROM_FLOAT_TO_DECIMAL  \033[0m");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, from_float_to_decimal_test_1);
  tcase_add_test(tc, from_float_to_decimal_test_2);
  tcase_add_test(tc, from_float_to_decimal_test_4);
  tcase_add_test(tc, from_float_to_decimal_test_6);
  tcase_add_test(tc, from_float_to_decimal_test_7);
  tcase_add_test(tc, from_float_to_decimal_test_8);
  tcase_add_test(tc, from_float_to_decimal_test_10);
  tcase_add_test(tc, from_float_to_decimal_test_11);
  tcase_add_test(tc, from_float_to_decimal_test_12);
  tcase_add_test(tc, from_float_to_decimal_test_13);
  tcase_add_test(tc, from_float_to_decimal_test_14);
  tcase_add_test(tc, from_float_to_decimal_test_15);
  tcase_add_test(tc, from_float_to_decimal_test_16);
  tcase_add_test(tc, from_float_to_decimal_test_17);
  tcase_add_test(tc, from_float_to_decimal_test_18);
  tcase_add_test(tc, from_float_to_decimal_test_19);
  tcase_add_test(tc, from_float_to_decimal_test_20);
  tcase_add_test(tc, from_float_to_decimal_test_21);
  tcase_add_test(tc, from_float_to_decimal_test_22);
  tcase_add_test(tc, from_float_to_decimal_test_23);
  tcase_add_test(tc, from_float_to_decimal_test_24);
  tcase_add_test(tc, from_float_to_decimal_test_25);

  suite_add_tcase(s, tc);
  return s;
}
