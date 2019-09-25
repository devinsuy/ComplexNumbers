#include <iostream>
using namespace std;

class Point{
private:
    double x, y;
public:
    Point(double x = 0, double y = 0){this->x = x; this->y = y;}
    double getX() const {return x;}
    double getY() const {return y;}
    void setX(const double x) {this->x = x;}
    void setY(const double y) {this->y = y;}
};
