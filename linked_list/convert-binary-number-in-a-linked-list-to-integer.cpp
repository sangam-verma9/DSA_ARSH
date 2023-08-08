#include <bits/stdc++.h>
using namespace std;
//*********** first approach ********
class Solution
{
public:
    int getlength(ListNode *head)
    {
        int cnt = 0;
        while (head != NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    int getDecimalValue(ListNode *head)
    {
        int l = getlength(head);
        int deci = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            int value = head->val;
            deci += value * pow(2, i);
            head = head->next;
        }
        return deci;
    }
};
//******  optimized approach ********
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int sum = 0;
        while (head != NULL)
        {
            sum *= 2;
            int val = head->val;
            sum += val;
            head = head->next;
        }
        return sum;
    }
};
//**************
int main()
{

    return 0;
}