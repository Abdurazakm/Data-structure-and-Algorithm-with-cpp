#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Infix to Postfix Conversion:
- Uses operator precedence and associativity to convert infix expressions to postfix.
- Handles unary operators by differentiating based on position.
*/

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For non-operators
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isOperand(char ch) {
    return isdigit(ch) || isalpha(ch);
}

string infixToPostfix(const string& expression) {
    stack<char> s;
    string postfix;
    bool wasOperand = false;

    for (size_t i = 0; i < expression.size(); i++) {
        char ch = expression[i];

        if (isOperand(ch)) {
            postfix += ch; // Add operand to output
            wasOperand = true;
        } else if (isOperator(ch)) {
            if (!wasOperand && (ch == '+' || ch == '-')) {
                postfix += '0'; // Treat as unary operator (add a '0' before)
            }

            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
            wasOperand = false;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string expression = "-(a+b)*c"; // Example input
    cout << "Postfix expression: " << infixToPostfix(expression) << endl;

    return 0;
}
