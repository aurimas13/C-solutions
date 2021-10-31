// Problem_5.c
//
// Created by Aurimas Nausedas on 9/17/19.
// Updated by Aurimas Nausedas on 10/31/21.

#include <stdio.h>
// ********************************************
// deklaruoju pagalbines funkcijas | declaring helper functions

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
    // a, b, n jau deklaruoti, scanf reikia zinoti tik jo adresa | a, b, n have already been declared, scanf only needs to know its address
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("n = ");
    scanf("%d", &n);

    // ----------------------------------------

    f = simpson(a,b,n); // Integralas | Integral

    // Rezultatas | Result -----------------------------

    printf("Integral = %.3lf\n",f);

    return 0;
}

// ********************************************
double simpson(double a, double b, int n)
{
    // jei n = k, tuomet reikia paskaiciuoti g(x) 2k + 1 vietose | if n = k, then we need to calculate g (x) at 2k + 1
    // pvz. jei du reziai, tuomet reikia paskaiciuoti: | e.g. if two times, then the following must be calculated:
    // 2 centrinius rezio taskus | 2 central points of the gap
    // 2 kairines krastines | 2 left edges
    // 1 dešinė kraštinė. | 1 right edge.


    // puse rezio plocio hpus = (b-a)/(2n) | half gap width hpus = (b-a)/(2n
    double hpus = (b - a) / (n * 2);

    // inicijuoju suma f | initiationg sum
    double f = 0;

    // ciklu skaiciavimui | cycle calculations
    int i = 1;

    // stabteliu prie kiekvienos skaiciuotinos | stop at each count
    // intervalo (a,b) vertes x | values of the interval (a, b) x
    for (double x = a; x <= b; x += hpus)
    {
        // galima isskirti tris situacijas: | three situations can be distinguished:

        // 1. jei tai pati intervalo (a,b) kaire arba desine | 1. if it is itself to the left or right of the interval (a, b)
        // tuomet pridedant g(i) prie sumos f. | then adding g (i) to the sum of f.
        if (i == 1 || i == (2 * n) + 1)
        {
            f += fk(x);
        }

        // 2. rezio jei i rezio vidury, g(i) dauginam is 4 | 2. the field if i is in the middle of the field, g (i) is multiplied by 4
        else if (i % 2 == 0) // jei lyginis, t.y. rezio vidurys | if even, i.e. the middle of the slot
        {
            f += 4 * fk(x);
        }

        // 3. jei i nelyginis, esu ties i verte tarp dvieju intervalu | 3. if i is odd, I am at the value between the two intervals
        else
        {
            f += 2 * fk(x);
        }


        // pridedu vieneta, | adding one
        i++;
    }
    return f * 2 * hpus / 6;
}

// ********************************************
// siuo atveju integruosime f(x) = x^2 funkcija. | in this case we integrate the function f (x) = x ^ 2.
// atsakymas siuo atveju turetu buti tikslus | the answer in this case should be accurate
double fk(double x)
{
    return x * x;
}
