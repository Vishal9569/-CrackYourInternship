#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int Rightsum = 0;

    for (int i = 0; i < k; ++i)
    {
        Rightsum += cardPoints[i];
    }

    int maxi = Rightsum;
    int totalPoints = Rightsum;

    for (int i = 0; i < k; ++i)
    {
        totalPoints += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
        maxi = max(maxi, totalPoints);
    }

    return maxi;
}

int main()
{
    vector<int> point;
    point = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScore(point, k);

    return 0;
}