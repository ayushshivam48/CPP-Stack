#include<iostream>
#include<stack>
using namespace std;

void removeAtIndex(stack<int> &st, int idx) {
    stack<int> tempStack;
    int n = st.size();

    // Step 1: Pop elements from the stack until we reach the desired index
    for (int i = 0; i < n - idx - 1; i++) {
        tempStack.push(st.top());
        st.pop();
    }

    // Step 2: Pop the element at the desired index (this is the element we want to remove)
    st.pop();

    // Step 3: Push the elements from the temporary stack back to the original stack
    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Remove the element at index 2 (which is '3')
    removeAtIndex(st, 2);

    // Display the stack contents
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }

    return 0;
}
