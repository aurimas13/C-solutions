//
// Problem_13.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>
#include "simpson.h"
#include "p13_f1.h" // hederis su f1(x) = x
#include "p13_f2.h" // hederis su f1(x) = x^2


// deklaruoju pagalbines funkcijas
void text();
char mygetchar(void);
void myclear(void);
void spresk(double (*funk) (double x));
int minimenu(void);

// ********************************************

int main()
{
    // hack'as: kad visada butu panasiai centruotas menu
    // pirma atspausdinu tusciu liniju
    myclear();
    text();
    for (;;)
    {
        char r = mygetchar();
        switch(r)
        {
            case 'x':
            {
                return 0;
            }

            case 'c':
            {
                myclear();
                text();
                break;
            }

            case 'f':
            {
                int a = 1;
                while(a)
                {
                    spresk(f1);
                    printf("\n");
                    // 1 arba 0
                    a = minimenu();
                    printf("\n");
                }

                myclear();
                text();
                break;
            }

            case 's':
            {
                int a = 1;
                while(a)
                {
                    spresk(f2);
                    printf("\n");
                    // 1 arba 0
                    a = minimenu();
                    printf("\n");
                }

                myclear();
                text();
                break;
            }

            default:
            {
                printf("\n\n");
            }
        }
    }
}


// Information ****************+*********+******
void text()
{
    printf("Menu \r\n\n");
    printf(" x - Exit\r\n");

    // clear screen nelabai cia reikalingas...
    printf(" с - Clear Screen\r\n\n");
    printf(" f - Integrate f(x) = x \r\n");
    printf(" s - Integrate f(x) = x^2\r\n\n");
    for (int i = 1; i < 5; i++)
        printf("\n");
}

// ********************************************
void spresk(double (*funk) (double x))
{
    double a,b,f;
    int n;

    // Duomenys -------------------------------
    printf("a = ");
    // a, b, n jau deklaruoti, scanf reikia zinoti tik jo adresa
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("n = ");
    scanf("%d", &n);

    // isvalo nuo susikaupusio "return" zenklo stinput
    while (getchar() != '\n');

    // ----------------------------------------

    f = simpson(funk,a,b,n); // Integralas

    // Rezultatas -----------------------------

    printf("Integralas = %.3lf\n",f);

}

// ********************************************
char mygetchar(void)
// only get the first char
// using it consistently throughout the code
// will prevent the issue of reading "return"

{
    char c = getchar();
    while (getchar() != '\n');
    return c;
}

// ********************************************
void myclear(void)
// hack to "clear" screen by printing empty lines
{
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
    }
}

// ********************************************
int minimenu(void)
// require the user to either enter 'x' or 'p'
// returns 0 or 1, respectively
{

    for (;;)
    {
        printf("p - Proceed with function\nx - Back to menu\n");
        char c = mygetchar();


        switch(c)
        {
            case 'p':
                return 1;
                break;

            case 'x':
                return 0;
                break;

        }
    }
}
