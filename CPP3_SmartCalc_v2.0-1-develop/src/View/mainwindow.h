#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dependencies.h"
#include "mainframe.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  QMenuBar* menuBar;
  QMenu* menu;

  MainFrame* mainFrame;

 private slots:
  void slotMenuBase();
  void slotMenuCredit();
  void slotMenuDeposit();
};
#endif  // MAINWINDOW_H
