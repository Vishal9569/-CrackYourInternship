#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPair(int n, int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = 1;

    while (start < n && end < n)
    {
        int diff = arr[end] - arr[start];

        if (diff == x && start != end)
        {
            return 1;
        }
        else if (diff < x)
        {
            end++;
        }
        else
        {
            start++;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {5, 20, 3, 2, 5, 80};

    cout << findPair(6, 78, arr);

    return 0;
}