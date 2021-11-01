// Problem_3.cpp
//
// Created by Aurimas A. Nausedas on 9/17/19.
// Updated by Aurimas A. Nausedas on 10/31/21.

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
  int i, n, x, y;

  for(x=0; x<=32; x++) // breziama pirma linija | first line drawn
  {
    cout << "_";
  }

  cout << endl;

  cout << "   " << "** Numerical systems **" << endl << endl; // nupiesiamas pavadinimas | the name is drawn
  cout << "\"10\" \t \"8\" \t \"16\" \t \"2\"" << endl; // nupiesiami identifikatoriai | identificators are drawn

  for(y=0; y<=29; y++) // piesiama antra linija | the second line is drawn
  {
    cout << "–";
  }

  cout << endl;

  for(i=0, n=0; i<=15 && n<=15; i++, n++) // for loop'as skirtas apskaiciuoti visas galimas 15-a skaiciu | fdor loop to calcualte all 15 numbers
  {
  printf(" %d \t  %o \t  %X \t", i, i, i); // if loop'as dvejatainei sistemai | if loop for binary system
  if (n<=1)
  {
  cout << "  " << bitset<1>(n) << endl;;
  }
  else if (n>=2 && n<=3)
  {
  cout << "  " << bitset<2>(n) << endl;
  }
  else if (n>=4 && n<=7)
  {
  cout << "  " << bitset<3>(n) << endl;
  }
  else
  {
  cout << "  " << bitset<4>(n) << endl;
  }
  }
}
