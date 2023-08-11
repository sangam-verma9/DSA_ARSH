#include <bits/stdc++.h>
using namespace std;
//****** first think**********
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        map<int, int> mp;
        while (curr)
        {
            mp[curr->val]++;
            curr = curr->next;
        }
        ListNode *prev = new ListNode(0);
        prev->next = NULL;
        ListNode *ans = prev;
        curr = head;
        while (curr)
        {
            if (mp[curr->val] == 1)
            {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return ans->next;
    }
};
//*******  optimized approach ********
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (head != NULL)
        {

            if (head->next != NULL && head->val == head->next->val)
            {

                while (head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }
                prev->next = head->next;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return dummy->next;
    }
};
// ****************
int main()
{

    return 0;
}