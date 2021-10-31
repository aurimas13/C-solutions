// Problem_1.cpp
//
// Created by Aurimas Nausedas on 9/17/19.
// Updated by Aurimas Nausedas on 10/31/21.

#include <iostream>
#include <ncurses.h>
#include <curses.h>

using namespace std;

int main()
{
    //printf("%c",196);
    cout<<"largest float=="<<numeric_limits<float>::max()
        <<",char is signed=="<<numeric_limits<char>::is_signed<<"\n";
    int i, j;
    printf("| \n");
    printf("| \n");
    int a = 5, b = 10;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    *p1 = 10;
    p1 = p2;
    *p1 = 20;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    int number = 88;
    int * pNumber;
    pNumber = &number;
    cout << pNumber << endl;
    cout << *pNumber << endl;
    int * pAnother = &number;
    *pNumber = 99;
    cout << *pNumber << endl;
    printf("\n–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
    cout << "Multiplication table" << endl; // multiplikacijos lentele
    printf("\n–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
    for(i=1; i<=10; i++)  {
        for(j=1; j<=10; j++)  {
          printf("%d \t", i*j);
        }
        cout << endl;
      }
    //for(i=1; i<=10; i++)  { // pirmas for loop'as, row | first row for loop
      //  for (j=1; j<=10; j++) { // antras for loop'as, column | second column for loop
        //cout << j*i << "\t";
        //}
    //cout << endl;
    //}
}
