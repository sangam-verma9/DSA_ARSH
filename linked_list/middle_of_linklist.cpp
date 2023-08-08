#include <bits/stdc++.h>
using namespace std;
//********* first approach **********
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        int p = cnt / 2;
        while (p--)
        {
            head = head->next;
        }
        return head;
    }
};
//******* second appraoch good but SC is not good
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next == NULL)
            {
                return slow->next;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
//***********
int main()
{

    return 0;
}