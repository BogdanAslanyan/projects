#include "base.h"

namespace s21 {
void Base::parsSrcStr() {
  std::vector<std::string> delimiters = {"(", ")", "+",   "-", "/", "*",
                                         "^", "%", "mod", "e", "E"};

  for (const auto& delimiter : delimiters) {
    size_t pos = 0;
    while ((pos = inputStr.find(delimiter, pos)) != std::string::npos) {
      inputStr.insert(pos, " ");
      inputStr.insert(pos + delimiter.length() + 1, " ");
      pos += delimiter.length() + 2;
    }
  }

  std::string tmp = inputStr;
  std::cout << tmp << std::endl;

  size_t pos = 0;

  while ((pos = tmp.find(' ')) != std::string::npos) {
    if (isExp(tmp.substr(0, pos))) {
      sourceData->emplace_back("*", 0, 0);
      sourceData->emplace_back("10", 0, 10);
      sourceData->emplace_back("^", 0, 0);
    } else if (tmp.substr(0, pos) != "") {
      if (isX(tmp.substr(0, pos))) wasX = true;
      sourceData->emplace_back(
          tmp.substr(0, pos), 0,
          isDoubleNumber(tmp.substr(0, pos)) ? std::stod(tmp) : 0);
    }
    tmp.erase(0, pos + 1);
  }

  if (tmp != "") {
    if (isX(tmp)) wasX = true;
    sourceData->emplace_back(tmp, 0, isDoubleNumber(tmp) ? std::stod(tmp) : 0);
  }

  // // отладочный вывод
  for (auto it = sourceData->begin(); it != sourceData->end(); it++) {
    std::cout << it->data_ << " | " << it->priority_ << "\n";
  }

  verify();
  setPriority();
  setRevPolNot();

  // отладочный вывод
  for (auto it = rpn->begin(); it != rpn->end(); it++) {
    std::cout << it->data_ << " | " << it->priority_ << "\n";
  }
  std::cout << std::endl;
}

bool Base::isExp(const std::string& token) {
  return token == "e" || token == "E" ? true : false;
}

bool Base::isX(const std::string& token) {
  return token == "x" || token == "X" ? true : false;
}

void Base::replaceX(double x) {
  for (size_t i = 0; i < rpn->size(); i++) {
    if (isX(rpn->at(i).data_)) {
      rpn->at(i).data_ = "";
      rpn->at(i).value_ = x;
    }
  }
}

void Base::setRevPolNot() {
  std::stack<Node> stack;
  for (size_t i = 0; i < sourceData->size(); i++) {
    std::string data = sourceData->at(i).data_;
    int priority = sourceData->at(i).priority_;
    double value = sourceData->at(i).value_;

    if (priority == 0) {
      rpn->emplace_back(data, priority, value);
    } else if ((priority == 1 || priority == 7) && !data.empty()) {
      stack.emplace(data, priority, value);
    } else if (priority >= 3 && priority <= 6) {
      if (!stack.empty()) {
        while (!stack.empty() && stack.top().priority_ > priority &&
               priority != 5) {
          rpn->emplace_back(stack.top().data_, stack.top().priority_,
                            stack.top().value_);
          stack.pop();
        }
      }
      stack.emplace(data, priority, value);
    } else if (priority == 2) {
      while (!stack.empty() && stack.top().priority_ != 1) {
        rpn->emplace_back(stack.top().data_, stack.top().priority_,
                          stack.top().value_);
        stack.pop();
      }
      if (!stack.empty()) {
        stack.pop();
      } else {
        badInput();
        throw std::runtime_error("Bracket balance violated");
      }

      if (!stack.empty() && stack.top().priority_ == 7) {
        rpn->emplace_back(stack.top().data_, stack.top().priority_,
                          stack.top().value_);
        stack.pop();
      }
    }
    if (i == sourceData->size() - 1) {
      while (!stack.empty()) {
        if (stack.top().priority_ == 1 || stack.top().priority_ == 2) {
          badInput();
          throw std::runtime_error("Bracket balance violated");
        }
        rpn->emplace_back(stack.top().data_, stack.top().priority_,
                          stack.top().value_);
        stack.pop();
      }
    }
  }
}

void Base::setPriority() {
  for (size_t i = 0; i < sourceData->size(); i++) {
    if (sourceData->at(i).data_ == "+" || sourceData->at(i).data_ == "-") {
      if (i == 0 || sourceData->at(i - 1).data_ == "(" ||
          isOp(sourceData->at(i - 1).data_)) {
        sourceData->at(i).priority_ = 6;
      } else {
        sourceData->at(i).priority_ = 3;
      }
    } else if (sourceData->at(i).data_ == "(") {
      sourceData->at(i).priority_ = 1;
    } else if (sourceData->at(i).data_ == ")") {
      sourceData->at(i).priority_ = 2;
    } else if (sourceData->at(i).data_ == "*" ||
               sourceData->at(i).data_ == "/" ||
               sourceData->at(i).data_ == "%" ||
               sourceData->at(i).data_ == "mod") {
      sourceData->at(i).priority_ = 4;
    } else if (sourceData->at(i).data_ == "^") {
      sourceData->at(i).priority_ = 5;
    } else {
      if (!isDoubleNumber(sourceData->at(i).data_) &&
          sourceData->at(i).data_ != "x" && sourceData->at(i).data_ != "X")
        sourceData->at(i).priority_ = 7;  // функция
    }
  }
}

double Base::calcUnaryOper(double tmp, std::string token) {
  double res = 0;

  if (token == "+") {
    res = tmp;
  } else if (token == "-") {
    res = -tmp;
  } else if (token == "sin") {
    res = sin(tmp);
  } else if (token == "cos") {
    res = cos(tmp);
  } else if (token == "tan") {
    if (fabs(fmod(tmp, M_PI / 2.)) > 1.570796) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = tan(tmp);
    }
  } else if (token == "acos") {
    if (tmp > 1. || tmp < -1.) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = acos(tmp);
    }
  } else if (token == "asin") {
    if (tmp > 1. || tmp < -1.) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = asin(tmp);
    }
  } else if (token == "atan") {
    res = atan(tmp);
  } else if (token == "sqrt") {
    if (tmp < 0) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = sqrt(tmp);
    }
  } else if (token == "ln") {
    if (tmp <= 0.) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = log(tmp);
    }
  } else if (token == "log") {
    if (tmp <= 0.) {
      badInput();
      throw std::runtime_error("Bad Input");
    } else {
      res = log10(tmp);
    }
  }

  return res;
}

