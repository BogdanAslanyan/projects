#include "deposit.h"

namespace s21 {

void Deposit::core() {
  double interestTemp = 0.;
  double taxTemp = 0.;
  int daysInMonth = 0;
  int month = 0;

  data->sumEndTerm = data->depositAmount;

  data->minimumBalance = 0.;

  for (int i = 0; i < data->periodOfPlacement; i++) {
    data->leapYear = isLeapYear(i);
    data->nextLeapYear = isLeapYear(i + 1);
    daysInMonth = (data->currentMoth + i) % 12;
    month = daysInMonth;
    daysInMonth = s21::Credit::dateCorrect(static_cast<s21::Date>(daysInMonth),
                                           data->leapYear);

    data->currentInterest = everyMonthCapital(daysInMonth);
    interestTemp += data->currentInterest;

    addToAmount(i);
    remAmount(i);

    depositPayments(&interestTemp, &taxTemp, month, i);
  }

  data->sumEndTerm = data->depositAmount;
}

void Deposit::depositPayments(double* interestTemp, double* taxTemp, int month,
                              int i) {
  if (data->paymentsType == EVERY_MONTH) {
    addingTemp(interestTemp, taxTemp);
  } else if (data->paymentsType == EVERY_HALF_YEAR) {
    if ((i > 0 && (month == data->currentMoth - 1 ||
                   month == (data->currentMoth + 5) % 12)) ||
        i == data->periodOfPlacement - 1) {
      addingTemp(interestTemp, taxTemp);
    }
  } else if (data->paymentsType == EVERY_YEAR) {
    if ((i > 0 && ((data->currentMoth + i) % 12) == data->currentMoth - 1) ||
        i == data->periodOfPlacement - 1) {
      addingTemp(interestTemp, taxTemp);
    }
  } else if (data->paymentsType == END_TERM) {
    if (i == data->periodOfPlacement - 1) {
      addingTemp(interestTemp, taxTemp);
    }
  }
  if ((i > 0 && (((data->currentMoth + i) % 12) == 11)) ||
      i == data->periodOfPlacement - 1) {
    data->sumTax += taxRateCalc(*taxTemp);
    *taxTemp = 0.;
  }
}

void Deposit::addingTemp(double* interestTemp, double* taxTemp) {
  data->sumInterest += *interestTemp;
  *taxTemp += *interestTemp;
  if (data->interestCapitalization) data->depositAmount += *interestTemp;
  *interestTemp = 0.;
}

void Deposit::addToAmount(int counter) {
  int month = (data->currentMoth + counter) % 12;

  for (int i = 0; i < data->addCount; i++) {
    if (data->replenishmentList[i].term == EVERY_MONTH) {
      addAmountEveryTime(i);
    } else if (data->replenishmentList[i].term == EVERY_HALF_YEAR) {
      if (counter > 0 && (month == data->currentMoth - 1 ||
                          month == (data->currentMoth + 5) % 12)) {
        addAmountEveryTime(i);
      }
    } else if (data->replenishmentList[i].term == EVERY_YEAR) {
      if (counter > 0 && month == data->currentMoth - 1) {
        addAmountEveryTime(i);
      }
    }
  }
}

void Deposit::remAmount(int counter) {
  int month = (data->currentMoth + counter) % 12;

  for (int i = 0; i < data->remCount; i++) {
    if (data->listPartialWithdrawals[i].term == EVERY_MONTH) {
      remAmountEveryTime(i);
    } else if (data->listPartialWithdrawals[i].term == EVERY_HALF_YEAR) {
      if (counter > 0 && (month == data->currentMoth - 1 ||
                          month == (data->currentMoth + 5) % 12)) {
        remAmountEveryTime(i);
      }
    } else if (data->listPartialWithdrawals[i].term == EVERY_YEAR) {
      if (counter > 0 && month == data->currentMoth - 1) {
        remAmountEveryTime(i);
      }
    }
  }
}

void Deposit::addAmountEveryTime(int num) {
  data->depositAmount += data->replenishmentList[num].money;
}

void Deposit::remAmountEveryTime(int num) {
  if (data->depositAmount - data->listPartialWithdrawals[num].money >=
      data->minimumBalance)
    data->depositAmount -= data->listPartialWithdrawals[num].money;
}

int Deposit::isLeapYear(int i) {
  return s21::Credit::isLeap(data->currentYear +
                             (data->currentMoth - 1 + i) / 12);
}

double Deposit::everyMonthCapital(int daysInMonth) {
  double profit = 0.;
  double daysInYear = 0.;
  daysInYear = data->leapYear ? 366. : 365.;

  if (data->leapYear != data->nextLeapYear) {
    if (data->leapYear) {
      profit = data->depositAmount * (data->interestRate / 100.) / 366. *
                   ((double)daysInMonth - data->currentDay) +
               data->currentDay *
                   ((data->interestRate / 100.) * data->depositAmount / 365.);
    } else {
      profit = data->depositAmount * (data->interestRate / 100.) / 365. *
                   ((double)daysInMonth - data->currentDay) +
               data->currentDay *
                   ((data->interestRate / 100.) * data->depositAmount / 366.);
    }
  } else {
    profit = data->depositAmount * (data->interestRate / 100.) / daysInYear *
             (double)daysInMonth;
  }

  return profit;
}

double Deposit::taxRateCalc(double accum) {
  double tax = 0.;
  double nonTaxableIncome = 75000.;  // ставка цб = 7.5%

  tax = accum - nonTaxableIncome;
  if (tax > 0.)
    tax *= (data->taxRate / 100.);
  else
    tax = 0.;

  return tax;
}

}  // namespace s21