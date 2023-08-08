#include <bits/stdc++.h>
using namespace std;
//******** first approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        set<vector<int>> s;

        for (int b = 0; b <= n - 2; b++)
        {

            long long newtarget = 0 - (long long)nums[b];
            int low = b + 1;
            int high = n - 1;
            while (low < high)
            {
                if ((nums[low] + nums[high]) > newtarget)
                {
                    high--;
                }
                else if ((nums[low] + nums[high]) < newtarget)
                {
                    low++;
                }
                else
                {
                    s.insert({nums[b], nums[low], nums[high]});
                    high--;
                    low++;
                }
            }
        }

        for (auto i : s)
        {
            v.push_back(i);
        }
        return v;
    }
};
//***********
int main()
{

    return 0;
}