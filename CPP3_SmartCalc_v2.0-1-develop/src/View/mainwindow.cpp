#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setFixedSize(400, 400);
  setWindowTitle("Smart Calc");

  mainFrame = new MainFrame();
  menuBar = new QMenuBar(this);
  menu = new QMenu("Calculator type", this);

  menuBar->setFixedSize(400, 25);
  menuBar->addMenu(menu);
  menu->addAction("Base calculator", this, SLOT(slotMenuBase()));
  menu->addAction("Credit calculator", this, SLOT(slotMenuCredit()));
  menu->addAction("Deposit calculator", this, SLOT(slotMenuDeposit()));

  setCentralWidget(mainFrame);

  slotMenuBase();

  menuBar->raise();
}

MainWindow::~MainWindow() { delete mainFrame; }

void MainWindow::slotMenuBase() {
  setWindowTitle("Smart Calc");
  mainFrame->creditCalc->hide();
  mainFrame->depositCalc->hide();
  mainFrame->baseCalc->show();
  menuBar->raise();
}

void MainWindow::slotMenuCredit() {
  setWindowTitle("Credit Calc");
  mainFrame->depositCalc->hide();
  mainFrame->baseCalc->hide();
  mainFrame->creditCalc->show();
  menuBar->raise();
}

void MainWindow::slotMenuDeposit() {
  setWindowTitle("Deposit Calc");
  mainFrame->creditCalc->hide();
  mainFrame->baseCalc->hide();
  mainFrame->depositCalc->show();
  menuBar->raise();
}
