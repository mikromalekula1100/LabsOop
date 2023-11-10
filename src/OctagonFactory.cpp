#include "OctagonFactory.h"

Figure* OctagonFactory::createFigure(
    
    const initializer_list<pair<double, double>>& base) {

    if(base.size() != Octagon::_numberVertices){

        throw std::invalid_argument("Введено не то кол-во аргументов для данного типа");
    }

    vector<pair<double, double>> points;

    for(pair<double, double> i : base){

        points.push_back(i);
    }
    
    double x1 = points[0].first;
    double y1 = points[0].second;

    double x2 = points[1].first;
    double y2 = points[1].second;

    double firstLength = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    double secondLength;

    for(int i = 1; i < points.size(); ++i){

        x1 = points[i].first;
        y1 = points[i].second;

        x2 = points[(i+1)%points.size()].first;
        y2 = points[(i+1)%points.size()].second;

        secondLength = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        
        if((secondLength -  firstLength) > EPSILON){

            throw std::invalid_argument("Фигура не равносторонняя!");
        }

        firstLength = secondLength;
    }

    return new Octagon(base);
   
}