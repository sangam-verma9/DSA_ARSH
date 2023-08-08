#include <bits/stdc++.h>
using namespace std;
//******* my first approach
class Solution
{
public:
    void solve(int left, int right, string s, vector<string> &ans)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(s);
            return;
        }
        if (left > 0)
        {
            s.push_back('(');
            solve(left - 1, right, s, ans);
            s.pop_back();
        }
        if (right > 0)
        {
            if (right > left)
            {
                s.push_back(')');
                solve(left, right - 1, s, ans);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int left = n, right = n;
        vector<string> ans;
        string s = "";
        solve(left, right, s, ans);
        return ans;
    }
};
int main()
{

    return 0;
}