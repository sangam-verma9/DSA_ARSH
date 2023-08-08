#include <bits/stdc++.h>
using namespace std;
//**** brute force first think
class Solution
{
public:
    bool solve(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                string s1 = s.substr(i, j - i);
                string s2 = s.substr(i + 1, j - i);
                bool flag1 = solve(s1);
                bool flag2 = solve(s2);
                return flag1 || flag2;
            }
        }
        return true;
    }
};
//*********
int main()
{

    return 0;
}