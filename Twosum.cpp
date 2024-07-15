#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> index;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                index.push_back(i);
                index.push_back(j);
            }
        }
    }

    return index;
}
int main()
{
    vector<int> arr = {2, 4, 5, 6, 8, 1};
    int target = 3;
    vector<int> index = twoSum(arr, target);

    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
}