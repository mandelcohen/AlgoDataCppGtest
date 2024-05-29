#include <vector>
#include "iostream"

#pragma once

template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class TurboBinarySearchTree
{
public:
    template<typename>
    class Iterator;
    Node<T>* root;
    std::vector<T> elements;

#pragma region Type_Names
// ----------- (Start) Type Name Definitions (used by GMock) ------------
    using value_type = T;
    using iterator               = Iterator<T>;
    using const_iterator         = Iterator<const T>;
    using Node = Node<T>;
// ----------- (End) Type Name Definitions (used by GMock) ------------
#pragma endregion Type_Names

#pragma region Collection_Code
// ----------- (Start) The "Real" Collection Code ---------------
    TurboBinarySearchTree() : root(nullptr) {}
    void Insert(const T& value);
    bool Search(const T& value);
    bool Delete(const T& value);
    void InorderTraversal(Node* node);
    void PreOrderTraversal(Node* node);
    TurboBinarySearchTree<T> Clone();
    void DeleteTree();
    void PrintTree();
private:
    void DeleteTree(Node* node);
    void PrintTreeHelper(const std::string& prefix, const Node* node, bool isLeft);
// ----------- (End) The "Real" Collection Code ---------------
#pragma endregion Collection_Code

#pragma region Iterator_Pattern
// ---------------  (Start) Iterator Pattern Code -------------------
public:
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    template<typename U>
    class Iterator
    {
        typename std::vector<const T>::const_iterator current;
    public:
        Iterator(typename std::vector<const T>::const_iterator iter) : current(iter) {}
        bool operator ==(const Iterator& other) const;
        bool operator !=(const Iterator& other) const;
        Iterator& operator ++();
        U& operator*() const;
    };
// ---------------  (End) Iterator Pattern Code -------------------
#pragma endregion Iterator_Pattern
};


#pragma region Collection_Code
// -------------- Binary Search Tree Code -----------------------
template <typename T>
void TurboBinarySearchTree<T>::Insert(const T& value)
{
    if(root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        Node* current = root;
        bool leafFound = false;

        while(!leafFound)
        {
            if(current->data < value)
            {
                if(current->right == nullptr)
                {
                    current->right = new Node(value);
                    leafFound = true;
                }
                else
                {
                    current = current->right;
                }
            }
            if(current->data> value)
            {
                if(current->left == nullptr)
                {
                    current->left = new Node(value);
                    leafFound = true;
                }
                else
                {
                    current = current->left;
                }
            }
        }
    }
    elements.clear();
    InorderTraversal(root);
}

template <typename T>
bool TurboBinarySearchTree<T>::Search(const T& value)
{
    Node* current = root;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        if (current->data < value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return false;
}

template <typename T>
bool TurboBinarySearchTree<T>::Delete(const T& value)
{
    Node* toDelete = root;
    Node* parent = nullptr;

    while(toDelete != nullptr && toDelete->data != value){
        parent = toDelete;
        if(toDelete->data < value)
        {
            toDelete = toDelete->right;
        }
        else if(toDelete->data > value)
        {
            toDelete = toDelete->left;
        }
    }

    if(toDelete == nullptr)
    {
        return false;
    }

        //  no children
    else if(toDelete->left == nullptr && toDelete->right == nullptr)
    {
        if(toDelete == root)
        {
            root = nullptr;
        }
        else if(parent->left == toDelete)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }

        //  one child
    else if(toDelete->left == nullptr)
    {
        if(toDelete == root)
        {
            root = toDelete->right;
        }
        else if(parent->left == toDelete)
        {
            parent->left = toDelete->right;
        }
        else
        {
            parent->right = toDelete->right;
        }
    }
    else if(toDelete->right == nullptr)
    {
        if(toDelete == root)
        {
            root = toDelete->left;
        }
        if(parent->left == toDelete)
        {
            parent->left = toDelete->left;
        }
        else
        {
            parent->right = toDelete->left;
        }
    }

        // two children
    else
    {
        Node* min = toDelete->right;
        Node* minParent = toDelete;
        while (min->left != nullptr)
        {
            minParent = min;
            min = min->left;
        }

        if (minParent != toDelete)
        {
            minParent->left = min->right;
            min->right = toDelete->right;
        }
        min->left = toDelete->left;

        if (toDelete == root)
        {
            root = min;
        }
        else if(parent->left == toDelete)
        {
            parent->left = min;
        }
        else
        {
            parent->right = min;
        }
    }

    delete toDelete;
    elements.clear();
    InorderTraversal(root);
    return true;
}

template <typename T>
void TurboBinarySearchTree<T>::InorderTraversal(TurboBinarySearchTree::Node* node)
{
    if(node == nullptr)
        return;
    InorderTraversal(node->left);
    elements.push_back(node->data);
    InorderTraversal(node->right);
}

template <typename T>
void TurboBinarySearchTree<T>::PreOrderTraversal(TurboBinarySearchTree::Node* node)
{
    if(node == nullptr)
        return;
    elements.push_back(node->data);
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

template <typename T>
TurboBinarySearchTree<T> TurboBinarySearchTree<T>::Clone()
{
    auto newTree = new TurboBinarySearchTree<T>();
    for (auto &item: elements)
    {
        newTree->Insert(item);
    }
    return *newTree;
}

template <typename T>
void TurboBinarySearchTree<T>::DeleteTree()
{
    DeleteTree(root);
    elements.clear();
    root = nullptr;
}

template <typename T>
void TurboBinarySearchTree<T>::DeleteTree(TurboBinarySearchTree::Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);

    delete node;
}

template <typename T>
void TurboBinarySearchTree<T>::PrintTreeHelper(const std::string &prefix, const TurboBinarySearchTree::Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        PrintTreeHelper(prefix + (isLeft ? "|   " : "    "), node->right, true);
        PrintTreeHelper(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

template <typename T>
void TurboBinarySearchTree<T>::PrintTree()
{
    PrintTreeHelper("", root, false);
}


#pragma endregion Collection_Code


#pragma region Iterator_Pattern
// --------------  Iterator Pattern -----------------------


template <typename T>
typename TurboBinarySearchTree<T>::iterator TurboBinarySearchTree<T>::begin()
{

    return Iterator<T>(elements.begin());
}

template <typename T>
typename TurboBinarySearchTree<T>::iterator TurboBinarySearchTree<T>::end()
{
    return Iterator<T>(elements.end());
}

template <typename T>
typename TurboBinarySearchTree<T>::const_iterator TurboBinarySearchTree<T>::begin() const
{
    return Iterator<const T>(elements.begin());
}

template <typename T>
typename TurboBinarySearchTree<T>::const_iterator TurboBinarySearchTree<T>::end() const
{
    return Iterator<const T>(elements.end());;
}


template <typename T>
template <typename U>
bool TurboBinarySearchTree<T>::Iterator<U>::operator==(const Iterator& other) const
{
    return other.current == current;
}


template <typename T>
template <typename U>
bool TurboBinarySearchTree<T>::Iterator<U>::operator!=(const Iterator& other) const
{
    return other.current != current;
}


template <typename T>
template <typename U>
typename TurboBinarySearchTree<T>::template Iterator<U>& TurboBinarySearchTree<T>::Iterator<U>::operator++()
{
    ++current;
    return *this;
}

template <typename T>
template <typename U>
U& TurboBinarySearchTree<T>::Iterator<U>::operator*() const
{
    return *current;
}

#pragma endregion Iterator_Pattern

