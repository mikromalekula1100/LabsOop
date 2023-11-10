#include <gtest/gtest.h>

#include "Octagon.h"
#include "Pentagon.h"
#include "Hexagon.h"

#include "FigureFactory.h"
#include "PentagonFactory.h"
#include "OctagonFactory.h"
#include "HexagonFactory.h"


class HexagonOperatorEqually : public ::testing::TestWithParam< std::initializer_list<pair<double, double>> > {};

TEST_P(HexagonOperatorEqually, OperatorEqually) {

  auto param = GetParam();
  
  Hexagon p(param);

  // arrange 
  Hexagon p1(param);
  
  // act
  bool result = (p == p1);

  // assert
  
  ASSERT_EQ(result, true);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonOperatorEqually,
	::testing::Values(
		     std::initializer_list<pair<double, double>>{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}}
        
));


class HexagonCenterFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>> > {};

TEST_P(HexagonCenterFigure, CenterFigure) {

  auto params = GetParam();

  Hexagon p(params.first);

  // arrange 
  pair<double, double> correctResult = params.second;
  
  // act
  pair<double, double> result;

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonCenterFigure,
	::testing::Values(
		    std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>>{{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}}, {0, 0}}
        
));


class HexagonSquareFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, double> > {};

TEST_P(HexagonSquareFigure, SquareFigure) {

  auto params = GetParam();

  Hexagon p(params.first);

  // arrange 
  double correctResult = params.second;
  
  // act
  double result = static_cast<double>(p);

  // assert
  ASSERT_EQ(result, correctResult);
}

INSTANTIATE_TEST_SUITE_P(
	StringsWithoutIncorrect,
	HexagonSquareFigure,
	::testing::Values(
		    std::pair<const std::initializer_list<pair<double, double>>, double>{{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}}, 0}
        
));