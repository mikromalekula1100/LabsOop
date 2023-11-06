#include "Octagon.h"
#include "Pentagon.h"
#include "Hexagon.h"

int main() {
    // Pentagon p{{0.0, 1.0}, {0.95106, 0.30902}, {0.58779, -0.80902}, {-0.58779, -0.80902}, {-0.95106, 0.30902}};
    // cout<<p<<endl;
    vector<Figure*> f;
    f.push_back(new Pentagon({{0.0, 1.0}, {0.95106, 0.30902}, {0.58779, -0.80902}, {-0.58779, -0.80902}, {-0.95106, 0.30902}}));
    f.push_back(new Octagon);
    f.push_back(new Hexagon);
    for(int i = 0; i < f.size(); ++i){
        cout<<*(f[i])<<endl;
    }
}   