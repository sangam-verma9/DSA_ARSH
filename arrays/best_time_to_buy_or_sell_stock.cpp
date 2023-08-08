#include <bits/stdc++.h>
using namespace std;
//******* my approach pointer approach SC:O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            int ans1 = prices[i] - buy;
            if (ans1 > ans)
                ans = ans1;
        }
        return ans;
    }
};

//********** first approach (?)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX;
        int ans = 0;
        int pist = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < mini)
            {
                mini = prices[i];
            }
            pist = prices[i] - mini;
            if (ans < pist)
            {
                ans = pist;
            }
        }
        return ans;
    }
};
//***********
int main()
{

    return 0;
}