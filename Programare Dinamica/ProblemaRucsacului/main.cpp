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

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= G; j++)
            d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + p[i]);
    }

    out << d[N][G];
    return 0;
}
