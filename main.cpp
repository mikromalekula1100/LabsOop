#include "Pentagon.h"
#include "Octagon.h"
#include "Hexagon.h"

using namespace std;

int main() {
 
    Pentagon p({{1, 2}, {2, 3}, {4,5}, {3,5}, {54,2}});
    Octagon o({{1, 2}, {2, 3}, {4,5}, {3,5}, {54,2}, {2, 3}, {4,5}, {3,5}, {54,2}});
    Hexagon h({{1, 2}, {2, 3}, {4,5}, {3,5}, {54,2}, {2, 3}, {4,5}});

    cout<<p.calculatGeomCenter()<<endl;
    cout<<o.calculatGeomCenter()<<endl;
    cout<<h.calculatGeomCenter()<<endl;

}