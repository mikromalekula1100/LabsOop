#pragma once

#include "Figure.h"

class FigureFactory{

protected:
    const double EPSILON = 0.000005;

protected:
    virtual Figure* createFigure(const initializer_list<pair<double, double>>&) = 0;

};