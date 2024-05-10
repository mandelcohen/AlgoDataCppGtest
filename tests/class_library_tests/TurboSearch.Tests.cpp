#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboSearch.h"
#include <chrono>

using namespace std;
using namespace TurboSearch;

TEST(TurboSearch, LinearSearch)
{
    auto list = new std::vector<int>;

    for (int i = 0; i < 1000; ++i) {
        list->push_back(i);
    }

    auto start_time = chrono::high_resolution_clock::now();
    ASSERT_THAT( Search::LinearSearch(*list, -5)  ,  -1);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "LinearSearch: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

    ASSERT_THAT( Search::LinearSearch(*list, 9)  ,  9);
}

TEST(TurboSearch, BinarySearch)
{
    auto list = new std::vector<int>;

    for (int i = 0; i < 1000; ++i) {
        list->push_back(i);
    }

    auto start_time = chrono::high_resolution_clock::now();
    ASSERT_THAT( Search::BinarySearch(*list, -5)  ,  -1);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "BinarySearch: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;

    ASSERT_THAT( Search::BinarySearch(*list, 9)  ,  9);
}