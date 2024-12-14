#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &st, int item) {
    if (st.empty()) {
        st.push(item);
    } else {
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, item);
        st.push(topElement);
    }
}

// Recursive function to reverse the stack
void reverseStack(stack<int> &st) {
    if (!st.empty()) {
        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack: ";
    stack<int> copy = st;
    while (!copy.empty()) {
        cout << copy.top() << " ";
        copy.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
