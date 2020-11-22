#include <iostream>

using namespace std;

int main()
{
  float y;
  int i;
  cout << "\t" << "*** Table ***" << endl << endl // pavadinimas
       << "x" << "\t" << "x^2" << "\t" << "x^3" << "\t" << "1/x" << endl; // nupiesti kriterijai
  for(i=1, y=1; i<=10 && y<=10; i++, y++) // for loopas dvejiems int
  {
    printf("%d\t%d\t%d\t%.2f\n", i, i*i, i*i*i, 1/y);
    //cout << i << "\t" << i*i << "\t" << i*i*i << "\t" << 1./i << endl;
  }
}
