#pragma once

#include "FigureValidator.h"


class PentagonValidator : public FigureValidator{

    bool validate(const vector<Point>&) override;
};