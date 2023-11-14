#include "Figure.h"

Figure::~Figure() {}


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
