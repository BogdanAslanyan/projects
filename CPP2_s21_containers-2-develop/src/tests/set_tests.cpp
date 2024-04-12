#include "tests.h"

TEST(SET, constructor1) { s21::set<int> s; }

TEST(SET, constructor2) { s21::set<int> numbers{1, 2, 3}; }

TEST(SET, constructor3) {
  s21::set<int> num1{1, 2, 3};
  s21::set<int> num2(num1);
}

TEST(SET, constructor4) {
  s21::set<int> num1{1, 2, 3};
  s21::set<int> num2(std::move(num1));
}

TEST(SET, constructor5) {
  s21::set<int> num1{1, 2, 3};
  s21::set<int> num2 = num1;
}

TEST(SET, InitializerListConstructor) {
  s21::set<char> test1{'c', 'b', 'b', 'b', 'r', 't'};
  std::set<char> test1_m{'c', 'b', 'b', 'b', 'r', 't'};

  auto start = test1.begin();
  auto start_m = test1_m.begin();
  auto end_m = test1_m.end();

  for (; start_m != end_m; ++start_m, ++start) {
    ASSERT_EQ(*start_m, *start);
  }
}

TEST(SET, capacity1) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  ASSERT_FALSE(num1.empty());
}

TEST(SET, capacity2) {
  s21::set<int> num1;
  ASSERT_TRUE(num1.empty());
}

TEST(SET, capacity3) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  ASSERT_EQ(num1.size(), 5);
}

TEST(SET, capacity4) {
  s21::set<int> num1{1, 2, 3};
  ASSERT_EQ(num1.size(), 3);
}

// TEST(SET, capacity5) {
//   s21::set<double> num1{1.2, 2.5, 7.4};
//   ASSERT_EQ(num1.max_size(), 3);
// }

// TEST(SET, capacity6) {
//   s21::set<int> num1{1, 2, 3};
//   ASSERT_EQ(num1.max_size(), 3);
// }

// TEST(SET, modifier1) {
//   s21::set<int> num1{1, 2, 3, 4, 5};
//   num1.clear();
//   ASSERT_TRUE(num1.empty());
// }

TEST(SET, modifier2) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  num1.insert(6);
  ASSERT_EQ(num1.size(), 6);
}

TEST(SET, modifier3) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  auto it = num1.find(2);
  num1.erase(it);
  ASSERT_EQ(num1.size(), 4);
  ASSERT_FALSE(num1.contains(2));
}

TEST(SET, modifier4) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  s21::set<int> num2{6, 7};
  num1.swap(num2);
  ASSERT_EQ(num1.size(), 2);
  ASSERT_EQ(num2.size(), 5);
}

TEST(SET, modifier5) {
  s21::set<int> num1{1, 2};
  s21::set<int> num2{6, 7};
  num1.merge(num2);
  ASSERT_EQ(num1.size(), 4);
}

TEST(SET, lookup1) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  ASSERT_TRUE(num1.contains(3));
}

TEST(SET, lookup2) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  ASSERT_TRUE(num1.contains(3));
}

TEST(SET, modifier6) {
  s21::set<int> num1{1, 2, 3, 4, 5};
  auto it = num1.find(4);
  num1.erase(it);
  ASSERT_EQ(num1.size(), 4);
  ASSERT_FALSE(num1.contains(4));
}

// Тестирование удаления узла без правого поддерева
TEST(SET, modifier_remove_node_without_right_subtree) {
  s21::set<int> num1{1, 2, 3, 4, 5};

  // Удаление узла со значением 2 (без правого поддерева)
  auto it = num1.find(2);
  num1.erase(it);

  // Проверка, что размер уменьшился, и узел больше не содержится в множестве
  ASSERT_EQ(num1.size(), 4);
  ASSERT_FALSE(num1.contains(2));
}

// Тестирование удаления узла без левого и правого поддеревьев (листовой узел)
TEST(SET, modifier_remove_leaf_node) {
  s21::set<int> num1{1, 2, 3, 4, 5};

  // Удаление листового узла со значением 5
  auto it = num1.find(5);
  num1.erase(it);

  // Проверка, что размер уменьшился, и узел больше не содержится в множестве
  ASSERT_EQ(num1.size(), 4);
  ASSERT_FALSE(num1.contains(5));
}

// Тестирование удаления узла с одним левым потомком
TEST(SET, modifier_remove_node_with_one_left_child) {
  s21::set<int> num1{1, 2, 3, 4, 5};

  // Удаление узла со значением 4 (с одним левым потомком)
  auto it = num1.find(4);
  num1.erase(it);

  // Проверка, что размер уменьшился, и узел больше не содержится в множестве
  ASSERT_EQ(num1.size(), 4);
  ASSERT_FALSE(num1.contains(4));
}
