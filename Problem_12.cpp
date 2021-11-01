//
// Problem_12.c
//
// Created by Aurimas A. Nausedas on 9/20/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <stdio.h>
#include <math.h>

// declaruoju pagalbine funkcijas | helper function declaration
void fk(double t, const double *a, double *f);
void step(double *t, double *a,double *f, double h, int n);
void dotline(int z);

// ********************************************
int main()
{
    // laikas ir zingsnis | Time and step
    double t = 0, h = 0.1;

    //masyvai
    const int n = 4; // masyvo ilgis | array length
    // inicijuoju du statinius masyvus | initialising du static arrays
    // a - x ir y vertems | for a-x and y values
    // f - f1(x,y,t) ir f2(x,y,t) vertems laikyti | to hold f - f1(x,y,t) and f2(x,y,t) values
    // f1 = -y; f2 = x


    double a[n] = {1,0},
           f[n];

    printf(" *** Runga and Kuta Method: Arrays ***\n\n");
    printf("   da[0]/dt = -a[1], da[1]/dt = a[0]\n\n");
    printf("      t = 0: a[0] = 1, a[1] = 0\n\n");
    printf("t      a[0]      cos(t)    a[1]      sin(t)\n");

    dotline(43);

    // output loop ----------------------------
    for (int i = 0; i <= 10; i++)
    {
        printf("%-.1lf    %-.4lf    %-.4lf    %-.4lf    %-.4lf\n",
               t,a[0],cos(t),a[1],sin(t));

        step(&t, a, f, h, n); // Integravimas | Integration
    }
    printf("\n");
    return 0;
}

// ********************************************
void step(double *t, double *a,double *f, double h, int n)
{
    // printf("%.2f %.2f\n",f[0],f[1]);
    // atnaujinu fk masyve saugomas vertes | updating the values stored in the fk array
    fk(*t, a, f);

    //printf("%.2f %.2f\n",f[0],f[1]);

    // iniciuoju laikina masyva saugoti a_tilde vertems | initiate a temporary array to store a_tilde values
    double at[n];

    // taip pat laikina masyva fk(tt,at) vertems saugoti | also a temporary array for storing fk (tt, at) values
    double ft[n];

    // paskaiciuoju a_tilde | calculating a_tilde
    for (int i = 0; i < n; i++)
    {
        at[i] = a[i] + h * f[i];
    }

    //printf("\t%.2f %.2f\n",a[0],a[1]);
    //printf("\t%.2f %.2f\n",at[0],at[1]);

    // paskaiciuju t sekanciame taske | count t at the next point
    double tt = *t + h;

    // paskaiciuoju fk vertems naujuose taskuose | calculate the fk values in the new points
    fk(tt, at, ft); 
    //printf("%.2f %.2f\n\n",ft[0],ft[1]);

    // perrasau vertes adresais a and t | rewrite values ​​to addresses a and t
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + (h / 2) * (f[i] + ft[i]);
    }

    *t = tt;

}

// ********************************************
void fk(double t, const double *a, double *f)
{
    f[0] = -a[1];
    f[1] = a[0];
}
// ********************************************
// linijai greit nusipiesti | to draw line quickly
void dotline(int z) 
{
    for (int i = 1; i <= z; i++)
    {
        printf("-");
    }
    printf("\n");
}
