#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("monede.in");
    ofstream out("monede.out");

    int n, suma;
    in >> n;
    int monede[n];

    for(int i = 0; i < n; i++)
        in >> monede[i];

    in >> suma;
    out << "Schimb " << suma << ":\n";

    for(int i = n-1; i >= 0; i--)
    {
        if(suma/(monede[i]))
        {
            out << suma/(monede[i]) << " monede de " << monede[i] << endl;
            suma = suma - (suma/(monede[i])) * (monede[i]);
        }
    }
    return 0;
}
