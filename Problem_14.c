//
// Problem_14.c
//
// Created by Aurimas A. Nausedas on 9/23/19.
// Updated by Aurimas A. Nausedas on 10/31/21.


#include <stdio.h>
#include <complex.h>

// Deklaruoju pagalbines funkcijas | helper functions declaration
void root(double complex *x, double const eps);
void fk(double complex *x);



// ************************************************************
int main()
{
    // Duomenys: tikslumas eps ir koks nors x | data: accuracy eps and any x
    double eps = 0.001;
    double complex x = 100 + -100 * I;

    // paskaiciuju sakni | Calculate Volume
    root(&x,eps);
    // Rezultatas: x | Result: x
    printf("Saknis = %.3f %.3fi\n\n",creal(x),cimag(x));
    return 0;

}

// ************************************************************
void root(double complex *x, double const eps)
{
    // is pradziu pasirenku delta kad tikrai butu daugiau uz eps | from the beginning i would choose delta to really be more than eps
    double delta = 2 * eps;

    // is smalsumo: iteraciju skaiciukle | out of curiosity calcualting number of iterations
    int i = 0;

    // Iteracija | Interation ----------------------------------------------
    while (delta>= eps)
    {
        // printf("x = %.3f %.3fi\n",creal(*x),cimag(*x));
        // paskaiciuju nauja x verte | Calculating new x value
        double complex a = *x;
        double complex b = *x + eps;
        fk(&a);
        fk(&b);

        double complex x1 = *x - eps/((b/a)-1);

        // perrasau x ir delta vertes: | reerite the x and delta values:
        delta = cabs(*x-x1);
        *x = x1;

        i++;
    }
    printf("iterations: %d\n\n",i);
}

// ************************************************************
void fk(double complex *x)
{
   *x = 1 + *x * *x;
}
