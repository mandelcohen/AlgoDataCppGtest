#include "TurboSearch.h"


TurboSearch::Search::Search() = default;

int TurboSearch::Search::LinearSearch(std::vector<int>& list, int value)
{
    int index = 0;
    for (int item : list)
    {
        if(list[index] == value)
            return index;
        ++index;
    }
    return -1;
}

int TurboSearch::Search::BinarySearch(std::vector<int> &list, int value)
{
    int lowerBound = 0;
    int upperBound = list.size() -1;

    while (lowerBound <= upperBound)
    {
        int mid = (lowerBound + upperBound) /2;

        if(list[mid] < value)
            lowerBound = mid +1;
        else if(list[mid] > value)
            upperBound = mid -1;
        else if(list[mid == value])
            return mid;
    }
    return -1;
}