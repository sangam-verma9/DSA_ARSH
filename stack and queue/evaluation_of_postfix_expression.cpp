#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                int num = S[i] - '0';
                st.push(num);
            }
            else if (S[i] == '+')
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            }
            else if (S[i] == '-')
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }
            else if (S[i] == '*')
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            }
            if (S[i] == '/')
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            }
        }
        int ans = st.top();
        return ans;
    }
};

int main()
{

    return 0;
}