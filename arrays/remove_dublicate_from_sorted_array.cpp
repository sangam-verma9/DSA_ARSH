#include <bits/stdc++.h>
using namespace std;
//***** optimized approach pointer curr indicating next unique ele
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int curr = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[curr] != nums[i] && (curr + 1) != i)
            {
                curr++;
                swap(nums[curr], nums[i]);
            }
            else if (nums[curr] != nums[i])
                curr++;
            else
                continue;
        }
        return curr + 1;
    }
};
//***** lay main approach (first approach)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i + 1);
                i--;
            }
        }
        return nums.size();
    }
};
//******
int main()
{

    return 0;
}