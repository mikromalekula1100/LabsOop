
#include <gtest/gtest.h>

#include "line_editor.h"

TEST(test_01, basic_test_set)
{   
    string text = "aaaaa";

    int n = 1;

    char old_value = 'a', new_value = 'b';
    
    string result = replace(text, n, old_value, new_value);

    EXPECT_EQ(result, "bbbbb");
}

TEST(test_02, basic_test_set)
{   
    // arrange
    string text = "aaaaa";

    int n = -1;

    char old_value = 'a', new_value = 'b';
    
    //act
    string result = replace(text, n, old_value, new_value);

    //assert
    EXPECT_EQ(result, "aaaaa");
}

TEST(test_03, basic_test_set)
{   
    string text = "abcabcabc";

    int n = 10;

    char old_value = 'a', new_value = 'z';
    
    string result = replace(text, n, old_value, new_value);

    EXPECT_EQ(result, "abcabcabc");
}

TEST(test_04, basic_test_set)
{   
    string text = "abcabcabc";

    int n = 2;

    char old_value = 'a', new_value = 'z';
    
    string result = replace(text, n, old_value, new_value);

    EXPECT_EQ(result, "abczbcabc");
    
}

TEST(test_05, basic_test_set)
{   
    string text = "Vader said: No, I am your father!";

    int n = 2;

    char old_value = 'a', new_value = 'o';
    
    string result = replace(text, n, old_value, new_value);

    EXPECT_EQ(result, "Vader soid: No, I am your fother!");
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}