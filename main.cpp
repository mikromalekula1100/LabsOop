
#include "Pentagon.h"
// pentagon 5
// hexagon 6
// octagon 8

// using namespace std;


// struct Сoordinates
// {
// private:
//     double _x, _y;
// public:
//     Сoordinates() : _x(0.0), _y(0.0){}
//     double getX(){
//         return _x;
//     }
//     double getY(){
//         return _y;
//     }
//     void setX(double x){
//         _x = x;
//     }
//     void setY(double y){
//         _y = y;
//     }
// };

// class Figure{
// public:
//     virtual ~Figure(){}
//     virtual pair<double, double> calculatGeomCenter() = 0;
//     virtual operator double() = 0;
// };

// class Pentagon : public Figure{

// private:
//     const int _numberVertices = 5;
//     vector<pair<double, double>> _points;

// public:
//     Pentagon() : _points(_numberVertices, {0, 0}){}

//     Pentagon(const initializer_list<pair<double, double>>& lst) {

//         for(auto& i : lst){
//             _points.push_back(i);
//         }
//     }
    
//     pair<double, double> calculatGeomCenter () override {
//         pair<double, double> geomCenter = {0, 0};
//         for(int i = 0; i < _numberVertices; ++i){
           
//                 geomCenter.second += _points[i].second;
       
//                 geomCenter.first += _points[i].first;
//         }
//         geomCenter.first /= _numberVertices;
//         geomCenter.second /= _numberVertices;
       
//         return geomCenter;
//     }
    
//     operator double() override{
//         pair<double, double> geomCenter = this->calculatGeomCenter();
//         return _numberVertices * 0.5 * abs((_points[2].first - _points[1].first) * (geomCenter.second - _points[1].second) - (geomCenter.first - _points[1].first) * (_points[2].second - _points[1].second));
//     }
// };




int main() {
    Pentagon p{{0.0, 1.0}, {0.95106, 0.30902}, {0.58779, -0.80902}, {-0.58779, -0.80902}, {-0.95106, 0.30902}};
    cout<<static_cast<double>(p)<<endl;
}   