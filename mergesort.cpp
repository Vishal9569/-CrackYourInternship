#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Last element in nums1's initial part
    int j = n - 1;     // Last element in nums2
    int k = m + n - 1; // Last position in nums1

    // Merge nums1 and nums2 from the end
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, add them to nums1
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {2, 3, 4, 5, 0, 0};
    vector<int> nums2 = {2, 6, 1};
    int m = 4;            // Number of initialized elements in nums1
    int n = nums2.size(); // Number of elements in nums2

    merge(nums1, m, nums2, n);

    // Print the merged array
    sort(nums1.begin(), nums1.end());
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
