//
//  P19MAIN.cpp
//
//  Created by Aurimas Nausedas on 9/28/19.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#include "P19FUNK.h"


// deklaruoju pagalbines funkcijas
void init();
void generation(Figure **f, int number);

int main()
{
    const int number = 21;
    double t;
    int randcol; // atsitiktine spalva

    // alokuoju rodykle is Figure klases objekta
    Figure *f[number];

    // inicializuoja grafini langa
    init();

    // uzpildau masyva isvestiniai Figure objektais
    generation(f, number);

    for(int i = 0; i < number; i++)
    {
        randcol = 1 + random(15);
        f[i] -> show(randcol);
        getch();
    }

    t = 0;
    do{
        t += 0.02;
        for (i = 0; i < number; i++)
        {
            f[i] -> move(-50 * sin(0.5 * i - t) + 240);

        }
    } while (!kbhit()); // kol nenuspaude mygtuko
    getch();

    closegraph();
    for (i = 0; i < number; i++) delete f[i];

    return 0;

}


//******************************************************
// pagalbines funkcijos

void init() // Grafine moda
{
    int Gd, Gm, ErCo;
    Gd=DETECT;
    initgraph(&Gd, &Gm, "c:\\TC\\BGI");
    ErCo=graphresult();
    if ( ErCo != grOk)
    {
        printf("Nera grafikos");
        exit(1);
    }
}

//----------------------------------------------------
void generation(Figure **f, int number) // kaip suprantu
// dvi zvaigzdes nes i) masyvas siunciamas 2) objektai masyve
{
    for (int i = 0; i < number; i++)
    {
        switch(random(4))
        {
            case 0:
                f[i] = new Circle(30 * i + 10, 240);
                break;
            case 1:
                f[i] = new Square(30 * i + 10, 240);
                break;
            case 2:
                f[i] = new Triangle(30 * i + 10, 240);
                break;
            case 3:
                f[i] = new Smile(30 * i + 10, 240);
        }
        if (f[i] == 0)
        {
            printf("Klaida talpinant figuras i masyva\n");
            exit(1);
        }
    }
}
