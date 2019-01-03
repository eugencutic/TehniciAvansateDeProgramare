#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int cmpOi(pair<int, int> oaie1, pair<int, int> oaie2)
{
    return oaie1.first < oaie2.first;
}

int main()
{
    ifstream in("lupu.in");
    ofstream out("lupu.out");

    priority_queue< pair<int, int> > pq;
    vector< pair<int, int> > oi;
    int lana;

    int n, x, l, d, a;
    in >> n >> x >> l;

    for(int i = 0; i < n; i++)
    {
        in >> d >> a;
        if(d < x)
        {
            oi.push_back( make_pair(d, a) );
        }
    }

    sort(oi.begin(), oi.end(), cmpOi);

    // Sectiunile pe distanta, nu pe numarul de oi!

    int primaSectiune = oi.size()%l;
    for(int i = 0; i < primaSectiune; i++)
    {
        pq.push(oi[i]);
    }

    lana += pq.top().second;
    pq.pop();


    for(int i = primaSectiune; i < oi.size(); i++)
    {
        while(i < i + l)
        {
            pq.push(oi[i]);
            i++;
        }
        lana += pq.top().second;
        pq.pop();
    }

    out << lana;

    return 0;
}
