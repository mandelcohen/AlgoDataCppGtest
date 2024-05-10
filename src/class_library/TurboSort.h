#pragma once

#include <iostream>
#include <cstdio>

namespace TurboSort
{
    class Sort
    {
        Sort();
        static int Partition(std::vector<int>& list, int low, int high);

    public:
        static void SelectionSort(std::vector<int>& list);
        static void BubbleSort(std::vector<int>& list);
        static void QuickSort(std::vector<int>& list, int low, int high);
    };
}

