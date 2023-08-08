#include <bits/stdc++.h>
using namespace std;
//******** first think
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int size = strs.size(), n = strs[0].length();
        for (int i = 1; i < size; i++)
        {
            int m = 0;
            while (m < n && strs[0][m] == strs[i][m])
            {
                m++;
            }
            n = min(n, m);
        }
        return strs[0].substr(0, n);
    }
};
//********  good (copy from leetcode)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
//***********
int main()
{

    return 0;
}