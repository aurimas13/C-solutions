//
// Problem_19_v3.cpp
//
// Created by Aurimas A. Nausedas on 9/28/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

// deklaruoju klases | declaring classes
// pagrindine | main
class Figure
{
public:
    Figure(int lx, int ly){x = lx; y = ly; c = 1;};
    void move(int ly);
    virtual void show(int lc) = 0;
    virtual void hide() = 0;
protected:
    int x,y,c;
    // spalva | colour
};

// ------------------------------------------------------
// isvestines klases | derived classes

class Circle : public Figure
{
public:
    Circle(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Square : public Figure
{
public:
    Square(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Triangle : public Figure
{
public:
    Triangle(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Smile : public Figure
{
public:
    Smile(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

//******************************************************

// deklaruoju pagalbines funkcijas | declaring helper functions
void init();
void generation(Figure **f, int number);

//******************************************************

int main()
{
    const int number = 21;
    double t;
    int randcol; // atsitiktine spalva | arbitrary colour

    // alokuoju rodykle is Figure klases objekta | allocate an arrow from the Figure class object
    Figure *f[number];

    // inicializuoja grafini langa | initializes the graphical window
    init();

    // uzpildau masyva isvestiniai Figure objektais | fill an array of derived Figure objects
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
    } while (!kbhit()); // kol nenuspaude mygtuko | until you press the button
    getch();

    closegraph();
    for (i = 0; i < number; i++) delete f[i];

    return 0;

}

//******************************************************
// klases funkciju apibrezimai | definitions of class functions

void Figure::move(int ly)
{
    hide();
    y = ly;
    show(c);
}

//----------------------------------------------------

void Circle::show(int lc) // spalva, nuo 0 iki 16, 0 = juoda.
{
    setcolor(lc);
    circle(x, y, 10);
    c = lc; // perrasau spalva kad galeciau naudoti su move | I rewrote the colour so I could use it with the move
} 

void Circle::hide()
{
    setcolor(0);
    circle(x, y, 10);
}

//----------------------------------------------------
void Square::show(int lc)
{
    setcolor(lc);
    rectangle(x - 10, y - 10, x + 10, y + 10);
    c = lc; // perrasau spalva kad galeciau naudoti su move | I rewrote the colour so I could use it with the move
}

void Square::hide()
{
    setcolor(0);
    rectangle(x - 10, y - 10, x + 10, y + 10);
}
//----------------------------------------------------
void Triangle::show(int lc)
{
    setcolor(lc);
    moveto(x - 10, y + 10);
    lineto(x, y - 10);
    lineto(x + 10, y + 10);
    lineto(x - 10, y + 10);
    c = lc; // perrasau spalva kad galeciau naudoti su move | I rewrote the colour so I could use it with the move
}

void Triangle::hide()
{
    setcolor(0);
    moveto(x - 10, y + 10);
    lineto(x, y - 10);
    lineto(x + 10, y + 10);
    lineto(x - 10, y + 10);
}

//----------------------------------------------------
void Smile::show(int lc)
{
    setcolor(lc);
    circle(x, y, 10);
    arc(x,y,190,290,7);
    int newcol = lc + 4;
    if (newcol > 16) newcol -= 16;
    setfillstyle(SOLID_FILL,newcol);
    setcolor(newcol);
    pieslice(x-3, y - 2, 180, 360, 3);
    pieslice(x+3, y - 2, 180, 360, 3);
    line(x - 6, y - 2, x + 6, y - 2);

    c = lc; // perrasau spalva kad galeciau naudoti su move | I rewrote the colour so I could use it with the move
}


void Smile::hide()
{
    setcolor(0);
    circle(x, y, 10);
    arc(x,y,190,290,7);
    setfillstyle(SOLID_FILL,0);
    pieslice(x-3, y - 2, 180, 360, 3);
    pieslice(x+3, y - 2, 180, 360, 3);
    line(x - 6, y - 2, x + 6, y - 2);
}

//----------------------------------------------------




//******************************************************
// kitos funkcijos | other functions

void init() // Grafine moda | Graphical mode
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
void generation(Figure **f, int number) // kaip suprantu | the way I understood
// dvi zvaigzdes nes i) masyvas siunciamas ii) objektai masyve | two stars because i) the array is sent ii) the objects in the array
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
            printf("Error placing shapes in an array\n");
            exit(1);
        }
    }
}
