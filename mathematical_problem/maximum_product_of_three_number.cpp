#include <bits/stdc++.h>
using namespace std;
//********** my approach good ********
// here only two case arises I-lase three ele sum II- first two ele and last one
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int case1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int case2 = nums[0] * nums[1] * nums[n - 1];
        return max(case1, case2);
    }
};
int main()
{

    return 0;
}