#include <bits/stdc++.h>
using namespace std;
//******** striver solution prefix-sum hashtable sol
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, presum = 0;
        for (int i = 0; i < n; i++)
        {
            presum += nums[i];
            cnt += mp[presum - k];
            mp[presum]++;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}