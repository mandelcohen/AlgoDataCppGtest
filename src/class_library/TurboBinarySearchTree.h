#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
class TurboBinarySearchTree
{
public:
    // class declaration to allow using it before
    // defining it
    template<typename>
    class Iterator;

    // pointer to the first node of the list
    // can be null, if the list is empty
    Node<T>* root{};


#pragma region Type_Names
// ----------- (Start) Type Name Definitions (used by GMock) ------------

    // these usings are necessary for gmock to work properly
    // gmock uses it to figure out, which type to use for
    // the iterators and which is the value_type of this
    // collection, e.g. TurboLinkedList<int>, T is int
    using value_type = T;
    // the type of the iterator if this is a non-const
    // collection, e.g. TurboLinkedList<int> list;
    using iterator               = Iterator<T>;
    // the type of the iterator if this is a const
    // collection, e.g. const TurboLinkedList<int> list;
    using const_iterator         = Iterator<const T>;
    // the type of the node that we use
    using node = Node<T>;
// ----------- (End) Type Name Definitions (used by GMock) ------------
#pragma endregion Type_Names

#pragma region Collection_Code
// ----------- (Start) The "Real" Collection Code ---------------
    void Insert(T value);
    bool Search(T value);
    bool Delete(T value);
    TurboBinarySearchTree<T> Clone();
    void DeleteTree();


// ----------- (End) The "Real" Collection Code ---------------
#pragma endregion Collection_Code

#pragma region Iterator_Pattern
// ---------------  (Start) Iterator Pattern Code -------------------

    // allows using for(auto& val : list)
    // also allows gmock to work with collections
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    template<typename U>
    class Iterator
    {
        node* current;
    public:
        Iterator(node* first);
        bool operator ==(const Iterator& other) const;
        bool operator !=(const Iterator& other) const;
        Iterator& operator ++();
        //U& operator*() const;
    };
// ---------------  (End) Iterator Pattern Code -------------------
#pragma endregion Iterator_Pattern
};


#pragma region Collection_Code
// -------------- Binary Search Tree Code -----------------------
template <typename T>
void TurboBinarySearchTree<T>::Insert(T value)
{
    if(root == nullptr)
    {
        root = new Node<T>{value, nullptr, nullptr};
    }
    else
    {
        Node<T>* current = root;
        bool leafFound = false;

        while(!leafFound)
        {
            if((*current).data < value)
            {
                if(current->right == nullptr)
                {
                    current->right = new Node<T>{value, nullptr, nullptr};
                    leafFound = true;
                }
                else
                {
                    current = current->right;
                }
            }
            if((*current).data > value)
            {
                if(current->left == nullptr)
                {
                    current->left = new Node<T>{value, nullptr, nullptr};
                    leafFound = true;
                }
                else
                {
                    current = current->left;
                }
            }
        }

    }

}

template <typename T>
bool TurboBinarySearchTree<T>::Search(T value)
{
    Node<T>* current = root;

    while (current != nullptr)
    {
        if ((*current).data == value)
        {
            return true;
        }
        if ((*current).data < value)
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
bool TurboBinarySearchTree<T>::Delete(T value)
{
    auto toDelete = root;
    Node<T>* parent = nullptr;
    while(toDelete != nullptr && (*toDelete).data != value){
        parent = toDelete;
        if((*toDelete).data < value)
        {
            toDelete = toDelete->right;
        }
        if((*toDelete).data > value)
        {
            toDelete = toDelete->left;
        }
    }

    if(toDelete == nullptr)
    {
        return false;
    }

    if(toDelete->left == nullptr && toDelete->right == nullptr)
    {
        if(toDelete == parent->left)
        {
            parent->left = nullptr;
        }
        if(toDelete == parent->right)
        {
            parent->right = nullptr;
        }
    }

    if(toDelete->left == nullptr && toDelete->right != nullptr)
    {
        if(toDelete == parent->left)
        {
            parent->left = toDelete->right;
        }
        if(toDelete == parent->right)
        {
            parent->right = toDelete->right;
        }
    }

    if(toDelete->left != nullptr && toDelete->right == nullptr)
    {
        if(toDelete == parent->left)
        {
            parent->left = toDelete->left;
        }
        if(toDelete == parent->right)
        {
            parent->right = toDelete->left;
        }
    }

    else
    {
        Node<T>* min = toDelete->right;
        while (min->left != nullptr)
        {
            min = min->left;
        }
        if(toDelete == parent->left)
        {
            parent->left = min;
            min->left = toDelete->left;
        }
        if(toDelete == parent->right)
        {
            parent->right = min;
            min->left = toDelete->left;
        }
    }
    return true;
}

template <typename T>
TurboBinarySearchTree<T> TurboBinarySearchTree<T>::Clone()
{

}

template <typename T>
void TurboBinarySearchTree<T>::DeleteTree()
{

}



#pragma endregion Collection_Code


#pragma region Iterator_Pattern
// -------------- Turbo Linked List Iterator Pattern -----------------------


template <typename T>
typename TurboBinarySearchTree<T>::iterator TurboBinarySearchTree<T>::begin()
{
    return iterator{root};
}


template <typename T>
typename TurboBinarySearchTree<T>::const_iterator TurboBinarySearchTree<T>::begin() const
{
    return const_iterator{root};
}


template <typename T>
typename TurboBinarySearchTree<T>::iterator TurboBinarySearchTree<T>::end()
{
    return iterator{nullptr};
}

template <typename T>
typename TurboBinarySearchTree<T>::const_iterator TurboBinarySearchTree<T>::end() const
{
    return const_iterator{nullptr};
}



template <typename T>
template <typename U>
TurboBinarySearchTree<T>::Iterator<U>::Iterator(node* first)
{
    current = first;
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
    current = current->left;
    return *this;
}

/*
// The Dereference Operator is supposed to return the current val
// In this case, it is the val in the node that we currently point to
template <typename T>
template <typename U>
U& TurboBinarySearchTree<T>::Iterator<U>::operator*() const
{
    return current->data;
}
*/
#pragma endregion Iterator_Pattern

