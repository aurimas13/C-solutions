// Problem_8.c
// 
// Created by Aurimas A. Nausedas on 9/20/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// deklaruoju funkcijas | declaring functions
double rnd(void);
double fk(double x);

//**************************************************

int main()
{

    // deklaruoju variables | declaring variables
    long i,
         n = 0,
         max = 5; // pradinis iteraciju skaicius | initial number of iterations

    // trims skirtingams metodams 3 skirtingos sumos si | for three different methods 3 different amounts si
    long s1 = 0;
    double s2 = 0,
           s3 = 0,
           ref = 0.5;

    // atspaudinu pirma eilute | print the first line
    printf("*** Integralas ( I - 0.5 ): Monte Carlo methods\n\n");
    printf("Exact result = 0.0250\n\n");
    printf("%8s %8s %8s %8s\n\n","Iter.","I","II","III");

    for (int j = 0; j < 13; j++)
    {
        for (i = 0; i < max; i++)
        {

            // Monte Karlo algoritmas 1 | Monte Carlo Algorithm 1
            // Klausimas: ka daryti su funkcija | Question: what to do with a function
            // kurios f(x) vertes virsija 1? | which values of f (x) exceed 1?
            // siuo atveju taip nera. | this is not the case.
            // spresciau "suspaudamas" funkcija | more "compressing" function
            // po to rezultata daugindamas is suspaudino.. | then multiply the result by compressing ..

            if(rnd() < fk(rnd())) // palyginame/comapre f<f(x) 
             {
             s1++;
             }

             // Monte Karlo algoritmas 2 | Monte Carlo Algorithm 2
             s2 += fk(rnd()); // s += f(x)


            // Monte Karo algoritmas 3 | Monte Carlo Algorithm 3
            double x = sqrt (rnd());
            s3+=(fk(x)/2/x); //s+=F(x)

            n++;
        }
        printf("%8ld %8.4lf %8.4lf %8.4lf\n",
               max,
               (double)s1/n-ref,
               s2/n-ref,
               s3/n-ref);

        max *= 2;

    }
    printf("\n");
    return 0;
}

//**************************************************

double rnd()
{
    return (double)rand() / RAND_MAX;
}

// ********************************************
double fk(double x)
{
    return x * (1 + 0.3 * x * (1 - x));
}
// ********************************************
