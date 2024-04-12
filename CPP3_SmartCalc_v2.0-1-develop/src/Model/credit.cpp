#include "credit.h"

// int Credit::isLeapYear(Deposit* dp, int i) {
//     return isLeap(dp->currentYear + (dp->currentMoth - 1 + i) / 12);
// }

namespace s21 {

bool Credit::isLeap(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int Credit::ppp() { return 1; }

int Credit::dateCorrect(Date date, bool leapYear) {
  int ret = 0;
  if (date == Date::JANUARY || date == Date::MARCH || date == Date::MAY ||
      date == Date::JULY || date == Date::AUGUST || date == Date::OCTOBER ||
      date == Date::DECEMBER)
    ret = 31;
  else if (date == Date::APRIL || date == Date::JUNE ||
           date == Date::SEPTEMBER || date == Date::NOVEMBER)
    ret = 30;
  else if (date == Date::FEBRUARY && leapYear)
    ret = 29;
  else if (date == Date::FEBRUARY && !leapYear)
    ret = 28;

  return ret;
}

void Credit::core() {
  if (!data->type) {
    annuity();
  } else {
    data->date = dateCorrect(static_cast<Date>(data->date), data->leapYear);
    differentiated();
  }
}

void Credit::annuity() {
  double monthlyRate = 0.;
  monthlyRate = data->interestRate / 1200.;
  data->monthlyPayment = data->totalCredit * monthlyRate /
                         (1 - pow((1 + monthlyRate), (-data->term)));
  data->overpaymentOnCredit =
      data->monthlyPayment * data->term - data->totalCredit;
  data->totalPayment = data->totalCredit + data->overpaymentOnCredit;
}

void Credit::differentiated() {
  calcPercentMonthSum();
  data->monthlyPayment = data->mainMonthSum + data->percentMonthSum;
  data->totalCredit -= data->mainMonthSum;
  data->overpaymentOnCredit += data->percentMonthSum;
  data->totalPayment += data->monthlyPayment;
}

void Credit::calcPercentMonthSum() {
  double daysYear = 365.;

  if (data->leapYear) daysYear = 366.;

  if (data->leapYear != data->nextLeapYear) {
    if (data->leapYear) {
      data->percentMonthSum =
          (data->totalCredit * data->interestRate / 100 *
           (double)(data->date - data->days)) /
              366. +
          (double)data->days * (data->totalCredit * data->interestRate / 100) /
              365.;
    } else {
      data->percentMonthSum =
          (data->totalCredit * data->interestRate / 100 *
           (data->date - data->days)) /
              365. +
          (double)data->days * (data->totalCredit * data->interestRate / 100) /
              366.;
    }
  } else {
    data->percentMonthSum =
        (data->totalCredit * data->interestRate / 100 * data->date) / daysYear;
  }
}

void Credit::calcMothForDiff(int& i, int& dateTmp, int& currYear) {
  data->date = (dateTmp + i) % 12;
  if (!((currYear + (dateTmp - 1 + i) / 12) % 4)) {
    data->leapYear = 1;
  } else {
    data->leapYear = 0;
  }
  if (!((currYear + (dateTmp + i) / 12) % 4)) {
    data->nextLeapYear = 1;
  } else {
    data->nextLeapYear = 0;
  }
}

}  // namespace s21