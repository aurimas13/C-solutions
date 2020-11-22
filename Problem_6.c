//  Problem_6.c
//
//  Created by Aurimas Nausedas on 9/19/19.
//

#include <stdio.h>
#include <math.h>

// declaruoju pagalbine funkcijas
double fk(double t,double x);
void step(double *pt, double *px, double h);

// ********************************************
int main()
{
    double t = 0, x = 1, h = 0.1;

    printf("Lygties dx/dt = -x sprendimas, kai x(0) = %.2lf\n\n",x);
    printf("%-4s\t%-6s\t%-6s\n\n","t","x","exp(-t)");

    // output loop ----------------------------
    for (int i = 0; i <= 10; i++)
    {
        printf("%-4.1lf\t%-.4lf\t%-.4lf\n",t,x,exp(-t));
        step(&t, &x, h); // Integravimas
    }
    printf("\n");
    return 0;
}

// ********************************************
void step(double *pt, double *px, double h)
{
    // paskaiciuoju px_tilde
    double pxt = *px + h * fk(*pt,*px);

    // paskaiciuju t sekanciame taske
    double ptt = *pt + h;

    // perrasau vertes adresais px and pt
    *px = *px + (h / 2) * (fk(*pt,*px) + fk(ptt,pxt));
    *pt = ptt;

}


// ********************************************
double fk(double t,double x)
{
    return -x;
}
// ********************************************
