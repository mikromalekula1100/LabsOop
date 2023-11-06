#include "Octagon.h"

int Octagon::getNumberVertices()const { return _numberVertices; }

const vector<pair<double, double>>& Octagon::getPoints() const { return _points; }
Octagon::Octagon() : _points(_numberVertices, {0, 0}){}

Octagon::Octagon(const initializer_list<pair<double, double>>& lst) {
    for(auto& i : lst){
        _points.push_back(i);
    }
}

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
   for(int i = 0; i < this->getNumberVertices(); ++i){
        out<<"X"<<i+1<<" = "<<this->getPoints()[i].first<<"; Y"<<i+1<<" = "<<this->getPoints()[i].second<<";"<<endl;
   }
   return out;
}
