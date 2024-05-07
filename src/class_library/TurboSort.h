#pragma once

#include <iostream>
#include <cstdio>

namespace TurboSort {

    class TurboSort {
        static void Swap(std::vector<int> list, int &a, int &b) {}
        static void SelectionSort(std::vector<int> list){}
        static void BubbleSort(std::vector<int> list){}
        static int Partition(std::vector<int> list, int low, int high){}
        static void QuickSort(std::vector<int> list, int low, int high){}
    };

}

