//
// Problem_18.cpp
// 
// Created by Aurimas A. Nausedas on 9/28/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

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

    // ivairiaspalves 1/(x/n) funkcijos, kur n = 1,...,5 | multicolored 1 / (x / n) functions, where n = 1, ..., 5
    int sk = 500; //zingsniu sk| number of steps
    double  Xmin = 0,
    Xmax = 10,
    Xdel = 1;
    double  Ymin = 0,
    Ymax = 10,
    Ydel = 1;

    char leg[20]; // pavadinimas | name 

    double x,f;
    double h = (Xmax - Xmin) / sk; // Zingsnis | Step

    init();

    Plot T(0,0,getmaxx(),getmaxy(), // Lango matmenys | Window size
           Xmin, Xmax, Xdel,        // X asis | X axis
           Ymin, Ymax, Ydel,        // Y asis | Y axis
           15, 13);                 // Fonas ir tinklelis | Background and grid


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
