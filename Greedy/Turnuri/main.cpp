#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct cub
{
    int latura;
    int culoare;
    int indice;
};

int cmpCub(cub a, cub b)
{
    return (a.latura > b.latura);
}

int main()
{
    ifstream in("turn.in");

    vector<cub> cuburi;
    cub x;
    int n, p, lat, cul;
    in >> n >> p;
    for(int i = 0; i < n; i++)
    {
        in >> lat >> cul;
        x.culoare = cul;
        x.latura = lat;
        x.indice = i;
        cuburi.push_back(x);

    }

    sort(cuburi.begin(), cuburi.end(), cmpCub);

    int ulCul = cuburi[0].culoare, inaltime = 0;
    vector<int> turn;

    turn.push_back(cuburi[0].indice + 1);
    inaltime += cuburi[0].latura;
    for(int i = 1; i < n; i++)
    {
        if(cuburi[i].culoare != ulCul)
        {
            turn.push_back(cuburi[i].indice + 1);
            inaltime += cuburi[i].latura;
            ulCul = cuburi[i].culoare;
        }
    }

    cout<<inaltime<<endl;
    for(int i = 0; i < turn.size(); i++)
    {
        cout << turn[i] <<  " ";
    }

    return 0;
}
