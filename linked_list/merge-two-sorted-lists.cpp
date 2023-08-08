#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void solve(ListNode *&head1, ListNode *&head2)
    {
        while (head1->next != NULL && head2 != NULL)
        {
            if (head2->val >= head1->val && head1->next->val > head2->val)
            {
                ListNode *temp = head2;
                head2 = head2->next;
                temp->next = head1->next;
                head1->next = temp;
                head1 = head1->next;
            }
            else
            {
                head1 = head1->next;
            }
        }
        if (head1->next == NULL)
        {
            head1->next = head2;
        }
    }

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *head1 = list1;
        ListNode *head2 = list2;
        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        else if (head1 == NULL)
        {
            return head2;
        }
        else if (head2 == NULL)
        {
            return head1;
        }
        else if (head2->val < head1->val)
        {
            head1 = list2;
            head2 = list1;
        }
        ListNode *head = head1;
        solve(head1, head2);
        return head;
    }
};
int main()
{

    return 0;
}