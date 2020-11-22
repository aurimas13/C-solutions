#include <iostream>
#include <bitset>

using namespace std;

int main()
{
  int i, n, x, y;

  for(x=0; x<=32; x++) // breziama pirma linija
  {
    cout << "_";
  }

  cout << endl;

  cout << "   " << "** Numerical systems **" << endl << endl; // nupiesiamas pavadinimas
  cout << "\"10\" \t \"8\" \t \"16\" \t \"2\"" << endl; // nupiesiami identifikatoriai

  for(y=0; y<=29; y++) // piesiama antra linija
  {
    cout << "–";
  }

  cout << endl;

  for(i=0, n=0; i<=15 && n<=15; i++, n++) // for loop'as skirtas apskaiciuoti visas galimas 15-a skaiciu
  {
  printf(" %d \t  %o \t  %X \t", i, i, i); // if loop'as dvejatainei sistemai
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
