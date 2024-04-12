QT += core gui

greaterThan(QT_MAJOR_VERSION, 4)
    : QT += widgets printsupport

          CONFIG += c++ 11

#You can make your code fail to compile if it uses deprecated APIs.
#In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE = \
    0x060000 #disables all the APIs deprecated before Qt 6.0.0

      SOURCES +=
          ../ Controller / controller.cpp../ Model / base.cpp../ Model /
          credit.cpp../ Model /
          deposit.cpp basecalc.cpp creditcalc.cpp customgraph.cpp depositcalc
          .cpp main.cpp mainframe.cpp mainwindow.cpp qcustomplot.cpp

              HEADERS +=../ Controller / controller.h../ Model / base.h../
                        Model / credit.h../ Model /
                        deposit.h basecalc.h creditcalc.h customgraph
          .h dependencies.h depositcalc.h mainframe.h mainwindow.h qcustomplot
          .h

#Default rules for deployment.
                            qnx : target.path = / tmp / $${TARGET} /
                                                bin else : unix : !android
    : target.path = / opt / $${TARGET} /
                    bin !isEmpty(target.path)
    : INSTALLS += target

                        DISTFILES += View.pro.user

                                         RESOURCES += style.qrc
