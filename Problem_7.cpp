//
// Problem_7.c
// 
// Created by Aurimas A. Nausedas on 9/19/19.
// Updated by Aurimas A. Nusedas on 10/31/21.

#include <stdio.h>

// Deklaruoju pagalbines funkcijas | declaring helper functions
void root(double& x, double eps);
double fk(double x);

// dar pasirasau funkcija absoliuciai vertei gauti | signed a function to get an absolute value
double get_abs(double x);

// ************************************************************
int main()
{
    // Duomenys: tikslumas eps ir koks nors x | Data: accuracy eps and any x
    double eps = 0.001, x = -1000;

    // paskaiciuju sakni | read the root

    root(x,eps);
    // Rezultatas: x | Solution: x
    printf("Saknis = %.3f\n\n",x);
    return 0;

}

// ************************************************************
void root(double& x, double eps)
{
    // is pradziu pasirenku delta kad tikrai butu daugiau uz eps | from the beginning I choose delta to be bigger than eps
    double delta = 2 * eps;

    // is smalsumo: iteraciju skaiciukle | from curiosity: iterations calculator
    int i = 0;

    // Iteracija | Iteration ----------------------------------------------
    while (delta>= eps)
    {
        // paskaiciuju nauja x verte | Calculating new x value
        double x1 = x - eps/((fk(eps + x)/fk(x))-1);

        // perrasau x ir delta vertes: | rewriting x and delta values
        delta = get_abs(x-x1);
        x = x1;

        i++;
    }
    printf("Iterations: %d\n\n",i);
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
