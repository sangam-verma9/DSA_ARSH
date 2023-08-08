#include <bits/stdc++.h>
using namespace std;
//***** my first approach not good
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
// ******** optimized approach
// What We can Do is That We Can Use That Given Array As an Frequency Array
// and Instade of Count The each Element we Can Use - [minus] To track Each Element we are traverse
// Or Not[as They said That any element can occoure max Twice] While Traverseing if We Get Negetive
// element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array class Solution
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}