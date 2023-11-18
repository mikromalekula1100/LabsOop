#pragma once

#include "Figure.h"
#include "PentagonValidator.h"

template <Number T, Number D>
class Pentagon : public Figure<T, D>{

public:

    using Figure<T, D>::Figure;

    static Pentagon create(vector<Point<T, D>>&);
};
Pentagon()->Pentagon<double, double>;
// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------

template <Number T, Number D>
Pentagon<T, D> Pentagon<T, D>::create(vector<Point<T, D>>& list) { 
    PentagonValidator<T, D> validator;
    validator.validate(list);

    return move(Pentagon<T, D>(list));
}
