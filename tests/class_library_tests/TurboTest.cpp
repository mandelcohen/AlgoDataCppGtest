#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboCollections.hpp"
#include "TurboLinkedStack.h"

#define ALL_TESTS

using namespace TurboCollections;
using namespace std;


TEST(Turbo, AddCorrectlyToStack)
{
    // given
    auto stack = new TurboStack::TurboLinkedStack<int>;

    // when
    stack->push(1);
    stack->push(2);
    stack->push(3);

    // then       // actual         // expected
    ASSERT_THAT(   *stack,        testing::ElementsAre(3, 2, 1));
}

TEST(Turbo, PopAndPeekInStack)
{
    auto stack = new TurboStack::TurboLinkedStack<int>;
    stack->push(1);
    stack->push(2);
    stack->push(3);

    ASSERT_EQ(stack->top(), 3);
    stack->pop();

    ASSERT_EQ(stack->top(), 2);
    ASSERT_THAT(*stack,        testing::ElementsAre(2, 1));
}

TEST(Turbo, StackSizeAndEmpty){
    auto stack = new TurboStack::TurboLinkedStack<int>;
    ASSERT_TRUE(stack->empty());

    stack->push(1);
    stack->push(2);
    stack->push(3);
    ASSERT_FALSE(stack->empty());

    ASSERT_EQ(stack->size(), 3);
}