// #include <gtest/gtest.h>

// #include "Octagon.h"
// #include "Pentagon.h"
// #include "Hexagon.h"

// #include "FigureFactory.h"
// #include "PentagonFactory.h"
// #include "OctagonFactory.h"
// #include "HexagonFactory.h"


// class PentagonOperatorEqually : public ::testing::TestWithParam< std::initializer_list<pair<double, double>> > {};

// TEST_P(PentagonOperatorEqually, OperatorEqually) {

//   auto param = GetParam();
  
//   Pentagon p(param);

//   // arrange 
//   Pentagon p1(param);
  
//   // act
//   bool result = (p == p1);

//   // assert
  
//   ASSERT_EQ(result, true);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	PentagonOperatorEqually,
// 	::testing::Values(
// 		     std::initializer_list<pair<double, double>>{
//           {1, 0}, {0.309017, 0.951057},
//           {-0.809017, 0.587785}, {-0.809017, -0.587785},
//            {0.309017, -0.951057}}
        
// ));

// class PentagonCenterFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>> > {};

// TEST_P(PentagonCenterFigure, CenterFigure) {

//   auto params = GetParam();

//   Pentagon p(params.first);

//   // arrange 
//   pair<double, double> correctResult = params.second;
  
//   // act
//   pair<double, double> result;

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	PentagonCenterFigure,
// 	::testing::Values(
// 		    std::pair<const std::initializer_list<pair<double, double>>, std::pair<double, double>>{{
//           {1, 0}, {0.309017, 0.951057},
//           {-0.809017, 0.587785}, {-0.809017, -0.587785},
//            {0.309017, -0.951057}}, {0, 0}}
        
// ));


// class PentagonSquareFigure : public ::testing::TestWithParam< std::pair<const std::initializer_list<pair<double, double>>, double> > {};

// TEST_P(PentagonSquareFigure, SquareFigure) {

//   auto params = GetParam();

//   Pentagon p(params.first);

//   // arrange 
//   double correctResult = params.second;
  
//   // act
//   double result = static_cast<double>(p);

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	PentagonSquareFigure,
// 	::testing::Values(
// 		    std::pair<const std::initializer_list<pair<double, double>>, double>{{
//           {1, 0}, {0.309017, 0.951057},
//           {-0.809017, 0.587785}, {-0.809017, -0.587785},
//            {0.309017, -0.951057}}, 0}
        
// ));