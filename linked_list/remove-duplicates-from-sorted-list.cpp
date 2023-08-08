#include <bits/stdc++.h>
using namespace std;
//*********** first think *****
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode *temp1 = head;
            ListNode *temp2 = head->next;
            while (temp2 != NULL)
            {
                if (temp1->val == temp2->val)
                {
                    temp1->next = temp2->next;
                    // ListNode* temp3=temp2;
                    temp2 = temp2->next;
                    // temp3=NULL;
                }
                else
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
        }
        return head;
    }
};
//***********  good *********
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL)
        {
            if (curr->val == prev->val)
            {
                // ListNode *temp = curr;  } optional
                // temp = NULL;
                curr = curr->next;
            }
            else
            {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return head;
    }
};
int main()
{

    return 0;
}