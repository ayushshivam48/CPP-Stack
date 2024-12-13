#include<iostream>
#include<stack>
using namespace std;

// Recursive function to remove the element at the given index 'idx'
void f(stack<int> &st, int idx) {
    // Base case: If the stack is empty, return
    if (st.empty()) {
        return;
    }

    // Pop the top element and store it
    int topElement = st.top();
    st.pop();

    // If index is 0, we reached the position to remove the element
    if (idx == 0) {
        // Do not push the top element back, effectively removing it
        return;
    }

    // Recursive call to remove the element at the previous index
    f(st, idx - 1);

    // Push the stored element back after the recursive call
    st.push(topElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Remove the element at index 2 (which is '3')
    f(st, 2);

    // Display the stack contents
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }

    return 0;
}
