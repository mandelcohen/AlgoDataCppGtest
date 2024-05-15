#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboBinarySearchTree.h"


#define ALL_TESTS

TEST(BST, TestInsertAndSearch)
{
    auto tree = new TurboBinarySearchTree<int>;

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(1); tree->Insert(3); tree->Insert(5); tree->Insert(7);


    ASSERT_TRUE(tree->Search(7));
    ASSERT_FALSE(tree->Search(9));
}

TEST(BST, TestDeleteValueNoChild)
{
    auto tree = new TurboBinarySearchTree<int>;

    tree->Insert(4); tree->Insert(2); tree->Insert(6);
    tree->Insert(1); tree->Insert(3); tree->Insert(5); tree->Insert(7);

    ASSERT_FALSE(tree->Delete(8));
    ASSERT_TRUE(tree->Delete(7));

}