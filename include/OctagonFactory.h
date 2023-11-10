#pragma once

#include "Octagon.h"
#include "FigureFactory.h"

class OctagonFactory : protected FigureFactory{

public:
    virtual Figure* createFigure(const initializer_list<pair<double, double>>&) override;

};