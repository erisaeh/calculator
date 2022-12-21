#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string str_parentheses_digging(string input)
{
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            count++;
        if ((input[i] < '0' || input[i] > '9') && input[i] != '(' && input[i] != ')' && input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '^' && input[i] != '/')
            return "false";
    }
    if (count == input.length())
        return "false";

    string tmp = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(' || input[i] == ')')
            tmp.push_back(input[i]);
    }
    return tmp;
}

bool is_valid_string(string expr)
{
    if (expr == "false")
        return false;
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++)
    {
        if (temp.empty())
        {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')'))
        {
            temp.pop();
        }
        else
        {
            temp.push(expr[i]);
        }
    }
    if (temp.empty())
    {
        return true;
    }
    return false;
}
