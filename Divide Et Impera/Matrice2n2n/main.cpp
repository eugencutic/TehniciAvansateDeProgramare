#include <iostream>
#include <fstream>

using namespace std;

void genereazaMatrice(int a[100][100], int n, int x, int y, int k)
{
    if(n == 0)
        return;

    if(n == 1)
    {
        a[x][y+1] = k;
        a[x+1][y] = k + 1;
        a[x][y] = k + 2;
        a[x+1][y+1] = k + 3;
    }

    genereazaMatrice(a, n-1, x, y + (1<<(n-1)), k);
    genereazaMatrice(a, n-1, x + (1<<(n-1)), y, k + (1<<(2*n-2)));
    genereazaMatrice(a, n-1, x, y, k + 2*(1<<(2*n-2)));
    genereazaMatrice(a, n-1, x + (1<<(n-1)), y + (1<<(n-1)), k + 3 * (1<<(2*n-2)));
}

int main()
{
    ifstream in("matrice.in");

    int n;
    in >> n;
    //n = 1 << n;

    int a[100][100];

    //int linie = 0, col = n-1, k = 1;
    genereazaMatrice(a, n, 0, 0, 1);

    for(int i = 0; i < (1<<n); i++)
    {
        for(int j = 0; j < (1<<n); j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
