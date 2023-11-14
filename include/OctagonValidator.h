#pragma once

#include "FigureValidator.h"


class OctagonValidator : public FigureValidator{

public:

    static const int numberVertices = 8;

    bool validate(vector<Point>&) override;
};