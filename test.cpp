#include "gtest/gtest.h"
#include "list.h"

TEST(TestListNode, init_value) {
  ListNode node;

  EXPECT_EQ(node.val, 0);
}

TEST(TestListNode, init_next) {
  ListNode node;

  EXPECT_EQ(node.next, nullptr);
}

TEST(TestMyList, init) {
  MyList list("1 2 3");
  std::vector<int> values = {1, 2, 3};
  int index = 0;
  for (auto it = list.begin(); it != list.end(); ++it) {
    EXPECT_EQ(*it, values[index++]);
  }
}

TEST(TestMyList, reverse) {
  MyList list("1 2 3");
  std::vector<int> values = {3, 2, 1};
  int index = 0;

  -list;
  for (auto it = list.begin(); it != list.end(); ++it) {
    EXPECT_EQ(*it, values[index++]);
  }
}