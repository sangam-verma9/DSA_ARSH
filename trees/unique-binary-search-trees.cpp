#include <bits/stdc++.h>
using namespace std;
//******* brute force approach (copyed from leetcode) ********
class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += numTrees(i - 1) * numTrees(n - i);
        }
        return ans;
    }
};
//********* dp solution memoziation *********
class Solution
{
public:
    int solvemem(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += solvemem(i - 1, dp) * solvemem(n - i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return solvemem(n, dp);
    }
};
//************ tabulation method ******
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};
//*********

/*Observing the series we get above for various numTrees(n),
we see that it is infact a series of popular numbers known as Catalan Numbers. */

class Solution
{
public:
    long ncr(int n, int r)
    {
        long ans = 1;
        for (int i = 0; i < r; i++)
        {
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    }
    int numTrees(int n)
    {
        return ncr(2 * n, n) / (n + 1);
    }
};
//************
int main()
{

    return 0;
}