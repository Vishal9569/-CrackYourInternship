#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    if (n < m)
        return 0;

    sort(a.begin(), a.end());

    long long mindiff = a[n - 1] - a[0];

    for (long long i = 0; i < a.size() - m + 1; i++)
    {

        if (mindiff < a[i + m - 1] - a[i])
        {
            mindiff = mindiff;
        }

        else
        {
            mindiff = a[i + m - 1] - a[i];
        }
    }
    return mindiff;
}

int main()
{

    vector<long long> value = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    int n = 8;

    cout << findMinDiff(value, n, m);

    return 0;
}