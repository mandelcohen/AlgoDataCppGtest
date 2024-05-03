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
    template <typename T>
        class Iterator;
    Node<T>* lastNode{};
public:

#pragma region Type_Names
// ----------- (Start) Type Name Definitions (used by GMock) ------------

    // these usings are necessary for gmock to work properly
    // gmock uses it to figure out, which type to use for
    // the iterators and which is the value_type of this
    // collection, e.g. TurboLinkedList<int>, T is int
    using value_type = T;
    // the type of the the iterator if this is a non-const
    // collection, e.g. TurboLinkedList<int> list;
    using iterator               = Iterator<T>;
    // the type of the the iterator if this is a const
    // collection, e.g. const TurboLinkedList<int> list;
    using const_iterator         = Iterator<const T>;
    // the type of the node that we use
    using node = Node<T>;
// ----------- (End) Type Name Definitions (used by GMock) ------------
#pragma endregion Type_Names

#pragma region Collection_Code
// ----------- (Start) The "Real" Collection Code ---------------
    void Add(T);
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




template <typename T>
class TurboLinkedStack<T> {
    struct Node {};
    Node* lastNode;
public:
    void push(const T& item) {
        Node* newNode = new Node{item, nullptr};
        lastNode->next = newNode;
        lastNode = newNode;
    }

    T& top() {
        return lastNode->Value;
        // Return the Value of Last Node here.
    }

    const void pop()
    {
        lastNode->Previous = lastNode;
        // Assign the Last Node's Previous Node to be the Last Node.
    }

    bool empty() const {
        if(lastNode == nullptr) return true;
        return false;
        // Return true, if the LastNode is null
    }

    size_t size() const {
        size_t count = 0;
        while(lastNode->Previous != nullptr){
            count++;
            lastNode = lastNode->Previous;
        }
        return count;
    }

    template<typename T>
    class Iterator{
        Node* currentNode;

    public:
        Iterator(Node* startAtNode) {
            currentNode = startAtNode;
        }

        Iterator<T>& operator++() {
            throw "NotImplementedException()";
            // Make currentNode point to currentNode's previous node
            return *this;
        }

        T& operator*() const {
            throw "NotImplementedException()";
            // Return the value of the CurrentNode
        }

        bool operator==(const Iterator<T>& other) const {
            throw "NotImplementedException()";
            // return true if both operators have the same current node
        }
        bool operator!=(const Iterator<T>& other) const {
            throw "NotImplementedException()";
            // return true if both operators have different current nodes
        }
    };

    Iterator<T> begin() {
        throw "NotImplementedException()";
        return Iterator<T>(lastNode);
    }

    Iterator<const T> begin() const {
        throw "NotImplementedException()";
        return Iterator<const T>(lastNode);
    }
};