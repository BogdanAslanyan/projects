#ifndef CREDIT_H
#define CREDIT_H

#include <cmath>
#include <iostream>

namespace s21 {

enum class Date {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER = 0
};

struct CreditData {
  bool type = false;
  double totalCredit = 0.;
  double term = 0.;
  int date = 0;
  double interestRate;
  double monthlyPayment = 0.;
  double overpaymentOnCredit = 0.;
  double totalPayment = 0.;
  double mainMonthSum = 0.;
  double percentMonthSum = 0.;
  int leapYear = 0;
  int nextLeapYear = 0;
  int days = 0;
  int startDateMonth = 0;
  int startDateYear = 0;
};

class Credit {
 public:
  Credit(CreditData* data) : data(data) {}
  ~Credit() {}

  int ppp();
  static bool isLeap(int year);
  static int dateCorrect(Date date, bool leapYear);

  void core();
  void calcMothForDiff(int& i, int& dateTmp, int& currYear);

 private:
  void annuity();
  void differentiated();
  void calcPercentMonthSum();

  CreditData* data;
};
}  // namespace s21

#endif  // CREDIT_H
