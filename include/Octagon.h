#pragma once

#include "Figure.h"
#include "OctagonValidator.h"

template <Number T, Number D>
class Octagon : public Figure<T, D>{

public:

    using Figure<T, D>::Figure;
    
    static Octagon create(vector<Point<T, D>>&);
};

Octagon()->Octagon<double, double>;

// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------

template <Number T, Number D>
Octagon<T, D> Octagon<T, D>::create(vector<Point<T, D>>& list) { 
    OctagonValidator<T, D> validator;
    validator.validate(list);

    return move(Octagon<T, D>(list));
}
