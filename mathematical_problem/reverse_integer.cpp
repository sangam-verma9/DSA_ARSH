#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int s = 0;
        while (x != 0)
        {
            int lastdigit = x % 10;
            if (s > INT_MAX / 10 || (s == INT_MAX / 10 && lastdigit > 7))
                return 0;
            if (s < INT_MIN / 10 || (s == INT_MIN / 10 && lastdigit < -8))
                return 0;
            s = s * 10 + lastdigit;
            x /= 10;
        }
        return s;
    }
};
int main()
{

    return 0;
}