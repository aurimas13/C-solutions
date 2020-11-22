//
// Problem_13
// Simpson.c
//
//  Created by Aurimas Nausedas on 9/20/19.


#ifndef simpson_h
#define simpson_h

// ********************************************
double simpson(double (*fname)(double x), double a, double b, int n)
{
    // jei n = k, tuomet reikia paskaiciuoti g(x) 2k + 1 vietose
    // pvz. jei du reziai, tuomet reikia paskaiciuoti:
    // 2 centrinius rezio taskus
    // 2 kairines krastines
    // 1 desine krastine.

    // specialus atvejis, kai a = b
    if (a == b)
    {
        double res = 0;
        return res;
    }

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
            f += fname(x);
        }

        // 2. rezio jei i rezio vidury, g(i) dauginam is 4
        else if (i % 2 == 0) // jei lyginis, t.y. rezio vidurys
        {
            f += 4 * fname(x);
        }

        // 3. jei i nelyginis, esu ties i verte tarp dvieju intervalu
        else
        {
            f += 2 * fname(x);
        }


        // pridedu vieneta,
        i++;
    }
    return f * 2 * hpus / 6;
}


#endif /* simpson_h */
