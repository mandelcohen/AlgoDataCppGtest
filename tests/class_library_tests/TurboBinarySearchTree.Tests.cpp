#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboBinarySearchTree.h"


TEST(BST, TestInsertAndSearch)
{
    auto tree = new TurboBinarySearchTree<int>();

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(1); tree->Insert(3); tree->Insert(5); tree->Insert(7);

    ASSERT_TRUE(tree->Search(7));
    ASSERT_FALSE(tree->Search(9));
    ASSERT_THAT(*tree, testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
}

TEST(BST, TestDeleteValueNoChild)
{
    auto tree = new TurboBinarySearchTree<int>;

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(1); tree->Insert(3); tree->Insert(5); tree->Insert(7);

    ASSERT_FALSE(tree->Delete(8));
    ASSERT_TRUE(tree->Delete(7));
    ASSERT_THAT(*tree, testing::ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(BST, TestDeleteValueOneChild)
{
    auto tree = new TurboBinarySearchTree<int>;

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(3); tree->Insert(5); tree->Insert(7);

    ASSERT_TRUE(tree->Delete(2));
}

TEST(BST, TestDeleteValueTwoChildren)
{
    auto tree = new TurboBinarySearchTree<int>;

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(1); tree->Insert(3); tree->Insert(5); tree->Insert(7);

    ASSERT_TRUE(tree->Delete(2));
    ASSERT_THAT(*tree, testing::ElementsAre(1, 3, 4, 5, 6, 7));
}