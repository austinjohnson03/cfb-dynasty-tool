#include "tree.h"
#include <gtest/gtest.h>

TEST(TreeTest, InsertAndSearch) {
  Tree<int> bst;
  bst.insert_node(10);
  bst.insert_node(5);
  bst.insert_node(15);

  EXPECT_TRUE(bst.search(10));
  EXPECT_TRUE(bst.search(5));
  EXPECT_TRUE(bst.search(15));
  EXPECT_FALSE(bst.search(20));
}

TEST(TreeTest, DeleteLeaf) {
  Tree<int> bst;
  bst.insert_node(10);
  bst.insert_node(5);
  bst.insert_node(15);

  bst.delete_node(5);

  EXPECT_TRUE(bst.search(10));
  EXPECT_FALSE(bst.search(5));
  EXPECT_TRUE(bst.search(15));
}

TEST(TreeTest, DeleteNodeWithOneChild) {
  Tree<int> bst;
  bst.insert_node(10);
  bst.insert_node(5);
  bst.insert_node(15);
  bst.insert_node(12);

  bst.delete_node(15);

  EXPECT_TRUE(bst.search(12));
  EXPECT_FALSE(bst.search(15));
  EXPECT_TRUE(bst.search(10));
}

TEST(TreeTest, DeleteNodeWithTwoChildren) {
  Tree<int> bst;
  bst.insert_node(10);
  bst.insert_node(5);
  bst.insert_node(15);
  bst.insert_node(12);
  bst.insert_node(20);

  bst.delete_node(15);

  EXPECT_FALSE(bst.search(15));
  EXPECT_TRUE(bst.search(12));
  EXPECT_TRUE(bst.search(20));
}
