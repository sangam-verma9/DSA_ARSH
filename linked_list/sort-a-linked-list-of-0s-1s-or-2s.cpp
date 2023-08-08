#include <bits/stdc++.h>
using namespace std;
//********* basic approach
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        Node *temp = head;
        Node *temp1 = head;
        int zero = 0, one = 0, two = 0;
        while (temp != NULL)
        {
            if (temp->data == 0)
                zero++;
            else if (temp->data == 1)
                one++;
            else
                two++;
            temp = temp->next;
        }
        for (int i = 0; i < zero; i++)
        {
            temp1->data = 0;
            temp1 = temp1->next;
        }
        for (int i = 0; i < one; i++)
        {
            temp1->data = 1;
            temp1 = temp1->next;
        }
        for (int i = 0; i < two; i++)
        {
            temp1->data = 2;
            temp1 = temp1->next;
        }
        return head;
    }
};
int main()
{

    return 0;
}