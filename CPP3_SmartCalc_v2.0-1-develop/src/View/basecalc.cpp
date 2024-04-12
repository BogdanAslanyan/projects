#include "basecalc.h"

BaseCalc::BaseCalc(QFrame* parent) : QFrame{parent} {
  Designer();
  Properties();
  Layouts();
  Connector();
}

BaseCalc::~BaseCalc() { delete cg; }

void BaseCalc::Designer() {
  cg = new CustomGraph();
  vblCalc = new QVBoxLayout(this);
  leResultText = new QLabel(this);
  leText = new QLineEdit(this);

  glCalc = new QGridLayout(this);

  pb0 = new QPushButton("0", this);
  pb1 = new QPushButton("1", this);
  pb2 = new QPushButton("2", this);
  pb3 = new QPushButton("3", this);
  pb4 = new QPushButton("4", this);
  pb5 = new QPushButton("5", this);
  pb6 = new QPushButton("6", this);
  pb7 = new QPushButton("7", this);
  pb8 = new QPushButton("8", this);
  pb9 = new QPushButton("9", this);
  pbAdd = new QPushButton("+", this);
  pbSub = new QPushButton("-", this);
  pbMul = new QPushButton("*", this);
  pbDiv = new QPushButton("/", this);
  pbMod = new QPushButton("%", this);
  pbPow = new QPushButton("^", this);

  pbSin = new QPushButton("sin", this);
  pbCos = new QPushButton("cos", this);
  pbAsin = new QPushButton("asin", this);
  pbAcos = new QPushButton("acos", this);
  pbTan = new QPushButton("tan", this);
  pbAtan = new QPushButton("atan", this);
  pbLn = new QPushButton("ln", this);
  pbLog10 = new QPushButton("log", this);
  pbSqrt = new QPushButton("sqrt", this);
  //    leScale = new QLineEdit(this);

  pbClear = new QPushButton("clear", this);
  pbBack = new QPushButton("<==", this);

  pbBrLeft = new QPushButton("(", this);
  pbBrRight = new QPushButton(")", this);

  pbX = new QPushButton("x", this);
  hblRange = new QHBoxLayout(this);
  spbXmin = new QSpinBox(this);
  spbXmax = new QSpinBox(this);

  pbResult = new QPushButton("=", this);
  //    pbBrL = new QPushButton("(", this);
}

void BaseCalc::Properties() {
  setFixedSize(400, 400);
  setWindowTitle("Graphing Calc");

  pb0->setFixedSize(60, 25);
  pb1->setFixedSize(60, 25);
  pb2->setFixedSize(60, 25);
  pb3->setFixedSize(60, 25);
  pb4->setFixedSize(60, 25);
  pb5->setFixedSize(60, 25);
  pb6->setFixedSize(60, 25);
  pb7->setFixedSize(60, 25);
  pb8->setFixedSize(60, 25);
  pb9->setFixedSize(60, 25);
  pbAdd->setFixedSize(60, 25);
  pbSub->setFixedSize(60, 25);
  pbMul->setFixedSize(60, 25);
  pbDiv->setFixedSize(60, 25);
  pbMod->setFixedSize(60, 25);
  pbPow->setFixedSize(60, 25);
  pbResult->setFixedSize(60, 25);

  pbSin->setFixedSize(60, 25);
  pbCos->setFixedSize(60, 25);
  pbAsin->setFixedSize(60, 25);
  pbAcos->setFixedSize(60, 25);
  pbTan->setFixedSize(60, 25);
  pbAtan->setFixedSize(60, 25);
  pbLn->setFixedSize(60, 25);
  pbLog10->setFixedSize(60, 25);
  pbSqrt->setFixedSize(60, 25);

  pbBack->setFixedSize(60, 25);
  pbClear->setFixedSize(60, 25);

  pbBrLeft->setFixedSize(60, 25);
  pbBrRight->setFixedSize(60, 25);

  //    leScale->setFixedSize(60, 25);
  //    leScale->setPlaceholderText("Scale=5");

  spbXmin->setFixedSize(120, 25);
  spbXmax->setFixedSize(120, 25);
  spbXmin->setPrefix("Xmin=");
  spbXmax->setPrefix("Xmax=");

  spbXmin->setRange(-1000000, 0);
  spbXmax->setRange(0, 1000000);

  spbXmin->setValue(-10);
  spbXmax->setValue(10);

  pbX->setFixedSize(60, 25);
}

