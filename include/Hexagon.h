#pragma once

#include "Figure.h"

class Hexagon : public Figure{

private:
    vector<pair<double, double>> _points;

public:
    static const int _numberVertices = 6;
    
    Hexagon();
    
    Hexagon(const initializer_list<pair<double, double>>& lst);

    Hexagon(const Hexagon&);

    Hexagon(Hexagon&&);

    Hexagon& operator=(const Hexagon&);

    Hexagon& operator=( Hexagon&&);

    bool operator==(const Hexagon&);

    const vector<pair<double, double>>& getPoints() const;

    pair<double, double> calculatGeomCenter () override;

    explicit operator double() override;

    ostream& print(ostream&) const override;
    
    istream& reading(istream&) override;
};

