#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboBinarySearchTree.h"


TEST(BST, TestInsert)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    ASSERT_THAT(tree, testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
    tree.PrintTree();
}

TEST(BST, returnTrueIfItemWasFound)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "Searching for 7 in tree:" << std::endl;
    ASSERT_TRUE(tree.Search(7));
}

TEST(BST, TestDeleteValueNoChild)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "The tree before deleting 7:" << std::endl;
    tree.PrintTree();

    ASSERT_FALSE(tree.Delete(8));
    ASSERT_TRUE(tree.Delete(7));

    std::cout << "The tree after deleting 7:" << std::endl;
    tree.PrintTree();

    ASSERT_THAT(tree, testing::ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(BST, TestDeleteValueOneChild)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "The tree before deleting 2:" << std::endl;
    tree.PrintTree();

    ASSERT_TRUE(tree.Delete(2));

    std::cout << "The tree after deleting 2:" << std::endl;
    tree.PrintTree();

    ASSERT_THAT(tree, testing::ElementsAre(3, 4, 5, 6, 7));
}

TEST(BST, TestDeleteValueTwoChildren)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "The tree before deleting 2:" << std::endl;
    tree.PrintTree();

    ASSERT_TRUE(tree.Delete(2));

    std::cout << "The tree after deleting 2:" << std::endl;
    tree.PrintTree();

    ASSERT_THAT(tree, testing::ElementsAre(1, 3, 4, 5, 6, 7));
}

TEST(BST, TestDeleteRootValue)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "The tree before deleting the root:" << std::endl;
    tree.PrintTree();

    ASSERT_TRUE(tree.Delete(4));

    std::cout << "The tree after deleting the root:" << std::endl;
    tree.PrintTree();

    ASSERT_THAT(tree, testing::ElementsAre(1, 2, 3, 5, 6, 7));
}

TEST(BST, TestCloningTree)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    std::cout << "The original tree:" << std::endl;
    tree.PrintTree();

    auto newTree = tree.Clone();
    std::cout << "The cloned tree:" << std::endl;
    newTree.PrintTree();

    ASSERT_THAT(tree,   testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
    ASSERT_THAT(newTree, testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
}


TEST(BST, TestDeletingTree)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    ASSERT_THAT(tree,   testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));

    tree.DeleteTree();
    ASSERT_THAT(tree,   testing::ElementsAre());
    ASSERT_TRUE(tree.elements.empty());
}

TEST(BST, TestIterationOverTree)
{
    TurboBinarySearchTree<int> tree{};

    tree.Insert(4); tree.Insert(2); tree.Insert(6);
    tree.Insert(1); tree.Insert(3); tree.Insert(5); tree.Insert(7);

    ASSERT_THAT(tree,   testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));

    for (auto i = 0; i < tree.elements.size(); ++i)
    {
        std::cout << tree.elements[i] << " ";
    }
}