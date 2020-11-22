//
//  main.cpp
//
// Problem_22.cpp
//
//  Created by Aurimas Nausedas on 10/15/19.

#include <iostream>
#include <iomanip> // kad galeciau kontroliuoti formatavima
using namespace std;


int main()
{
    // atspausdinu lentele pavadima,
    // kiek supratau centruoti teksta su C elegantiskai neiseina
    cout << "\t\t  *** Daugybos lentele ***\n\n";

    // pradedu eiluciu cikla
    for (int i = 1; i < 11; i++)
    {
        // pradedu stulpeliu cikla
        for (int j = 1; j < 11; j++)
        {
            // paskaiciuoju sandauga (product)
            int p = i * j;

            // atpazistu pirma stulpeli: sandauga sutampa su
            // stulpelio numeriu

            cout << setw( 4 ) << p;
            if (p == i) cout <<"|";
        }

        cout << '\n';

        if (i == 1) cout << "-----------------------------------------\n";
    }
    cout << '\n';
}
