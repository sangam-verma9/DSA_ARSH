#include <bits/stdc++.h>
using namespace std;
//********** copy from leetcode
class Solution
{
public:
    int dis(vector<int> p, vector<int> q)
    {
        int ans = (q[1] - p[1]) * (q[1] - p[1]) + (q[0] - p[0]) * (q[0] - p[0]);
        return ans;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        unordered_set<int> disarr;
        disarr.insert(dis(p1, p2));
        disarr.insert(dis(p1, p3));
        disarr.insert(dis(p1, p4));
        disarr.insert(dis(p2, p3));
        disarr.insert(dis(p2, p4));
        disarr.insert(dis(p3, p4));
        if (disarr.count(0))
            return false;
        return disarr.size() == 2;
    }
};
int main()
{

    return 0;
}