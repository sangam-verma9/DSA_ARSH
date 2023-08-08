#include <bits/stdc++.h>
using namespace std;
//****** first think bruteforce (TLE)
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        int maxval = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = abs(points[i][0] - points[j][0]);
                if (a <= k)
                {
                    int b = (points[i][1] + points[j][1]) + a;
                    maxval = max(maxval, b);
                }
            }
        }
        return maxval;
    }
};
//******* second think (TLE)
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        int maxval = INT_MIN;
        int i = 0, j = 1;
        while (i < n - 1 && j < n)
        {
            int a = abs(points[i][0] - points[j][0]);
            if (a <= k)
            {

                int b = a + (points[i][1] + points[j][1]);
                // cout<<i<<" "<<j<<" "<<b<<endl;
                maxval = max(maxval, b);
                j++;
            }
            if (a > k || (j == n && i != n - 1))
            {
                i++;
                j = i + 1;
            }
        }
        return maxval;
    }
};
//********* optimal approcah (copyed from leetcode)
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        for (int i = 0; i < points.size(); i++)
        {
            while (!pq.empty() && (points[i][0] - pq.top().second) > k)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};
int main()
{

    return 0;
}