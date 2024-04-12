#include "unit.h"

TEST(DEPOSIT_TESTS, TEST_0) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 3.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_MONTH;
  dd.interestCapitalization = 1;
  dd.currentDay = 10;
  dd.currentMoth = 7;
  dd.currentYear = 2023;
  dd.addCount = 0;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();

  EXPECT_NEAR(dd.sumInterest, 71050.72, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 3571050.72, 1e-2);
  EXPECT_NEAR(dd.sumTax, 0.0, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_1) {
  s21::DepositData dd;

  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 3.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_MONTH;
  dd.interestCapitalization = 0;
  dd.currentDay = 10;
  dd.currentMoth = 7;
  dd.currentYear = 2023;
  dd.addCount = 0;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 70575.34, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 3500000.00, 1e-2);
  EXPECT_NEAR(dd.sumTax, 0.0, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_2) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 9.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_MONTH;
  dd.interestCapitalization = 0;
  dd.currentDay = 10;
  dd.currentMoth = 7;
  dd.currentYear = 2023;
  dd.addCount = 0;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 210747.21, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 3500000.00, 1e-2);
  EXPECT_NEAR(dd.sumTax, 7897.14, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_3) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 35.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_MONTH;
  dd.interestCapitalization = 1;
  dd.currentDay = 10;
  dd.currentMoth = 7;
  dd.currentYear = 2023;
  dd.addCount = 0;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 916785.40, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 4416785.40, 1e-2);
  EXPECT_NEAR(dd.sumTax, 80182.10, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_4) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 35.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_HALF_YEAR;
  dd.interestCapitalization = 1;
  dd.currentDay = 5;
  dd.currentMoth = 7;
  dd.currentYear = 2023;
  dd.addCount = 1;
  dd.replenishmentList[0].term = s21::EVERY_MONTH;
  dd.replenishmentList[0].money = 10999.;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 946844.81, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 4831809.81, 1e-2);
  EXPECT_NEAR(dd.sumTax, 93839.83, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_5) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 9.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_YEAR;
  dd.interestCapitalization = 1;
  dd.currentDay = 5;
  dd.currentMoth = 7;
  dd.currentYear = 2025;
  dd.addCount = 1;
  dd.replenishmentList[0].term = s21::EVERY_HALF_YEAR;
  dd.replenishmentList[0].money = 10999.;
  dd.remCount = 0;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 210408.75, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 3721407.75, 1e-2);
  EXPECT_NEAR(dd.sumTax, 17603.14, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_6) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 13.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_YEAR;
  dd.interestCapitalization = 1;
  dd.currentDay = 5;
  dd.currentMoth = 7;
  dd.currentYear = 2025;
  dd.addCount = 1;
  dd.replenishmentList[0].term = s21::EVERY_HALF_YEAR;
  dd.replenishmentList[0].money = 10999.;
  dd.remCount = 1;
  dd.listPartialWithdrawals[0].term = s21::EVERY_YEAR;
  dd.listPartialWithdrawals[0].money = 888.;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 306266.02, 1e-2);
  EXPECT_NEAR(dd.sumEndTerm, 3827376.02, 1e-2);
  EXPECT_NEAR(dd.sumTax, 30064.58, 1e-2);
}

TEST(DEPOSIT_TESTS, TEST_7) {
  s21::DepositData dd;
  dd.depositAmount = 3500000.;
  dd.periodOfPlacement = 24.;
  dd.interestRate = 8.;
  dd.taxRate = 13.;
  dd.paymentsType = s21::EVERY_MONTH;
  dd.interestCapitalization = 1;
  dd.currentDay = 12;
  dd.currentMoth = 7;
  dd.currentYear = 2024;
  dd.addCount = 1;
  dd.replenishmentList[0].term = s21::EVERY_YEAR;
  dd.replenishmentList[0].money = 10999.;
  dd.remCount = 1;
  dd.listPartialWithdrawals[0].term = s21::EVERY_HALF_YEAR;
  dd.listPartialWithdrawals[0].money = 888.;

  s21::Deposit dp(&dd);
  dp.core();
  EXPECT_NEAR(dd.sumInterest, 605376.95, 1e-0);
  EXPECT_NEAR(dd.sumEndTerm, 4123822.95, 1e-0);
  EXPECT_NEAR(dd.sumTax, 49449.00, 1e-0);
}