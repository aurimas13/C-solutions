//
// Problem_4.c
//
// Created by Aurimas A. Nausedas on 9/17/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <stdio.h>
#include <ctype.h>

void lentele4prat(int start, int end)
{
    // linija | line
    for (int k = 1; k <= 73; k++)
    {
        printf("-");
    }
    printf("\n");

    // Lentele
    for (int i = start; i <= end; i ++)
    {
        int j = i + 1;


        // ar prieita lenteles kaire krastine? | have the tables been accessed on the left bank?
        if (i % 8 == 0)
        {
            printf("|");
        }
        // pasinaudojus biblioteka ctype.h | using the library ctype.h
        // patikrinti ar zenklas spausdintinas | check if the mark is printable
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
    printf("\n\"NS\" - Unprintable sign\n");
}

int main()
{
    // pavadinimas | name
    printf("ASCII symbols from 0 to 127\n");

    // bruksnys is lygybes zenklu | the hyphen of signs of equality
    for (int i = 1; i <= 73; i++)
    {
        printf("=");
    }
    printf("\n");

    // pirma lentele | first table
    lentele4prat(0, 127);

    // pavadinimas | name
    printf("\n\n\ASCII symbols from 128 to 255\n");

    // bruksnys is lygybes zenklu | the hyphen of signs of equality
    for (int i = 1; i <= 73; i++)
    {
        printf("=");
    }
    printf("\n");

    // pirma lentele | first table
    lentele4prat(128, 255);
}
