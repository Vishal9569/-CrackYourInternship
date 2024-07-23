#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(long long a[], long long b[], int n, long long k)
{

    sort(a, a + n);
    sort(b, b + n, std::greater<long long>()); // Sort b in descending order

    for (int i = 0; i < n; ++i)
    {
        if (a[i] + b[i] < k)
        {
            return false; // If any pair sum is less than k, return false
        }
    }
    return true; // If all pairs satisfy the condition, return true
}

int main()
{

    long long a[] = {2, 1, 3};
    long long b[] = {7, 8, 9};

    cout << isPossible(a, b, 3, 10);

    return 0;
}