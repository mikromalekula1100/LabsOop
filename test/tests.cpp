
#include <gtest/gtest.h>

#include "line_editor.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(replace("aaaaa", 1, 'a', 'b')=="bbbbb");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}