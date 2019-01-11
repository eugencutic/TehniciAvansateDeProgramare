#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("submultimi.in");
    ofstream out("submultimi.out");
    int n;

    in >> n;

    for (int i = 1; i <= (1<<n); i++)
    {
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                out << j + 1 << " ";
        out << endl;
    }

    return 0;
}
