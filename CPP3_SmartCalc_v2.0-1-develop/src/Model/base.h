#ifndef BASE_H
#define BASE_H

// #include <boost/algorithm/string.hpp>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {

class Base {
 public:
  Base(std::string input = "")
      : inputStr(input),
        sourceData(new std::vector<Node>()),
        rpn(new std::vector<Node>()),
        result(0),
        wasError(false) {}
  ~Base() {
    sourceData->clear();
    delete sourceData;
    rpn->clear();
    delete rpn;
  }
  double getResult() const { return result; }
  bool containX() const { return wasX; }
  void replaceX(double x);
  std::string getStr() const { return inputStr; }
  void parsSrcStr();
  double calcExpression(double x);
  void calcExpression(double xMin, double xMax);
  std::vector<double> getCoordX() { return coord.first; }
  std::vector<double> getCoordY() { return coord.second; }

 private:
  class Node {
   public:
    Node(std::string data = "", int priority = 0, double value = 0.)
        : data_(data), priority_(priority), value_(value) {}
    ~Node() {}

    std::string data_;
    int priority_;
    double value_;
  };

  std::string inputStr;
  std::vector<Node>* sourceData;  // source tokens
  std::vector<Node>* rpn;         // reverse polish notation
  double result;
  bool wasError;
  bool wasX;
  std::pair<std::vector<double>, std::vector<double>> coord;

  bool isDoubleNumber(const std::string& str);
  bool isCorrectOperand(std::string& str);
  bool isExp(const std::string& token);
  bool isX(const std::string& token);

  void setPriority();
  void setRevPolNot();
  bool isOp(std::string& str);
  double calcBinaryOper(double tmp1, double tmp2, std::string oper);
  double calcUnaryOper(double tmp, std::string oper);
  void badInput();
  void verify();
};
}  // namespace s21

#endif  // BASE_H
