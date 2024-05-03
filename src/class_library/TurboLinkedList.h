#pragma once

template<typename T>
struct Node
{
    T value;
    Node* next;
};

template<typename T>
class TurboLinkedList
{
public:
    // class declaration to allow using it before
    // defining it
    template<typename>
    class Iterator;

    // pointer to the first node of the list
    // can be null, if the list is empty
    Node<T>* first{};


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



// --------------- All Function Implementations (Inline) -------------------
// They need to be inline because this is a Template Class
// This means, that the code is only compiled for all types that are being used
// e.g. if you use TurboLinkedList<int>, then the class is compiled for type int
// if you use TurboLinkedList<Player>, then the clas is compiled for type Player

// If the implementations were in the cpp file and not in the header
// Then the Library wouldn't compile any instances of TurboLinkedList
// Since it is not using the List itself.
// Instead, the code needs to be in the header
// So that your other project, e.g. your SpotifyQueue Application
// can compile the code from the Header if it needs e.g.
// a TurboLinkedQueue<SpotifySong>

#pragma region Collection_Code
// -------------- Turbo Linked List Code -----------------------
template <typename T>
void TurboLinkedList<T>::Add(T item)
{
    if(first == nullptr)
    {
        first = new Node<T>{item, nullptr};
    }
    else
    {
        Node<T>* current = first;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node<T>{item, nullptr};
    }
}
#pragma endregion Collection_Code


#pragma region Iterator_Pattern
// -------------- Turbo Linked List Iterator Pattern -----------------------

// The begin() is supposed to return an Iterator that points to the first element
template <typename T>
typename TurboLinkedList<T>::iterator TurboLinkedList<T>::begin()
{
    return iterator{first};
}

// The begin() is supposed to return an Iterator that points to the first element
template <typename T>
typename TurboLinkedList<T>::const_iterator TurboLinkedList<T>::begin() const
{
    return const_iterator{first};
}

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
template <typename T>
typename TurboLinkedList<T>::iterator TurboLinkedList<T>::end()
{
    return iterator{nullptr};
}

// The end() is supposed to return an Iterator that points BEHIND the last element
// To say, that we've overshot and nothing is left anymore
template <typename T>
typename TurboLinkedList<T>::const_iterator TurboLinkedList<T>::end() const
{
    return const_iterator{nullptr};
}


// -------------- Turbo Linked List Iterator Code -----------------------
template <typename T>
template <typename U>
TurboLinkedList<T>::Iterator<U>::Iterator(node* first)
{
    current = first;
}

// The Equality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
template <typename T>
template <typename U>
bool TurboLinkedList<T>::Iterator<U>::operator==(const Iterator& other) const
{
    return other.current == current;
}

// The Inequality Operator is supposed to say whether two Iterators
// Point to the same element of the queue
template <typename T>
template <typename U>
bool TurboLinkedList<T>::Iterator<U>::operator!=(const Iterator& other) const
{
    return other.current != current;
}


// The Increment Operator is supposed to move to the next value
// In this case, it is the node which is next from the one we currently point to
template <typename T>
template <typename U>
typename TurboLinkedList<T>::template Iterator<U>& TurboLinkedList<T>::Iterator<U>::operator++()
{
    current = current->next;
    return *this;
}

// The Dereference Operator is supposed to return the current value
// In this case, it is the value in the node that we currently point to
template <typename T>
template <typename U>
U& TurboLinkedList<T>::Iterator<U>::operator*() const
{
    return current->value;
}
#pragma endregion Iterator_Pattern
