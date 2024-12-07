#include<iostream>
#include<limits.h>
using namespace std;

class Stack{
    int capacity;
    int* arr;
    int top;
public:
    Stack(int c){
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    // Push an element onto the stack
    void push(int data){
        if(this->top == this->capacity - 1){
            cout << "Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    // Pop an element from the stack
    int pop(){
        if(this->top == -1){  // Corrected condition
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        int poppedValue = this->arr[this->top];
        this->top--;
        return poppedValue;  // Return the popped value
    }

    // Get the top element of the stack
    int getTop(){
        if(this->top == -1){  // Corrected condition
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    // Check if the stack is empty
    bool isEmpty(){
        return this->top == -1;
    }

    // Get the current size of the stack
    int size(){
        return this->top + 1;
    }

    // Check if the stack is full
    bool isFull(){
        return this->top == this->capacity - 1;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop() << endl;
    st.push(4);
    st.push(5);
    cout << st.getTop() << endl;
    st.push(8);

    st.pop();
    st.pop();
    cout << st.getTop() << endl;
}
