#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> ele = {4, 5, 6, 7, 0, 1, 2};

    cout << " index of target : " << search(ele, 0);

    return 0;
}
