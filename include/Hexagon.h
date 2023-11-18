#pragma once

#include "Figure.h"
#include "HexagonValidator.h"

template <Number T, Number D>
class Hexagon : public Figure<T, D>{

public:
    
    static Hexagon create(vector<Point<T, D>>&);
    
    using Figure<T, D>::Figure;
};

Hexagon()->Hexagon<double, double>;
// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------

template <Number T, Number D>
Hexagon<T, D> Hexagon<T, D>::create(vector<Point<T, D>>& list) { 
    HexagonValidator<T, D> validator;
    validator.validate(list);

    return move(Hexagon<T, D>(list));
}
