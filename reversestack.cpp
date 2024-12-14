#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &st) {
    stack<int> tempStack;

    // Pop elements from the original stack and push them onto the temporary stack
    while (!st.empty()) {
        tempStack.push(st.top());
        st.pop();
    }

    // The original stack is now empty, so we push elements back from the temporary stack
    st = tempStack;  // Directly assigning tempStack to st reverses the original stack
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
