#include "Octagon.h"

Octagon::Octagon() : _points(_numberVertices, {0, 0}){}

Octagon::Octagon(const initializer_list<pair<double, double>>& lst) {

    for(auto& i : lst){

        _points.push_back(i);
    }
}

Octagon::Octagon(const Octagon& other) {

    this->_points = other._points;
}

Octagon::Octagon(Octagon&& other) : _points(move(other._points)){}

Octagon& Octagon::operator=(const Octagon& other) {

   this->_points = other._points;

   return *this;
}

Octagon& Octagon::operator=(Octagon&& other) {

   this->_points = move(other._points);
    
   return *this;
}

bool Octagon::operator==(const Octagon& other){

    for(int i = 0; i < _numberVertices; ++i){

        if(_points[i].first != other.getPoints()[i].first || _points[i].second != other.getPoints()[i].second){

            return 0;
        }
    }

    return 1;
}

const vector<pair<double, double>>& Octagon::getPoints() const {return _points;}

pair<double, double> Octagon:: calculatGeomCenter (){

    pair<double, double> geomCenter = {0, 0};
    for(int i = 0; i < _numberVertices; ++i){
        
            geomCenter.second += _points[i].second;
    
            geomCenter.first += _points[i].first;
    }

    geomCenter.first /= _numberVertices;

    geomCenter.second /= _numberVertices;
    
    return geomCenter;
}

Octagon::operator double(){

    pair<double, double> geomCenter = this->calculatGeomCenter();
    
    return _numberVertices * 0.5 * abs((_points[2].first - _points[1].first) * (geomCenter.second - _points[1].second) - (geomCenter.first - _points[1].first) * (_points[2].second - _points[1].second));
}

ostream& Octagon::print(ostream& out) const {

    if(this->_points.size() == 0){

        return out;
   }

   for(int i = 0; i < _numberVertices; ++i){

        out<<"X"<<i+1<<" = "<<_points[i].first<<"; Y"<<i+1<<" = "<<_points[i].second<<";"<<endl;
   }

   return out;
}

istream& Octagon::reading(istream& is) {

    cout<<"Введите " << _numberVertices<<" пар координат точек пятиугольник в порядке их обхода через пробел."<<endl;

    for(int i = 0; i < _numberVertices; ++i){

        is>>_points[i].first;

        is>>_points[i].second;
    }  
    
    return is;
}