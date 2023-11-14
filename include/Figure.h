#pragma once

#include "Point.h"
#include <vector>

using namespace std;

class Figure{

friend ostream& operator<<(ostream& out, const Figure& obj);
friend istream& operator>>(istream& is, Figure& obj);

protected:
    vector<Point> _points;

public:
    virtual ~Figure();

    // virtual Point calculatGeomCenter();

    // virtual operator double() = 0;

};

