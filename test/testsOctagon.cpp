// #include <gtest/gtest.h>

// #include "Octagon.h"


// class OctagonOperatorEqually : public ::testing::TestWithParam< vector<Point> > {};

// TEST_P(OctagonOperatorEqually, OperatorEqually) {

//   auto param = GetParam();
  
//   Octagon p1({{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
//      {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
//       {0.707107, -0.707107}});


//   // arrange 
//   Octagon p(param);
//   // act
//   bool result = (p == p1);

//   // assert
  
//   ASSERT_EQ(result, true);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonOperatorEqually,
// 	::testing::Values(
// 		    vector<Point>{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
//      {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
//       {0.707107, -0.707107}}
        
// ));

// class OctagonCenterFigure : public ::testing::TestWithParam< std::pair<vector<Point>, Point> > {};

// TEST_P(OctagonCenterFigure, CenterFigure) {

//   auto params = GetParam();

//   Octagon p(params.first);

//   // arrange 
//   Point correctResult = params.second;
  
//   // act
//   Point result = p.calculatGeomCenter();

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonCenterFigure,
// 	::testing::Values(
// 		    std::pair<vector<Point>, Point>{{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
//      {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
//       {0.707107, -0.707107}}, {0, 0}}
        
// ));


// class OctagonSquareFigure : public ::testing::TestWithParam< std::pair<vector<Point>, double> > {};

// TEST_P(OctagonSquareFigure, SquareFigure) {

//   auto params = GetParam();
  
//   double correctResult = params.second;
//   // arrange 
//   Octagon p(params.first);
  
//   // act
//   double result = static_cast<double>(p);

//   // assert
//   ASSERT_EQ(result, correctResult);
// }

// INSTANTIATE_TEST_SUITE_P(
// 	StringsWithoutIncorrect,
// 	OctagonSquareFigure,
// 	::testing::Values(
// 		    std::pair<vector<Point>, double>{{{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
//      {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
//       {0.707107, -0.707107}}, 0.353553}
        
// ));