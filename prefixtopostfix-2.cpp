#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix to postfix
string prefixToPostfix(string prefix) {
    stack<string> st;
    
    // Traverse the string from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // If the character is an operator
        if (isOperator(c)) {
            // Pop two operands from the stack
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            
            // Concatenate them in the order: operand1 operand2 operator
            string temp = op1 + op2 + c;
            
            // Push the result back to the stack
            st.push(temp);
        } 
        // If the character is an operand
        else {
            st.push(string(1, c));
        }
    }
    
    // The stack will contain the postfix expression
    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Prefix: " << prefix << endl;
    
    string postfix = prefixToPostfix(prefix);
    cout << "Postfix: " << postfix << endl;
    
    return 0;
}
