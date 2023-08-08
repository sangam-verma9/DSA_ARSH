#include <bits/stdc++.h>
using namespace std;
//***** here we first calculate sum from begining then one by one removing from back and  sum and from last
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int maxsum = 0;
        for (int i = 0; i < k; i++)
        {
            maxsum += cardPoints[i];
        }
        int cnt = 1;
        int sum = maxsum;
        for (int i = 0; i < k; i++)
        {
            sum = sum + cardPoints[n - cnt] - cardPoints[k - cnt];
            maxsum = max(maxsum, sum);
            cnt++;
        }
        return maxsum;
    }
};
//*****
int main()
{

    return 0;
}