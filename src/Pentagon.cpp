#include "Pentagon.h"



Pentagon::Pentagon(const vector<Point>& points) {

    for(Point i : points){
        
        _points.push_back(i);
    }
}

Pentagon::Pentagon(const Pentagon& other) {
    
    _points = other._points;
}
