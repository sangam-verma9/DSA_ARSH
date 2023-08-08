#include <bits/stdc++.h>
using namespace std;
// ********* first approach *******
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2, s3;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int c = 0;
        while (!s1.empty() && !s2.empty())
        {
            int num = s1.top() + s2.top() + c;
            s1.pop();
            s2.pop();
            s3.push(num % 10);
            c = num / 10;
        }
        while (!s1.empty())
        {
            int num = s1.top() + c;
            s1.pop();
            s3.push(num % 10);
            c = num / 10;
        }
        while (!s2.empty())
        {
            int num = s2.top() + c;
            s2.pop();
            s3.push(num % 10);
            c = num / 10;
        }
        if (c != 0)
        {
            s3.push(c);
        }
        ListNode *head = new ListNode(-1);
        ListNode *trav = NULL;
        while (!s3.empty())
        {
            if (trav == NULL)
            {
                head->val = s3.top();
                s3.pop();
                trav = head;
            }
            else
            {
                ListNode *temp = new ListNode(s3.top());
                s3.pop();
                trav->next = temp;
                trav = temp;
            }
        }
        trav->next = NULL;
        return head;
    }
};
//********** good approach *********

// The idea is to add zeros to the start of the smaller list (which is
// allowed since it doesn't tamper with the original structure of the list)
// such that both the lists become of equal size and then use recursion to perform
// digit by digit addition (starting from the last digits, obviously).

// We now use recursion to dive to the end of both the lists and start addition
// from the end.
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Adding zeros to the start of the smaller list:
        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr1 != NULL || ptr2 != NULL)
        {
            if (ptr1 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;

                ptr2 = ptr2->next;
            }
            else if (ptr2 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;

                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        // Main operation:
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = addTwoDigit(l1, l2, carry);
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }

        return dummy->next;
    }

    ListNode *addTwoDigit(ListNode *l1, ListNode *l2, int &carry)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        ListNode *newNode = new ListNode(-1);
        newNode->next = addTwoDigit(l1->next, l2->next, carry);

        newNode->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;

        return newNode;
    }
};
//************
int main()
{

    return 0;
}