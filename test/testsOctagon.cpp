// #include <gtest/gtest.h>

// #include "Octagon.h"
// #include "Pentagon.h"
// #include "Hexagon.h"

// #include "FigureFactory.h"
// #include "PentagonFactory.h"
// #include "OctagonFactory.h"
// #include "HexagonFactory.h"


// class OctagonOperatorEqually : public ::testing::TestWithParam< std::initializer_list<pair<double, double>> > {};

// TEST_P(OctagonOperatorEqually, OperatorEqually) {

//   auto param = GetParam();
  
//   Octagon p(param);

//   // arrange 
//   Octagon p1(param);
  
//   // act
//   bool result = (p == p1);

//   // assert
  
//   ASSERT_NE(result, true);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonOperatorEqually,
// 	::testing::Values(
// 		     std::initializer_list<pair<double, double>>{{1, 0}, {0.5, 0.866025},
//      {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}
        
// ));


// class OctagonCenterFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>> > {};

// TEST_P(OctagonCenterFigure, CenterFigure) {

//   auto params = GetParam();

//   Octagon p(params.first);

//   // arrange 
//   pair<double, double> correctResult = params.second;
  
//   // act
//   pair<double, double> result;

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonCenterFigure,
// 	::testing::Values(
// 		    std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>>{{{1, 0}, {0.5, 0.866025},
//      {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, {0, 0}}
        
// ));


// class OctagonSquareFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, double> > {};

// TEST_P(OctagonSquareFigure, SquareFigure) {

//   auto params = GetParam();

//   Octagon p(params.first);

//   // arrange 
//   double correctResult = params.second;
  
//   // act
//   double result = static_cast<double>(p);

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonSquareFigure,
// 	::testing::Values(
// 		    std::pair<const std::initializer_list<pair<double, double>>, double>{{{1, 0}, {0.5, 0.866025},
//      {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}, 0}
        
// ));