#include <iostream>
#include <fstream>

using namespace std;

int aflaCadran(int x, int y, int n)
{
    if(x <= (1<<(n-1)))
    {
        if(y <= (1<<(n-1)))
            return 1;
        return 2;
    }

    if(y <= (1<<(n-1)))
        return 3;
    return 4;

}

int divide(int n, int x, int y)
{
    if(n == 0)
        return 1;

    int cadran = aflaCadran(x, y, n);
    if(cadran == 1)
    {
        return divide(n-1, x, y);
    }
    if(cadran == 2)
    {
        return (1 << (2*n - 2)) + divide(n-1, x, y - (1<<(n-1)));
    }
    if(cadran == 3)
    {
        return 2*(1 << (2*n - 2)) + divide(n-1, x - (1 << (n - 1)), y);
    }
    if(cadran == 4)
    {
        return 3*(1 << (2*n - 2)) + divide(n-1, x - (1 << (n - 1)), y - (1 << (n - 1)));
    }
}

int main()
{
    ifstream in("z.in");
    ofstream out("z.out");

    int x, y, n, k;

    in >> n >> k;
    for(int i = 0; i < k; i++)
    {
        in >> x >> y;
        out << divide(n, x, y) << endl;
    }
    return 0;
}
