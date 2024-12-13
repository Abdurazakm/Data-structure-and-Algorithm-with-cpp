#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isPalindrome(const string &str)
{
    stack<char> s;
    for (char ch : str)
    {
        s.push(ch);
    }
    for (char ch : str)
    {
        if (s.top() != ch)
        {
            return false;
        }
        s.pop();
    }
    return true;
}
void decimalToBinary(int number)
{
    stack<int> s;
    if (number == 0)
    {
        cout << "0\n";
    }
    while (number > 0)
    {
        s.push(number % 2);
        number /= 2;
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
int evaluatePostfix(const string &expression)
{
    stack<int> s;
    for (char ch : expression)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            default:
                cout << "Invalid operator encountered: " << ch << endl;
                return -1;
            }
        }
    }
    return s.top();
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For non-operators
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isOperand(char ch)
{
    return isdigit(ch) || isalpha(ch);
}

string infixToPostfix(const string &expression)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];

        if (isOperand(ch)) // If the character is an operand
        {
            postfix += ch;
        }
        else if (isOperator(ch)) // If the character is an operator
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if (ch == '(') // If the character is an opening parenthesis
        {
            s.push(ch);
        }
        else if (ch == ')') // If the character is a closing parenthesis
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) // Pop the opening parenthesis
                s.pop();
        }
    }

    // Pop all remaining operators in the stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    cout << "what do you want?\n";
    cout << "for palindrome press 1:\n";
    cout << "for decimal to binary press 2:\n";
    cout << "for post evaluation press 3:\n";
    cout << "for convert infix to postfix press 4\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        string str; // Example input
        cout << "Enter the word you want to check:";
        cin >> str;
        if (isPalindrome(str))
        {
            cout << "\"" << str << "\" is a palindrome.\n";
        }
        else
        {
            cout << "\"" << str << "\" is not a palindrome.\n";
        }
    }
    else if (choice == 2)
    {
        int number;
        cout << "Enter the number you want to conver to binary: ";
        cin >> number;
        cout << "Binary representation of " << number << ": ";
        decimalToBinary(number);
    }
    else if (choice == 3)
    {
        string expression;
        cout << "Enter the expression you want to evaluate: ";
        cin >> expression;
        cout << "Result of postfix expression \"" << expression << "\": ";
        cout << evaluatePostfix(expression) << endl;
    }
    else if (choice == 4)
    {
        string expression; // Example input
        cout << "enter the infix  you convert postfix: ";
        cin >> expression;
        cout << "Postfix expression: " << infixToPostfix(expression) << endl;
    }

    return 0;
}