#pragma once

#include <iostream>
#include <cstdio>

namespace TurboSearch{
    class Search {
        Search();
    public:
        static int LinearSearch(std::vector<int>& list, int value);
        static int BinarySearch(std::vector<int>& list, int value);
    };
}




