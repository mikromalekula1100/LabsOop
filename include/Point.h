#pragma once

#include <iostream>
#include <concepts>
#include <typeinfo>

using namespace std;

template <typename T>
concept Number = (std::integral<T> || std::floating_point<T>) 
                 && !std::same_as<T, bool>
                 && !std::same_as<T, char>;

template<Number T, Number D>
class Point{

template <Number U, Number U1>
friend bool operator==(const Point<U, U1>& a, const Point<U, U1>& b);

template <Number U, Number U1>
friend istream& operator>>(istream& is, Point<U, U1>& obj);

template <Number U, Number U1>
friend ostream& operator<<(ostream& out, const Point<U, U1>& obj);

template <Number U, Number U1>
friend bool operator!=(const Point<U, U1>& a, const Point<U, U1>& b);

protected:
    T _x;
    D _y;

public:
    Point();

    Point(T x, D y);

    Point(const Point& other);

    Point(Point&& other);

    auto operator[](int x) const;

    Point& operator=(const Point& other);

    Point& operator=(Point&& other);

    T getX() const;

    D getY() const;

    void setX(T);

    void setY(D);
};

Point()->Point<double, double>;

// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------


template<Number T, Number D>
Point<T, D>::Point() = default;

template<Number T, Number D>
Point<T, D>::Point(T x, D y) : _x(x), _y(y) {}

template<Number T, Number D>
Point<T, D>::Point(const Point<T, D>& other) : _x(other._x), _y(other._y) {}

template<Number T, Number D>
Point<T, D>::Point(Point<T, D>&& other) : _x(other._x), _y(other._y){
    other._x = 0;
    other._y = 0;
}

template<Number T, Number D>
auto Point<T, D>::operator[](int x) const{
    return (x % 2) ? _y : _x;
}

template<Number T, Number D>
Point<T, D>& Point<T, D>::operator=(const Point<T, D>& other){

    _x = other._x;

    _y = other._y;
    
    return *this;
}

template<Number T, Number D>
Point<T, D>& Point<T, D>::operator=(Point<T, D>&& other){

    _x = other._x;
    _y = other._y;

    other._x = other._y = 0;
    
    return *this;
}   

template<Number T, Number D>
T Point<T, D>::getX() const{

    return _x;
}

template<Number T, Number D>
D Point<T, D>::getY() const{

    return _y;
}

template<Number T, Number D>
void Point<T, D>::setX(T x){

    _x = x;
}

template<Number T, Number D>
void Point<T, D>::setY(D y){

    _y = y;
}

template<Number T, Number D>
istream& operator>>(istream& is, Point<T, D>& obj){
    cout<<"Введи координаты точки через пробел, начиная с X"<<endl;
    is>>obj._x>>obj._y;
    return is;
}

template<Number T, Number D>
ostream& operator<<(ostream& out, const Point<T, D>& obj){
    out<<"x = "<<obj._x<<", y = "<<obj._y<<".";
    return out;
}

template<Number T, Number D>
bool operator!=(const Point<T, D>& a, const Point<T, D>& b) { 
    return (a._x != b._x || a._y != b._y);    
}

template<Number T, Number D>
bool operator==(const Point<T, D>& a, const Point<T, D>& b){
    return (a._x == b._x && a._y == b._y);
}