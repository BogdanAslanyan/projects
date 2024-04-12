#include <stack>

#include "tests.h"

TEST(Stack, defaultConstructor) {
  s21::stack<int> s1;
  std::stack<int> s2;

  ASSERT_EQ(s1.empty(), s2.empty());
  ASSERT_EQ(s1.size(), s2.size());
}

TEST(Stack, defaultConstructorWithValues) {
  s21::stack<int> s1 = {1, 2, 3, 4, 5};
  std::stack<int> s2;

  for (int i : {1, 2, 3, 4, 5}) {
    s2.push(i);
  }

  EXPECT_EQ(s1.empty(), s2.empty());

  while (!s1.empty()) {
    EXPECT_EQ(s1.top(), s2.top());
    s1.pop();
    s2.pop();
  }
}

TEST(Stack, push) {
  s21::stack<int> s1;
  std::stack<int> s2;

  s1.push(1);
  s1.push(2);
  s1.push(3);

  s2.push(1);
  s2.push(2);
  s2.push(3);

  EXPECT_EQ(s1.size(), s2.size());

  while (!s1.empty()) {
    EXPECT_EQ(s1.top(), s2.top());
    s1.pop();
    s2.pop();
  }
}

TEST(Stack, pop) {
  s21::stack<int> s1;
  std::stack<int> s2;

  s1.push(1);
  s1.push(2);
  s1.push(3);

  s2.push(1);
  s2.push(2);
  s2.push(3);

  s1.pop();
  s2.pop();

  EXPECT_EQ(s1.top(), s2.top());
}

TEST(Stack, swap) {
  s21::stack<int> s1;
  s21::stack<int> s2;

  std::stack<int> s3;
  std::stack<int> s4;

  s1.push(1);
  s1.push(2);
  s1.push(3);

  s3.push(1);
  s3.push(2);
  s3.push(3);

  s2.push(4);
  s2.push(5);
  s2.push(6);

  s4.push(4);
  s4.push(5);
  s4.push(6);

  s1.swap(s2);
  s3.swap(s4);

  EXPECT_EQ(s1.top(), s3.top());
  EXPECT_EQ(s2.top(), s4.top());
}

TEST(Stack, insert_many_front) {
  s21::stack<int> s1;

  s1.insert_many_front(1, 2, 3, 4, 5);

  for (int i = 5; i > 0; --i) {
    EXPECT_EQ(s1.top(), i);
    s1.pop();
  }
}

TEST(Stack, copyConstructor) {
  s21::stack<int> s1;

  s1.push(1);
  s1.push(2);
  s1.push(3);

  s21::stack<int> s2(s1);

  for (int i = 3; i > 0; --i) {
    EXPECT_EQ(s2.top(), i);
    s2.pop();
  }
}

TEST(Stack, MoveAssignment) {
  s21::stack<int> s1;
  s1.push(1);
  s1.push(2);
  s21::stack<int> s2;
  s2 = std::move(s1);
  EXPECT_EQ(s2.top(), 2);
  EXPECT_TRUE(s1.empty());
}

TEST(Stack, EmptyOnNewStack) {
  s21::stack<int> s;
  EXPECT_TRUE(s.empty());
}

TEST(Stack, SizeOnNewStack) {
  s21::stack<int> s;
  EXPECT_EQ(s.size(), 0);
}

TEST(Stack, SizeAndEmptyAfterPush) {
  s21::stack<int> s;
  s.push(1);
  EXPECT_FALSE(s.empty());
  EXPECT_EQ(s.size(), 1);
}

TEST(Stack, SizeAndEmptyAfterPop) {
  s21::stack<int> s;
  s.push(1);
  s.pop();
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(StackTest, InitializerListConstructor) {
  s21::stack<int> my_stack({1, 2, 3});
  std::stack<int> std_stack({1, 2, 3});

  ASSERT_EQ(my_stack.empty(), std_stack.empty());
  ASSERT_EQ(my_stack.size(), std_stack.size());
  ASSERT_EQ(my_stack.top(), std_stack.top());
}