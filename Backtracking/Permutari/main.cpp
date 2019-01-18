#include <iostream>
#include <fstream>

using namespace std;

ifstream in("permutari.in");
ofstream out("permutari.out");

bool contains(int v[8], int n, int el)
{
    bool found = false;
    for (int i = 0; i < n; i++)
        if (v[i] == el)
            found = true;
    return found;
}

void bkt(int sol[8], int n, int poz)
{
    for (int i = 1; i <= n; i++)
    {
        sol[poz] = i;
        if(poz > 0 && !contains(sol, poz, sol[poz]))
        {
            if (poz == n - 1)
            {
                for (int j = 0; j < n; j++)
                    out << sol[j] << " ";
                out << endl;
            }
            else
                bkt(sol, n, poz + 1);
        }
        else
            if (poz == 0)
                bkt(sol, n, poz + 1);
    }
}

int main()
{
    int n, sol[8];
    in >> n;
    bkt(sol, n, 0);
    return 0;
}
