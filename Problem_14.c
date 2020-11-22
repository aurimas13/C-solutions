//
// Problem_14.c
//
//  Created by Aurimas Nausedas on 9/23/19.


#include <stdio.h>
#include <complex.h>

// Deklaruoju pagalbines funkcijas
void root(double complex *x, double const eps);
void fk(double complex *x);



// ************************************************************
int main()
{
    // Duomenys: tikslumas eps ir koks nors x
    double eps = 0.001;
    double complex x = 100 + -100 * I;

    // paskaiciuju sakni
    root(&x,eps);
    // Rezultatas: x
    printf("Saknis = %.3f %.3fi\n\n",creal(x),cimag(x));
    return 0;

}

// ************************************************************
void root(double complex *x, double const eps)
{
    // is pradziu pasirenku delta kad tikrai butu daugiau uz eps
    double delta = 2 * eps;

    // is smalsumo: iteraciju skaiciukle
    int i = 0;

    // Iteracija ----------------------------------------------
    while (delta>= eps)
    {
        //printf("x = %.3f %.3fi\n",creal(*x),cimag(*x));
        // paskaiciuju nauja x verte
        double complex a = *x;
        double complex b = *x + eps;
        fk(&a);
        fk(&b);

        double complex x1 = *x - eps/((b/a)-1);

        // perrasau x ir delta vertes:
        delta = cabs(*x-x1);
        *x = x1;

        i++;
    }
    printf("iteracijos: %d\n\n",i);
}

// ************************************************************
void fk(double complex *x)
{
   *x = 1 + *x * *x;
}
