//
// Problem_11.c
//
// Created by Aurimas Nausedas on 9/20/19.
// Update by Aurimas Nausedas on 10/31/21.

#include <stdio.h>

// deklaruoju funkcija | function declaration
int fibo(int n);

int main()
{
    // naudoju for cikla spaudinimui, bet ne Fibonacio skaiciu skaiciavimui I use for cycle but not for counting Fibonacci numbers
    for (int n = 0; n < 10; n++)
    {
        int r = fibo(n);
        //printf("%d-as The number of Fibonacci rows is %d\n",n,r);
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
