#pragma once

template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    Node* parent;

    Node(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

template<typename T>
class TurboBinarySearchTree
{
public:
    template<typename>
    class Iterator;
    Node<T>* root;


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
    TurboBinarySearchTree<T> Clone();
    void DeleteTree();
// ----------- (End) The "Real" Collection Code ---------------
#pragma endregion Collection_Code

#pragma region Iterator_Pattern
// ---------------  (Start) Iterator Pattern Code -------------------
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    template<typename U>
    class Iterator
    {
        Node* current;
    public:
        Iterator(Node* node);
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

    // Find the node to delete
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

    // If the value is not found, return false
    if(toDelete == nullptr)
    {
        return false;
    }

    // Handle root deletion separately
    if(toDelete == root)
    {
        root = nullptr;
    }

        // Case 1: Node to delete has no children
    else if(toDelete->left == nullptr && toDelete->right == nullptr)
    {
        if(parent->left == toDelete)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }

        // Case 2: Node to delete has only one child
    else if(toDelete->left == nullptr)
    {
        if(parent->left == toDelete)
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
        if(parent->left == toDelete)
        {
            parent->left = toDelete->left;
        }
        else
        {
            parent->right = toDelete->left;
        }
    }

        // Case 3: Node to delete has two children
    else
    {
        Node* min = toDelete->right;
        Node* minParent = toDelete;
        while (min->left != nullptr)
        {
            minParent = min;
            min = min->left;
        }

        // Replace toDelete with min
        if(parent->left == toDelete)
        {
            parent->left = min;
        }
        else
        {
            parent->right = min;
        }

        // Update pointers to the left subtree of min
        if(minParent != toDelete)
        {
            minParent->left = min->right;
            min->right = toDelete->right;
        }
        min->left = toDelete->left;
    }

    delete toDelete;
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
// --------------  Iterator Pattern -----------------------


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
TurboBinarySearchTree<T>::Iterator<U>::Iterator(Node* first)
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
    if (current == nullptr) return *this;

    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            current = current->left;
        }
    } else {
        Node* parent = current->parent;
        while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return *this;
}

template <typename T>
template <typename U>
U& TurboBinarySearchTree<T>::Iterator<U>::operator*() const
{
    return current->data;
}

#pragma endregion Iterator_Pattern

