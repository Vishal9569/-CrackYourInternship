#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int maxi = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        int width = right - left;
        int minHeight = min(height[right], height[left]);
        int currentmax = width * minHeight;
        maxi = max(maxi, currentmax);

        if (height[left] < height[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return maxi;
}

int main()
{

    vector<int> height;
    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height);

    return 0;
}