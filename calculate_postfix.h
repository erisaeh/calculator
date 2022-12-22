#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int calculate_postfix(string post_exp)
{
    stack<int> s;
    int len = post_exp.length();
    int i = 0;
    while (i < len)
    {
        if (post_exp[i] == ' ')
            i++;
        else if (post_exp[i] >= '0' && post_exp[i] <= '9')
        {
            string tmp = "";
            while (post_exp[i] >= '0' && post_exp[i] <= '9')
            {
                tmp += post_exp[i];
                i++;
            }
            s.push(stoi(tmp));
            tmp = "";
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (post_exp[i])
            {
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            case '^':
                s.push(pow(b, a));
                break;
            }
            i++;
        }
    }
    return s.top();
}
