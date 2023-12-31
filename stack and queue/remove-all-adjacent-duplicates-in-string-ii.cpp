#include <bits/stdc++.h>
using namespace std;
// ****** copyed from leetcode
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty() || st.top().first != s[i])
            {
                st.push({s[i], 1});
            }
            else
            {
                auto topele = st.top();
                st.pop();
                st.push({s[i], topele.second + 1});
            }
            if (st.top().second == k)
                st.pop();
        }
        string ans = "";
        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            while (curr.second--)
            {
                ans += curr.first;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{

    return 0;
}