#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;

  QFile styleFile(":/new/style/DarkGrey.qss");
  if (styleFile.open(QFile::ReadOnly)) {
    QString styleSheet = QLatin1String(styleFile.readAll());
    a.setStyleSheet(styleSheet);
  } else
    qDebug() << "Style can't be loaded.";

  w.show();
  return a.exec();
}
