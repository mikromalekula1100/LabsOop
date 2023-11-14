#include "Pentagon.h"


using namespace std;

int main() {
 
    Pentagon a({{1, 2}, {2, 3}, {4,5}, {3,5}, {54,2}});
    Pentagon a1(move(a));
    // // Pentagon b(move(a));
    // cout<<(a1 == a)<<endl;
    cout<<a.calculatGeomCenter()<<endl;


}