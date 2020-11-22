//
// Problem_10.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>
#include <stdlib.h>

char generation();
void wandering(char d, long& x, long& y, long& z);
double rnd();

// ******************************************
int main()
{
    int max = 1;
    long n = 0;
    int i,j;

    char d;     // Puodo vardas
    long x = 0, // Pirmas puodas
         y = 0, // Antras puodas
         z = 0; // Trecias puodas

    printf("Monte Karlo atsitiktinis procesas - 3 puodai \n\n");
    printf("Tikslus resultatas: X = 3, Y = 2, Z = 1\n\n");
    printf("    Iter.     X       Y       Z\n\n");

    for (j = 0; j < 21; j++)
    {
        for (i = 0; i < max; i++)
        {
            d = generation();
            n++;
            wandering(d, x, y, z);
        }

        printf("%8ld  %7.4f  %7.4f  %7.4f\n"
               ,n,
               (double)x / n,
               (double)y / n,
               (double)z / n);

        if (j != 0)
        {
            max *= 2;
        }
    }
    printf("\n");
    return 0;
}

// ******************************************
char generation()
{
    double r = rnd();
    if (r < 2. / 9) // x generacijos tikimybe
    {
        return 'x';
    }

    else if (r < (2. / 9) + (1. / 9)) // y generacijos tikimybe 1/9
    {
        return 'y';
    }

    else
    {
        return 'z';
    }
}


// ******************************************
void wandering(char d, long& x, long& y, long& z)
{
    double r;

    for(;;)
    {
        r = rnd();
        switch(d)                   // Puodas X
        {
            // ******************************************
            case 'x':
                x++;
                if (r < 1. / 9)        // P(X -> Y) = 1/9
                {
                    d = 'y';
                }

                                        // P(X -> Z) = 0
                                        // t.y. niekad taip nebus


                else if (r < (1. / 9) + (1. / 9))  // P(Zutis) = 1/9
                {
                    return;
                }
                break;              // P( lieka X puode) = 7/9


            // ******************************************
            case 'y':               // Puodas Y
                y++;
                if (r < 2. / 9)       // P (Y -> X) = 2/9
                {
                    d = 'x';
                }

                else if (r < (2. / 9) + (1. / 9))  // P (Y -> Z) = 1/9
                {
                    d = 'z';
                }

                else if (r < (2. / 9) + (1. / 9) + (1. / 9))   // P(Zutis) = 1/9
                {
                    return;
                }
                break;
                            // P( lieka Y puode) = 5/9

            // ******************************************
            case 'z':               // Puodas Z
                z++;
                                    // P (Z -> X) = 0
                if (r < 4. / 9)      // P (Z -> Y) = 0
                {
                    d = 'y';
                }

                else if (r < (4. / 9) + (4. / 9))   // P (Zutis) = 4 / 9
                {
                    return;
                }

                // P (Lieka Z puode) = 1/9
        }
    }
}

// ******************************************
double rnd()
{
    return (double)rand() / RAND_MAX;
}
