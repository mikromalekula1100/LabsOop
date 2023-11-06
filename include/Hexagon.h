#pragma once

#include "Figure.h"

class Hexagon : public Figure{

private:
    const int _numberVertices = 6;
    vector<pair<double, double>> _points;

public:
    int getNumberVertices() const;
    const vector<pair<double, double>>& getPoints() const;
    Hexagon();
    Hexagon(const initializer_list<pair<double, double>>& lst);
    pair<double, double> calculatGeomCenter () override;
    operator double() override;
    ostream& print(ostream&) const override;
};

