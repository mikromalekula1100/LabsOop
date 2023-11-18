#include "Octagon.h"
#include "OctagonValidator.h"

Octagon Octagon::create(vector<Point>& list) { 

    OctagonValidator validator;
    
    validator.validate(list);

    return move(Octagon(list));
}
