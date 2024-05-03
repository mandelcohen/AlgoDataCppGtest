#include <iostream>
#include <vector>
#include "TurboCollections.hpp"
#include "TurboLinkedStack.h"
#include "TurboLinkedQueue.h"

using namespace TurboCollections;
using namespace TurboStack;
using namespace TurboQueue;

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
// Preliminary "Tests" (Awaiting help getting gmock to test collections)
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