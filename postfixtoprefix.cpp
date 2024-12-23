#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> st;
    
    // Traverse the string from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // If the character is an operand
        if (!isOperator(c)) {
            st.push(string(1, c));
        } 
        // If the character is an operator
        else {
            // Pop two operands from the stack
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            
            // Concatenate them in the order: operator operand1 operand2
            string temp = c + op1 + op2;
            
            // Push the result back to the stack
            st.push(temp);
        }
    }
    
    // The stack will contain the prefix expression
    return st.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Postfix: " << postfix << endl;
    
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix: " << prefix << endl;
    
    return 0;
}
