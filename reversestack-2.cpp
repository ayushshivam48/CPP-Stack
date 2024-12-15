#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &st) {
    stack<int> t1,t2;
    while(! st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }
    while(! t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    while(! t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack(st);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    
    }
    }
