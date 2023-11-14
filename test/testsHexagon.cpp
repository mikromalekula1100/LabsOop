#include <gtest/gtest.h>

#include "Hexagon.h"


class HexagonOperatorEqually : public ::testing::TestWithParam< vector<Point> > {};

TEST_P(HexagonOperatorEqually, OperatorEqually) {

  auto param = GetParam();
  
  Hexagon p1({{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}});


  // arrange 
  Hexagon p(param);
  // act
  bool result = (p == p1);

  // assert
  
  ASSERT_EQ(result, true);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonOperatorEqually,
	::testing::Values(
		    vector<Point>{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}
        
));

class HexagonCenterFigure : public ::testing::TestWithParam< std::pair<vector<Point>, Point> > {};

TEST_P(HexagonCenterFigure, CenterFigure) {

  auto params = GetParam();

  Hexagon p(params.first);

  // arrange 
  Point correctResult = params.second;
  
  // act
  Point result = p.calculatGeomCenter();

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonCenterFigure,
	::testing::Values(
		    std::pair<vector<Point>, Point>{{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, {0, 0}}
        
));


class HexagonSquareFigure : public ::testing::TestWithParam< std::pair<vector<Point>, double> > {};

TEST_P(HexagonSquareFigure, SquareFigure) {

  auto params = GetParam();
  
  double correctResult = params.second;
  // arrange 
  Hexagon p(params.first);
  
  // act
  double result = static_cast<double>(p);

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonSquareFigure,
	::testing::Values(
		    std::pair<vector<Point>, double>{{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, 0.433011}
        
));