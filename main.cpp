
#include "/home/maks/Desktop/LabsOop/include/Hexagon.h"
#include "/home/maks/Desktop/LabsOop/include/Pentagon.h"
#include "/home/maks/Desktop/LabsOop/include/Octagon.h"

using namespace std;

int main() {
    vector<Point<double, double>> a = {  
          {1, 0}, {0.309017, 0.951057},
          {-0.809017, 0.587785}, {-0.809017, -0.587785},
           {0.309017, -0.951057}};

    vector<Point<double, double>> b = {{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}};

    vector<Point<double, double>> c = {{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}};

    Pentagon<double, double> aa = Pentagon<double, double>::create(a);
    cout<<aa<<endl;

    Hexagon<double, double> bb = Hexagon<double, double>::create(b);
    cout<<bb<<endl;

    Octagon<double, double> cc = Octagon<double, double>::create(c);
    cout<<cc<<endl;

}



