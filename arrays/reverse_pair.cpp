#include <bits/stdc++.h>
using namespace std;
// ***** time limit exided sol bruteforce
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long a = nums[i];
                long long b = 2 * (long long)nums[j];
                if (a > b)
                    cnt++;
            }
        }
        return cnt;
    }
};

//******* optimal solution merge sort (divide ans quaqur approach) but ? not correct ans in leetcode
class Solution
{
public:
    void merge(int s, int mid, int e, vector<int> &nums, int &ans)
    {

        int a = mid + 1;
        for (int i = s; i <= mid; i++)
        {
            while (a <= e && nums[i] > 2 * (long long)nums[a])
            {
                a++;
            }
            ans += (a - mid + 1);
        }
        int size = e - s + 1;
        vector<int> temp(size, 0);
        int b = 0;
        int i = s, j = mid + 1;
        while (i <= mid && j <= e)
        {
            if (nums[i] <= nums[j])
            {
                temp[b++] = nums[i++];
            }
            else
            {
                temp[b++] = nums[j++];
            }
        }
        while (i <= mid)
        {
            temp[b++] = nums[i++];
        }
        while (j <= e)
        {
            temp[b++] = nums[j++];
        }
        int m = 0;
        for (int k = s; k <= e; k++)
        {
            nums[i] = temp[m++];
        }
    }
    void mergesort(int s, int e, vector<int> &nums, int &ans)
    {
        if (s >= e)
        {
            return;
        }
        int mid = (s + e) / 2;

        mergesort(s, mid, nums, ans);
        mergesort(mid + 1, e, nums, ans);

        merge(s, mid, e, nums, ans);
    }
    int reversePairs(vector<int> &nums)
    {
        int ans = 0;
        mergesort(0, nums.size() - 1, nums, ans);
        return ans;
    }
};
//**********
int main()
{

    return 0;
}