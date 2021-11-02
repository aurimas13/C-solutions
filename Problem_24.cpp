//
// Problem_24.cpp
// 
// Created by Aurimas A. Nausedas on 10/20/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;
namespace myns
{
    int w = 12;
}
//---------------------------------------------------

template <class T>
void show(T x);

//---------------------------------------------------
int main()
{

    cout << setfill('_') << setw(myns::w) <<"x";
    cout << setw(myns::w) <<"x^2";
    cout << setw(myns::w) <<"x^3";
    cout << setw(myns::w) <<"100/x"<<endl;
    cout << setfill(' ');
    cout << '\n';


    show(7);
    show(7.);
    show(3);
    show(3.);
    cout << '\n';

    return 0;
}

//---------------------------------------------------
template <class T>
void show(T x)
{
    T mult = x;
    for (int i=0; i < 3; i++)
    {
        cout << setw(myns::w) << mult;
        mult *= x;
    }
    cout <<setw(myns::w) << 100/x << '\n';
}
