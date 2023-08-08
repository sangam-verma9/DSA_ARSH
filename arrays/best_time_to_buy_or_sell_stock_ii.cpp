#include <bits/stdc++.h>
using namespace std;
//******** simple but not to do
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprof = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
            {
                maxprof += prices[i + 1] - prices[i];
            }
        }
        return maxprof;
    }
};
//****** recursive approach
class Solution
{
public:
    int solve(int ind, int buy, vector<int> &prices)
    {
        if (ind == prices.size())
            return 0;
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[ind] + solve(ind + 1, 0, prices);
            int skipkaro = 0 + solve(ind + 1, 1, prices);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[ind] + solve(ind + 1, 1, prices);
            int skipkaro = 0 + solve(ind + 1, 0, prices);
            profit = max(sellkaro, skipkaro);
        }
        return profit;
    }
    int maxProfit(vector<int> &prices)
    {

        return solve(0, 1, prices);
    }
};
//********** dp solution memozation
class Solution
{
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[ind] + solve(ind + 1, 0, prices, dp);
            int skipkaro = 0 + solve(ind + 1, 1, prices, dp);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[ind] + solve(ind + 1, 1, prices, dp);
            int skipkaro = 0 + solve(ind + 1, 0, prices, dp);
            profit = max(sellkaro, skipkaro);
        }
        dp[ind][buy] = profit;
        return dp[ind][buy];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
//*************

int main()
{

    return 0;
}