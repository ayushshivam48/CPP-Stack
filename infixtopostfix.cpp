#include <iostream>
#include <stack>
#include <cctype>   // for isdigit()
#include <string>
#include <unordered_map>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // If the character is an operand, add it to the output
        if (isdigit(c)) {
            postfix += c;
        }
        // If the character is an opening bracket, push it to the stack
        else if (c == '(') {
            st.push(c);
        }
        // If the character is a closing bracket, pop and output from the stack 
        // until an opening bracket is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        // If an operator is encountered
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop all the operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // If the character is an operand, push it to the stack
        if (isdigit(c)) {
            st.push(c - '0'); // convert char to int
        }
        // If the character is an operator, pop two elements from stack,
        // apply the operator and push the result back
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            st.push(applyOp(val1, val2, c));
        }
    }
    
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    
    return 0;
}
