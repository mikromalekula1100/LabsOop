#pragma once

#include "/home/maks/Desktop/LabsOop/include/FigureValidator.h"

template <Number T, Number D>
class PentagonValidator : public FigureValidator<T, D>{

public:

    static const int numberVertices = 5;

    bool validate(vector<Point<T, D>>&) override;
};



// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------

template <Number T, Number D>
bool PentagonValidator<T, D>::validate(vector<Point<T, D>>& list) {

    if(list.size() != PentagonValidator<T, D>::numberVertices){

        throw std::invalid_argument("Введено не то кол-во аргументов для данного типа");
    }

    double x,y;

    for(Point<T, D>& i : list){

        x = i.getX();
        y = i.getY();

        x = static_cast<int>(x * this->EPSILON) / this->EPSILON;
        y = static_cast<int>(y * this->EPSILON) / this->EPSILON;

        i.setX(x);
        i.setY(y);
    }


    double x1 = list[0].getX();
    double y1 = list[0].getY();

    double x2 = list[1].getX();
    double y2 = list[1].getY();

    double firstLength = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    double secondLength;

    for(int i = 1; i < list.size(); ++i){

        x1 = list[i].getX();
        y1 = list[i].getY();

        x2 = list[(i+1) % list.size()].getX();
        y2 = list[(i+1) % list.size()].getY();

        secondLength = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        
        if(abs(secondLength -  firstLength) > this->INACCURACY){
            cout<<secondLength - firstLength<<endl;
            throw std::invalid_argument("Фигура не равносторонняя!");
        }

        firstLength = secondLength;
    }

    return true;
}