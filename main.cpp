#include "Pentagon.h"
#include "Octagon.h"
#include "Hexagon.h"

using namespace std;

int main() {
 
    
    Octagon o({{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}});
    

    cout<<static_cast<double>(o)<<endl;
    cout<<o.calculatGeomCenter()<<endl;
     
    



}