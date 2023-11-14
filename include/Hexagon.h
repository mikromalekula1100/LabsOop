#pragma once

#include "Figure.h"

class Hexagon : public Figure{

public:
    
    static Hexagon create(vector<Point>&);
    
    using Figure::Figure;
};

