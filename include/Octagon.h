#pragma once

#include "Figure.h"

class Octagon : public Figure{

public:
    vector<pair<double, double>> _points;

public:
    static const int _numberVertices = 8;

    Octagon();

    Octagon(const initializer_list<pair<double, double>>& lst);

    Octagon(const Octagon&);

    Octagon(Octagon&&);

    Octagon& operator=(const Octagon&);

    Octagon& operator=(Octagon&&);

    bool operator==(const Octagon&);

    const vector<pair<double, double>>& getPoints() const;

    pair<double, double> calculatGeomCenter () override;

    explicit operator double() override;

    ostream& print(ostream&) const override;

    istream& reading(istream&) override;
};
