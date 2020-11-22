//  Problem_7.c
//
//  Created by Aurimas Nausedas on 9/19/19.
//


#include <stdio.h>

// Deklaruoju pagalbines funkcijas
void root(double& x, double eps);
double fk(double x);

// dar pasirasau funkcija absoliuciai vertei gauti
double get_abs(double x);

// ************************************************************
int main()
{
    // Duomenys: tikslumas eps ir koks nors x
    double eps = 0.001, x = -1000;

    // paskaiciuju sakni
    root(x,eps);
    // Rezultatas: x
    printf("Saknis = %.3f\n\n",x);
    return 0;

}

// ************************************************************
void root(double& x, double eps)
{
    // is pradziu pasirenku delta kad tikrai butu daugiau uz eps
    double delta = 2 * eps;

    // is smalsumo: iteraciju skaiciukle
    int i = 0;

    // Iteracija ----------------------------------------------
    while (delta>= eps)
    {
        // paskaiciuju nauja x verte
        double x1 = x - eps/((fk(eps + x)/fk(x))-1);

        // perrasau x ir delta vertes:
        delta = get_abs(x-x1);
        x = x1;

        i++;
    }
    printf("iteracijos: %d\n\n",i);
}

// ************************************************************
double fk(double x)
{
    return 1 - x * x;
}
// ************************************************************
double get_abs(double x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}
