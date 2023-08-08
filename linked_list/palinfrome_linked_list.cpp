#include <bits/stdc++.h>
using namespace std;
//******** first approach *********
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *t = head;
        int cnt = 0;
        while (t != NULL)
        {
            cnt++;
            t = t->next;
        }
        ListNode *t1 = head;
        stack<int> s;
        for (int i = 0; i < cnt / 2; i++)
        {
            s.push(t1->val);
            t1 = t1->next;
        }
        if (cnt % 2 == 0)
        {
            while (t1 != NULL)
            {
                if (t1->val != s.top())
                {
                    return false;
                }
                s.pop();
                t1 = t1->next;
            }
            return true;
        }
        else
        {
            t1 = t1->next;
            while (t1 != NULL)
            {
                if (t1->val != s.top())
                {
                    return false;
                }
                s.pop();
                t1 = t1->next;
            }
            return true;
        }
    }
};
//******* second approach *******
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        string s;
        while (head != NULL)
        {
            char c = head->val + '0';
            s += c;
            head = head->next;
        }
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
//************ optimized approach *******
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow;
        slow = slow->next;
        prev->next = NULL;
        ListNode *temp = NULL;
        while (slow != NULL)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head;
        slow = prev;
        while (slow != NULL)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};
//************

int main()
{

    return 0;
}