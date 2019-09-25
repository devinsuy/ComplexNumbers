#include "Point.cpp"

class Polar;

class Rectangular: public Point{
public:
    Rectangular(double real = 0, double imaginary = 0): Point(real, imaginary){}
    Rectangular(Polar* p);
    Rectangular operator+( const Rectangular &rec ) const{
        return Rectangular(getX() + rec.getX(), getY() + rec.getY());
    }
    Rectangular operator-( const Rectangular &rec ) const{
        return Rectangular(getX() - rec.getX(), getY() - rec.getY());
    }
    friend ostream &operator << (ostream &os, const Rectangular &r){
        string op;
        op = r.getY() < 0 ? "-" : "+";
        os << r.getX() << " " << op << " j" << abs(r.getY());
        return os;
    }
    int getReal(){return getY();}
};
