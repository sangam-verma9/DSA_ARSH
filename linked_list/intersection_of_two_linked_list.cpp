#include <bits/stdc++.h>
using namespace std;
//********* first think  *********
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        vector<ListNode *> v;
        while (headA != NULL)
        {
            v.push_back(headA);
            headA = headA->next;
        }
        ListNode *p = NULL;
        bool flag = 0;
        while (headB != NULL)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (headB == v[i])
                {
                    p = headB;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
            headB = headB->next;
        }
        return p;
    }
};
//********** second think ********
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> mp;
        while (headA != NULL)
        {
            mp[headA] = true;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (mp[headB] == true)
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
//********** optimized *******
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        if (p1 == NULL || p2 == NULL)
            return NULL;
        while (p1 != NULL && p2 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2)
                return p1;
            if (p1 == NULL)
                p1 = headB;
            if (p2 == NULL)
                p2 = headA;
        }
        return p1;
    }
};
//**********

int main()
{

    return 0;
}