#include <iostream>
#include <vector>
#include "TurboCollections.hpp"
#include "TurboLinkedStack.h"
#include "TurboLinkedQueue.h"
#include "TurboSort.h"

using namespace TurboCollections;
using namespace TurboStack;
using namespace TurboQueue;
using namespace TurboSort;

int main()
{
    std::cout << "SelectionSort: " << std::endl;
    std::vector<int> selection;
    selection.push_back(5);
    selection.push_back(2);
    selection.push_back(4);
    selection.push_back(6);
    selection.push_back(1);
    selection.push_back(3);
    for (auto val: selection) {
        std::cout << val << " ";
    }
    std::cout << endl;

    TurboSort::Sort::SelectionSort(selection);
    for (auto val: selection) {
        std::cout << val << " ";
    }
    std::cout << endl;
    std::cout << endl;

    std::cout << "BubbleSort: " << std::endl;
    std::vector<int> bubbles;
    bubbles.push_back(5);
    bubbles.push_back(1);
    bubbles.push_back(12);
    bubbles.push_back(-5);
    bubbles.push_back(16);
    for (auto val: bubbles) {
        std::cout << val << " ";
    }
    std::cout << endl;

    TurboSort::Sort::BubbleSort(bubbles);
    for (auto val: bubbles) {
        std::cout << val << " ";
    }
    std::cout << endl;
    std::cout << endl;

    std::cout << "QuickSort: " << std::endl;
    std::vector<int> quickies;
    quickies.push_back(9);
    quickies.push_back(-3);
    quickies.push_back(5);
    quickies.push_back(2);
    quickies.push_back(6);
    quickies.push_back(8);
    quickies.push_back(-6);
    quickies.push_back(1);
    quickies.push_back(3);

    for (auto val: quickies) {
        std::cout << val << " ";
    }
    std::cout << endl;

    TurboSort::Sort::QuickSort(quickies, 0, quickies.size()-1);
    for (auto val: quickies) {
        std::cout << val << " ";
    }
    std::cout << endl;
    std::cout << endl;;

    return 0;
}



/*
// SpotifySongQueue
int main()
{
    auto songQueue = new TurboLinkedQueue<string>{};
    bool quit = false;

    while (!quit)
    {
        if(songQueue->empty())
        {
            std::cout << "The Queue is empty! [a]dd or [q]uit?" << std::endl;
        }
        else
        {
            std::cout << "What would you like to do? [s]kip or [a]dd?" << std::endl;
        }

        char input;
        cin >> input;

        if (input == 's' && songQueue->empty())
            std::cout << "The Queue is empty! [a]dd or [q]uit?" << std::endl;


        if (input == 'a')
        {
            std::cout << "Enter the Song's name:" << std::endl;
            string songName;
            std::cin >> songName;
            songQueue->enqueue(songName);
        }
        if (input == 's')
        {
            std::cout << "Now Playing: " << songQueue->front() << std::endl;
            songQueue->dequeue();
        }
        if(input == 'q')
        {
            std::cout << "Quitting Spotify..." << std::endl;
            delete songQueue;
            quit = true;
        }
    }
    return 0;
}
*/

/*
// Preliminary "Tests" TurboQueue (Awaiting help getting gmock to test collections)
int main()
{
    // Can items be enqueued?
    auto testQueue = new TurboLinkedQueue<int>{};
    testQueue->enqueue(1);
    testQueue->enqueue(2);
    testQueue->enqueue(3);

    for (auto& a : *testQueue) {
        std::cout << a << " " ;
    }
    std::cout << std::endl;

    //Does front and dequeue work as expected?
    std::cout << "At front: " << testQueue->front() << std::endl;
    testQueue->dequeue();
    std::cout << "After dequeue: " << testQueue->front() << std::endl;

    // Does size and empty work as expected?
    std::cout << "Size: " << testQueue->size() << std::endl;
    std::cout << "Empty? " << testQueue->empty() << std::endl;
    testQueue->dequeue();
    std::cout << "After dequeue: " << testQueue->empty() << std::endl;
    return 0;
}
*/

/*
// GameStateHistory
int main()
{
    auto stateHistory = new TurboLinkedStack<string> {};
    stateHistory->push("Main Menu");
    auto nextLevel = 1;

    while (!stateHistory->empty())
    {
        tryAgain:
        if(stateHistory->top() == "Main Menu")
        {
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "[0]: Go to Level " << nextLevel << std::endl;
            std::cout << "[1]: Go to Settings" << std::endl;
            std::cout << "[q]: Quit" << std::endl;
        }
        else
        {
            std::cout << "You are here: " << stateHistory->top() << std::endl;
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "[0]: Go to Level " << nextLevel << std::endl;
            std::cout << "[1]: Go to Main Menu" << std::endl;
            std::cout << "[b]: Go back to " << stateHistory->secondFromTop() << std::endl;
        }

        char input;
        std::cin >> input;

        if (stateHistory->top() == "Main Menu")
        {
            if(input == '1')
            {
                stateHistory->push("Settings");
                std::cout << "[b]: Go back to Main Menu" << std::endl;
                BackFromMenu:
                char goBack;
                std::cin >> goBack;
                while(goBack != 'b')
                {
                    goto BackFromMenu;
                }
                stateHistory->pop();
            }
        }
        else
        {
            if(input == '1')
            {
                while(stateHistory->top() != "Main Menu")
                {
                    stateHistory->pop();
                }
                nextLevel = 1;
            }
            if(input == 'b')
            {
                stateHistory->pop();
                --nextLevel;
            }
        }

        if(input == '0')
        {
            string level = to_string(nextLevel);
            stateHistory->push("Level " + level);
            ++nextLevel;
        }

        if(input == 'q')
        {
            while (!stateHistory->empty())
            {
                stateHistory->pop();
            }
        }

        else
        {
            goto tryAgain;
        }
    }
    return 0;
}
*/

/*
// Preliminary "Tests" TurboStack (Awaiting help getting gmock to test collections)
int main()
{
    //Can items be pushed into the stack?
    auto testStack = new TurboLinkedStack<int>{};
    testStack->push(1);
    testStack->push(2);
    testStack->push(3);

    for (auto& a : *testStack) {
        std::cout << a << " " ;
    }
    std::cout << std::endl;

    //Does top and pop work as expected?
    std::cout << testStack->top() << std::endl;
    testStack->pop();
    std::cout << testStack->top() << std::endl;

    // Does size and empty work as expected?
    std::cout << "Size: " << testStack->size() << std::endl;
    testStack->pop();
    std::cout << "Empty? " << testStack->empty() << std::endl;

    return 0;
}
*/

/*
int main()
{
    for (auto& odd : TurboMaths::GetOddNumbers(5)) {
        cout << odd << " " << endl;
    }

    for (auto& even : TurboMaths::GetEvenNumbers(5)) {
        cout << even << " " << endl;
    }

    return 0;
}
*/