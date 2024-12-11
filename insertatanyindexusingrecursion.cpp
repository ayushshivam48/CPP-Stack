#include<iostream>
#include<stack>
using namespace std;

// Recursive function to insert 'x' at the given index 'idx'
void insertAt(stack<int> &st, int x, int idx) {
    // Base case: If index is 0, push 'x' onto the stack
    if (idx == 0) {
        st.push(x);
        return;
    }

    // Pop the top element and store it
    int topElement = st.top();
    st.pop();

    // Recursive call to insert 'x' at the previous index
    insertAt(st, x, idx - 1);

    // Push the stored element back after inserting 'x'
    st.push(topElement);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAt(st,100,1);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
}