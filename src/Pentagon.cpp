#include "Pentagon.h"

Pentagon::Pentagon() : _points(_numberVertices, {0, 0}) {}

Pentagon::Pentagon(const initializer_list<pair<double, double>>& lst) {

    for(auto& i : lst){

        _points.push_back(i);
    }
}

Pentagon::Pentagon(const Pentagon& other) {

    this->_points = other._points;
}

Pentagon::Pentagon(Pentagon&& other) : _points(move(other._points)) {}

bool Pentagon::operator==(const Pentagon& other){

    for(int i = 0; i < _numberVertices; ++i){

        if(_points[i].first != other.getPoints()[i].first || _points[i].second != other.getPoints()[i].second){

            return 0;
        }
    }

    return 1;
}

const vector<pair<double, double>>& Pentagon::getPoints() const {return _points;}

pair<double, double> Pentagon:: calculatGeomCenter (){

    pair<double, double> geomCenter = {0, 0};
    
    for(int i = 0; i < _numberVertices; ++i){
        
            geomCenter.second += _points[i].second;
    
            geomCenter.first += _points[i].first;
    }

    geomCenter.first /= _numberVertices;

    geomCenter.second /= _numberVertices;
    
    return geomCenter;
}

Pentagon::operator double(){

    pair<double, double> geomCenter = this->calculatGeomCenter();

    return _numberVertices * 0.5 * abs((_points[2].first - _points[1].first) * (geomCenter.second - _points[1].second) - (geomCenter.first - _points[1].first) * (_points[2].second - _points[1].second));
}

Pentagon& Pentagon::operator=(const Pentagon& other) {

    this->_points = other._points;

    return *this;
}

ostream& Pentagon::print(ostream& out) const {

   if(this->_points.size() == 0){

        return out;
   }
        
   for(int i = 0; i < _numberVertices; ++i){

        out<<"X"<<i+1<<" = "<<_points[i].first<<"; Y"<<i+1<<" = "<<_points[i].second<<";"<<endl;
   }

   return out;
}

Pentagon& Pentagon::operator=(Pentagon&& other) {
    
   this->_points = move(other._points);
  
   return *this;
}

istream& Pentagon::reading(istream& is) {

    cout<<"Введите " << _numberVertices<<" пар координат точек пятиугольник в порядке их обхода через пробел."<<endl;

    for(int i = 0; i < _numberVertices; ++i){

        is>>_points[i].first;
        
        is>>_points[i].second;
    }
    
    return is;
}








