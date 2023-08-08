#include <bits/stdc++.h>
using namespace std;
//********* first solution *********
class Solution
{
public:
    void remove(ListNode *&head, int n)
    {
        if (head == NULL)
        {
            return;
        }
        if (n == 1)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            int cnt = 0;
            ListNode *curr = head;
            ListNode *prev = NULL;
            while (cnt < n - 1)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            ListNode *temp = curr;
            prev->next = curr->next;
            curr->next = NULL;
            delete temp;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *pre = NULL;
        ListNode *curr = head;
        ListNode *fow = NULL;
        while (curr != NULL)
        {
            fow = curr->next;
            curr->next = pre;
            pre = curr;
            curr = fow;
        }
        return pre;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = reverse(head);
        remove(temp, n);
        ListNode *ans = reverse(temp);
        return ans;
    }
};
//********* second solution **********
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || (head->next == NULL && n == 1))
            return NULL;
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        ListNode *prev = new ListNode(0);
        prev->next = head;
        int diff = cnt - n;
        while (cnt - n > 0)
        {
            prev = prev->next;
            cnt--;
        }
        temp = prev->next;
        // check if delete for last node
        if (temp->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = temp->next; // delete middle node
            temp->next = NULL;
            delete temp;
        }
        if (diff == 0) // delete first node
        {
            prev = prev->next;
            return prev;
        }
        return head;
    }
};
//********** optimized two pointer approach (copyed from leetcode) ******
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
            return head->next;
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
//***********
int main()
{

    return 0;
}