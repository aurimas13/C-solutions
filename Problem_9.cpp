//
// Problem_9.c
//
// Created by Aurimas A. Nausedas on 9/20/19.
// Updated by Aurimas A. Nausedas on 11/01/21.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// deklaruoju funkcijas
double rnd(void);
double fk(double x, double y);

//**************************************************

int main()
{

    // deklaruoju variables
    long i,
    n = 0,
    max = 5; // pratinis iteraciju skaicius

    // dviems skirtingams metodams dvi skirtingos sumos si kur i = 1 arba 2
    long s1 = 0;
    double s2 = 0;

    // atspausdinu pirma eilute
    printf("*** Tetraedro tūris: Monte Karlo 1 ir 2 metodai\n\n");
    printf("Tikslus rezultatas = 1/3\n\n");
    printf("%8s %8s %8s\n\n","Iter.","I","II");

    for (int j = 0; j < 15; j++)
    {
        for (i = 0; i < max; i++)
        {

            if (rnd() < fk(rnd(),rnd())) // palyginame f<f(x,y)
                // cia skaiciuoju vieno kampo turi, po to padauginsiu is 4
                // ir atimsiu ir 1 (kubo turio).
            {
                s1++;
            }

            // Monte Karlo algoritmas 2
            double x = rnd();
            double y = rnd();

            /* skaiciuoju tokius bandymus, kur x ir y yra suderinami, o pagrindas yra lygusis trikampis apribotas x ir y asies, kur y = 1 - x */
            if (x + y < 1)
            {
                // Monte Karlo 2 metodas
                s2 += fk(x,y); // s += f(x,y)
            }

            n++;
        }
        printf("%8ld %8.4lf %8.4lf \n", max, 1 - 4 * (double)s1/n, 1 - 4 * s2/n);
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
double fk(double x, double y)
{
    // z - plokstuma tetraedro su kampais
    // (0,0,0),(1,0,0),(0,1,0),(0,0,1)

    return 1 - x - y;
}
// ********************************************
