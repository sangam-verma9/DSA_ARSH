#include <bits/stdc++.h>
using namespace std;
//******** simple think *******
class StockSpanner
{
public:
    vector<int> v;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int ans = 1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] <= price)
                ans++;
            else
            {
                break;
            }
        }
        v.push_back(price);
        return ans;
    }
};
//********** optimized (copyed from leetcode) *******
class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int curspan = 1;
        while (!s.empty() && s.top().first <= price)
        {
            int prevspan = s.top().second;
            s.pop();
            curspan += prevspan;
        }
        s.push({price, curspan});
        return curspan;
    }
};
//************

int main()
{

    return 0;
}