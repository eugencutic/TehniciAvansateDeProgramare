#include <iostream>
#include <fstream>

using namespace std;

ifstream in("combinari.in");
ofstream out("combinari.out");

void bkt(int v[18], int n, int k, int p)
{
    for (int i = 1; i <= n; i++)
    {
        v[p] = i;
        if (p > 0 && v[p] > v[p - 1])
        {
            if (p == k - 1)
            {
                for (int j = 0; j < k; j++)
                    out << v[j] << " ";
                out << endl;
            }
            else
                bkt(v, n, k, p + 1);
        }
        else if(p == 0)
            bkt(v, n, k, p + 1);
    }
}

int main()
{
    int n, v[18] = {0}, k;
    in >> n >> k;
    bkt(v, n, k, 0);
    return 0;
}
