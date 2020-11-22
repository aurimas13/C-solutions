//
// Problem_15.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>

// Deklaracija -------------------------
class Vector
{
public:
    // default konstruktorius (inline)
    Vector(){};
    Vector(double x, double y, double z);
    friend Vector operator+(const Vector& A, const Vector& B);
    friend double operator*(const Vector& A, const Vector& B);
    friend Vector operator^(const Vector& A, const Vector& B);

    void show(char* s);
private:
    double xv,yv,zv;
};

// Funkcijos ----------------------------
// konstruktorius
Vector::Vector(double x, double y, double z)
{
    xv = x;
    yv = y;
    zv = z;
};



// vektoriu suma
Vector operator+(const Vector& A, const Vector& B)
{
    return Vector(A.xv + B.xv,A.yv + B.yv,A.zv + B.zv);
};



// vektoriu skaliarine sandauga
double operator*(const Vector& A, const Vector& B)
{
    double mult = A.xv * B.xv + A.yv * B.yv + A.zv * B.zv;
    return mult;
};


// vektoriu vector sandauga
Vector operator^(const Vector& A, const Vector& B)
{

    double cx = A.yv * B.zv - B.yv * A.zv;
    double cy = -(A.xv * B.zv - B.xv * A.zv);
    double cz = A.xv * B.yv - B.xv * A.yv;

    return Vector(cx,cy,cz);
};



// show funkcija
void Vector::show(char* s)
{
    printf("%s: %7.3f %7.3f %7.3f\n",s,xv,yv,zv);
};


int main()
{
    Vector A(1, 2, 3), B(-4, 2, 1), C;
    printf("*** Vectoriai 3D*** \n");
    A.show("A");
    B.show("B");
    printf("\n");

    C = A + B;
    C.show("C = A + B");
    printf("\n(A*B): %7.3f\n\n", A * B);
    (A^B).show("[A*B]");
    printf("\n");
    return 0;
}
