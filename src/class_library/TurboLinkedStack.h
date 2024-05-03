#pragma once

#include <iostream>
#include <cstdio>


template <typename T>
struct Node {
    T Value;
    Node* Previous;
};

template <typename T>
class TurboLinkedStack {
public:
    template<typename>
    class Iterator;
    Node<T> *lastNode{};


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
    void push(const T& item);
    T& top();
    const T& top() const;
    void pop();
    bool empty() const;
    size_t size() const;
// ----------- (End) The "Real" Collection Code ---------------
#pragma endregion Collection_Code

#pragma region Iterator_Pattern
// ---------------  (Start) Iterator Pattern Code -------------------

    // allows using for(auto& value : list)
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
        U& operator*() const;
    };
// ---------------  (End) Iterator Pattern Code -------------------
#pragma endregion Iterator_Pattern
};
#pragma region Collection_Code
// -------------- Turbo Linked List Code -----------------------
template <typename T>
void TurboLinkedStack<T>::push(const T &item)
{
    node* newNode = new node{item, nullptr};
    lastNode->next = newNode;
    lastNode = newNode;
}

template <typename T>
T& TurboLinkedStack<T>::top() {
    return lastNode->Value;
    // Return the Value of Last Node here.
}

template <typename T>
void TurboLinkedStack<T>::pop() {
    lastNode->Previous = lastNode;
    // Assign the Last Node's Previous Node to be the Last Node.
}

template <typename T>
bool TurboLinkedStack<T>::empty() const {
    if(lastNode == nullptr) return true;
    return false;
    // Return true, if the LastNode is null
}

template <typename T>
size_t TurboLinkedStack<T>::size() const {
    size_t count = 0;
    while(lastNode->Previous != nullptr){
        count++;
        lastNode = lastNode->Previous;
    }
    return count;
}

#pragma endregion Collection_Code

#pragma region Iterator_Pattern
template <typename T>
typename TurboLinkedStack<T>::iterator TurboLinkedStack<T>::begin()
{
    return iterator{lastNode};
}


// The begin() is supposed to return an Iterator that points to the first element
template <typename T>
typename TurboLinkedStack<T>::const_iterator TurboLinkedStack<T>::begin() const
{
    return const_iterator{lastNode};
}

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
template <typename T>
typename TurboLinkedStack<T>::iterator TurboLinkedStack<T>::end()
{
    return iterator{nullptr};
}

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
template <typename T>
typename TurboLinkedStack<T>::const_iterator TurboLinkedStack<T>::end() const
{
    return const_iterator{nullptr};
}


// -------------- Turbo Linked List Iterator Code -----------------------
template <typename T>
template <typename U>
TurboLinkedStack<T>::Iterator<U>::Iterator(node* first)
{
    current = first;
}

// The Equality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
template <typename T>
template <typename U>
bool TurboLinkedStack<T>::Iterator<U>::operator==(const Iterator& other) const
{
    return other.current == current;
}

// The Inequality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
template <typename T>
template <typename U>
bool TurboLinkedStack<T>::Iterator<U>::operator!=(const Iterator& other) const
{
    return other.current != current;
}


// The Increment Operator is supposed to move to the next value
// In this case, it is the node which is next from the one we currently point to
template <typename T>
template <typename U>
typename TurboLinkedStack<T>::template Iterator<U>& TurboLinkedStack<T>::Iterator<U>::operator++()
{
    current = current->next;
    return *this;
}

// The Dereference Operator is supposed to return the current value
// In this case, it is the value in the node that we currently point to
template <typename T>
template <typename U>
U& TurboLinkedStack<T>::Iterator<U>::operator*() const
{
    return current->value;
}
#pragma endregion Iterator_Pattern