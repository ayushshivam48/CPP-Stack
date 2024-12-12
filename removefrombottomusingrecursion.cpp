#include<iostream>
#include<stack>
using namespace std;

void f(stack<int> &st){
    if(st.size()==1){
        st.pop();
        return;;
    }
    int curr = st.top();
    st.pop();
    f(st);
    st.push(curr);

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    f(st);
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
}