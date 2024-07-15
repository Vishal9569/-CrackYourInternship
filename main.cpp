#include <iostream>
#include <vector>
using namespace std;

int removeAllduplicate(vector<int> &nums)
{
    int index = 1;
    if (nums.size() == 0)
    {
        return 0;
    }
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {1, 1, 0, 2, 2, 3, 4, 4};
    cout << removeAllduplicate(nums);
    return 0;
}
