#include <list>

#include "tests.h"

bool listsEqual(s21::list<int> L1, std::list<int> L2) {
  if (L1.size() != L2.size()) {
    return false;
  }
  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  for (; it_L1 != L1.end(); ++it_L1, ++it_L2) {
    if (*it_L1 != *it_L2) {
      return false;
    }
  }
  return true;
}

TEST(ListConstructors, DefaultConstructor) {
  s21::list<int> L1;
  std::list<int> L2;

  ASSERT_EQ(L1.size(), L2.size());
}

TEST(ListConstructors, ListConstructor) {
  s21::list<int> L1(5);
  std::list<int> L2(5);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListConstructors, ListConstructorsWithValues) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListConstructors, moveConstructor) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = std::move(L1);
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = std::move(L3);

  ASSERT_EQ(L2.size(), L4.size());
  ASSERT_TRUE(listsEqual(L2, L4));
}

TEST(ListConstructors, copyConstructor) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2(L1);
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4(L3);

  ASSERT_EQ(L2.size(), L4.size());
  ASSERT_TRUE(listsEqual(L2, L4));
}

TEST(ListMethods, emptySize) {
  s21::list<int> L1;
  std::list<int> L2;

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListMethods, nonEmptySize) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListMethods, emptyList) {
  s21::list<int> L1;
  std::list<int> L2;

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListMethods, emptyListWithSize) {
  s21::list<int> L1(5);
  std::list<int> L2(5);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(ListMethods, emptyMoveConstructor) {
  s21::list<int> L1;
  s21::list<int> L2(std::move(L1));
  std::list<int> L3;
  std::list<int> L4(std::move(L3));

  ASSERT_EQ(L2.empty(), L4.empty());
}

TEST(ListSwapMethod, swapWithNonEmptyList) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {6, 7, 8, 9, 10};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10};

  L1.swap(L2);
  L3.swap(L4);

  ASSERT_EQ(L1.size(), L3.size());
  ASSERT_TRUE(listsEqual(L1, L3));
  ASSERT_EQ(L2.size(), L4.size());
  ASSERT_TRUE(listsEqual(L2, L4));
}

TEST(ListSwapMethod, swapDifferentSizeLists) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  L1.swap(L2);
  L3.swap(L4);

  ASSERT_EQ(L1.size(), L3.size());
  ASSERT_TRUE(listsEqual(L1, L3));
  ASSERT_EQ(L2.size(), L4.size());
  ASSERT_TRUE(listsEqual(L2, L4));
}

TEST(ListReverseMethod, reverseNonEmptyList) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  L1.reverse();
  L2.reverse();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListReverseMethod, reverseListWithOneElement) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};

  L1.reverse();
  L2.reverse();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListReverseMethod, reverseListWithTwoElements) {
  s21::list<int> L1 = {1, 2};
  std::list<int> L2 = {1, 2};

  L1.reverse();
  L2.reverse();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListReverseMethod, reverseListWithElements) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  L1.reverse();
  L2.reverse();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListInsertMethod, insertNonEmptyList) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();

  ++it_L1;
  ++it_L2;

  L1.insert(it_L1, 120);
  L2.insert(it_L2, 120);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(ListEraseMethod, eraseMiddleElement) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};

  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();

  ++it_L1;
  ++it_L2;

  L1.erase(it_L1);
  L2.erase(it_L2);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listSortMethod, sortNonEmptyList) {
  s21::list<int> L1 = {53, 41, -3, -2, 0};
  std::list<int> L2 = {53, 41, -3, -2, 0};

  L1.sort();
  L2.sort();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listSortMethod, sortListWithOneElement) {
  s21::list<int> L1 = {53};
  std::list<int> L2 = {53};

  L1.sort();
  L2.sort();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listSortMethod, sortStringElements) {
  s21::list<std::string> L1 = {"aadf", "bsadf", "csadf", "dfas", "e"};
  std::list<std::string> L2 = {"aadf", "bsadf", "csadf", "dfas", "e"};

  L1.sort();
  L2.sort();

  ASSERT_EQ(L1.size(), L2.size());

  s21::list<std::string>::iterator it_L1 = L1.begin();
  std::list<std::string>::iterator it_L2 = L2.begin();
  for (; it_L2 != L2.end(); ++it_L2, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L2);
  }
}

