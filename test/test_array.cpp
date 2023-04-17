#include "gtest.h"
extern "C"{
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm_array.h"
//#include "testdata.h"
}

#if ALGORITHM_DESCRIPTION("测试数组实现队列")

/* 1,测试思路： 接口测试 + 混合测试 */
TEST(test_array_queue, queueIsEmpty)
{
    CycleQueue queue = {0};
    int empty = CycleQueue_IsEmpty(&queue);
    EXPECT_EQ(1, empty);
}
TEST(test_array_queue, queuePUSH)
{
    CycleQueue queue = {0};
    int testSize = 5;
    for (int i = 0; i < testSize; i++) {
        CycleQueue_PUSH(&queue, i);
    }
    EXPECT_EQ(0, queue.data[0]);
    EXPECT_EQ(1, queue.data[1]);
    EXPECT_EQ(2, queue.data[2]);
    EXPECT_EQ(3, queue.data[3]);
    EXPECT_EQ(4, queue.data[4]);
}
TEST(test_array_queue, queuePOP)
{
    CycleQueue queue = {0};
    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE; i++) {
        CycleQueue_PUSH(&queue, i);
    }
    int popData;
    CycleQueue_POP(&queue, &popData);
    EXPECT_EQ(0, popData);
    CycleQueue_POP(&queue, &popData);
    EXPECT_EQ(1, popData);
    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE - 2; i++) {
        CycleQueue_POP(&queue, &popData);
    }
    EXPECT_EQ(99, popData);
}
TEST(test_array_queue, queueIsFull)
{
    CycleQueue queue = {0};
    int ret;
    int popData;
    int full = CycleQueue_IsFull(&queue);
    EXPECT_EQ(0, full);
    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE; i++) {
        ret |= CycleQueue_PUSH(&queue, i);
    }
    EXPECT_EQ(0, ret);
    full = CycleQueue_IsFull(&queue);
    EXPECT_EQ(1, full);
    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE; i++) {
        CycleQueue_POP(&queue, &popData);
    }
    full = CycleQueue_IsFull(&queue);
    EXPECT_EQ(0, full);
}

TEST(test_array_queue, queueOverPUSH)
{
    int ret = 0;
    int popData;
    CycleQueue queue = {0};

    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE*2; i++) {
        ret |= CycleQueue_PUSH(&queue, i);
    }
    EXPECT_EQ(-1, ret);
    EXPECT_EQ(1, CycleQueue_IsFull(&queue));
    ret = CycleQueue_POP(&queue, &popData);
    EXPECT_EQ(0, ret);
    EXPECT_EQ(0, CycleQueue_IsFull(&queue));
    EXPECT_EQ(0, popData);
}

TEST(test_array_queue, queueOverPOP)
{
    int ret = 0;
    int popData;
    CycleQueue queue = {0};

    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE; i++) {
        ret |= CycleQueue_PUSH(&queue, i);
    }
    EXPECT_EQ(0, ret);
    EXPECT_EQ(1, CycleQueue_IsFull(&queue));
    ret = 0;
    for (int i = 0; i < CYCLE_QUEUE_MAX_SIZE*2; i++) {
        ret |= CycleQueue_POP(&queue, &popData);
    }
    EXPECT_EQ(-1, ret);
    EXPECT_EQ(1, CycleQueue_IsEmpty(&queue));
    EXPECT_EQ(99, popData);
}

#endif

TEST(test_array, testminSubArrayLen)
{
    int nums[] = {2,3,1,2,4,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 7;
    int result = minSubArrayLen(target, nums, numsSize);
    EXPECT_EQ(2, result);
}
