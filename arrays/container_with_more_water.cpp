#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int vol = 0;
        int size = height.size();
        int s = 0;
        int e = size - 1;
        while (e > s)
        {
            int w = e - s;
            int h = min(height[s], height[e]);
            int v = w * h;
            vol = max(vol, v);
            if (height[s] < height[e])
            {
                s++;
            }
            else if (height[s] > height[e])
            {
                e--;
            }
            else
            {
                if (height[s + 1] > height[e - 1])
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return vol;
    }
};
int main()
{

    return 0;
}