#pragma once

#include <iostream>
#include <cstdio>

namespace TurboQueue{

    template <typename T>
    struct Node {
        T Value;
        Node* Next;
    };

    template <typename T>
    class TurboLinkedQueue {
    public:
        template<typename>
        class Iterator;
        Node<T>* firstNode{};


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

        bool empty() const;
// returns the current amount of items contained in the queue.
        size_t size();
// adds one item to the back of the queue.
        void enqueue(T item);
// returns the item in the front of the queue without removing it.
        T& front();
        const T& front() const;
// removes the item from the front of the queue.
        void dequeue();

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
            U& operator*() const;
        };
// ---------------  (End) Iterator Pattern Code -------------------
#pragma endregion Iterator_Pattern
    };


#pragma region Collection_Code
// -------------- Turbo Linked Stack Code -----------------------
    template <typename T>
    bool TurboLinkedQueue<T>::empty() const {
        if(firstNode == nullptr) return true;
        return false;
    }

    template <typename T>
    size_t TurboLinkedQueue<T>::size() {
        size_t count = 1;
        auto current = firstNode;
        while(current->Next != nullptr){
            count++;
            current = current->Next;
        }
        return count;
    }

    template <typename T>
    void TurboLinkedQueue<T>::enqueue(T item)
    {
        if(firstNode == nullptr)
        {
            firstNode = new Node<T>{item, nullptr};
        }
        else
        {
            Node<T>* current = firstNode;
            while(current->Next != nullptr)
            {
                current = current->Next;
            }
            current->Next = new Node<T>{item, nullptr};
        }
    }

    template <typename T>
    T& TurboLinkedQueue<T>::front() {
        return firstNode->Value;
    }

    template <typename T>
    const T& TurboLinkedQueue<T>::front() const {
        return firstNode->Value;
    }

    template <typename T>
    void TurboLinkedQueue<T>::dequeue() {
        auto toDelete = firstNode;
        firstNode = toDelete->Next;
        delete toDelete;
    }



#pragma endregion Collection_Code

#pragma region Iterator_Pattern
    template <typename T>
    typename TurboLinkedQueue<T>::iterator TurboLinkedQueue<T>::begin()
    {
        return iterator{firstNode};
    }


// The begin() is supposed to return an Iterator that points to the first element
    template <typename T>
    typename TurboLinkedQueue<T>::const_iterator TurboLinkedQueue<T>::begin() const
    {
        return const_iterator{firstNode};
    }

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
    template <typename T>
    typename TurboLinkedQueue<T>::iterator TurboLinkedQueue<T>::end()
    {
        return iterator{nullptr};
    }

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
    template <typename T>
    typename TurboLinkedQueue<T>::const_iterator TurboLinkedQueue<T>::end() const
    {
        return const_iterator{nullptr};
    }


// -------------- Turbo Linked List Iterator Code -----------------------
    template <typename T>
    template <typename U>
    TurboLinkedQueue<T>::Iterator<U>::Iterator(node* first)
    {
        current = first;
    }

// The Equality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
    template <typename T>
    template <typename U>
    bool TurboLinkedQueue<T>::Iterator<U>::operator==(const Iterator& other) const
    {
        return other.current == current;
    }

// The Inequality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
    template <typename T>
    template <typename U>
    bool TurboLinkedQueue<T>::Iterator<U>::operator!=(const Iterator& other) const
    {
        return other.current != current;
    }


// The Increment Operator is supposed to move to the next val
// In this case, it is the node which is next from the one we currently point to
    template <typename T>
    template <typename U>
    typename TurboLinkedQueue<T>::template Iterator<U>& TurboLinkedQueue<T>::Iterator<U>::operator++()
    {
        current = current->Next;
        return *this;
    }

// The Dereference Operator is supposed to return the current val
// In this case, it is the val in the node that we currently point to
    template <typename T>
    template <typename U>
    U& TurboLinkedQueue<T>::Iterator<U>::operator*() const
    {
        return current->Value;
    }
#pragma endregion Iterator_Pattern
}