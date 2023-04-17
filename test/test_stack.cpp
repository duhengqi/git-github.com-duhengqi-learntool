#include "gtest.h"
extern "C"{
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm_stack.h"
//#include "testdata.h"
}

#if ALGORITHM_DESCRIPTION("测试基本计算器")

/* 1,测试思路： 接口测试 + 混合测试 */
TEST(test_stack_calculate, easyAdd)
{
    char s[] = "1+2";
    int result = calculate(s);
    EXPECT_EQ(3, result);
}

TEST(test_stack_calculate, easyAdd2)
{
    char s[] = "1+2*3";
    int result = calculate(s);
    EXPECT_EQ(7, result);
}

TEST(test_stack_calculate, easyBrackets)
{
    char s[] = "(1+2)*3";
    int result = calculate(s);
    EXPECT_EQ(9, result);
}

TEST(test_stack_calculate, complaxBrackets)
{
    char s[] = "(1+(4+5+2)-3)+(6+8)";
    int result = calculate(s);
    EXPECT_EQ(23, result);
}

TEST(test_stack_calculate, complaxBrackets2)
{
    char s[] = "(1+(4+5*2)-3)+(6+8)";
    int result = calculate(s);
    EXPECT_EQ(26, result);
}

TEST(test_stack_calculate, special)
{
    char s1[] = "1";
    char s2[] = "(1)";
    char s3[] = "(((1)))";
    int result = calculate(s1);
    EXPECT_EQ(1, result);
    result = calculate(s2);
    EXPECT_EQ(1, result);
    result = calculate(s3);
    EXPECT_EQ(1, result);
}

TEST(test_stack_calculate, negative)
{
    char s[] = "-2+1";
    int result = calculate(s);
    EXPECT_EQ(-1, result);
}

TEST(test_stack_calculate, negative2)
{
    char s[] = "-2";
    int result = calculate(s);
    EXPECT_EQ(-2, result);
}

TEST(test_stack_calculate, negativeAndBrackets)
{
    char s[] = "-(-2+1)";
    int result = calculate(s);
    EXPECT_EQ(1, result);
}

#endif
