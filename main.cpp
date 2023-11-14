#include "Pentagon.h"
#include "Octagon.h"
#include "Hexagon.h"

#include "PentagonValidator.h"
#include "OctagonValidator.h"
#include "HexagonValidator.h"

using namespace std;

int main() {
    vector<Point> a = {
          {1, 0}, {0.309017, 0.951057},
          {-0.809017, 0.587785}, {-0.809017, -0.587785},
           {0.309017, -0.951057}};

    vector<Point> b = {{1, 0}, {0.5, 0.866025},
     {-0.5, 0.866025}, {-1, 0.0000000358979}, {-0.5, -0.866025}, { 0.5, -0.866025}};

    vector<Point> c = {{1, 0}, { 0.707107, 0.707107}, { 0.0000000017949, 1 },
     {-0.707107, 0.707107}, {-1, 0.00000000358979}, { -0.707107, -0.707107 }, {-0.00000000538469, -1 },
      {0.707107, -0.707107}};

    Pentagon aa = Pentagon::create(a);
    cout<<aa<<endl;

    Hexagon bb = Hexagon::create(b);
    cout<<bb<<endl;

    Octagon cc = Octagon::create(c);
    cout<<cc<<endl;
}