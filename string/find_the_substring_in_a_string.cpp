#include <bits/stdc++.h>
using namespace std;
//********* first solution
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int count = 0;
        int s1 = haystack.length();
        int s2 = needle.length();
        for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < s2; j++)
            {
                if (haystack[j + i] == needle[j])
                {
                    count++;
                }
                else
                {
                    count = 0;
                    break;
                }
                if (count == s2)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
//********* good approach (copy from lrrtcode solution)
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int count = 0;
        int s1 = haystack.length();
        int s2 = needle.length();
        for (int i = 0; i < s1; i++)
        {

            if (haystack[i] == needle[count])
            {
                count++;
            }
            else
            {
                i = i - count;
                count = 0;
            }
            if (count == s2)
            {
                return i - count + 1;
            }
        }
        return -1;
    }
};
//******
int main()
{

    return 0;
}