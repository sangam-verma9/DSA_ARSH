#include <bits/stdc++.h>
using namespace std;
//******** native approach **********
class Solution
{
public:
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    // Function to get the precedence of an operator
    int getPrecedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    string infixToPostfix(const string &infix)
    {
        string postfix;
        stack<char> operatorStack;

        for (char ch : infix)
        {
            if (isspace(ch))
            {
                continue; // Skip spaces
            }
            else if (isdigit(ch))
            {
                // If it's a digit, add it to the postfix expression
                postfix += ch;
            }
            else if (isOperator(ch))
            {
                postfix += '|';
                // If it's an operator
                while (!operatorStack.empty() &&
                       getPrecedence(operatorStack.top()) >= getPrecedence(ch))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
            }
        }
        postfix += '|';
        // Pop any remaining operators from the stack and add them to the postfix expression
        while (!operatorStack.empty())
        {
            postfix += operatorStack.top();
            operatorStack.pop();
        }

        return postfix;
    }
    int calculate(string s)
    {
        if (s.length() <= 1)
        {
            int a = int(s[0] - '0');
            return a;
        }
        string ex = infixToPostfix(s);
        stack<int> num;
        for (int i = 0; i < ex.length(); i++)
            if (isdigit(ex[i]))
            {
                int cur = 0;
                while (i < ex.length() && isdigit(ex[i]))
                    cur = cur * 10 + (ex[i++] - '0');
                num.push(cur);
            }
            // else if(ex[i]=='|')continue;
            else
            {
                int num1 = num.top();
                num.pop();
                int num2 = num.top();
                num.pop();
                if (ex[i] == '*')
                    num.push(num2 * num1);
                else if (ex[i] == '/')
                    num.push(num2 / num1);
                else if (ex[i] == '+')
                    num.push(num2 + num1);
                else if (ex[i] == '-')
                    num.push(num2 - num1);
            }

        return num.top();
    }
};
//*********
int main()
{

    return 0;
}