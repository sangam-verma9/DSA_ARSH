#include <bits/stdc++.h>
using namespace std;
//***** optimized aproach TC:O(N) SC:(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ind = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ind = i;
                break;
            }
        }
        if (ind != -1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i > ind && nums[i] != 0)
                {
                    swap(nums[ind], nums[i]);
                    ind++;
                }
            }
        }
    }
};
//********* my first approach TC: O(N^2) SC: O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ind = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ind = i;
                break;
            }
        }
        if (ind != -1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i > ind && nums[i] != 0)
                {
                    swap(nums[ind], nums[i]);
                    ind++;
                }
            }
        }
    }
};
//***********
int main()
{

    return 0;
}