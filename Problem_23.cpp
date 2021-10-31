//
// Problem_23.cpp
//
// Created by Aurimas Nausedas on 10/20/19.
// Updated by Aurimas Nausedas on 10/31/21.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace myform
{
    int w = 10;
}

// 15 pratimas perdarytas | Exercise 15 re-done
// apie stream classes etc: http://www.cplusplus.com/reference/ios/ | about stream classes etc: http://www.cplusplus.com/reference/ios/


// Deklaracija |. Declaration -------------------------
class Vector
{
public:
    // default konstruktorius (inline) | default constructor
    Vector(){};
    Vector(double x, double y, double z);
    friend Vector operator+(const Vector& A, const Vector& B);
    friend double operator*(const Vector& A, const Vector& B);
    friend Vector operator^(const Vector& A, const Vector& B);

    void show(string s);
private:
    double xv,yv,zv;
};

// Funkcijos | Functions ----------------------------
// konstruktorius | constructor
Vector::Vector(double x, double y, double z)
{
    xv = x;
    yv = y;
    zv = z;
};



// vektoriu suma | sum of vedctors
Vector operator+(const Vector& A, const Vector& B)
{
    return Vector(A.xv + B.xv,A.yv + B.yv,A.zv + B.zv);
};



// vektoriu skaliarine sandauga | vector scalar product
double operator*(const Vector& A, const Vector& B)
{
    double mult = A.xv * B.xv + A.yv * B.yv + A.zv * B.zv;
    return mult;
};


// vektoriu sandauga | vector multiplication
Vector operator^(const Vector& A, const Vector& B)
{

    double cx = A.yv * B.zv - B.yv * A.zv;
    double cy = -(A.xv * B.zv - B.xv * A.zv);
    double cz = A.xv * B.yv - B.xv * A.yv;

    return Vector(cx,cy,cz);
};



// show funkcija | show function
void Vector::show(string s)
{
    long sl = s.length();

    // kad lygiavimas butu grazus, pirma tarp darysiu mazesni arba didesni: | to make the alignment nice, first of all I will make it smaller or bigger:
    int pt = 2 * myform::w;

    if (sl > pt) pt = myform::w; // jei labai ilgas uzrasas, nieko nedarau | if the caption is very long, I don't do anything
    else pt -= sl;

    cout << s << ':';
    //cout << setw(4) << xv << '\t' << yv << '\t' << zv <<'\n';
    cout << setw(pt) << xv << setw(myform::w) << yv << setw(myform::w) << zv <<'\n';
};


int main()
{
    Vector A(1.00, 2.01, 3), B(-4, 2, 1), C;
    cout << "*** Vectors 3D*** \n";
    A.show("A");
    B.show("B");
    printf("\n");

    C = A + B;
    C.show("C = A + B");
    cout << "\n(A*B):" << setw(2*myform::w-5) << A * B << '\n';
    (A^B).show("[A*B]");
    cout << '\n';

    //string z = "1234";
    //cout << "1234 dydis yra" << z.length(); | cout << "1234 size is" << z.length();

    return 0;
}
