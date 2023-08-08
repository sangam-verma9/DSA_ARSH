#include <bits/stdc++.h>
using namespace std;
//***********
long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    string s1, s2;
    long long M = 1e9 + 7;
    while (l1 != NULL)
    {
        string s = to_string(l1->data);
        s1 += s;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        string s = to_string(l2->data);
        s2 += s;
        l2 = l2->next;
    }
    long long num1 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        num1 *= 10;
        num1 %= M;
        num1 += (s1[i] - '0');
        num1 %= M;
    }
    //   cout<<num1<<endl;
    long long x = 1;
    long long ans = 0;
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        long long val = s2[i] - '0';

        val *= x;
        val %= M;
        x *= 10;
        x %= M;
        ans += (num1 * val) % M;
        ans %= M;
    }
    return ans;
}
int main()
{

    return 0;
}