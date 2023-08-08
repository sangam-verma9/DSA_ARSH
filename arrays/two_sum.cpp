#include <bits/stdc++.h>
using namespace std;
//******* my solution TC:O(N^2) SC:O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int newt = target - nums[i];
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == newt)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};
//******** striver solution TC:O(N) SC:O(N)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int newtar = target - nums[i];
            if (m.find(newtar) != m.end())
            {
                return {i, m[newtar]};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
//*****
int main()
{

    return 0;
}