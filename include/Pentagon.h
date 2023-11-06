#pragma once

#include "Figure.h"

class Pentagon : public Figure{

private:
    const int _numberVertices = 5;
    vector<pair<double, double>> _points;

public:
    Pentagon();
    Pentagon(const initializer_list<pair<double, double>>& lst);
    pair<double, double> calculatGeomCenter () override;
    operator double() override;
};