TEST(listSortMethod, sortSortedList) {
  s21::list<int> L1 = {-3, -2, 0, 41, 53};
  std::list<int> L2 = {-3, -2, 0, 41, 53};

  L1.sort();
  L2.sort();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(mergeMethodList, mergeIdenticalLists) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {1, 2, 3, 4, 5};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {1, 2, 3, 4, 5};

  L1.merge(L2);
  L3.merge(L4);

  ASSERT_EQ(L1.size(), L3.size());
  ASSERT_TRUE(listsEqual(L1, L3));
}

TEST(mergeMethodList, mergeDifferentLists) {
  s21::list<int> L1 = {1, 2, 3, 4, 5};
  s21::list<int> L2 = {6, 7, 8, 9, 10};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10};

  L1.merge(L2);
  L3.merge(L4);

  ASSERT_EQ(L1.size(), L3.size());
  ASSERT_TRUE(listsEqual(L1, L3));
}

TEST(listUniqueMethod, uniqueNonEmptyList) {
  s21::list<int> L1 = {1, 1, 2, 2, 3, 3, 4, 4, 5};
  std::list<int> L2 = {1, 1, 2, 2, 3, 3, 4, 4, 5};

  L1.unique();
  L2.unique();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listUniqueMethod, uniqueUnsortedList) {
  s21::list<int> L1 = {1, 2, -3, 42, 53, 1, 2, 233, 34, 5};
  std::list<int> L2 = {1, 2, -3, 42, 53, 1, 2, 233, 34, 5};

  L1.unique();
  L2.unique();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listFrontMethod, frontNonEmptyList) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};

  ASSERT_EQ(L1.front(), L2.front());
}

TEST(listFrontMethod, frontListWithOneElement) {
  s21::list<int> L1 = {1};
  std::list<int> L2 = {1};

  ASSERT_EQ(L1.front(), L2.front());
}

TEST(listPushMethod, pushBackList) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};

  L1.push_back(4);
  L2.push_back(4);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listPushMethod, pushFrontList) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};

  L1.push_front(4);
  L2.push_front(4);

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listPopMethod, popBackList) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};

  L1.pop_back();
  L2.pop_back();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listPopMethod, popFrontList) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};

  L1.pop_front();
  L2.pop_front();

  ASSERT_EQ(L1.size(), L2.size());
  ASSERT_TRUE(listsEqual(L1, L2));
}

TEST(listOperators, plusPlusOperator) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};

  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();

  ++it_L1;
  ++it_L2;

  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(listOperators, differenceExistingList) {
  s21::list<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};

  s21::list<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();

  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(listOperators, equalOperator) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};

  ASSERT_EQ(L1.begin() == L1.begin(), L2.begin() == L2.begin());
}

TEST(listOperators, notEqualOperator) {
  s21::list<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};

  ASSERT_EQ(L1.begin() != L1.begin(), L2.begin() != L2.begin());
}

TEST(listOperators, equalCopyOperator) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = L1;
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = L3;

  ASSERT_EQ(L1.begin() == L2.begin(), L3.begin() == L4.begin());
}

TEST(listSpliceMethod, spliceAtTail) {
  s21::list<int> L1 = {1, 2, 3};
  s21::list<int> L2 = {4, 5, 6};

  L1.splice(L1.end(), L2);

  ASSERT_EQ(L1.size(), 6);
  ASSERT_EQ(L2.size(), 0);
  ASSERT_TRUE(listsEqual(L1, {1, 2, 3, 4, 5, 6}));
}

TEST(listSpliceMethod, spliceInMiddle) {
  s21::list<int> L1 = {1, 2, 6, 7};
  s21::list<int> L2 = {3, 4, 5};

  auto it = L1.begin();
  for (int i = 0; i < 2; ++i) {  // Перемещаем итератор на третий элемент в L1
    ++it;
  }
  L1.splice(it, L2);

  ASSERT_EQ(L1.size(), 7);
  ASSERT_EQ(L2.size(), 0);
  std::list<int> expected = {1, 2, 3, 4, 5, 6, 7};
  ASSERT_TRUE(listsEqual(L1, expected));
}
