#include<bits/stdc++.h>
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

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void deleteAtHead(Node* &head){

}

class Stack{
    public:
    Node* top = NULL;
    int data;


    void push(int d){
            insertAtHead(top, d);   
    } 

    int pop(){
        if(top == NULL){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    void peek(){
        cout<< top->data <<endl;
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        return false;
    }
};

int main(){
   
   Stack stk;
   stk.push(34);
   stk.push(55);
   stk.peek();
   cout<<stk.pop()<<endl;
   stk.peek();
   stk.pop();
    if(stk.isEmpty()){
        cout<<"the stack is Empty"<<endl;
    }
    else{
        cout<<"the stack is not Empty"<<endl;
    }

   return 0;
}
