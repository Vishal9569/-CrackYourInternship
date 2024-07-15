#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minprice = prices[0];
    int maxprofit = 0;
    int profit;
    for (int index = 0; index < prices.size(); index++)
    {
        // Calculate profit if selling at prices[index]
        int profit = prices[index] - minprice;

        // Update maxprofit if current profit is higher
        if (profit > maxprofit)
        {
            maxprofit = profit;
        }

        // Update minPrice if current price is lower
        if (prices[index] < minprice)
        {
            minprice = prices[index];
        }
    }

    return maxprofit;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 2};

    cout << maxProfit(arr);

    return 0;
}
