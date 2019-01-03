#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int v[3000000];

int sdo(int left, int right, int k, int v[])
{
   cout << left << " " << right << " " << k << "\n";

    if(left == right)
        return v[left];

    int mid = (left + right) / 2;
    int val = v[mid];


    vector<int> st, dr;
    for(int i = left; i <= right; i++)
    {
        if(v[i] < val)
            st.push_back(v[i]);
        else if(v[i] > val)
            dr.push_back(v[i]);
    }

    if(st.size() < k && k < (right - left + 1) - dr.size() + 1)
        return val;

    for(int i = 0; i < st.size(); i++)
        v[i + left] = st[i];
    for(int i = 0; i < dr.size(); i++)
        v[right - i] = dr[i];

    if(k <= st.size())
        return sdo(left, left + st.size() - 1, k, v);
    else
        return sdo(right - dr.size() + 1, right, k - (right - left + 1 - dr.size()), v);
}

int main()
{
    ifstream in("sdo.in");
    ofstream out("sdo.out");

    int n, k;
    in >> n >> k;


    for(int i = 0; i < n; i++)
        in >> v[i];

    out << sdo(0, n - 1, k, v);
    return 0;
}
