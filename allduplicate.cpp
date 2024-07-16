#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> index;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            index.push_back(nums[i]);
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 2, 4, 5, 7, 8};

    vector<int> duplicates = findDuplicates(arr);

    for (int i = 0; i < duplicates.size(); i++)
    {
        cout << duplicates[i] << " ";
    }
}