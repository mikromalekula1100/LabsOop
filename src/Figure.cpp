#include "Figure.h"


Figure::~Figure() {}

ostream& operator<<(ostream& out, const Figure& obj) {
   return obj.print(out);
}
