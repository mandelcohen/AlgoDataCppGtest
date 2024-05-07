
#include "TurboSort.h"

namespace TurboSort {

    static void Swap(std::vector<int> list, int a, int b) {
        int temp = list[a];
        list[a] = list[b];
        list[b] = temp;
    }

    static void SelectionSort(std::vector<int> list){
        int min;
        for (int i = 0; i < list.size(); ++i)
        {
            min = i;
            for (int j = i +1; j < list.size(); ++j)
            {
                if(list[j] < list[min])
                {
                    min = j;
                }
            }

            if(min != i)
            {
                Swap(list, min, i);
            }
        }
    }
    
    static void BubbleSort(std::vector<int> list){
        auto loop = list.size();
        for (int i = loop -1; i > 0; --i) {
            bool swapped = false;
            for (int j = 0; j < i; ++j) {
                if(list[j] > list[j+1])
                    Swap(list, j, j+1);
                swapped = true;
            }
            if(!swapped) break;
        }
    }

    static int Partition(std::vector<int> list, int low, int high)
    {
        int pivot = list[high];
        int i = low;
        for (int j = low; j <= high -1 ; ++j) {
            if(list[j] < pivot)
            {
                Swap(list, j, i);
                ++i;
            }
        }
        Swap(list, i, high);
        return i;
    }


    static void QuickSort(std::vector<int> list, int low, int high)
    {
        if(low <= high)
        {
            auto partitionIndex = Partition(list, low, high);
            QuickSort(list, low, partitionIndex -1);
            QuickSort(list, partitionIndex +1, high);
        }

    }


} // TurboSort