#include <bits/stdc++.h>
using namespace std;
//************ copyed from leetcode
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber)
        {
            if (columnNumber % 26 == 0)
            {
                ans += 'Z';
                columnNumber--;
            }
            else
            {
                ans += (columnNumber % 26 - 1) + 'A';
            }
            columnNumber /= 26;
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};
//********** second approcah (copyed from leetcode)
class Solution
{
public:
    string convertToTitle(int colNum)
    {
        // Just convert colNum into the 26 base Alpabets
        string res = "";
        while (colNum > 0)
        {
            colNum--;
            res = char(colNum % 26 + 'A') + res;
            colNum /= 26;
        }
        return res;
    }
};
//**************
int main()
{

    return 0;
}