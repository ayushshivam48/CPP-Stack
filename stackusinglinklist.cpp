#include<iostream>
#include<limits.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Stack{
    Node* head;
    int capacity;
    int currSize;
    public:
    Stack(int c){
        this->capacity = c;
        this->currSize = 0;
        head = NULL;
    }

     // Check if the stack is empty
    bool isEmpty(){
        return this->head == NULL;
    }

    // Check if the stack is full
    bool isFull(){
        return this->currSize == this->capacity;
    }

    void push(int data){
        if(this->currSize == this->capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
        this->currSize++;
    }

    int pop(){
        if(this->head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        Node* new_head = this->head->next;
        this->head->next = NULL;
        Node* tobeRemoved = this->head;
        int result = tobeRemoved->data;
        delete tobeRemoved;
        this->head = new_head;
        return result;
    }
    
    int size(){
        return this->currSize;
    }

    int getTop(){
        if(this->head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return this->head->data;
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