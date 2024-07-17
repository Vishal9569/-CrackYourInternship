#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {

        if (prices[i] > prices[i - 1])
        {

            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> stock;
    stock = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(stock);

    return 0;
}