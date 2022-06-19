#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../app/func.hpp"

TEST(test1_suite1, test1)
{
    EXPECT_EQ(my_func(0), 10);

    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(7 * 6, 42);
}

TEST(test1_suite1, test2)
{
    EXPECT_EQ(7 * 6, 41);
    EXPECT_EQ(7 * 6, 42);
}
