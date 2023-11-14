#include <gtest/gtest.h>

#include "Pentagon.h"


class PentagonOperatorEqually : public ::testing::TestWithParam< vector<Point> > {};

TEST_P(PentagonOperatorEqually, OperatorEqually) {

  auto param = GetParam();
  
  Pentagon p1({{1, 0}, {0.309017, 0.951057},
          {-0.809017, 0.587785}, {-0.809017, -0.587785},
           {0.309017, -0.951057}});


  // arrange 
  Pentagon p(param);
  // act
  bool result = (p == p1);

  // assert
  
  ASSERT_EQ(result, true);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	PentagonOperatorEqually,
	::testing::Values(
		    vector<Point>{
          {1, 0}, {0.309017, 0.951057},
          {-0.809017, 0.587785}, {-0.809017, -0.587785},
           {0.309017, -0.951057}}
        
));

class PentagonCenterFigure : public ::testing::TestWithParam< std::pair<vector<Point>, Point> > {};

TEST_P(PentagonCenterFigure, CenterFigure) {

  auto params = GetParam();

  Pentagon p(params.first);

  // arrange 
  Point correctResult = params.second;
  
  // act
  Point result = p.calculatGeomCenter();

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	PentagonCenterFigure,
	::testing::Values(
		    std::pair<vector<Point>, Point>{{
          {1, 0}, {0.309017, 0.951057},
          {-0.809017, 0.587785}, {-0.809017, -0.587785},
           {0.309017, -0.951057}}, {0, 0}}
        
));


class PentagonSquareFigure : public ::testing::TestWithParam< std::pair<vector<Point>, double> > {};

TEST_P(PentagonSquareFigure, SquareFigure) {

  auto params = GetParam();
  
  double correctResult = params.second;
  // arrange 
  Pentagon p(params.first);
  
  // act
  double result = static_cast<double>(p);

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	PentagonSquareFigure,
	::testing::Values(
		    std::pair<vector<Point>, double>{{
            {1, 0}, {0.309017, 0.951057},
            {-0.809017, 0.587785}, {-0.809017, -0.587785},
            {0.309017, -0.951057}}, 0.475528}
        
));