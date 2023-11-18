#pragma once

#include "Point.h"
#include <vector>
#include <math.h>

using namespace std;

template <Number T, Number D>
class Figure{

template <Number U, Number U1>
friend ostream& operator<<(ostream& out, const Figure<U, U1>& obj);

template <Number U, Number U1>
friend istream& operator>>(istream& is, Figure<U, U1>& obj);

protected:
    vector<Point<T, D>> _points;

    const long double EPSILON = 1000000.0; 
    
public:
    virtual ~Figure();

    Figure();

    Figure(const vector<Point<T, D>>& points);

    Figure(const Figure<T, D>& other);

    Figure(Figure<T, D>&&);

    virtual Figure<T, D>& operator=(const Figure<T, D>&);

    virtual Figure<T, D>& operator=(Figure<T, D>&&);

    virtual bool operator==(const Figure<T, D>&);

    virtual Point<T, D> calculatGeomCenter();

    virtual explicit operator double();

};



// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------

template <Number T, Number D>
Figure<T, D>::~Figure() {}

template <Number T, Number D>
Figure<T, D>::Figure() = default;

template <Number T, Number D>
Figure<T, D>::Figure(Figure<T, D>&& other) { 
    
    _points = move(other._points);
}

template <Number T, Number D>
Figure<T, D>& Figure<T, D>::operator=(const Figure<T, D>& other) {
    _points = other._points;
    return *this;
}

template <Number T, Number D>
Figure<T, D>& Figure<T, D>::operator=(Figure<T, D>&& other) {
    _points = move(other._points);
    return *this;
}

template <Number T, Number D>
bool Figure<T, D>::operator==(const Figure<T, D>& other) {
    if(this->_points.size() == 0 || other._points.size() == 0){
        throw("Фигура не существует.");
    }
    
    for(int i = 0; i < _points.size(); ++i){
        if(_points[i] != other._points[i]){
            return false;
        }
    }
    return true;
}

template <Number T, Number D>
Figure<T, D>::Figure(const vector<Point<T, D>>& points) {
   
    for(Point<T, D> i : points){
        
        _points.push_back(i);
    }

}

template <Number T, Number D>
Figure<T, D>::Figure(const Figure<T, D>& other) {

    _points = other._points;
}

template <Number T, Number D>

ostream& operator<<(ostream& out, const Figure<T, D>& obj){
    out<<"Фигура "<<typeid(obj).name()<<" : "<<endl;
    for(const Point<T, D>& i : obj._points){
        out<<i<<endl;
    }
    return out;
}

template <Number T, Number D>
istream& operator>>(istream& is, Figure<T, D>& obj){
    cout<<"Для того, чтобы ввести фигуру("<<typeid(obj).name()<<"):"<<endl;
    for(int i = 0; i < obj._points.size(); ++i){
        is>>obj._points[i];
    }

    return is;
};

template <Number T, Number D>
Point<T, D> Figure<T, D>::calculatGeomCenter() {
    
    if(_points.size() == 0){
        throw("Фигура не существует.");
    } 

    double x = 0, y = 0;

    int sizeListPoints = _points.size();

    for(int i = 0; i < sizeListPoints; ++i){

        x += _points[i].getX();

        y += _points[i].getY();
    }

    x /= sizeListPoints;

    y /= sizeListPoints;

    x = static_cast<int>(x * EPSILON) / EPSILON;

    y = static_cast<int>(y * EPSILON) / EPSILON;

    Point<T, D> centerPoint(x, y);

    return move(centerPoint);
}

template <Number T, Number D>
Figure<T, D>::operator double() {

    if(_points.size() == 0){

        throw("Фигура не задана.");
    }

    double a, b, c, squareFigure, semiperimeterFigure;
    
    Point<T, D> center = this->calculatGeomCenter();

    a = sqrt(pow((_points[0].getX() - _points[1].getX()), 2) + pow((_points[0].getY() - _points[1].getY()), 2));

    a = static_cast<int>(a * EPSILON) / EPSILON;

    b = sqrt(pow((_points[0].getX() - center.getX()), 2) + pow((_points[0].getY() - center.getY()), 2));
    
    b = static_cast<int>(b * EPSILON) / EPSILON;

    c = b;

    semiperimeterFigure = (a + b + c) / 2;

    semiperimeterFigure = static_cast<int>(semiperimeterFigure * EPSILON) / EPSILON;

    squareFigure = sqrt(semiperimeterFigure * (semiperimeterFigure - a) * (semiperimeterFigure - b) * (semiperimeterFigure - c));

    squareFigure = static_cast<int>(squareFigure * EPSILON) / EPSILON;

    return squareFigure;
}
