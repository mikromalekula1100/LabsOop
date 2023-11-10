#pragma once

#include "Hexagon.h"
#include "FigureFactory.h"

class HexagonFactory : protected FigureFactory{

public:
    virtual Figure* createFigure(const initializer_list<pair<double, double>>&) override;

};