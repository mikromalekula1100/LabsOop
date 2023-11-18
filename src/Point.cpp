#include "Point.h"

Point::Point() = default;

Point::Point(double x, double y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(Point&& other) : _x(other._x), _y(other._y){
    
    other._x = 0;
    other._y = 0;
}

double Point::operator[](int x) const{
    return (x % 2) ? _y : _x;
}

Point& Point::operator=(const Point& other){

    _x = other._x;

    _y = other._y;
    
    return *this;
}

Point& Point::operator=(Point&& other){

    _x = other._x;
    _y = other._y;

    other._x = other._y = 0;
    
    return *this;
}   

double Point::getX() const{

    return _x;
}

double Point::getY() const{

    return _y;
}

void Point::setX(double x){

    _x = x;
}

void Point::setY(double y){

    _y = y;
}

istream& operator>>(istream& is, Point& obj){
    cout<<"Введи координаты точки через пробел, начиная с X"<<endl;
    is>>obj._x>>obj._y;
    return is;
}

ostream& operator<<(ostream& out, const Point& obj){
    out<<"x = "<<obj._x<<", y = "<<obj._y<<".";
    return out;
}

bool operator!=(const Point& a, const Point& b) { 
    return (a._x != b._x || a._y != b._y);    
}

bool operator==(const Point& a, const Point& b){
    return (a._x == b._x && a._y == b._y);
}