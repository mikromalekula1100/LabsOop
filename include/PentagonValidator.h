#pragma once

#include "FigureValidator.h"


class PentagonValidator : public FigureValidator{

public:

    static const int numberVertices = 5;

    bool validate(vector<Point>&) override;
};