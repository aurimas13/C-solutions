//
// Problem_18.cpp
//
//  Created by Aurimas Nausedas on 9/20/19.
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>

#include "plot.h"


double fk(double x,double n);

int main()
{

    // ivairiaspalves 1/(x/n) funkcijos, kur n = 1,...,5
    int sk = 500; //zingsniu sk
    double  Xmin = 0,
    Xmax = 10,
    Xdel = 1;
    double  Ymin = 0,
    Ymax = 10,
    Ydel = 1;

    char leg[20]; // pavadinimams

    double x,f;
    double h = (Xmax - Xmin) / sk; // Zingsnis

    init();

    Plot T(0,0,getmaxx(),getmaxy(), // Lango matmenys
           Xmin, Xmax, Xdel,        // X asis
           Ymin, Ymax, Ydel,        // Y asis
           15, 13);                 // Fonas ir tinklelis

    T.on();
    getch();


    for (int n = 1; n < 6; n++)
    {
        x = Xmin;
        f = fk(x,n);
        T.start(x,f);
        setcolor(n);


        for (int i = 1; i <= sk; i++)
        {
            x = Xmin + i * h;
            f = fk(x,n);
            T.draw(x,f);
            char legfull[40] = "n/x, kur n = ";
            gcvt(n,0,leg);
            strcat(legfull,leg);

            T.legend(getmaxx()-200,n * 20, 10, legfull);
        }
        getch();
    }


    getch();
    closegraph();
    return 0;

}

// ---------------------------------
double fk(double x,double n)
{
    return n/(x);
}
