#include "Pentagon.h"

Pentagon::Pentagon() : _points(_numberVertices, {0, 0}){}

Pentagon::Pentagon(const initializer_list<pair<double, double>>& lst) {

    for(auto& i : lst){
        _points.push_back(i);
    }
}

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
