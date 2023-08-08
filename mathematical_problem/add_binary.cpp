#include <bits/stdc++.h>
using namespace std;
//************* first approach ********
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() - 1;

        string s = "";
        char c = '0';
        while (i >= 0 && j >= 0)
        {
            if (a[i] == '0' && b[j] == '0' && c == '0')
            {
                s += '0';
                c = '0';
            }
            else if (a[i] == '0' && b[j] == '0' && c == '1')
            {
                s += '1';
                c = '0';
            }
            else if (a[i] == '0' && b[j] == '1' && c == '0')
            {
                s += '1';
                c = '0';
            }
            else if (a[i] == '0' && b[j] == '1' && c == '1')
            {
                s += '0';
                c = '1';
            }
            else if (a[i] == '1' && b[j] == '0' && c == '0')
            {
                s += '1';
                c = '0';
            }
            else if (a[i] == '1' && b[j] == '0' && c == '1')
            {
                s += '0';
                c = '1';
            }
            else if (a[i] == '1' && b[j] == '1' && c == '0')
            {
                s += '0';
                c = '1';
            }
            else if (a[i] == '1' && b[j] == '1' && c == '1')
            {
                s += '1';
                c = '1';
            }
            i--;
            j--;
        }
        if (i >= 0)
        {
            for (; i >= 0; i--)
            {
                if (a[i] == '0' && c == '0')
                {
                    s += '0';
                    c = '0';
                }
                else if (a[i] == '0' && c == '1')
                {
                    s += '1';
                    c = '0';
                }
                else if (a[i] == '1' && c == '0')
                {
                    s += '1';
                    c = '0';
                }
                else if (a[i] == '1' && c == '1')
                {
                    s += '0';
                    c = '1';
                }
            }
        }
        if (j >= 0)
        {
            for (; j >= 0; j--)
            {
                if (b[j] == '0' && c == '0')
                {
                    s += '0';
                    c = '0';
                }
                else if (b[j] == '0' && c == '1')
                {
                    s += '1';
                    c = '0';
                }
                else if (b[j] == '1' && c == '0')
                {
                    s += '1';
                    c = '0';
                }
                else
                {
                    s += '0';
                    c = '1';
                }
            }
        }
        if (c == '1')
        {
            s += '1';
        }

        // cout<<s<<endl;
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }

        return s;
    }
};
//************  good and cool approach **** from leetcode same intution as upper
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};
//***********

int main()
{

    return 0;
}