// Problem_8.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// deklaruoju funkcijas
double rnd(void);
double fk(double x);

//**************************************************

int main()
{

    // deklaruotu variables
    long i,
         n = 0,
         max = 5; // pratinis iteraciju skaicius

    // trims skirtingams metodams 3 skirtingos sumos si
    long s1 = 0;
    double s2 = 0,
           s3 = 0,
           ref = 0.5;

    // atspaudinu pirma eilute
    printf("*** Integralas ( I - 0.5 ): Monte Karlo metodai\n\n");
    printf("Tikslus rezultatas = 0.0250\n\n");
    printf("%8s %8s %8s %8s\n\n","Iter.","I","II","III");

    for (int j = 0; j < 13; j++)
    {
        for (i = 0; i < max; i++)
        {

             // Monte Karlo algoritmas 1
            // Klausimas: ka daryti su funkcija
            // kurios f(x) vertes virsija 1?
            // siuo atveju taip nera.
            // spresciau "suspaudamas" funkcija
            // po to rezultata daugindamas is suspaudino..

            if(rnd() < fk(rnd())) // palyginame f<f(x)
             {
             s1++;
             }

             // Monte Karlo algoritmas 2
             s2 += fk(rnd()); // s += f(x)


            // Monte Karo algoritmas 3
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
