#include <bits/stdc++.h>
using namespace std;
//******* first approcah think (TLE)
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int area = INT_MIN;
        int n = heights.size();
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            int minval = INT_MAX;
            for (int j = i; j < n; j++)
            {
                minval = min(minval, heights[j]);
                mp[{i, j}] = minval;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int b = j - i + 1;
                int h = mp[{i, j}];
                int c = b * h;
                area = max(area, c);
            }
        }
        return area;
    }
};
//****** second approach (TLE)
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int area = INT_MIN;
        int n = heights.size();
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            int minval = INT_MAX;
            for (int j = i; j < n; j++)
            {
                minval = min(minval, heights[j]);
                mp[{i, j}] = minval;
            }
        }
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int b = j - i + 1;
            area = max(area, b * mp[{i, j}]);
            if (heights[i] > heights[j])
                j--;
            else
                i++;
        }
        return area;
    }
};
//******* optimized approach (copy from codehelp)
class Solution
{
public:
    vector<int> nextSmallerele(vector<int> &heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> prevSmallerele(vector<int> &heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int area = INT_MIN;
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerele(heights, n);
        vector<int> prev(n);
        prev = prevSmallerele(heights, n);

        for (int i = 0; i < n; i++)
        {
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = b * heights[i];
            area = max(area, newarea);
        }
        return area;
    }
};
//***********
int main()
{

    return 0;
}