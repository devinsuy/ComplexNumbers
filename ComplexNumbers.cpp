#include "Polar.cpp"


Rectangular::Rectangular(Polar* p):
Point(cos(p->getY() * M_PI / 180) * p->getX(),
      sin(p->getY() * M_PI / 180) * p->getX()){}

int main(){
    const double XL1 = 2 * M_PI * 1500 * 0.00053052;
    const double XC2 = -1 / ( 2 * M_PI * 1500 * 0.00000212 );
    const double XL3 = 2 * M_PI * 1500 * 0.01592;
    const int R1 = 20;
    const int R2 = 5;

    Rectangular Z1(R1, XL1);
    Rectangular Z2(R2, XC2);
    Rectangular Z3(0, XL3);
    Rectangular Z[3];
    Z[0] = Z1;
    Z[1] = Z2;
    Z[2] = Z3;
    Polar one(1, 0);

    Rectangular zSum(0,0);
    for (int i = 0; i < 3; i++){
        Polar temp = one / Polar(Z[i]);
        zSum = zSum + Rectangular(&temp);
    }

    Polar ZT = one / Polar(zSum);
    Polar VT(40, 0);
    Polar IT = VT / ZT;

    cout << "Z1 in rectangular form = " << Z1 << endl;
    cout << "Z1 in polar form = " << Polar(Z1) << endl;
    cout << "Z2 in rectangular form = " << Z2 << endl;
    cout << "Z2 in polar form = " << Polar(Z2) << endl;
    cout << "Z3 in rectangular form = " << Z3 << endl;
    cout << "Z3 in polar form = " << Polar(Z3) << endl;
    cout << "ZT in rectangular form = " << Rectangular(&ZT) << endl;
    cout << "ZT in polar form = " << ZT << endl;
    cout << "IT in rectangular form = " << Rectangular(&IT) << endl;
    cout << "IT in polar form = " << IT << endl;

}
