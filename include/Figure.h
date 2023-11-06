#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figure{
public:
    virtual ~Figure(){}
    virtual pair<double, double> calculatGeomCenter() = 0;
    virtual operator double() = 0;
};