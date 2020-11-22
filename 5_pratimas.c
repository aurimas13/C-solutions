//  Problem_5.c
//
//  Created by Aurimas Nausedas on 9/17/19.
//

#include <stdio.h>
// ********************************************
// deklaruoju pagalbines funkcijas

double simpson(double a, double b, int n);
double fk(double x);

// ********************************************

int main()
{
    double a,b,f;
    int n;

    //...

    // Duomenys -------------------------------
    printf("a = ");
    // a, b, n jau deklaruoti, scanf reikia zinoti tik jo adresa
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("n = ");
    scanf("%d", &n);

    // ----------------------------------------

    f = simpson(a,b,n); // Integralas

    // Rezultatas -----------------------------

    printf("Integralas = %.3lf\n",f);

    return 0;
}

// ********************************************
double simpson(double a, double b, int n)
{
    // jei n = k, tuomet reikia paskaiciuoti g(x) 2k + 1 vietose
    // pvz. jei du reziai, tuomet reikia paskaiciuoti:
    // 2 centrinius rezio taskus
    // 2 kairines krastines
    // 1 desine krastine.


    // puse rezio plocio hpus = (b-a)/(2n)
    double hpus = (b - a) / (n * 2);

    // inicijuoju suma f
    double f = 0;

    // ciklu skaiciavimui
    int i = 1;

    // stabteliu prie kiekvienos skaiciuotinos
    // intervalo (a,b) vertes x
    for (double x = a; x <= b; x += hpus)
    {
        // galima isskirti tris situacijas:

        // 1. jei tai pati intervalo (a,b) kaire arba desine
        // tuomet pridedant g(i) prie sumos f.
        if (i == 1 || i == (2 * n) + 1)
        {
            f += fk(x);
        }

        // 2. rezio jei i rezio vidury, g(i) dauginam is 4
        else if (i % 2 == 0) // jei lyginis, t.y. rezio vidurys
        {
            f += 4 * fk(x);
        }

        // 3. jei i nelyginis, esu ties i verte tarp dvieju intervalu
        else
        {
            f += 2 * fk(x);
        }


        // pridedu vieneta,
        i++;
    }
    return f * 2 * hpus / 6;
}

// ********************************************
// siuo atveju integruosime f(x) = x^2 funkcija.
// atsakymas siuo atveju turetu buti tikslus
double fk(double x)
{
    return x * x;
}
