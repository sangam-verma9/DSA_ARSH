#include <bits/stdc++.h>
using namespace std;
//***** first approach (my approach) ******
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s2.push(x);
    }

    int pop()
    {
        if (s2.empty())
        {
            return -1;
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        int ans = s1.top();
        s1.pop();
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return ans;
    }

    int peek()
    {
        if (s2.empty())
        {
            return -1;
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        int ans = s1.top();
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return ans;
    }

    bool empty()
    {
        if (s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
//**********
int main()
{

    return 0;
}