#include "creditcalc.h"

#include "../Model/credit.h"

CreditCalc::CreditCalc(QFrame* parent) : QFrame{parent} {
  Designer();
  Properties();
  Layouts();
  Connector();
}

void CreditCalc::Designer() {
  glButtons = new QGridLayout(this);
  pbResult = new QPushButton("Посчитать", this);
  cmType = new QComboBox(this);
  dsbSum = new QDoubleSpinBox(this);

  lTime = new QLabel("Срок кредита (мес.)", this);
  lPersent = new QLabel("Процентная ставка", this);
  sbTime = new QSpinBox(this);
  dsbPersent = new QDoubleSpinBox(this);
  lSum = new QLabel("Cумма кредита", this);

  lStartDate = new QLabel("Начало срока (д.м.г.)", this);
  sbStartDateDay = new QSpinBox(this);
  sbStartDateMonth = new QSpinBox(this);
  sbStartDateYear = new QSpinBox(this);

  outputAnn = new QFrame(this);
  glOutAnn = new QGridLayout(this);
  lMonthlyPayment = new QLabel(this);
  lOverpayment = new QLabel(this);
  lTotalPayment = new QLabel(this);
  pbCloseAnn = new QPushButton("Закрыть", this);

  outputDiff = new QFrame(this);
  hblOutDiff = new QVBoxLayout(this);
  glOutDiff = new QGridLayout(this);
  lOverpaymentDiff = new QLabel(this);
  lTotalPaymentDiff = new QLabel(this);
  pbCloseDiff = new QPushButton("Закрыть", this);
  saDiff = new QScrollArea(this);

  lMonthlyPaymentDiff = new QLabel(this);
}

void CreditCalc::Properties() {
  this->setFixedSize(400, 400);
  pbResult->setFixedSize(100, 40);
  //    cmType->setFixedSize(200, 40);
  //    dsbSum->setFixedSize(200, 40);
  dsbSum->setMaximumSize(200, 25);
  dsbSum->setRange(0, 1000000000);

  sbTime->setMaximumSize(70, 25);
  dsbPersent->setMaximumSize(70, 25);

  lTime->setMinimumSize(200, 25);
  lPersent->setMinimumSize(200, 25);

  cmType->addItem("аннуитетный тип ежемесячных платежей");
  cmType->addItem("дифференцированный тип ежемесячных платежей");

  sbStartDateYear->setRange(1900, 2500);
  sbStartDateMonth->setRange(1, 12);
  sbStartDateYear->setValue(QDate::currentDate().year());
  sbStartDateMonth->setValue(QDate::currentDate().month());
  sbStartDateDay->setValue(QDate::currentDate().day());
  setStartDay();

  outputAnn->setFixedSize(400, 400);

  lMonthlyPayment->setMaximumSize(400, 40);
  lOverpayment->setMaximumSize(400, 40);
  lTotalPayment->setMaximumSize(400, 40);
  pbCloseAnn->setFixedSize(60, 40);

  saDiff->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  saDiff->setWidgetResizable(true);
  saDiff->setGeometry(0, 25, 400, 380);

  lOverpaymentDiff->setMaximumSize(400, 40);
  lTotalPaymentDiff->setMaximumSize(400, 40);
  pbCloseDiff->setFixedSize(60, 40);

  outputAnn->hide();
  saDiff->hide();
}

void CreditCalc::Layouts() {
  this->setLayout(glButtons);

  glButtons->addWidget(cmType, 0, 0, 1, 4);
  glButtons->addWidget(lSum, 2, 0, 1, 1);
  glButtons->addWidget(dsbSum, 2, 1, 1, 3);
  glButtons->addWidget(lTime, 3, 0, 1, 1);
  glButtons->addWidget(sbTime, 3, 1, 1, 3);
  glButtons->addWidget(lPersent, 4, 0, 1, 1);
  glButtons->addWidget(dsbPersent, 4, 1, 1, 3);

  glButtons->addWidget(lStartDate, 5, 0, 1, 1);
  glButtons->addWidget(sbStartDateDay, 5, 1, 1, 1);
  glButtons->addWidget(sbStartDateMonth, 5, 2, 1, 1);
  glButtons->addWidget(sbStartDateYear, 5, 3, 1, 1);

  glButtons->addWidget(pbResult, 6, 0, 1, 1);

  outputAnn->setLayout(glOutAnn);
  glOutAnn->addWidget(lMonthlyPayment, 0, 0, 1, 2);
  glOutAnn->addWidget(lOverpayment, 1, 0, 1, 2);
  glOutAnn->addWidget(lTotalPayment, 2, 0, 1, 2);
  glOutAnn->addWidget(pbCloseAnn, 3, 1, 1, 1);

  saDiff->setWidget(outputDiff);
  outputDiff->setLayout(glOutDiff);

  glOutDiff->addWidget(lMonthlyPaymentDiff, 1, 0, 1, 2);
  glOutDiff->addWidget(lOverpaymentDiff, 2, 0, 1, 2);
  glOutDiff->addWidget(lTotalPaymentDiff, 3, 0, 1, 2);
  glOutDiff->addWidget(pbCloseDiff, 4, 1, 1, 1);
}

