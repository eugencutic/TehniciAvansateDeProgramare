#include <iostream>
#include <fstream>

using namespace std;

int d[5005][10005], w[5005], p[5005];

int main()
{
    ifstream in("rucsac.in");
    ofstream out("rucsac.out");

    int N, G;
    in >> N >> G;

    for(int i = 1; i <= N; i++)
        in >> w[i] >> p[i];

    for (int i = 0; i <= G; i++)
        d[0][i] = -1000000000;

    d[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= G; j++)
            if (j >= w[i])
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + p[i]);
            else
                d[i][j] = d[i - 1][j];
    }

    int rezultat = 0;
    for (int i = 1; i <= G; i++)
        if (d[N][i] > rezultat)
            rezultat = d[N][i];
    out << rezultat;
    return 0;
}
