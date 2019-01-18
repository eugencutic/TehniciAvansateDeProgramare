#include <iostream>
#include <fstream>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");

int aflaCadran(int k, int n)
{
    int limCadran[4];
    limCadran[1] = (1 << (n - 2));
    limCadran[2] = 3 * (1 << (2 * n - 2));
    limCadran[3] = (1 << (n - 1));

    if (k <= limCadran[1])
        return 1;
    if (k <= limCadran[3])
        return 3;
    if (k <= limCadran[2])
        return 2;
    return 4;
}

int aflaCoordonate(int n, int k)
{

    int cadran = aflaCadran(k, n);

    if (cadran == 1)
        aflaCoordonate(n - 2, k);
    if (cadran == 2)
        aflaCoordonate(n - 1, k);

}

int main()
{



    in.close();
    out.close();
    return 0;
}
