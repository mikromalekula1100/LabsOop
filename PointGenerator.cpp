#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265
using namespace std;
struct Point {
    double x, y;
};

std::vector<Point> generatePolygon(int n, double r) {
    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i].x = r * cos(2 * PI * i / n);
        points[i].y = r * sin(2 * PI * i / n);
    }
    return points;
}

void printPolygon(const std::vector<Point>& points) {
    for (const auto& point : points) {
        std::cout   << point.x << " " << point.y <<" ";
    }
}

int main() {
    int n;
    double r = 1.0;
    
    // Пятиугольник
    n = 5;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;

    // Шестиугольник
    n = 6;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    // Восьмиугольник
    n = 8;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;
    printPolygon(generatePolygon(n, r));
    cout<<endl;

    return 0;
}