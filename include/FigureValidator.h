#pragma once

#include "Point.h"
#include <vector>
#include <math.h>


class FigureValidator{

public:
    
    const double EPSILON = 1000000.0; 
    const double INACCURACY = 10e-5; 

    virtual bool validate(vector<Point>&) = 0;
};