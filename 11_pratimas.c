///
// Problem_11.c
//
//  Created by Aurimas Nausedas on 9/20/19.

#include <stdio.h>

// deklaruoju funkcija
int fibo(int n);

int main()
{
    // naudoju for cikla spaudinimui, bet ne Fibonacio skaiciu skaiciavimui
    for (int n = 0; n < 10; n++)
    {
        int r = fibo(n);
        //printf("%d-as Fibonacio eiles skaicius yra %d\n",n,r);
        printf("%d, ",r);
    }

    printf("\n\n");
    return 0;

}

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        int z = fibo(n-1) + fibo(n-2);
        return z;
    }
}
