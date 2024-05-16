#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboCollections.hpp"
#include "TurboLinkedStack.h"
#include "TurboLinkedQueue.h"

#define ALL_TESTS

using namespace TurboCollections;
using namespace std;


TEST(TurboStack, AddCorrectlyToStack)
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

TEST(TurboStack, PopAndPeekInStack)
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

TEST(TurboStack, StackSizeAndEmpty){
    auto stack = new TurboStack::TurboLinkedStack<int>;
    ASSERT_TRUE(stack->empty());

    stack->push(1);
    stack->push(2);
    stack->push(3);
    ASSERT_FALSE(stack->empty());

    ASSERT_EQ(stack->size(), 3);
}

TEST(TurboQueue, AddCorrectlyToQueue)
{
    // given
    auto queue = new TurboQueue::TurboLinkedQueue<int>;

    // when
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    // then       // actual         // expected
    ASSERT_THAT(   *queue,        testing::ElementsAre(1, 2, 3));
    ASSERT_EQ(queue->front(), 1);
}

TEST(TurboQueue, CheckFrontandDequeue)
{
    auto queue = new TurboQueue::TurboLinkedQueue<int>;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    ASSERT_EQ(queue->front(), 1);
    ASSERT_EQ(queue->size(), 3);

    queue->dequeue();
    ASSERT_EQ(queue->size(), 2);
    ASSERT_EQ(queue->front(), 2);
}
