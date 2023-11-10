#pragma once

#include "Figure.h"

class Pentagon : public Figure{

private:
    vector<pair<double, double>> _points;

public:
    static const int _numberVertices = 5;

    Pentagon();

    Pentagon(const initializer_list<pair<double, double>>& lst);

    Pentagon(const Pentagon& other);

    Pentagon(Pentagon&&);

    Pentagon& operator=(const Pentagon&);

    Pentagon& operator=(Pentagon&&);

    bool operator==(const Pentagon&);

    const vector<pair<double, double>>& getPoints() const;

    pair<double, double> calculatGeomCenter () override;

    explicit operator double() override;

    ostream& print(ostream&) const override;

    istream& reading(istream&) override;
    
    
};

