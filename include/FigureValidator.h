#pragma once

#include "/home/maks/Desktop/LabsOop/include/Point.h"
#include <vector>
#include <math.h>

template <Number T, Number D>
class FigureValidator{

public:
    
    const double EPSILON = 1000000.0; 
    const double INACCURACY = 10e-5; 

    virtual bool validate(vector<Point<T, D>>&) = 0;
};
