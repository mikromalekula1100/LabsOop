#pragma once

#include "Figure.h"

class Octagon : public Figure{

public:

    static Octagon create(vector<Point>&);
    
    using Figure::Figure;
};
