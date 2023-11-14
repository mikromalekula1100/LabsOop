#pragma once

#include "FigureValidator.h"


class HexagonValidator : public FigureValidator{

public:

    static const int numberVertices = 6;

    bool validate(vector<Point>&) override;
};