#pragma once

#include <iostream>

using namespace std;

class Point{

friend bool operator==(const Point& a, const Point& b);
friend istream& operator>>(istream& is, Point& obj);
friend ostream& operator<<(ostream& out, const Point& obj);

protected:
    double _x;
    double _y;

public:
    Point();

    Point(double x, double y);

    Point(const Point& other);

    Point(Point&& other);

    Point(initializer_list<double>& list);

    double operator[](int x) const;

    Point& operator=(const Point& other);

    Point& operator=(Point&& other);

    double getX();

    double getY();

    void setX(double x);

    void setY(double y);
};



