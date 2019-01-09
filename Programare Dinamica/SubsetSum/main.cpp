#include <iostream>

using namespace std;

bool isSubsetSum(int v[100], int n, int sum)
{
    if (n == 0 && sum != 0)
        return false;
    if (sum == 0)
        return true;
    if (v[n - 1] > sum)
        return isSubsetSum(v, n - 1, sum);
    return isSubsetSum(v, n - 1, sum - v[n - 1]) || isSubsetSum(v, n - 1, sum);
}

int main()
{
    int v[100], n;

    cin >> n;

    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int sum;
    cin >> sum;
    isSubsetSum(v, n, sum) ? cout << "True" : cout << "False";

    return 0;
}
