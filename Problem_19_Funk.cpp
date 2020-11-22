//
// Problem_19.cpp
//
//  Created by Aurimas Nausedas on 9/28/19.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#include "Problem_19_Funk.h"


//******************************************************
// klases funkciju apibrezimai

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
    c = lc; // perrasau spalva kad galeciau naudoti su move
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
    c = lc; // perrasau spalva kad galeciau naudoti su move
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
    c = lc; // perrasau spalva kad galeciau naudoti su move
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

    c = lc; // perrasau spalva kad galeciau naudoti su move
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
