#pragma once

#include "Point.h"
#include <vector>
#include <math.h>

using namespace std;

class Figure{

friend ostream& operator<<(ostream& out, const Figure& obj);
friend istream& operator>>(istream& is, Figure& obj);

protected:
    vector<Point> _points;

    const long double EPSILON = 1000000.0; 
    
public:
    virtual ~Figure();

    Figure();

    Figure(const vector<Point>& points);

    Figure(const Figure& other);

    Figure(Figure&&);

    virtual Figure& operator=(const Figure&);

    virtual Figure& operator=(Figure&&);

    virtual bool operator==(const Figure&);

    virtual Point calculatGeomCenter();

    virtual explicit operator double();

};

