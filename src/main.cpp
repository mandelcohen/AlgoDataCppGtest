#include <iostream>
#include <cstdio>
#include <vector>
#include "TurboCollections.hpp"

using namespace std;
using namespace TurboCollections;


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
