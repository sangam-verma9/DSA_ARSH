#include <bits/stdc++.h>
using namespace std;
//*********** optimized copyed from leetcode
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *lefttail = left;
        ListNode *righttail = right;
        while (head)
        {
            if (head->val < x)
            {
                lefttail->next = head;
                lefttail = head;
            }
            else
            {
                righttail->next = head;
                righttail = head;
            }
            head = head->next;
        }
        lefttail->next = right->next;
        righttail->next = NULL;
        return left->next;
    }
};
//**********
int main()
{

    return 0;
}