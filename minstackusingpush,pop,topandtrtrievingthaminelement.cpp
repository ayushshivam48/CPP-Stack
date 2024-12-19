#include<iostream>
#include<stack>
#include<limits.h>
#define ll long long int
using namespace std;

class MinStack{

public:
    stack<ll> st;
    ll mn;
    MinStack(){
        this->mn = INT_MAX;
    }

    void push(int val){
        if(this->st.empty()){
            this->mn = val;
            this->st.push(val);
        }else{
            this->st.push(val - this->mn);
            if(this->mn > val){
                this->mn = val;
            }
        }
    }

    void pop(){
        if(!this->st.empty()){
            if(this->st.top() >= 0){
                this->st.pop();
            }else{
                this->mn = this->mn - this->st.top();
                this->st.pop();
            }
        }
    }

    int top(){
        if(this->st.size() == 1){
            return this->st.top();
        }else if(this->st.top() < 0){
            return this->mn;
        }else{
            return this->mn + this->st.top();
        }
    }

    int getMin(){
        return this->mn;
    }
};

int main(){
    MinStack minStack;
    
    minStack.push(3);
    minStack.push(5);
    cout << "Minimum: " << minStack.getMin() << endl; // Should print 3
    
    minStack.push(2);
    minStack.push(1);
    cout << "Minimum: " << minStack.getMin() << endl; // Should print 1
    
    minStack.pop();
    cout << "Minimum: " << minStack.getMin() << endl; // Should print 2
    
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Should print 5
    cout << "Minimum: " << minStack.getMin() << endl; // Should print 3
    
    return 0;
}
