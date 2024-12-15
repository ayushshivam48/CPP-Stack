#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &st, int x){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x); // Insert x at the bottom
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

// Recursive function to reverse the stack
void f(stack<int> &st) {
    if(st.empty()) return;  // Base case: if stack is empty, return
    
    int curr = st.top();  // Take the top element
    st.pop();  // Remove the top element
    f(st);  // Recursively reverse the remaining stack
    insertAtBottom(st, curr);  // Insert the top element at the bottom
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    f(st);
    
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }
}
