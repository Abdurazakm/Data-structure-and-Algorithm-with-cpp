#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Palindrome Check:
- A string is a palindrome if it reads the same backward as forward.
- This implementation uses a stack to reverse the string and compare it to the original.
*/

bool isPalindrome(const string& str) {
    stack<char> s;
    
    // Push all characters of the string onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters from the stack and compare with the original string
    for (char ch : str) {
        if (s.top() != ch) {
            return false; // Mismatch found
        }
        s.pop();
    }

    return true; // All characters match
}

int main() {
    string str = "madam"; // Example input

    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome.\n";
    } else {
        cout << "\"" << str << "\" is not a palindrome.\n";
    }

    return 0;
}
