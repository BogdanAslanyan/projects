#ifndef BASECALC_H
#define BASECALC_H

#include "../Controller/controller.h"
#include "customgraph.h"
#include "dependencies.h"

class BaseCalc : public QFrame {
  Q_OBJECT
 public:
  explicit BaseCalc(QFrame* parent = nullptr);
  ~BaseCalc();

  void Designer();
  void Properties();
  void Layouts();
  void Connector();

  CustomGraph* cg;

  QVBoxLayout* vblCalc;
  QLabel* leResultText;
  QLineEdit* leText;  //  поле ввода

  QGridLayout* glCalc;
  // layout glCalc
  QPushButton* pb0;
  QPushButton* pb1;
  QPushButton* pb2;
  QPushButton* pb3;
  QPushButton* pb4;
  QPushButton* pb5;
  QPushButton* pb6;
  QPushButton* pb7;
  QPushButton* pb8;
  QPushButton* pb9;
  QPushButton* pbAdd;
  QPushButton* pbSub;
  QPushButton* pbMul;
  QPushButton* pbDiv;
  QPushButton* pbMod;
  QPushButton* pbPow;
  QPushButton* pbResult;
  QPushButton* pbSin;
  QPushButton* pbCos;
  QPushButton* pbAsin;
  QPushButton* pbAcos;
  QPushButton* pbTan;
  QPushButton* pbAtan;
  QPushButton* pbLn;
  QPushButton* pbLog10;
  QPushButton* pbSqrt;
  QPushButton* pbX;
  QPushButton* pbClear;
  QPushButton* pbBack;
  QPushButton* pbBrLeft;
  QPushButton* pbBrRight;

  //    QPushButton* pbBrR;
  //    QLineEdit* leScale;

  QHBoxLayout* hblRange;
  QSpinBox* spbXmin;
  QSpinBox* spbXmax;
  // layout glCalc

  QString qStr;      // содержит данные из поля ввода
  QString qBackStr;  // запомнить строку

 private slots:
  void slotPb0();
  void slotPb1();
  void slotPb2();
  void slotPb3();
  void slotPb4();
  void slotPb5();
  void slotPb6();
  void slotPb7();
  void slotPb8();
  void slotPb9();
  void slotPbAdd();
  void slotPbSub();
  void slotPbMul();
  void slotPbDiv();
  void slotPbMod();
  void slotPbPow();
  void slotPbSin();
  void slotPbCos();
  void slotPbAsin();
  void slotPbAcos();
  void slotPbTan();
  void slotPbAtan();
  void slotPbLn();
  void slotPbLog10();
  void slotPbSqrt();
  void slotPbResult();
  void slotPbX();

  void slotBr();

  void slotPbClear();
  void slotPbBack();
};

#endif  // BASECALC_H