void CreditCalc::Connector() {
  connect(pbResult, SIGNAL(clicked()), this, SLOT(slotPbResult()));
  connect(pbCloseAnn, SIGNAL(clicked()), this, SLOT(slotPbCloseAnn()));
  connect(pbCloseDiff, SIGNAL(clicked()), this, SLOT(slotPbCloseDiff()));

  connect(sbStartDateYear, SIGNAL(valueChanged(int)), this,
          SLOT(setStartDay()));
  connect(sbStartDateMonth, SIGNAL(valueChanged(int)), this,
          SLOT(setStartDay()));
}

void CreditCalc::setStartDay() {
  int date = 0;
  date = sbStartDateMonth->value() == 12 ? 0 : sbStartDateMonth->value();
  date =
      s21::Credit::dateCorrect(static_cast<s21::Date>(date),
                               s21::Credit::isLeap(sbStartDateYear->value()));
  sbStartDateDay->setRange(1, date);
}

void CreditCalc::slotPbCloseAnn() { outputAnn->hide(); }

void CreditCalc::slotPbCloseDiff() { saDiff->hide(); }

void CreditCalc::slotPbResult() {
  s21::CreditData cd;
  cd.type = cmType->currentIndex();
  cd.interestRate = dsbPersent->value();
  cd.totalCredit = dsbSum->value();
  cd.term = sbTime->value();
  cd.mainMonthSum = cd.totalCredit / cd.term;
  s21::Controller controller(&cd);

  if (!cd.type) {
    controller.callCredit();
    lMonthlyPayment->setText("Ежемесячный платеж: " +
                             QString::number(cd.monthlyPayment, 'f', 2));
    lOverpayment->setText("Переплата по кредиту: " +
                          QString::number(cd.overpaymentOnCredit, 'f', 2));
    lTotalPayment->setText("Общая выплата: " +
                           QString::number(cd.totalPayment, 'f', 2));
    outputAnn->show();
  } else if (cd.type) {
    qDebug() << "mainMonthSum: " << cd.mainMonthSum;
    QString strMonth = NULL;
    int dateTmp = sbStartDateMonth->value();
    int currYear = sbStartDateYear->value();
    cd.days = sbStartDateDay->value();

    for (int i = 0; i < cd.term; i++) {
      controller.getCredit()->calcMothForDiff(i, dateTmp, currYear);
      strMonth += QString::number(currYear + (dateTmp - 1 + i) / 12);
      strMonth += " ";
      dateToString(static_cast<s21::Date>(cd.date), &strMonth);
      strMonth += ": ";
      controller.callCredit();
      strMonth += QString::number(cd.monthlyPayment, 'f', 2);
      strMonth += "\n";
      lMonthlyPaymentDiff->setText(strMonth);
    }

    lOverpaymentDiff->setText("Переплата по кредиту: " +
                              QString::number(cd.overpaymentOnCredit, 'f', 2));
    lTotalPaymentDiff->setText("Общая выплата: " +
                               QString::number(cd.totalPayment, 'f', 2));

    saDiff->show();
  }
}

void CreditCalc::dateToString(s21::Date date, QString* strDate) {
  if (date == s21::Date::JANUARY)
    *strDate += "JANUARY";
  else if (date == s21::Date::FEBRUARY)
    *strDate += "FEBRUARY";
  else if (date == s21::Date::MARCH)
    *strDate += "MARCH";
  else if (date == s21::Date::APRIL)
    *strDate += "APRIL";
  else if (date == s21::Date::MAY)
    *strDate += "MAY";
  else if (date == s21::Date::JUNE)
    *strDate += "JUNE";
  else if (date == s21::Date::JULY)
    *strDate += "JULY";
  else if (date == s21::Date::AUGUST)
    *strDate += "AUGUST";
  else if (date == s21::Date::SEPTEMBER)
    *strDate += "SEPTEMBER";
  else if (date == s21::Date::OCTOBER)
    *strDate += "OCTOBER";
  else if (date == s21::Date::NOVEMBER)
    *strDate += "NOVEMBER";
  else if (date == s21::Date::DECEMBER)
    *strDate += "DECEMBER";
}
