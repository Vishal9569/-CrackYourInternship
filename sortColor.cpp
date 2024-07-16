#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums)
{
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = 0 + i; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> nums = {2, 3, 4, 5, 6, 7, 3, 2, 8};

    sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
}
