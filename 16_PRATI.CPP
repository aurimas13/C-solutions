//
// Problem_16.c
//
//  Created by Aurimas Nausedas on 9/20/19.
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>
#include <stdlib.h>

// Klasiu deklaracija -----------------------------------------------

class Window
{
public:
  Window(int lxp, int lyp, int lxd, int lyd, int lsf);
  void act();
  void on();
  void off();
protected:
  void* buf;
  text_info txinf;
  int xp, yp, xg, yg,
      xd, yd,
      sf;
};


// ----------------------------------------------------------------
class Frame : public Window
{
public:
  Frame(int lxp, int lyp, int vxd, int vyd, int lsf);
  void on();
  void act();
}


// Klasiu funkcijos ------------------------------------------------

// konstruktorius klases Window
Window::Window(int lxp, int lyp, int lxd, int lyd, int lsf)
{
  xp = lxp;
  yp = lyp;
  xd = lxd;
  yd = lyd;
  sf = lsf;

  xg = xd + xp - 1;
  yg = yd + yp - 1;
};

// konstruktorius klases Frame
Frame::Frame(int lxp, int lyp, int vxd, int vyd, int lsf) :
Window(lxp, lyp, vxd+2, vyd+2,lsf)
{
}

// ----------------------------------------------------------------


// lango aktyvavimas
void Window::act()
{
  window(xp,yp,xg + 1,yg); // langa darau viena eilute platesni is desines
                           // kitaip neiseina isvengti eiluciu sokinejimo
  textcolor(15);
  textbackground(sf);
};


// frame lango aktyvavimas...


// ----------------------------------------------------------------
// lango rodymas
void Window::on()
{

  // lango informacijos uzrasymas i buferi
  int size = 2 * (xd + 1) * yd; // buferio dydis
  buf = new char[size]; // alokuoju masyva
  if (buf == 0) // pirmo elemonto adresas priskiriamas rodyklei buf
  {
    printf("Klaida, nealokuota atmintis buferio dinaminiam masyvui\n");
    exit(1);
  }
  gettext(xp, yp, xg + 1, yg, buf);

  // papildomai buvusio lango info saugoti
  gettextinfo(&txinf);

  // activuoju langa
  act();

  // Naujo lango piesimas
  int y = 1;
  for (y; y<=yd; y++)
  {
    int x = 1; // reset x each time
    for (x; x<=xd; x++)
    {
      gotoxy(x, y);
      cprintf("%c",' ');
    }
  }


};

// ----------------------------------------------------------------
// frame lango rodymas
void Frame::on()
{
  // nupiesiamas langas (per 2 didesnis nei 'uzsakyta')
  Window::on();

  //printf("xp,yp,xg,yg are %d,%d,%d,%d",xp,yp,xg,yg);


  // Remo piesimas
  int y = 1;

  for (y; y<=yd; y++)
  {

    int x = 1; // reset x each time
    for (x; x<=xd; x++)
    {
      gotoxy(x, y);
      // jei kampas:
      if ((y == 1) && (x == 1))
      {
        cprintf("%c",201);
      }

      // jei kampas:
      else if ((y == 1) && (x == xd))
      {
        cprintf("%c",187);
      }

      // jei kampas:
      else if ((y == yd) && (x == 1))
      {
        cprintf("%c",200);
      }

      // jei kampas:
      else if ((y == yd) && (x == xd))
      {
        //gotoxy(x, y);
        cprintf("%c",188);
      }

      //jei virsus arba apacia
      else if ((y == 1) || (y == yd))
      {
        //gotoxy(x, y);
        cprintf("%c",205);
      }

      //jei kaire arba desine
      else if ((x == 1) || (x == xd))
      {
        //gotoxy(x, y);
        cprintf("%c",186);
      }

      else
      {
        //gotoxy(x ,y);
        cprintf("%c",' ');
      }

    }

  }


}


// ----------------------------------------------------------------
void Window::off()
{
  puttext(xp, yp, xg + 1, yg, buf);
  delete []buf; // isvalau dinamiskai alokuota atminties gabala

  // graziname buvusio lango atributus, kursoriaus lokacija
  window(txinf.winleft, txinf.wintop, txinf.winright, txinf. winbottom);
  textattr(txinf.attribute);
  gotoxy(txinf.curx,txinf.cury);
};


// Main programa --------------------------------------------------


int main()
{
  // paleidziant emuliatoriu ir turbo C
  // paleidziama programa, kuri spausdina "turbo C"
  // ekrane, reikia isvalyti
  clrscr();

  Window A(25, 7, 10, 5, 14);
  Frame B(30, 10, 20, 6, 2);
  //Frame B(1,1,20,6,2);

  // nestandartine conio.h funkcija, tik edukacijai
  gotoxy(12,10);

  // tikriausiai irgi nestandartine conio.h funkcija, tik edukacijai
  cprintf("Some Text on the Black Screen");
  getch();

  // ---------------------------------------------------------------
  A.on();		// Pirmas langas
  gotoxy(3, 2);
  textcolor(11);
  cprintf("First");
  gotoxy(3, 3);
  cprintf("window");
  gotoxy(4, 4);
  cprintf("On!");
  getch();


  // ---------------------------------------------------------------
  B.on();		// Antras langas
  textcolor(0);
  gotoxy(6, 3);
  cprintf("One more");
  gotoxy(7, 4);
  cprintf("window");
  getch();

  // ---------------------------------------------------------------
  B.off();
  getch();


  // ---------------------------------------------------------------
  A.off();
  getch();

  return 0;

}