void Base::badInput() { wasError = true; }

void Base::verify() {
  for (size_t i = 0; i < sourceData->size(); i++) {
    if (isDoubleNumber(sourceData->at(i).data_) ||
        isCorrectOperand(sourceData->at(i).data_)) {
      if (i == 0) continue;
      if (isCorrectOperand(sourceData->at(i).data_) &&
          sourceData->at(i - 1).data_ == "(" &&
          sourceData->at(i + 1).data_ == ")") {
        badInput();
        throw std::runtime_error("Incorrect input 3");
      }
      if (!(isOp(sourceData->at(i - 1).data_) &
            isOp(sourceData->at(i).data_))) {
        continue;
      } else {
        badInput();
        throw std::runtime_error("Incorrect input 2");
      }
    } else {
      badInput();
      throw std::runtime_error("Incorrect input 1");
    }
  }
}

double Base::calcBinaryOper(double tmp1, double tmp2, std::string oper) {
  double res = 0;
  if (oper == "+") {
    res = tmp1 + tmp2;
  } else if (oper == "-") {
    res = tmp1 - tmp2;
  } else if (oper == "*") {
    res = tmp1 * tmp2;
  } else if (oper == "/") {
    if (fabs(tmp2) <= 1e-8) {
      badInput();
      throw std::runtime_error("Сalculation error");
    }
    res = tmp1 / tmp2;
  } else if (oper == "%" || oper == "mod") {
    res = fmod(tmp1, tmp2);
  } else if (oper == "^") {
    res = pow(tmp1, tmp2);
  }

  return res;
}

double Base::calcExpression(double x) {
  std::stack<Node> stack;
  for (size_t i = 0; i < rpn->size(); i++) {
    std::string data = rpn->at(i).data_;
    int priority = rpn->at(i).priority_;
    double value = rpn->at(i).value_;
    if (priority == 0) {
      if (isX(data))
        stack.emplace(data, priority, x);
      else
        stack.emplace(data, priority, value);
    } else if (priority >= 3 && priority <= 5) {
      double tmp2 = stack.top().value_;
      stack.pop();
      double tmp1 = stack.top().value_;
      stack.pop();
      stack.emplace("", 0, calcBinaryOper(tmp1, tmp2, data));
    } else if (priority == 6 || priority == 7) {
      double tmp = stack.top().value_;
      stack.pop();
      stack.emplace("", 0, calcUnaryOper(tmp, data));
    }
  }
  result = stack.top().value_;
  stack.pop();

  return result;
}

void Base::calcExpression(double xMin, double xMax) {
  double x = xMin;
  double h = 0.00005;
  coord.first.clear();
  coord.second.clear();
  if (fabs(x - fabs(xMax - x)) > 1000.) h = 0.01;
  if (fabs(x - fabs(xMax - x)) > 10000.) h = 0.1;
  if (fabs(x - fabs(xMax - x)) > 100000.) h = 1;
  if (fabs(x - fabs(xMax - x)) > 500000.) h = 10;
  while (x < xMax) {
    coord.first.push_back(x);
    coord.second.push_back(calcExpression(x));
    x += h;
  }
  coord.first.push_back(x);
  coord.second.push_back(calcExpression(x));
  std::cout << "END CALC" << std::endl;
}

bool Base::isOp(std::string& str) {
  std::vector<std::string> operators = {"+", "-", "*", "/", "%", "mod", "^"};
  for (size_t i = 0; i < operators.size(); i++)
    if (str == operators[i]) return true;
  return false;
}

bool Base::isCorrectOperand(std::string& str) {
  std::vector<std::string> patterns = {
      "sin", "cos", "tan", "acos", "asin", "atan", "sqrt", "ln",
      "log", "mod", "(",   ")",    "+",    "-",    "/",    "*",
      "%",   "x",   "X",   " ",    "^",    "e",    "E"};
  for (size_t i = 0; i < patterns.size(); i++) {
    if (str == patterns[i]) return true;
  }
  return false;
}

bool Base::isDoubleNumber(const std::string& str) {
  std::stringstream iss(str);
  double val;
  iss >> val;
  return iss.eof() && !iss.fail();
}

}  // namespace s21
