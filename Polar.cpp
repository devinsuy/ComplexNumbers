#define _USE_MATH_DEFINES
#include <cmath>
#include "Rectangular.cpp"

class Polar: public Point{
public:
    Polar(double magnitude = 0, double angle = 0): Point(magnitude, angle){}
    Polar(Rectangular r):
    Point(sqrt(pow(r.getX(), 2) + pow(r.getY(), 2)),
          ((atan(r.getY() / r.getX())) * 180) / M_PI){}

    Polar operator*( const Polar &p ) const{
        return Polar(getX() * p.getX(), getY() + p.getY());
    }
    Polar operator/( const Polar &p ) const{
        return Polar(getX() / p.getX(), getY() - p.getY());
    }
    friend ostream& operator << (ostream&os , const Polar &p){
        os << p.getX() << " @" << p.getY() << " degrees";
        return os;
    }
};
