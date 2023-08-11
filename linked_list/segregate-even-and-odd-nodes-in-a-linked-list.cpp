#include <bits/stdc++.h>
using namespace std;
//***** my approach (brute force) *********
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *left = new Node(0);
        Node *right = new Node(0);
        Node *lefttail = left;
        Node *righttail = right;
        while (head)
        {
            if (head->data % 2 == 0)
            {
                lefttail->next = head;
                lefttail = head;
            }
            else
            {
                righttail->next = head;
                righttail = head;
            }
            head = head->next;
        }
        lefttail->next = right->next;
        righttail->next = NULL;
        return left->next;
    }
};
//***********
int main()
{

    return 0;
}