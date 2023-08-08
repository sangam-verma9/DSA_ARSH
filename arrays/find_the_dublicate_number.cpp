#include <bits/stdc++.h>
using namespace std;
//******* good solution but here we modify the existing array but q says not do
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            int a = nums[i];
            int b = nums[nums[i] - 1];
            if (nums[i] == i + 1)
            {
                i++;
            }
            else if (nums[i] == nums[nums[i] - 1])
            {
                return nums[i];
            }
            else
                swap(nums[i], nums[nums[i] - 1]);
        }
        return -1;
    }
};
//********* optiminzed approach-> here we consider array as linked list which is circular
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
//********
int main()
{

    return 0;
}