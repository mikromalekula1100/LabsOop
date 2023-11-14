#include "Figure.h"

Figure::~Figure() {}

Figure::Figure() = default;

Figure::Figure(Figure&& other) { 
    cout<<typeid(other).name()<<endl;
    _points = move(other._points);
}

Figure& Figure::operator=(const Figure& other) {
    _points = other._points;
    return *this;
}

Figure& Figure::operator=(Figure&& other) {
    _points = move(other._points);
    return *this;
}

bool Figure::operator==(const Figure& other) {
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

Figure::Figure(const vector<Point>& points) {
    double x,y;
    for(const Point& i : points){

        x = i.getX();
        y = i.getY();

        x = static_cast<int>(x * EPSILON) / EPSILON;
        y = static_cast<int>(y * EPSILON) / EPSILON;
        
        _points.push_back({x, y});
    }

}

Figure::Figure(const Figure& other) {

    _points = other._points;
}

ostream& operator<<(ostream& out, const Figure& obj){
    out<<"Фигура "<<typeid(obj).name()<<" : "<<endl;
    for(const Point& i : obj._points){
        out<<i<<endl;
    }
    return out;
}
istream& operator>>(istream& is, Figure& obj){
    cout<<"Для того, чтобы ввести фигуру("<<typeid(obj).name()<<"):"<<endl;
    for(int i = 0; i < obj._points.size(); ++i){
        is>>obj._points[i];
    }

    return is;
};

Point Figure::calculatGeomCenter() {
    
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

    Point centerPoint(x, y);

    return move(centerPoint);
}

Figure::operator double() {

    if(_points.size() == 0){

        throw("Фигура не задана.");
    }

    double a, b, c, squareFigure, semiperimeterFigure;
    
    Point center = this->calculatGeomCenter();

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
