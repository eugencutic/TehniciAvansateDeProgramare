#include <iostream>
#include <fstream>

using namespace std;

///for full 0 initialization
long long d[1005][1005][2];

int main()
{
    ifstream in("pm.in");
    ofstream out("pm.out");

    int x, y;
    in >> x >> y;

    ///Initializare

    d[1][1][1] = 1;
    d[1][0][0] = 1;

    ///Recurenta
    for (int i = 2; i <= x + y; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            d[i][j][0] = d[i - 1][j][1];
            if (j > 0)
                d[i][j][1] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1];
        }
    }

    out << d[x + y][x][1] + d[x + y][x][0];
    in.close();
    out.close();
    return 0;
}
