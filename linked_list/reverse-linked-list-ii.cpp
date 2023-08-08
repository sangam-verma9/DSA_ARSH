#include <bits/stdc++.h>
using namespace std;
//********** optimized approach (copy from leetcode)
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }
        ListNode *curr = prev->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *fow = curr->next;
            curr->next = fow->next;
            fow->next = prev->next;
            prev->next = fow;
        }
        return dummy->next;
    }
};
int main()
{

    return 0;
}