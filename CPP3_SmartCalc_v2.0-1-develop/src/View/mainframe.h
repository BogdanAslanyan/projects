#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "basecalc.h"
#include "creditcalc.h"
#include "dependencies.h"
#include "depositcalc.h"

class MainFrame : public QFrame {
  Q_OBJECT
 public:
  explicit MainFrame(QFrame* parent = nullptr);
  int aboba;
  CreditCalc* creditCalc;
  DepositCalc* depositCalc;
  BaseCalc* baseCalc;
};

#endif  // MAINFRAME_H
