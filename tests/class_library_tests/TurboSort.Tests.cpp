#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboSort.h"

#define ALL_TESTS
using namespace TurboSort;
using namespace std;


TEST(TurboSort, SelectionSort)
{
    // given
    auto selection = new std::vector<int>;

    // when
    selection->push_back(5);
    selection->push_back(2);
    selection->push_back(4);
    selection->push_back(6);
    selection->push_back(1);
    selection->push_back(3);

    TurboSort::Sort::SelectionSort(*selection);

    // then       // actual         // expected
    ASSERT_THAT(   *selection,        testing::ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(TurboSort, BubbleSort)
{
    // given
    auto list = new std::vector<int>;

    // when
    list->push_back(5);
    list->push_back(2);
    list->push_back(4);
    list->push_back(6);
    list->push_back(1);
    list->push_back(3);

    TurboSort::Sort::BubbleSort(*list);

    // then       // actual         // expected
    ASSERT_THAT(   *list,        testing::ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(TurboSort, Quicksort)
{
    // given
    auto list = new std::vector<int>;

    // when
    list->push_back(5);
    list->push_back(2);
    list->push_back(4);
    list->push_back(6);
    list->push_back(1);
    list->push_back(3);

    TurboSort::Sort::QuickSort(*list, 0, list->size() -1);

    // then       // actual         // expected
    ASSERT_THAT(   *list,        testing::ElementsAre(1, 2, 3, 4, 5, 6));
}