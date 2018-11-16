#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class A
{
public:
    int x;
    int y;
};

struct sort_pred {
    bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second < right.second;
    }
}sortObj;

int cmp(const pair<int,int>& left, const pair<int,int>& right)
{
    if(left.second == right.second)
        return left.first < right.first;
    return left.second < right.second;
}

int cmpClasses(const A* left, const A* right)
{
    if(left->y == right->y)
        return left->x < right->x;
    return left->y < right->y;
}

int main()
{
    ifstream fin("intervale.in");

    vector<pair<int, int> > intervals;
    int n;
    fin>>n;
    for(int i = 0; i<n; i++)
    {
        int s,t;
        fin>>s>>t;
        intervals.push_back(make_pair(s,t));
    }
    sort(intervals.begin(), intervals.end(), cmp);

    if(intervals.empty())
        return 0;

    pair<int, int> currInt = intervals[0];
    cout<<currInt.first<<" "<<currInt.second<<endl;
    for(int i = 0; i<n; i++)
    {
        if(intervals[i].first > currInt.second)
        {
            currInt = intervals[i];
            cout<<currInt.first<<" "<<currInt.second<<endl;
        }
    }
    fin.close();

    vector<A*> objects;
    for(int i=0; i<n; i++)
    {
        A* obj = new A();
        cin>> obj->x >> obj->y;
        objects.push_back(obj);
    }

    sort(objects.begin(), objects.end(), cmpClasses);
    for(int i=0; i<n; i++)
    {
        cout<<objects[i]->x << " " << objects[i]->y << endl;
    }

    return 0;
}
