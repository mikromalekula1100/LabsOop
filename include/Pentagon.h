#pragma once

#include "Figure.h"

class Pentagon : public Figure{

public:

    using Figure::Figure;

    static Pentagon create(vector<Point>&);
};

