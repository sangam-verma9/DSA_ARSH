#include <bits/stdc++.h>
using namespace std;
//***** optimized approach Dutch National Flag algorithm
/*The algorithm works by maintaining three pointers: low, mid, and high. The low pointer points to the beginning of the array, the high pointer points to the end of the array, and the mid pointer starts at the beginning of the array and moves through it.
The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, and all the 1s between the low and high pointers. The algorithm moves the mid pointer through the array, comparing the value at each position with 1. If the value is 0, the element is swapped with the element at the low pointer, and the low and mid pointers are incremented. If the value is 2, the element is swapped with the element at the high pointer, and the high pointer is decremented. If the value is 1, the mid pointer is simply incremented.*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
//********* my first  approach
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                a++;
            }
            else if (nums[i] == 1)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        for (int i = 0; i < a; i++)
        {
            nums[i] = 0;
        }
        for (int i = a; i < (a + b); i++)
        {
            nums[i] = 1;
        }
        for (int i = (a + b); i < (a + b + c); i++)
        {
            nums[i] = 2;
        }
    }
};
//********
int main()
{

    return 0;
}