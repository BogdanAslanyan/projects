#include "unit.h"

TEST(CREDIT_TESTS, CREDIT_0) {
  s21::CreditData cd;
  cd.term = 36;
  cd.totalCredit = 1200000;
  cd.type = 0;
  cd.interestRate = 12;

  s21::Credit cr(&cd);

  cr.core();

  EXPECT_NEAR(cd.monthlyPayment, 39857.17, 1e-0);
  EXPECT_NEAR(cd.overpaymentOnCredit, 234858.12, 1e-0);
  EXPECT_NEAR(cd.totalPayment, 1434858.12, 1e-0);
}

TEST(CREDIT_TESTS, CREDIT_1) {
  s21::CreditData cd;
  cd.term = 9;
  cd.totalCredit = 1200000;
  cd.type = 1;
  cd.interestRate = 12;
  cd.date = 0;
  cd.mainMonthSum = cd.totalCredit / cd.term;
  cd.totalPayment = 0.;
  cd.overpaymentOnCredit = 0.;
  cd.monthlyPayment = 0.;

  cd.days = 1;
  int dateTmp = 7;
  int currYear = 2023;
  double monthlyPayments[255] = {145563.47, 144204.56, 142538.81,
                                 141486.75, 139908.67, 138768.47,
                                 137398.90, 135868.85, 134688.55};

  s21::Credit cr(&cd);

  for (int i = 0; i < cd.term; i++) {
    cr.calcMothForDiff(i, dateTmp, currYear);
    cr.core();
    EXPECT_NEAR(cd.monthlyPayment, monthlyPayments[i], 1e-0);
  }

  EXPECT_NEAR(cd.totalPayment, 1260427.52, 1e-0);
  EXPECT_NEAR(cd.overpaymentOnCredit, 60427.52, 1e-0);
}

TEST(CREDIT_TESTS, CREDIT_2) {
  s21::CreditData cd;
  cd.term = 9;
  cd.totalCredit = 1200000;
  cd.type = 1;
  cd.interestRate = 12;
  cd.date = 0;
  cd.mainMonthSum = cd.totalCredit / cd.term;
  cd.totalPayment = 0.;
  cd.overpaymentOnCredit = 0.;
  cd.monthlyPayment = 0.;

  cd.days = 24;
  int dateTmp = 7;
  int currYear = 2024;
  double monthlyPayments[255] = {145530.05, 144174.86, 142513.66,
                                 141464.48, 139890.71, 138765.59,
                                 137410.04, 135788.12, 134692.26};

  s21::Credit cr(&cd);

  for (int i = 0; i < cd.term; i++) {
    cr.calcMothForDiff(i, dateTmp, currYear);
    cr.core();
    EXPECT_NEAR(cd.monthlyPayment, monthlyPayments[i], 1e-0);
  }

  EXPECT_NEAR(cd.totalPayment, 1260230., 1e-0);
  EXPECT_NEAR(cd.overpaymentOnCredit, 60230., 1e-0);
}
