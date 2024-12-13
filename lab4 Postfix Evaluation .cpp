#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Postfix Evaluation:
- Postfix expressions are evaluated from left to right.
- Operands are pushed onto a stack.
- Operators pop two operands from the stack, perform the operation, and push the result back.
*/

int evaluatePostfix(const string& expression) {
    stack<int> s;

    for (char ch : expression) {
        if (isdigit(ch)) {
            // Push operand (convert char to int)
            s.push(ch - '0');
        } else {
            // Pop two operands for the operator
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();

            // Perform the operation and push the result
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.top(); // Final result
}

int main() {
    string expression = "53+82-*"; // Example input
    cout << "Result of postfix expression \"" << expression << "\": ";
    cout << evaluatePostfix(expression) << endl;

    return 0;
}
