#include <bits/stdc++.h>
using namespace std;
// optimized approach here we assume first element is major then traverse if same element
// then increase count else count-- or change major element according to count
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == ans)
            {
                count++;
            }
            else if (nums[i] != ans)
            {

                if (count > 0)
                    count--;

                if (count == 0)
                {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}