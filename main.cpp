#include "Hexagon.h"
#include "Pentagon.h"
#include "Octagon.h"
#include "Array.h"

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
    // cout<<aa<<endl;

    Hexagon<double, double> bb = Hexagon<double, double>::create(b);
    // cout<<bb<<endl;

    Octagon<double, double> cc = Octagon<double, double>::create(c);
    // cout<<cc<<endl;


    shared_ptr<Figure<double, double>> aa_ptr = make_shared<Figure<double, double>>(aa);
    shared_ptr<Figure<double, double>> bb_ptr = make_shared<Figure<double, double>>(bb);
    shared_ptr<Figure<double, double>> cc_ptr = make_shared<Figure<double, double>>(cc);
    Array<shared_ptr<Figure<double, double>>> list = {aa_ptr, bb_ptr, cc_ptr};

    // list.erase(1); 

    for(int i = 0; i < list.getSize(); ++i){
      cout<<*list[i]<<endl;
      cout<<static_cast<double>(*list[i])<<endl;
      cout<<(*list[i]).calculatGeomCenter()<<endl;
    }

}



