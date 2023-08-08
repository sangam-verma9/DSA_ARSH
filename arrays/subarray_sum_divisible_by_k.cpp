#include <bits/stdc++.h>
using namespace std;
//****** bruteforce approach fist time think
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
//******* optimized approach prefixsum hash map approach
// here we first calculate prefixsum first then it's mod to k then if this mod k element present in map then we add to cnt and then increase map frequancy
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int cnt = 0;
        int prefixsum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixsum += nums[i];
            if (mp[(prefixsum % k + k) % k] > 0)
            {
                cnt += mp[(prefixsum % k + k) % k];
            }
            mp[(prefixsum % k + k) % k] += 1;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}