#include "Octagon.h"
#include "Pentagon.h"
#include "Hexagon.h"

#include "PentagonFactory.h"
#include "OctagonFactory.h"
#include "HexagonFactory.h"

#include <iostream>
#include <vector>

using namespace std;

vector<Figure*> listFigures;

void printSquare(){
    for(auto i : listFigures)
        cout<<"Название производного класса: "<<typeid(*i).name()<<",  площадь фигуры:" << static_cast<double>(*i)<<endl;
}

void printGeomCenter(){
    for(auto i : listFigures)
        cout<<"Название производного класса: "<<typeid(*i).name()<<",  координаты центра фигуры: X = " << i->calculatGeomCenter().first<<", Y = "<< i->calculatGeomCenter().second<<endl;
}
int main() {

    PentagonFactory pF;

    HexagonFactory xF;

    OctagonFactory oF;

    listFigures.push_back(pF.createFigure({{1, 0},{0.309017, 0.951057},
    {-0.809017, 0.587785}, {-0.809017, -0.587785}, {0.309017, -0.951057}}));

    listFigures.push_back(xF.createFigure({{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}}));
     
    listFigures.push_back(oF.createFigure({{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}}));

    printGeomCenter();
    printSquare();
    
    for(Figure* i : listFigures){

        delete i;
    }

}
