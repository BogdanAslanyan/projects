#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <cmath>
#include <iostream>

#include "credit.h"

namespace s21 {

enum PaymentsPeriod { EVERY_MONTH, EVERY_HALF_YEAR, EVERY_YEAR, END_TERM };

typedef struct AddMoney {
  int term;
  double money;
} AddMoney;

typedef struct RemMoney {
  int term;
  double money;
} RemMoney;

typedef struct DepositData {
  double depositAmount = 0.;      // сумма вклада
  double periodOfPlacement = 0.;  // срок размещния
  double interestRate = 0.;       // процентная ставка
  double taxRate = 0.;            // налоговая ставка
  int periodOfPayments = 0;       // периодичность выплат
  int interestCapitalization = 0;  // капитализация процентов

  AddMoney replenishmentList[255] = {};  // список пополнений
  int addCount = 0;
  RemMoney listPartialWithdrawals[255] = {};  // список частичных снятий
  int remCount = 0;
  double minimumBalance = 0.;

  int paymentsType = 0;

  double currentInterest = 0.;

  int currentMoth = 0;
  int currentYear = 0;
  int currentDay = 0;
  int leapYear = 0;
  int nextLeapYear = 0;

  double taxArr[255] = {};
  int countTaxArr = 0;

  double sumInterest = 0.;
  double sumTax = 0.;
  double sumEndTerm = 0.;
} DepositData;

class Deposit {
 public:
  Deposit(DepositData* data) : data(data) {}
  ~Deposit() {}

  void core();

 private:
  DepositData* data;

  int isLeapYear(int i);
  double everyMonthCapital(int daysInMonth);
  void addToAmount(int counter);
  void addAmountEveryTime(int num);
  void remAmount(int counter);
  void remAmountEveryTime(int num);
  void depositPayments(double* interestTemp, double* taxTemp, int month, int i);
  double taxRateCalc(double accum);
  void addingTemp(double* interestTemp, double* taxTemp);
};
}  // namespace s21

#endif  // DEPOSIT_H
