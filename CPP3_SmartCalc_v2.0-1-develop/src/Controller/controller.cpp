#include "controller.h"

namespace s21 {

double Controller::callBase() {
  double result = 0;
  baseCalc->parsSrcStr();
  if (baseCalc->containX()) {
    baseCalc->calcExpression(xMin, xMax);
  } else {
    result = baseCalc->calcExpression(0);
  }
  return result;
}

void Controller::callCredit() { creditCalc->core(); }

void Controller::callDeposit() { depositCalc->core(); }

}  // namespace s21
