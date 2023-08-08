#include <bits/stdc++.h>
using namespace std;
//*********** first think (brute force)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
};
//*********** second approach
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int sum2 = n * (n + 1) / 2;
        return sum2 - sum;
    }
};
//********** optimized approach
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int x = 0;
        for (int l : nums)
        {
            x ^= l;
        }
        for (int i = 0; i <= nums.size(); i++)
        {
            x ^= i;
        }
        return x;
    }
};
//******
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
            ans ^= i + 1;
        }
        return ans;
    }
};
//***********
int main()
{

    return 0;
}