#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figure{

public:
    virtual ~Figure();

    virtual pair<double, double> calculatGeomCenter() = 0;

    virtual operator double() = 0;

    virtual ostream& print(ostream&) const = 0;

    virtual istream& reading(istream&)  = 0;
    
};

ostream& operator<<(ostream& out, const Figure& obj);

istream& operator>>(istream& is, Figure& obj);