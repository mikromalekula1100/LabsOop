#include "Hexagon.h"


Hexagon::Hexagon() : _points(_numberVertices, {0, 0}){}

Hexagon::Hexagon(const Hexagon& other){

    this->_points = other._points;
}

Hexagon::Hexagon(Hexagon&& other) : _points(move(other._points)) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {

   this->_points = other._points;

   return *this;
}

Hexagon::Hexagon(const initializer_list<pair<double, double>>& lst) {

    for(auto& i : lst){
        
        _points.push_back(i);
    }
}

Hexagon& Hexagon::operator=(Hexagon&& other) {
   
   this->_points = move(other._points);

   return *this;
}

bool Hexagon::operator==(const Hexagon& other) {

   for (int i = 0; i < _numberVertices; ++i) {

      if (_points[i].first != other.getPoints()[i].first ||
          _points[i].second != other.getPoints()[i].second) {
         return false;
      }
   }
   return true;
}

const vector<pair<double, double>>& Hexagon::getPoints() const { return _points;}

pair<double, double> Hexagon:: calculatGeomCenter (){

    pair<double, double> geomCenter = {0, 0};

    for(int i = 0; i < _numberVertices; ++i){
        
        geomCenter.second += _points[i].second;
    
        geomCenter.first += _points[i].first;
    }

    geomCenter.first /= _numberVertices;

    geomCenter.second /= _numberVertices;
    
    return geomCenter;
}

Hexagon::operator double(){

    pair<double, double> geomCenter = this->calculatGeomCenter();

    return _numberVertices * 0.5 * abs((_points[2].first - _points[1].first) * (geomCenter.second - _points[1].second) - (geomCenter.first - _points[1].first) * (_points[2].second - _points[1].second));
}

ostream& Hexagon::print(ostream& out) const {

    if(this->_points.size() == 0){

        return out;
   }

   for(int i = 0; i < _numberVertices; ++i){

        out<<"X"<<i+1<<" = "<<_points[i].first<<"; Y"<<i+1<<" = "<<_points[i].second<<";"<<endl;
   }
   return out;
}

istream& Hexagon::reading(istream& is)  {

    cout<<"Введите " << _numberVertices<<" пар координат точек пятиугольник в порядке их обхода через пробел."<<endl;
    for(int i = 0; i < _numberVertices; ++i){

        is>>_points[i].first;
        
        is>>_points[i].second;
    }   
    return is;
}