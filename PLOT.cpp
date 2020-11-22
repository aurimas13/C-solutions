//
// Problem_18.cpp
//
//  Created by Aurimas Nausedas on 9/24/19.

#include <math.h>
#include <string.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#include "plot.h"

//******************************************************
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

// Klases Plot funkcijos ******************************
Plot::Plot(int lxp, int lyp, int xd, int yd, // lango matmenys pixeliais
           double lminX, double lmaxX, double ldeltaX,
           double lminY, double lmaxY, double ldeltaY,
           int lsp, int lspt)
{
    xp = lxp;
    yp = lyp;
    xg = xp + xd; // pixeliais
    yg = yp + yd; // pixeliais
    sp = lsp; // fillstyle number
    spt = lspt;
    minX = lminX; // vienetais x asyje
    maxX = lmaxX; // vienetais x asyje
    deltaX = ldeltaX; // groteliu plotis
    minY = lminY; // vienetais y asyje
    maxY = lmaxY; // vienetais y asyje
    deltaY = ldeltaY; // groteliu plotis

    // daugini atstuma x vienetais is XtoP ir gauni pixelius
    XtoP = ((double)(xg - xp - 39)) / (maxX - minX);

    // daugini atstuma y vienetais is XtoP ir gauni pixelius
    YtoP = ((double)(yg - yp - 39)) / (maxY - minY);

}
// ------------------------------------------------------
void Plot::on()
{
    double Xst, Yst, a, b;
    int r, l, rb;
    char s[20]; // for storing floats as strings later

    // visa (max) ekrana uzpildau pasirinkta spalva
    setviewport(0, 0, getmaxx(), getmaxy(), 1); // max screen coord.
    // sita perkelciau i atskira funkcija
    // jei butu poreikis kelis subplots padaryti
    setfillstyle(SOLID_FILL, sp); //set the current viewport for
    // graphics output, absolute coord
    bar(xp, yp, xg, yg); // rectangle filled

    // pasirinkta staciakampi (pixeliais) apibreziu remu
    setviewport(xp, yp, xg, yg, 1);
    Xst = deltaX * ceil(minX / deltaX);// pirmo bruksneliu padetis
    Yst = deltaY * ceil(minY / deltaY); // pirmo bruksneliu padetis
    setcolor(0);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(20, 20, xg - xp - 20, yg - yp - 19);// remas

    // X asies pavadinimai
    for (a = Xst; a < maxX; a += deltaX)
    {
        r = fx(a); // zingsniuoju pasirinktais vnt, bet piesiu pixeliais
        b = fabs(fmod(a, 5 * deltaX)) / deltaX; // absolute, modulo
        if ((b < 0.1) || (b > 4.9))
        {
            rb = 10;
            if (fabs(a) < deltaX/2)
            {
                a = 0;
            }

            // prepare x label as string
            gcvt(a, 4, s); // float to string
            l = strlen(s);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

            // atspaudinama xticklabel
            outtextxy(r + 16 - l / 2, yg - yp - 10, s);
        }
        else
        {
            rb = 5; // kiek islinde solid black tik
        }

        // trumpi juodi ticks
        line(r + 20, 20, r + 20, 20 + rb); // virsuje
        line(r + 20, yg - yp - 20 - rb, r + 20, yg - yp - 20); // apacioje

        if((r != 0) && (r != xg - xp - 40)) //jei ne remo krastai
        {
            setcolor(spt);
            setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
            line(r + 20, 20 + rb, r + 20, yg - yp - 20 - rb);
            setcolor(0);
            setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        }
    }

    // analogiskai su y-asimi
    for(a = Yst; a < maxY; a += deltaY)
    {
        r = fy(a);
        b = fabs(fmod(a, 5 * deltaY)) / deltaY;
        if ((b <0.1) || (b > 4.9))
        {
            rb = 10;
            if (fabs(a) < deltaY / 2)
            {
                a = 0;
            }
            gcvt(a, 4, s);
            l = strlen(s);
            settextstyle(DEFAULT_FONT, VERT_DIR, 1);
            outtextxy(13, r + 17 + 1 / 2, s);
        }

        else
        {
            rb = 5;
        }

        line(20, r + 20, 20 + rb, r + 20);
        line(xg - xp - 20 - rb, r + 20, xg - xp - 20, r + 20);
        if((r != 0) && (r != yg - yp - 39))
        {
            setcolor(spt);
            setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
            line(xg - xp - 20 - rb, r + 20, 20 + rb, r + 20);

            //return to previous default state
            setcolor(0);
            setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        }
    }
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    act();
}
// ----------------------------------------------------------
void Plot::act()
{
    // paskutinis - clip
    // activuojama placiau
    setviewport(xp + 20, yp + 20, xg - 20, yg - 20, 1);
}

// ----------------------------------------------------------
int Plot::fx(double x)
{
    // padeti ekrane pixeliais pakeicia i padet x-asyje (regis)
    return (int)(floor(XtoP * (x - minX)));
}

// ----------------------------------------------------------
int Plot::fy(double y)
{
    return (int)(yg - yp - 39 - floor(YtoP * (y - minY)));
}
// ----------------------------------------------------------

void Plot::point(double x, double y, int spalva)
{
    // pades taska tam tikroje vietoje
    putpixel(fx(x), fy(y), spalva);
}

// ----------------------------------------------------------
void Plot::start(double x, double y)
{
    moveto(fx(x),fy(y));
}

// ----------------------------------------------------------
void Plot::draw(double x, double y)
{
    lineto(fx(x),fy(y));
}

// ----------------------------------------------------------
void Plot::legend(double x, double y, double pix, char mystr[])
{
    //short line
    double xprev = getx();
    double yprev = gety();

    setlinestyle(0, 0, THICK_WIDTH);
    line(x,y,x+pix,y);
    setlinestyle(0, 0, NORM_WIDTH);

    // text
    outtextxy(x + 2. * pix, y,mystr);

    //go back
    moveto(xprev,yprev);
}
