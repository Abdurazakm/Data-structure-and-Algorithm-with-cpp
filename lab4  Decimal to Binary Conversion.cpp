#include <iostream>
#include <stack>
using namespace std;

/*
Decimal to Binary Conversion:
- A stack is used to store the binary digits (remainder when dividing by 2).
- The binary representation is read from top to bottom of the stack.
*/

void decimalToBinary(int number) {
    stack<int> s;

    // Handle the edge case where the number is 0
    if (number == 0) {
        cout << "0\n";
        return;
    }

    // Convert decimal to binary
    while (number > 0) {
        s.push(number % 2); // Push remainder onto the stack
        number /= 2;
    }

    // Print binary representation by popping from the stack
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    int number = 23; // Example input
    cout << "Binary representation of " << number << ": ";
    decimalToBinary(number);

    return 0;
}
