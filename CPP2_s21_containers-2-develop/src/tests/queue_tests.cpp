#include <queue>

#include "tests.h"

TEST(Queue, empty) {
  s21::queue<int> q1;
  std::queue<int> q2;

  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());
}

TEST(Queue, push) {
  s21::queue<int> q1;
  std::queue<int> q2;

  for (int i = 0; i < 10; ++i) {
    q1.push(i);
    q2.push(i);
  }

  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());

  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(Queue, initializerListConstructor) {
  s21::queue<int> q1 = {1, 2, 3, 4, 5};
  std::queue<int> q2({1, 2, 3, 4, 5});

  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.size(), q2.size());

  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(Queue, copyConstructorTest) {
  s21::queue<int> q1 = {1, 2, 3, 4, 5};
  s21::queue<int> q2(q1);
  std::queue<int> q3({1, 2, 3, 4, 5});
  std::queue<int> q4(q3);

  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());

  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(Queue, moveConstructor) {
  s21::queue<int> q1 = {1, 2, 3, 4, 5};
  s21::queue<int> q2(std::move(q1));
  std::queue<int> q3({1, 2, 3, 4, 5});
  std::queue<int> q4(std::move(q3));

  EXPECT_EQ(q2.empty(), q4.empty());
  EXPECT_EQ(q2.size(), q4.size());

  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }

  EXPECT_EQ(q1.empty(), q3.empty());
  EXPECT_EQ(q1.size(), q3.size());
}

TEST(Queue, copyAssignment) {
  s21::queue<int> q1 = {1, 2, 3, 4, 5};
  s21::queue<int> q2 = {6, 7, 8, 9, 10};
  std::queue<int> q3({1, 2, 3, 4, 5});
  std::queue<int> q4({6, 7, 8, 9, 10});

  q1 = q2;
  q3 = q4;

  EXPECT_EQ(q1.empty(), q3.empty());
  EXPECT_EQ(q1.size(), q3.size());

  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q3.front());
    q1.pop();
    q3.pop();
  }
}

TEST(Queue, swapTest) {
  s21::queue<int> q1 = {1, 2, 3, 4, 5};
  s21::queue<int> q2 = {6, 7, 8, 9, 10};
  std::queue<int> q3({1, 2, 3, 4, 5});
  std::queue<int> q4({6, 7, 8, 9, 10});

  q1.swap(q2);
  q3.swap(q4);

  EXPECT_EQ(q1.empty(), q3.empty());
  EXPECT_EQ(q1.size(), q3.size());

  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q3.front());
    q1.pop();
    q3.pop();
  }
}

// TEST(Queue, ExceptionHandlingForFrontAndBack) {
//   s21::queue<int> q;
//   EXPECT_THROW(q.front(), std::logic_error);
//   EXPECT_THROW(q.back(), std::logic_error);
// }

TEST(Queue, PopFunctionality) {
  s21::queue<int> q;
  for (int i = 1; i <= 5; ++i) q.push(i);
  q.pop();
  EXPECT_EQ(q.front(), 2);
}

TEST(Queue, InsertManyBackFunctionality) {
  s21::queue<int> q;
  q.insert_many_back(1, 2, 3, 4, 5);
  EXPECT_EQ(q.size(), 5);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 5);
}