#include "Hexagon.h"
#include "HexagonValidator.h"

Hexagon Hexagon::create(vector<Point>& list) { 
    HexagonValidator validator;
    validator.validate(list);

    return move(Hexagon(list));
}
