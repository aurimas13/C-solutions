//
// Problem_17.c
//
// Created by Aurimas Nausedas on 9/20/19.
// Pixel graphics

#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include <graphics.h>

void init();
void changetextstyle(int font, int direction, int charsize);

// **********************************************

int main()
{

  init(); //I grafine moda
  //outtextxy(100, 50, "Pikseline Moda");
  getch();

  setfillstyle( SOLID_FILL, RED );
  fillellipse(230,330,90,120);

  circle(200, 300, 30); // // Apskritimas
  circle(260, 300, 30); // Apskritimas
  circle(215, 285, 8);
  circle(275, 285, 8);

  setlinestyle(0, 0, THICK_WIDTH);
  arc(200, 290, 50, 135, 30);
  moveto(240,260);
  lineto(250,250);
  lineto(275,260);

  //burna
  line(200,380,260,400);

  // mintys
  setlinestyle(0, 0, NORM_WIDTH);
  //setfillstyle(SOLID_FILL, WHITE);

  getch();
  fillellipse(285,180,40,20);
  setcolor(1);
  ellipse(285,180,0,360,40,20);
  getch();


  fillellipse(380,100,120,60);
  setcolor(2);
  ellipse(380,100,0,360,120,60);
  getch();

  // tekstas:
  changetextstyle(0, HORIZ_DIR, 2);
  outtextxy(310, 80, "Ka gi cia");
  outtextxy(305, 100, "nupiesus?..");
  getch();

  closegraph() ;
  return 0;
}

// **********************************************

void init()
{
  int gd;
  int gm;
  int err;
  gd = DETECT;
  initgraph(&gd, &gm, "c:\\TC\\BGI");
  err = graphresult();
  if(err != grOk)
  {
    /* Error occured during init	*/
    printf(" Graphics System Error: %s\n", grapherrormsg(err));
    exit(1);
  }
}

// **********************************************

void changetextstyle(int font, int direction, int charsize)
{
  int ErrorCode;

  graphresult();			/* clear error code		*/
  settextstyle(font, direction, charsize);
  ErrorCode = graphresult();		/* check result 		*/
  if( ErrorCode != grOk ){		/* if error occured		*/
    closegraph();
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}