void BaseCalc::Layouts() {
  int rowSpan = 1;
  int columnSpan = 1;

  setLayout(vblCalc);
  vblCalc->addWidget(leResultText);
  vblCalc->addWidget(leText);
  vblCalc->addLayout(glCalc);

  glCalc->addWidget(pb1, 0, 1, rowSpan, columnSpan);
  glCalc->addWidget(pb2, 0, 2, rowSpan, columnSpan);
  glCalc->addWidget(pb3, 0, 3, rowSpan, columnSpan);

  glCalc->addWidget(pb4, 1, 1, rowSpan, columnSpan);
  glCalc->addWidget(pb5, 1, 2, rowSpan, columnSpan);
  glCalc->addWidget(pb6, 1, 3, rowSpan, columnSpan);

  glCalc->addWidget(pb7, 2, 1, rowSpan, columnSpan);
  glCalc->addWidget(pb8, 2, 2, rowSpan, columnSpan);
  glCalc->addWidget(pb9, 2, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbBrLeft, 3, 1, rowSpan, columnSpan);
  glCalc->addWidget(pb0, 3, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbBrRight, 3, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbAdd, 4, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbSub, 4, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbMul, 4, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbDiv, 5, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbMod, 5, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbPow, 5, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbSin, 6, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbCos, 6, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbTan, 6, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbAsin, 7, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbAcos, 7, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbAtan, 7, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbLn, 8, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbLog10, 8, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbX, 8, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbSqrt, 9, 1, rowSpan, columnSpan);
  glCalc->addWidget(pbBack, 9, 2, rowSpan, columnSpan);
  glCalc->addWidget(pbClear, 9, 3, rowSpan, columnSpan);

  glCalc->addWidget(pbResult, 10, 3, rowSpan, columnSpan);

  vblCalc->addLayout(hblRange);
  hblRange->addWidget(spbXmin);
  hblRange->addWidget(spbXmax);
}

void BaseCalc::Connector() {
  connect(pb0, SIGNAL(clicked()), this, SLOT(slotPb0()));
  connect(pb1, SIGNAL(clicked()), this, SLOT(slotPb1()));
  connect(pb2, SIGNAL(clicked()), this, SLOT(slotPb2()));
  connect(pb3, SIGNAL(clicked()), this, SLOT(slotPb3()));
  connect(pb4, SIGNAL(clicked()), this, SLOT(slotPb4()));
  connect(pb5, SIGNAL(clicked()), this, SLOT(slotPb5()));
  connect(pb6, SIGNAL(clicked()), this, SLOT(slotPb6()));
  connect(pb7, SIGNAL(clicked()), this, SLOT(slotPb7()));
  connect(pb8, SIGNAL(clicked()), this, SLOT(slotPb8()));
  connect(pb9, SIGNAL(clicked()), this, SLOT(slotPb9()));

  connect(pbAdd, SIGNAL(clicked()), this, SLOT(slotPbAdd()));
  connect(pbSub, SIGNAL(clicked()), this, SLOT(slotPbSub()));
  connect(pbMul, SIGNAL(clicked()), this, SLOT(slotPbMul()));
  connect(pbDiv, SIGNAL(clicked()), this, SLOT(slotPbDiv()));
  connect(pbMod, SIGNAL(clicked()), this, SLOT(slotPbMod()));
  connect(pbPow, SIGNAL(clicked()), this, SLOT(slotPbPow()));

  connect(pbSin, SIGNAL(clicked()), this, SLOT(slotPbSin()));
  connect(pbCos, SIGNAL(clicked()), this, SLOT(slotPbCos()));
  connect(pbAsin, SIGNAL(clicked()), this, SLOT(slotPbAsin()));
  connect(pbAcos, SIGNAL(clicked()), this, SLOT(slotPbAcos()));
  connect(pbTan, SIGNAL(clicked()), this, SLOT(slotPbTan()));
  connect(pbAtan, SIGNAL(clicked()), this, SLOT(slotPbAtan()));
  connect(pbLog10, SIGNAL(clicked()), this, SLOT(slotPbLog10()));
  connect(pbLn, SIGNAL(clicked()), this, SLOT(slotPbLn()));
  connect(pbSqrt, SIGNAL(clicked()), this, SLOT(slotPbSqrt()));

  connect(pbClear, SIGNAL(clicked()), this, SLOT(slotPbClear()));
  connect(pbBack, SIGNAL(clicked()), this, SLOT(slotPbBack()));

  connect(pbBrLeft, SIGNAL(clicked()), this, SLOT(slotBr()));
  connect(pbBrRight, SIGNAL(clicked()), this, SLOT(slotBr()));

  connect(pbX, SIGNAL(clicked()), this, SLOT(slotPbX()));

  connect(pbResult, SIGNAL(clicked()), this, SLOT(slotPbResult()));
}

void BaseCalc::slotBr() {
  qStr = leText->text();
  qStr += qobject_cast<QPushButton*>(sender())->text();
  leText->setText(qStr);
}

