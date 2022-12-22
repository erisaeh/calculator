#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
        return 1;

    if (alpha == '*' || alpha == '/')
        return 2;

    if (alpha == '^')
        return 3;

    return 0;
}

string convert_to_postfix(string infix)
{
    int i = 0;
    string postfix = "";
    stack<char> s;

    while (i < infix.length())
    {
        while (infix[i] == ' ')
        {
            i++;
        }
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            while (infix[i] >= '0' && infix[i] <= '9')
            {
                postfix += infix[i];
                i++;
            }
            postfix += " ";
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top()))
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        postfix += " ";
        s.pop();
    }

    return postfix;
}
