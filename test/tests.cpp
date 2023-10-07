#include <gtest/gtest.h>
#include "MaxAndMinForMyArray.h"
#include "MyArray.h"
#include "BitString.h"


class StringsForMax :public ::testing::TestWithParam< std::vector<std::string> > {};
TEST_P(StringsForMax, MaxForMyArray) {

  auto strings = GetParam();
  std::string str1 = strings[0];
  std::string str2 = strings[1];
  std::string str3 = strings[2];

  // arrange 
  MyArray first(str1);
  MyArray second(str2);
  
  // act
  MyArray result = max(first, second);

  // assert
  MyArray expectedResult(str3);
  ASSERT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	StringsForMax,
	::testing::Values(
		    std::vector<std::string>{"10010", "10", "10010"},
        std::vector<std::string>{"10010", "10000", "10010"},
        std::vector<std::string>{"101", "1", "101"},
        std::vector<std::string>{"1011", "", "1011"}
));

class StringsForMin :public ::testing::TestWithParam< std::vector<std::string> > {};

TEST_P(StringsForMin, MinForMyArray) {

  auto strings = GetParam();
  std::string str1 = strings[0];
  std::string str2 = strings[1];
  std::string str3 = strings[2];

  // arrange 
  MyArray first(str1);
  MyArray second(str2);
  
  // act
  MyArray result = min(first, second);

  // assert
  MyArray expectedResult(str3);
  ASSERT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	StringsForMin,
	::testing::Values(
		    std::vector<std::string>{"10010", "10", "10"},
        std::vector<std::string>{"10010", "10000", "10000"},
        std::vector<std::string>{"101", "1", "1"},
        std::vector<std::string>{"1011", "", ""}
));

class StringsOperatorLess :public ::testing::TestWithParam< std::pair<std::pair<std::string, std::string>, bool> > {};
TEST_P(StringsOperatorLess, MinForMyArray) {

  auto strings = GetParam();
  std::string str1 = strings.first.first;
  std::string str2 = strings.first.second;
  bool res = strings.second;

  // arrange 
  BitString first(str1);
  BitString second(str2);
  
  // act
  bool result = (first < second);

  // assert
  ASSERT_EQ(result, res);
}


INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	StringsOperatorLess,
	::testing::Values(
		    std::pair<std::pair<std::string, std::string>, bool>{{"1001", "1"}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"10010", "100"}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"101", "1"}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"1", "101"}, false}
));


class StringsOperatorMore :public ::testing::TestWithParam< std::pair<std::pair<std::string, std::string>, bool> > {};
TEST_P(StringsOperatorMore, MinForMyArray) {

  auto strings = GetParam();
  std::string str1 = strings.first.first;
  std::string str2 = strings.first.second;
  bool res = strings.second;

  // arrange 
  BitString first(str1);
  BitString second(str2);
  
  // act
  bool result = (first > second);

  // assert
  ASSERT_EQ(result, res);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	StringsOperatorMore,
	::testing::Values(
		    std::pair<std::pair<std::string, std::string>, bool>{{"1001", "1"}, false},
        std::pair<std::pair<std::string, std::string>, bool>{{"10010", "100"}, false},
        std::pair<std::pair<std::string, std::string>, bool>{{"101", "1"}, false},
        std::pair<std::pair<std::string, std::string>, bool>{{"11", "111"}, true}
));


class StringsOperatorEquality :public ::testing::TestWithParam< std::pair<std::pair<std::string, std::string>, bool> > {};
TEST_P(StringsOperatorEquality, MinForMyArray) {

  auto strings = GetParam();
  std::string str1 = strings.first.first;
  std::string str2 = strings.first.second;
  bool res = strings.second;

  // arrange 
  BitString first(str1);
  BitString second(str2);
  
  // act
  bool result = (first == second);

  // assert
  ASSERT_EQ(result, res);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	StringsOperatorEquality,
	::testing::Values(
		    std::pair<std::pair<std::string, std::string>, bool>{{"1001", "1001"}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"10010", "100"}, false},
        std::pair<std::pair<std::string, std::string>, bool>{{"1", "1"}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"", ""}, true},
        std::pair<std::pair<std::string, std::string>, bool>{{"11", "00"}, false},
        std::pair<std::pair<std::string, std::string>, bool>{{"1000", "1001"}, false}
));