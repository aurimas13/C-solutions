//  Problem_4.c
//
//  Created by Aurimas Nausedas on 9/17/19.
//

#include <stdio.h>
#include <ctype.h>

void lentele4prat(int start, int end)
{
    // linija
    for (int k = 1; k <= 73; k++)
    {
        printf("-");
    }
    printf("\n");

    // Lentele
    for (int i = start; i <= end; i ++)
    {
        int j = i + 1;


        // ar prieita lenteles kaire krastine?
        if (i % 8 == 0)
        {
            printf("|");
        }
        // pasinaudojus biblioteka ctype.h
        // patikrinti ar zenklas spausdintinas
        if (isprint(i))
        {
            printf("%3d%5c",i,i);
        }
        else
        {
            printf("%3d <NS>",i);
        }

        // krastas
        printf("|");

        if (j % 8 == 0)
        {
            printf("\n");
        }

    }

    // linija
    for (int k = 1; k <= 73; k++)
    {
        printf("-");
    }
    printf("\n\"NS\" - NeSpausdinamas zenklas\n");
}

int main()
{
    // pavadinimas
    printf("ASCII simboliai nuo 0 iki 127\n");

    // bruksnys is lygybes zenklu
    for (int i = 1; i <= 73; i++)
    {
        printf("=");
    }
    printf("\n");

    // pirma lentele
    lentele4prat(0, 127);

    // pavadinimas
    printf("\n\n\nASCII simboliai nuo 128 iki 255\n");

    // bruksnys is lygybes zenklu
    for (int i = 1; i <= 73; i++)
    {
        printf("=");
    }
    printf("\n");

    // pirma lentele
    lentele4prat(128, 255);
}
