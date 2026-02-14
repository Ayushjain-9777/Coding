// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
    vector<int> prices;
    int profit;

    prices = {7,1,5,3,6,4};
    profit = maxProfit(prices);
    cout << profit << endl;

    prices = {7,6,4,3,1};
    profit = maxProfit(prices);
    cout << profit << endl;

    return 0;
}

int maxProfit(vector<int>& prices)
{
    int buy = INT_MAX;
    int profit = 0;

    for(int i=0; i<prices.size(); ++i)
    {
        if(prices[i]<buy)
            buy = prices[i];
        else if(prices[i]-buy > profit)
        {
            profit = prices[i] - buy;
        }
    }

    return profit;
}