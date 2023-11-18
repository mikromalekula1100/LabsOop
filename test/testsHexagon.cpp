#include <gtest/gtest.h>
#include "Hexagon.h"

class HexagonOperatorEqually : public ::testing::TestWithParam< vector<Point<double, double>> > {};

TEST_P(HexagonOperatorEqually, OperatorEqually) {

  auto param = GetParam();
  
  Hexagon<double, double> p1({{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}});

  // arrange 
  Hexagon<double, double> p(param);
  // act
  bool result = (p == p1);

  // assert
  ASSERT_EQ(result, true);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonOperatorEqually,
	::testing::Values(
		    vector<Point<double, double>>{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}
));

class HexagonCenterFigure : public ::testing::TestWithParam< std::pair<vector<Point<double, double>>, Point<double, double>> > {};

TEST_P(HexagonCenterFigure, CenterFigure) {

  auto params = GetParam();

  Hexagon<double, double> p(params.first);

  // arrange 
  Point<double, double> correctResult = params.second;
  
  // act
  Point<double, double> result = p.calculatGeomCenter();

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonCenterFigure,
	::testing::Values(
		    std::pair<vector<Point<double, double>>, Point<double, double>>{{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, {0, 0}}
        
));


class HexagonSquareFigure : public ::testing::TestWithParam< std::pair<vector<Point<double, double>>, double> > {};

TEST_P(HexagonSquareFigure, SquareFigure) {

  auto params = GetParam();
  
  double correctResult = params.second;
  // arrange 
  Hexagon<double, double> p(params.first);
  
  // act
  double result = static_cast<double>(p);

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonSquareFigure,
	::testing::Values(
		    std::pair<vector<Point<double, double>>, double>{{{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, 0.433011}
        
));