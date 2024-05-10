#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboSearch.h"
#include <chrono>

using namespace std;
using namespace TurboSearch;

TEST(TurboSearch, LinearSearch)
{
    auto list = new std::vector<int>;

    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_back(7);

    auto start_time = chrono::high_resolution_clock::now();
    ASSERT_THAT( Search::LinearSearch(*list, 6)  ,  -1);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

    ASSERT_THAT( Search::LinearSearch(*list, 7)  ,  5);
}

TEST(TurboSearch, BinarySearch)
{
    auto list = new std::vector<int>;

    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_back(7);

    auto start_time = chrono::high_resolution_clock::now();
    ASSERT_THAT( Search::BinarySearch(*list, 6)  ,  -1);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

    ASSERT_THAT( Search::BinarySearch(*list, 7)  ,  5);
}