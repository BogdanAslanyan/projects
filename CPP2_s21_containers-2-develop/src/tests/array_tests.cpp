#include <array>

#include "tests.h"

bool compareArrays(s21::array<int, 10> const& a, std::array<int, 10> const& b) {
  for (size_t i = 0; i < 10; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

TEST(Array, defaultConstructor) {
  s21::array<int, 10> a1;

  ASSERT_NO_THROW(a1[0]);
}

TEST(Array, DefaultConstructorValues) {
  s21::array<int, 10> arr;
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr[i], int());  // Проверяем, что все элементы инициализированы
                               // значением по умолчанию
  }
}

TEST(Array, initializerListConstructor) {
  s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(compareArrays(a1, a2), true);
}

TEST(Array, copyConstructor) {
  s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> a2{a1};

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4{a3};

  ASSERT_EQ(compareArrays(a2, a4), true);
}

TEST(Array, moveConstructor) {
  s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> a2{std::move(a1)};

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4{std::move(a3)};

  ASSERT_EQ(compareArrays(a2, a4), true);
}

TEST(Array, copyAssignment) {
  s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> a2;
  a2 = a1;

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4;
  a4 = a3;

  ASSERT_EQ(compareArrays(a2, a4), true);
}

TEST(Array, begin) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  auto it = arr.begin();
  EXPECT_EQ(*it, 8);

  *it = 11;
  EXPECT_EQ(arr[0], 11);
}

TEST(Array, end) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  auto it = arr.end();
  EXPECT_EQ(*(it - 1), 0);

  *(it - 1) = 11;
  EXPECT_EQ(arr[9], 11);
}

TEST(Array, data) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  std::array<int, 10> arr1 = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  auto it = arr.data();
  auto it1 = arr1.data();
  EXPECT_EQ(*it, 8);
  EXPECT_EQ(*it, *it1);

  *it = 11;
  EXPECT_EQ(arr[0], 11);
}

TEST(Array, atValid) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_EQ(arr.at(0), 8);
  EXPECT_EQ(arr.at(9), 0);
}

TEST(Array, atInvalid) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(Array, atConstValid) {
  const s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_EQ(arr.at(0), 8);
  EXPECT_EQ(arr.at(9), 0);
}

TEST(Array, atConstInvalid) {
  const s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_THROW(arr.at(13), std::out_of_range);
}

TEST(Array, front) {
  s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_EQ(arr.front(), 8);
}

TEST(Array, frontConst) {
  const s21::array<int, 10> arr = {8, 7, 3, 9, 5, 2, 6, 1, 4, 0};
  EXPECT_EQ(arr.front(), 8);
}

TEST(Array, back) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, backConst) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, size) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.size(), 10);
}

TEST(Array, max_size) {
  s21::array<int, 10> arr;
  EXPECT_EQ(arr.max_size(), 10);
}

TEST(Array, empty) {
  s21::array<int, 10> arr;
  EXPECT_EQ(arr.empty(), false);
}

TEST(Array, fill) {
  s21::array<int, 10> arr;
  arr.fill(5);
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr[i], 5);
  }
}

TEST(Array, swap) {
  s21::array<int, 10> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, arr2;
  arr2.swap(arr1);
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr2[i], i);
  }
}

TEST(Array, operatorSquareBrackets) {
  s21::array<int, 10> arr;
  arr.fill(5);
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr[i], 5);
  }
}

TEST(Array, operatorSquareBracketsConst) {
  s21::array<int, 10> arr;
  arr.fill(5);
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr[i], 5);
  }
}

TEST(Array, operatorSquareBracketsConstInvalid) {
  s21::array<int, 10> arr;
  arr.fill(5);
  EXPECT_THROW(arr[13], std::out_of_range);
}

TEST(Array, operatorSquareBracketsInvalid) {
  s21::array<int, 10> arr;
  arr.fill(5);
  EXPECT_THROW(arr[13], std::out_of_range);
}

TEST(Array, operatorAssignment) {
  s21::array<int, 10> arr1, arr2;
  arr1.fill(5);
  arr2 = arr1;
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr2[i], 5);
  }
}

TEST(Array, operatorAssignmentInitializerList) {
  s21::array<int, 10> arr;
  arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr[i], i);
  }
}

TEST(Array, operatorAssignmentInitializerListInvalid) {
  s21::array<int, 10> arr;
  EXPECT_THROW((arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13}),
               std::out_of_range);
}

TEST(Array, moveOperator) {
  s21::array<int, 10> arr1, arr2;
  arr1.fill(5);
  arr2 = std::move(arr1);
  for (size_t i = 0; i < 10; ++i) {
    EXPECT_EQ(arr2[i], 5);
  }
}

TEST(Array, Iterator) {
  s21::array<int, 10> arr;
  arr.fill(5);
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    EXPECT_EQ(*it, 5);
  }
}

TEST(Array, MaxSize) {
  s21::array<int, 10> arr;
  EXPECT_EQ(arr.max_size(), 10);
}
