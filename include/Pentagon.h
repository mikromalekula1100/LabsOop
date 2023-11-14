#pragma once

#include "Figure.h"

class Pentagon : public Figure{

public:
    
    Pentagon(const vector<Point>& points);

    Pentagon(const Pentagon& other);

    // Pentagon(Pentagon&&);

    // Pentagon& operator=(const Pentagon&);

    // Pentagon& operator=(Pentagon&&);

    // bool operator==(const Pentagon&);

    // const vector<pair<double, double>>& getPoints() const;

    // pair<double, double> calculatGeomCenter () override;

    // explicit operator double() override;
  
    
};

