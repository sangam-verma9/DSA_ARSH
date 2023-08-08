#include <bits/stdc++.h>
using namespace std;
//********* first think appraoch my appraoch
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = 0, p2 = 0;
        int cnt = m;
        while (p2 < n)
        {
            if (nums1[p1] < nums2[p2] && p1 < cnt)
                p1++;
            else
            {
                nums1.insert(nums1.begin() + p1, nums2[p2]);
                p1++;
                p2++;
                cnt++;
            }
        }

        for (int i = m + 2 * n - 1; i >= m + n; i--)
        {
            nums1.erase(nums1.begin() + i);
        }
    }
};
//******** better appraoch (copy from leetcode solution)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 and j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[k--] = nums2[j--];
            }
            else
            {
                nums1[k--] = nums1[i--];
            }
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
int main()
{

    return 0;
}