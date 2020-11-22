//
// Problem_12.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>
#include <math.h>

// declaruoju pagalbine funkcijas
void fk(double t, const double *a, double *f);
void step(double *t, double *a,double *f, double h, int n);
void dotline(int z);

// ********************************************
int main()
{
    // laikas ir zingsnis
    double t = 0, h = 0.1;

    //masyvai
    const int n = 4; // masyvo ilgis
    // inicijuoju du statinius masyvus
    // a - x ir y vertems
    // f - f1(x,y,t) ir f2(x,y,t) vertems laikyti
    // f1 = -y; f2 = x


    double a[n] = {1,0},
           f[n];

    printf(" *** Runges ir Kutos Metodas: Masyvai ***\n\n");
    printf("   da[0]/dt = -a[1], da[1]/dt = a[0]\n\n");
    printf("      t = 0: a[0] = 1, a[1] = 0\n\n");
    printf("t      a[0]      cos(t)    a[1]      sin(t)\n");

    dotline(43);

    // output loop ----------------------------
    for (int i = 0; i <= 10; i++)
    {
        printf("%-.1lf    %-.4lf    %-.4lf    %-.4lf    %-.4lf\n",
               t,a[0],cos(t),a[1],sin(t));

        step(&t, a, f, h, n); // Integravimas
    }
    printf("\n");
    return 0;
}

// ********************************************
void step(double *t, double *a,double *f, double h, int n)
{
    //printf("%.2f %.2f\n",f[0],f[1]);
    // atnaujinu fk masyve saugomas vertes
    fk(*t, a, f);

    //printf("%.2f %.2f\n",f[0],f[1]);

    // iniciuoju laikina masyva saugoti a_tilde vertems
    double at[n];

    // taip pat laikina masyva fk(tt,at) vertems saugoti
    double ft[n];

    // paskaiciuoju a_tilde
    for (int i = 0; i < n; i++)
    {
        at[i] = a[i] + h * f[i];
    }

    //printf("\t%.2f %.2f\n",a[0],a[1]);
    //printf("\t%.2f %.2f\n",at[0],at[1]);

    // paskaiciuju t sekanciame taske
    double tt = *t + h;

    // paskaiciuoju fk vertems naujuose taskuose
    fk(tt, at, ft);
    //printf("%.2f %.2f\n\n",ft[0],ft[1]);

    // perrasau vertes adresais a and t
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
// linijai greit nusipiesti
void dotline(int z)
{
    for (int i = 1; i <= z; i++)
    {
        printf("-");
    }
    printf("\n");
}
