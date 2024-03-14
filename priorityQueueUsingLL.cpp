#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class PriorityQue{
    public:
    Node* head;
    Node* tail ;
    int size ;

    PriorityQue(){
        this->size = 0;
        this->head=NULL;
        this->tail=NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        // Node* temp1 = head;
        // Node* temp2 = head->next;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else if(data < head->data){
            newNode->next = head;
            head = newNode;
        }
        else if(data >= tail->data){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            Node* temp1=head;
            Node* temp2=head->next;
            while(temp2!= NULL){
                if((temp1->data <= data) && (temp2->data > data)){
                    temp1->next = newNode;
                    newNode->next = temp2;
                    return;
                }
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }
    }
    void pop(){
        if(head == NULL){
            cout<<"que is already empty"<<endl;
            return ;
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            delete temp;
        }
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int peek(){
        if(tail==NULL){
            cout<<"Ntg to return";
            return -1;
        }
        return tail->data;   
    }
};

int main(){

    PriorityQue* val=new PriorityQue();
    val->push(5);
    val->push(9);
    val->push(53);
    val->push(8);
    val->push(12);
    val->pop();
    
    cout<<val->peek();

    val->pop();

    cout<<val->peek();
}