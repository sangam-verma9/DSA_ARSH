#include <bits/stdc++.h>
using namespace std;
// ********* first solution ( my approach ) **********
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    flag = true;
                }
                if (flag && nums1[i] < nums2[j])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};
//********** optimized (copyed from leetcode) ******
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        unordered_map<int, int> mp;
        for (int i : nums2)
        {
            while (!s.empty() && s.top() < i)
            {
                mp[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans;
        for (auto n : nums1)
        {
            ans.push_back(mp.count(n) ? mp[n] : -1);
        }
        return ans;
    }
};
//**********
int main()
{

    return 0;
}