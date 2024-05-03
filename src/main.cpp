#include <iostream>
#include <vector>
#include "TurboCollections.hpp"
#include "TurboLinkedStack.h"

using namespace TurboCollections;
using namespace TurboStack;


// GameStateHistory
int main()
{
    auto testStack = new TurboLinkedStack<int>{};
    testStack->push(1);
    testStack->push(2);
    testStack->push(3);

    for (auto& a : *testStack) {
        std::cout << a << " " ;
    }
    std::cout << std::endl;




    return 0;
}


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