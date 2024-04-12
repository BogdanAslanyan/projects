#include "unit.h"

TEST(BASE_TESTS, TEST_0) {
  s21::Base ppp("2^2^3");
  ppp.parsSrcStr();
  EXPECT_NEAR(256, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_1) {
  s21::Base ppp("(2^2)^3");
  ppp.parsSrcStr();
  EXPECT_NEAR(64, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_2) {
  s21::Base ppp("asin(0.523)");
  ppp.parsSrcStr();
  EXPECT_NEAR(0.550366917610664, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_3) {
  s21::Base ppp("atan(0.523)");
  ppp.parsSrcStr();
  EXPECT_NEAR(0.481877852, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_4) {
  s21::Base ppp("(sqrt(5.5)+ln(5))^(log(3))");
  ppp.parsSrcStr();
  EXPECT_NEAR(1.927048845, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_5) {
  s21::Base ppp("(sqrt(5.5)+ln(5))^(log(3)+acos(0.145))");
  ppp.parsSrcStr();
  EXPECT_NEAR(13.67540606, ppp.calcExpression(0), 1e-7);
}

TEST(BASE_TESTS, TEST_6) {
  s21::Base ppp("x");
  ppp.parsSrcStr();

  ppp.calcExpression(-10, 10);
}

TEST(BASE_TESTS, TEST_7) {
  s21::Base ppp("1e(-3)");
  ppp.parsSrcStr();
  EXPECT_NEAR(0.001, ppp.calcExpression(0), 1e-7);
}