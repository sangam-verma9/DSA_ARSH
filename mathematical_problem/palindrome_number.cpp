#include <bits/stdc++.h>
using namespace std;
//************ first think ********
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int d = s.length();
        for (int i = 0; i < d / 2; i++)
        {
            if (s[i] != s[d - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
//********** second approach
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long reversed = 0;
        int y = x;
        while (y != 0)
        {
            int ld = y % 10;
            reversed = reversed * 10 + ld;
            y /= 10;
        }
        while (x != 0 && reversed != 0)
        {
            int ld1 = x % 10;
            int ld2 = reversed % 10;
            if (ld1 != ld2)
            {
                return false;
            }
            x /= 10;
            reversed /= 10;
        }
        if (x > 0)
            return false;
        if (reversed > 0)
            return false;
        return true;
    }
};
//**********  optimized version of second approach
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long reversed = 0;
        int y = x;
        while (y != 0)
        {
            int ld = y % 10;
            reversed = reversed * 10 + ld;
            y /= 10;
        }
        if (x == reversed)
            return true;
        else
            return false;
    }
};
//**********
int main()
{

    return 0;
}