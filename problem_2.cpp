// Problem_2.cpp
//
// Created by Aurimas Nausedas on 9/17/19.
// Updated by Aurimas Nausedas on 10/31/21.

#include <iostream>

using namespace std;

int main()
{
  float y;
  int i;
  cout << "\t" << "*** Table ***" << endl << endl // pavadinimas | name
       << "x" << "\t" << "x^2" << "\t" << "x^3" << "\t" << "1/x" << endl; // nupiesti kriterijai | drawn requirements
  for(i=1, y=1; i<=10 && y<=10; i++, y++) // for loopas dvejiems int
  {
    printf("%d\t%d\t%d\t%.2f\n", i, i*i, i*i*i, 1/y);
    //cout << i << "\t" << i*i << "\t" << i*i*i << "\t" << 1./i << endl;
  }
}
