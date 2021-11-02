// 
// Problem_10.c
//
// Created by Aurimas A. Nausedas on 9/20/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

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

    char d;     // Puodo vardas | The name of the pot
    long x = 0, // Pirmas puodas | First pot
         y = 0, // Antras puodas | Second pot
         z = 0; // Trecias puodas | Third pot

    printf("Monte Carlo random process - 3 pots \n\n");
    printf("Exact resutl: X = 3, Y = 2, Z = 1\n\n");
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
    if (r < 2. / 9) // x generacijos tikimybe | x generation probability
    {
        return 'x';
    }

    else if (r < (2. / 9) + (1. / 9)) // y generacijos tikimybe 1/9 | x generation probability 1/9
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
        switch(d)                   // Puodas X | Pot X
        {
            // ******************************************
            case 'x':
                x++;
                if (r < 1. / 9)        // P(X -> Y) = 1/9
                {
                    d = 'y';
                }

                                        // P(X -> Z) = 0
                                        // t.y. niekad taip nebus | that is it will never happen


                else if (r < (1. / 9) + (1. / 9))  // P(Death) = 1/9
                {
                    return;
                }
                break;              // P(Stays in X pot) = 7/9


            // ******************************************
            case 'y':               // Puodas Y | Pot Y
                y++;
                if (r < 2. / 9)       // P (Y -> X) = 2/9
                {
                    d = 'x';
                }

                else if (r < (2. / 9) + (1. / 9))  // P (Y -> Z) = 1/9
                {
                    d = 'z';
                }

                else if (r < (2. / 9) + (1. / 9) + (1. / 9))   // P(Death) = 1/9
                {
                    return;
                }
                break;
                            // P(Stays in Y pot) = 5/9

            // ******************************************
            case 'z':               // Puodas Z | Pot Z
                z++;
                                    // P (Z -> X) = 0
                if (r < 4. / 9)      // P (Z -> Y) = 0
                {
                    d = 'y';
                }

                else if (r < (4. / 9) + (4. / 9))   // P (Death) = 4 / 9
                {
                    return;
                }

                // P (Stays in Z pot) = 1/9
        }
    }
}

// ******************************************
double rnd()
{
    return (double)rand() / RAND_MAX;
}
