#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include "validate_string.h"
#include "convert_to_postfix.h"
#include "calculate_postfix.h"
using namespace std;

int main()
{
    cout << "\"Calculator\"" << endl
         << endl;
    cout << "\"q\" to exit" << endl;
    string fullExpression;
    string line;
    int answer;
    while (true)
    {
        cout << ">> ";
        getline(cin, fullExpression);
        if (fullExpression == "q")
            break;
        else if (fullExpression == "")
            continue;
        else
        {
            if (!is_valid_string(str_parentheses_digging(fullExpression)))
            {
                cout << "Invalid expression. Try again:" << endl;
                continue;
            }
            fullExpression = convert_to_postfix(fullExpression);
            answer = calculate_postfix(fullExpression);
            cout << "answer = " << answer << endl;
        }
    }
    cout << endl;
    cout << "Good Bye!" << endl;
    cout << endl;
}