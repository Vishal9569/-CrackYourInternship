#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    vector<int> nonZeroes;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nonZeroes.push_back(nums[i]);
        }
        else
        {
            count++;
        }
    }

    for (int i = 0; i < nonZeroes.size(); i++)
    {

        nums[i] = nonZeroes[i];
    }
    for (int i = nonZeroes.size(); i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}
int main()
{
    vector<int> nums = {1, 0, 0, 2, 2, 3, 4, 4};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }

    return 0;
}
