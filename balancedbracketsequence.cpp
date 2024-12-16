#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str){
    stack<int> st;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch=='[' or ch=='{' or ch=='('){
            st.push(ch);
        }else{
            if(ch==')' and !st.empty() and st.top()=='('){
                st.pop();
            }else if(ch=='}' and !st.empty() and st.top()=='{'){
                st.pop();
            }else if(ch==']' and !st.empty() and st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
        
    }return st.empty();
}

int main() {
    string str = "()()(())";
    cout<<isValid(str)<<endl;
}
