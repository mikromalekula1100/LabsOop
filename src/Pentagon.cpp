#include "Pentagon.h"
#include "PentagonValidator.h"

Pentagon Pentagon::create(vector<Point>& list) { 
    PentagonValidator validator;
    validator.validate(list);

    return move(Pentagon(list));
}
