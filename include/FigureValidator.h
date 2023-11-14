#pragma once

#include "Point.h"
#include <vector>


class FigureValidator{

public:
    virtual bool validate(const vector<Point>&) = 0;
};