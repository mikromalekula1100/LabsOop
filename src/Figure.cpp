#include "Figure.h"


Figure::~Figure() {}

ostream& operator<<(ostream& out, const Figure& obj) {

   return obj.print(out);
}

istream& operator>>(istream& is, Figure& obj) {

   return obj.reading(is);
}
