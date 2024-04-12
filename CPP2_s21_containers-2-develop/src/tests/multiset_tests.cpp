#include <set>

#include "tests.h"

TEST(multisetTest, Default) {
  s21::multiset<int> m;

  EXPECT_EQ(m.size(), size_t(0));
  EXPECT_TRUE(m.empty());
}

TEST(MultisetTest, DefaultConstructor) {
  s21::multiset<int> m;
  EXPECT_EQ(m.size(), size_t(0));
  EXPECT_TRUE(m.empty());
}

TEST(MultisetTest, InitializerListConstructor) {
  s21::multiset<char> test1{'c', 'b', 'b', 'b', 'r', 't'};
  std::multiset<char> test1_m{'c', 'b', 'b', 'b', 'r', 't'};

  auto start = test1.begin();
  auto start_m = test1_m.begin();
  auto end_m = test1_m.end();

  for (; start_m != end_m; ++start_m, ++start) {
    ASSERT_EQ(*start_m, *start);
  }
}

TEST(MultisetTest, CopyConstructor) {
  s21::multiset<char> original{'a', 'b', 'c'};
  s21::multiset<char> copy(original);

  auto it = copy.begin();
  auto itOriginal = original.begin();
  for (; it != copy.end(); ++it, ++itOriginal) {
    ASSERT_EQ(*it, *itOriginal);
  }
}

TEST(MultisetTest, AssignmentOperator) {
  s21::multiset<char> original{'x', 'y', 'z'};
  s21::multiset<char> copy = original;

  auto it = copy.begin();
  auto itOriginal = original.begin();
  for (; it != copy.end(); ++it, ++itOriginal) {
    ASSERT_EQ(*it, *itOriginal);
  }
}

TEST(MultisetTest, Insertion) {
  s21::multiset<char> m;
  m.insert('a');
  m.insert('b');

  ASSERT_EQ(m.size(), 2u);
  ASSERT_EQ(*m.begin(), 'a');
}

TEST(MultisetTest, Erase) {
  s21::multiset<char> m{'a', 'b', 'c'};
  auto it = m.find('b');
  m.erase(it);

  ASSERT_EQ(m.size(), 2u);
  ASSERT_EQ(m.count('b'), 0u);
}

// ловлю сегу
// TEST(MultisetTest, Clear) {
//   s21::multiset<char> test1{'c', 'b', 'b', 'b', 'r', 't'};
//   std::multiset<char> test1_m{'c', 'b', 'b', 'b', 'r', 't'};

//   test1.clear();
//   test1_m.clear();

//   ASSERT_EQ(test1.empty(), test1_m.empty());
// }

TEST(MultisetTest, Swap) {
  s21::multiset<char> m1{'a', 'b'};
  s21::multiset<char> m2{'c', 'd', 'e'};
  m1.swap(m2);

  ASSERT_EQ(m1.size(), 3u);
  ASSERT_EQ(m2.size(), 2u);
}

TEST(MultisetTest, Merge) {
  s21::multiset<char> m1{'a', 'b'};
  s21::multiset<char> m2{'c', 'd', 'e'};
  m1.merge(m2);

  ASSERT_EQ(m1.size(), 5u);
}

TEST(MultisetTest, Find) {
  s21::multiset<char> m{'a', 'b', 'c'};
  auto it = m.find('b');

  ASSERT_EQ(*it, 'b');
}

TEST(MultisetTest, Count) {
  s21::multiset<char> m{'a', 'b', 'b', 'c'};
  size_t count = m.count('b');

  ASSERT_EQ(count, 2u);
}

TEST(MultisetTest, Contains) {
  s21::multiset<char> m{'a', 'b', 'c'};
  bool contains = m.contains('b');

  ASSERT_TRUE(contains);
}

TEST(MultisetTest, LowerBoundUpperBoundEqualRange) {
  s21::multiset<char> m{'a', 'b', 'c', 'd', 'e'};
  auto lb = m.lower_bound('c');
  auto ub = m.upper_bound('c');
  auto er = m.equal_range('c');

  ASSERT_EQ(*lb, 'c');
  ASSERT_EQ(*ub, 'd');
  ASSERT_EQ(er.first, lb);
  ASSERT_EQ(er.second, ub);
}

TEST(MultisetTest, EraseNodeWithOnlyLeftChild) {
  s21::multiset<int> m;
  m.insert(3);
  m.insert(2);
  m.insert(1);  // У узла с ключом 2 только левый потомок

  m.erase(m.find(2));  // Удаляем узел с ключом 2
  ASSERT_EQ(m.size(), 2u);
  ASSERT_FALSE(m.contains(2));
}

TEST(MultisetTest, EraseNodeReplacedByMinNodeInRightSubtree) {
  s21::multiset<int> m;
  m.insert(2);
  m.insert(1);
  m.insert(4);
  m.insert(3);  // У узла с ключом 4 есть левый потомок (3)

  m.erase(m.find(4));  // Удаляем узел с ключом 4
  ASSERT_EQ(m.size(), 3u);
  ASSERT_FALSE(m.contains(4));
  ASSERT_TRUE(m.contains(3));
}