void BaseCalc::slotPbClear() {
  if (!leText->text().isEmpty()) qBackStr = leText->text();
  leText->setText("");
  leText->setPlaceholderText("");
}

void BaseCalc::slotPbBack() {
  leText->setText(qBackStr);
  leText->setPlaceholderText("");
}

void BaseCalc::slotPbSqrt() {
  qStr = leText->text();
  qStr += "sqrt(";
  leText->setText(qStr);
}

void BaseCalc::slotPb0() {
  qStr = leText->text();
  qStr += "0";
  leText->setText(qStr);
}
void BaseCalc::slotPb1() {
  qStr = leText->text();
  qStr += "1";
  leText->setText(qStr);
}
void BaseCalc::slotPb2() {
  qStr = leText->text();
  qStr += "2";
  leText->setText(qStr);
}
void BaseCalc::slotPb3() {
  qStr = leText->text();
  qStr += "3";
  leText->setText(qStr);
}
void BaseCalc::slotPb4() {
  qStr = leText->text();
  qStr += "4";
  leText->setText(qStr);
}
void BaseCalc::slotPb5() {
  qStr = leText->text();
  qStr += "5";
  leText->setText(qStr);
}
void BaseCalc::slotPb6() {
  qStr = leText->text();
  qStr += "6";
  leText->setText(qStr);
}
void BaseCalc::slotPb7() {
  qStr = leText->text();
  qStr += "7";
  leText->setText(qStr);
}
void BaseCalc::slotPb8() {
  qStr = leText->text();
  qStr += "8";
  leText->setText(qStr);
}
void BaseCalc::slotPb9() {
  qStr = leText->text();
  qStr += "9";
  leText->setText(qStr);
}

void BaseCalc::slotPbAdd() {
  qStr = leText->text();
  qStr += "+";
  leText->setText(qStr);
}

void BaseCalc::slotPbSub() {
  qStr = leText->text();
  qStr += "-";
  leText->setText(qStr);
}

void BaseCalc::slotPbMul() {
  qStr = leText->text();
  qStr += "*";
  leText->setText(qStr);
}

void BaseCalc::slotPbDiv() {
  qStr = leText->text();
  qStr += "/";
  leText->setText(qStr);
}

void BaseCalc::slotPbMod() {
  qStr = leText->text();
  qStr += "%";
  leText->setText(qStr);
}

void BaseCalc::slotPbPow() {
  qStr = leText->text();
  qStr += "^";
  leText->setText(qStr);
}

void BaseCalc::slotPbSin() {
  qStr = leText->text();
  qStr += "sin(";
  leText->setText(qStr);
}

void BaseCalc::slotPbCos() {
  qStr = leText->text();
  qStr += "cos(";
  leText->setText(qStr);
}

void BaseCalc::slotPbAsin() {
  qStr = leText->text();
  qStr += "asin(";
  leText->setText(qStr);
}

void BaseCalc::slotPbAcos() {
  qStr = leText->text();
  qStr += "acos(";
  leText->setText(qStr);
}

void BaseCalc::slotPbTan() {
  qStr = leText->text();
  qStr += "tan(";
  leText->setText(qStr);
}

void BaseCalc::slotPbAtan() {
  qStr = leText->text();
  qStr += "atan(";
  leText->setText(qStr);
}

void BaseCalc::slotPbLn() {
  qStr = leText->text();
  qStr += "ln(";
  leText->setText(qStr);
}

void BaseCalc::slotPbLog10() {
  qStr = leText->text();
  qStr += "log(";
  leText->setText(qStr);
}

void BaseCalc::slotPbX() {
  qStr = leText->text();
  qStr += "x";
  leText->setText(qStr);
}

void BaseCalc::slotPbResult() {
  qStr = leText->text();
  qBackStr = qStr;
  if (qStr.isEmpty()) {
    leText->clear();
    leText->setPlaceholderText("Некорректное выражение");
  } else {
    try {
      s21::Controller controllerModel(qStr.toStdString(), spbXmin->value(),
                                      spbXmax->value());
      double result = controllerModel.callBase();
      if (controllerModel.getBase()->containX()) {
        cg->x.clear();
        cg->y.clear();
        for (double tmp : controllerModel.getBase()->getCoordX())
          cg->x.append(tmp);
        for (double tmp : controllerModel.getBase()->getCoordY())
          cg->y.append(tmp);

        cg->drawGraph();
        cg->show();
      } else {
        leText->setText(QString::number(result, 'g', 10));
      }
    } catch (std::exception& e) {
      qDebug() << e.what();
      leText->clear();
      leText->setPlaceholderText("Некорректное выражение");
    }
  }
}
