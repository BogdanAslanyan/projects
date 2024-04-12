#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/base.h"
#include "../Model/credit.h"
#include "../Model/deposit.h"

namespace s21 {
class Controller {
 public:
  Controller(DepositData* data)
      : baseCalc(nullptr),
        creditCalc(nullptr),
        depositCalc(new Deposit(data)),
        xMin(0),
        xMax(0) {}
  Controller(CreditData* data)
      : baseCalc(nullptr),
        creditCalc(new Credit(data)),
        depositCalc(nullptr),
        xMin(0),
        xMax(0) {}
  Controller(std::string inputStr, double xMin, double xMax)
      : baseCalc(new Base(inputStr)),
        creditCalc(nullptr),
        depositCalc(nullptr),
        xMin(xMin),
        xMax(xMax) {}
  ~Controller() { delete baseCalc; }

  double callBase();
  void callCredit();
  void callDeposit();

  Base* getBase() { return baseCalc; }
  Credit* getCredit() { return creditCalc; }
  Deposit* getDeposit() { return depositCalc; }

 private:
  Base* baseCalc;
  Credit* creditCalc;
  Deposit* depositCalc;
  double xMin;
  double xMax;
};
}  // namespace s21

#endif  // CONTROLLER_H
