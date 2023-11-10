#pragma once

#include "Pentagon.h"
#include "FigureFactory.h"

class PentagonFactory : protected FigureFactory{

public:
    virtual Figure* createFigure(const initializer_list<pair<double, double>>&) override;

};