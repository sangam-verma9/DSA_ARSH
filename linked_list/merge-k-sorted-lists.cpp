#include <bits/stdc++.h>
using namespace std;
//*********** first approach ********
class Solution
{
    ListNode *connect(ListNode *list1, ListNode *list2)
    {

        ListNode *head = list1;
        while (list1->next != NULL && list2 != NULL)
        {
            if (list1->val < list2->val && list1->next->val < list2->val)
            {
                list1 = list1->next;
            }
            else if (list1->val <= list2->val && list1->next->val >= list2->val)
            {
                ListNode *temp = list2->next;
                list2->next = list1->next;
                list1->next = list2;
                list2 = temp;
                list1 = list1->next;
            }
        }
        if (list2 != NULL)
        {
            list1->next = list2;
        }
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int size = lists.size();
        ListNode *head = NULL;
        if (size == 0)
        {
            return head;
        }
        if (size == 1)
        {
            head = lists[0];
            return head;
        }
        head = lists[0];
        for (int i = 1; i < size; i++)
        {
            if (head == NULL)
            {
                head = lists[i];
                continue;
            }
            else if (lists[i] == NULL)
            {
                head = head;
                continue;
            }
            else if (head->val > lists[i]->val)
            {
                head = connect(lists[i], head);
            }
            else
            {
                head = connect(head, lists[i]);
            }
        }
        return head;
    }
};
//************ priority queue approach (copyed from leetcode) ********
class Solution
{
public:
// we define pair as pi
#define pi pair<int, ListNode *>

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size(); // taking the size of the linked list

        if (k == 0)      // if no linked list is present
            return NULL; // simply return null

        priority_queue<pi, vector<pi>, greater<pi>> minh; // making priority queue

        for (int i = 0; i < k; i++) // traverse from the whole array
        {
            ListNode *curr_list = lists[i]; // extracting current linked list

            if (curr_list != NULL) // if element present in the linked list
            {
                minh.push({curr_list->val, curr_list}); // push into min heap
            }
        }

        // this does not gurantee that k is zero,
        // suppose an array like this [[],[],[],],here k = 3 and size of array is 0
        if (minh.size() == 0) // if their is no element i.e zero element
            return NULL;

        ListNode *head = new ListNode(); // can also be called as dummy
        ListNode *curr = head;           // make a pointer pointing to head

        while (minh.empty() == false) // adding further most elements to min heap
        {
            pair<int, ListNode *> temp = minh.top(); // extracting top pair
            minh.pop();                              // pop that pair

            if (temp.second->next != NULL) // if elements still remaining in the linked list then push them
            {
                minh.push({temp.second->next->val, temp.second->next});
            }

            curr->next = temp.second;
            curr = curr->next;
        }

        curr->next = NULL;
        head = head->next; // move head, which is actually containg the list

        return head; // return head
    }
};
//**********
int main()
{

    return 0;
}