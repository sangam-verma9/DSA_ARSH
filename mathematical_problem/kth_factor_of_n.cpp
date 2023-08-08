#include <bits/stdc++.h>
using namespace std;
//********* brute force approach
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> fac;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                fac.push_back(i);
            }
        }
        int size = fac.size();
        if (size < k)
            return -1;
        return fac[k - 1];
    }
};
//********* good approach copyed from leetcode
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                k--;
                if (k == 0)
                    return i;
            }
        }
        if (k == 1)
            return n;
        return -1;
    }
};
//********** optimized approach
int kthFactor(int n, int k)
{
    int d = 1;
    for (; d * d <= n; ++d)
        if (n % d == 0 && --k == 0)
            return d;
    for (d = d - 1; d >= 1; --d)
    {
        if (d * d == n)
            continue;
        if (n % d == 0 && --k == 0)
            return n / d;
    }
    return -1;
}
//***********
int main()
{

    return 0;
}