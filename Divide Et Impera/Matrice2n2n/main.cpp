#include <iostream>
#include <fstream>

using namespace std;

void genereazaMatrice(int a[100][100], int n, int linie, int col, int k)
{
    if(linie >= n || linie < 0 || col >= n || col < 0)
        return;
    a[linie][col] = k;

    int k1 = k+1, k2 = k+2, k3 = k+3;
    genereazaMatrice(a, n, linie+1, col-1, k1);
    genereazaMatrice(a, n, linie, col-1, k2);
    genereazaMatrice(a, n, linie+1, col, k3);
}

int main()
{
    ifstream in("matrice.in");

    int n;
    in >> n;
    n = 1 << n;

    int a[100][100];

    int linie = 0, col = n-1, k = 1;
    genereazaMatrice(a, n, linie, col, k);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
