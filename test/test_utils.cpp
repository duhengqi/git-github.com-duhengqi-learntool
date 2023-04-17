#include "gtest.h"
extern "C"{
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm_utils.h"
//#include "testdata.h"
}

/* 测试公共接口： 测试 数的位数 18 2位数 */
TEST(test_utils_GetNumberOfDigits, all)
{
    EXPECT_EQ(1, Algorithm_GetNumberOfDigits(0));
    EXPECT_EQ(1, Algorithm_GetNumberOfDigits(8));
    EXPECT_EQ(2, Algorithm_GetNumberOfDigits(18));
    EXPECT_EQ(2, Algorithm_GetNumberOfDigits(28));
    EXPECT_EQ(3, Algorithm_GetNumberOfDigits(129));
}
