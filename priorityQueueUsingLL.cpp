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
    Node* head = NULL;
    Node* tail = NULL;
    int size;

    PriorityQue(){
        this->size = 0;
    }

    void push(int data){
        Node* newNode = new Node(data);
        Node* temp1 = head;
        Node* temp2 = temp1->next;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else if(data < head->data){
            Node* temp = head;
            newNode->next = temp;
            head = newNode;
            // size++;
        }
        else if(data >= tail->data){
            Node* temp = tail;
            temp->next = newNode;
            tail = newNode;
        }
        else{
            while(temp2 != NULL){
                if((temp1->data <= data) && (temp2->data > data)){
                    newNode->next = temp2;
                    temp1->next = newNode;
                }
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }
    }

    int pop(){
        int val = -1;
        if(head == NULL){
            cout<<"que is already empty"<<endl;
            return -1;
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            val = temp->data;
            tail->next = NULL;
            delete temp;
        }
        size = size-1;
        return val;
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int peek(){
        return tail->data;   
    }

    void printQue(){
        Node* temp = head;
        while(temp != tail->next){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){

    PriorityQue que;
    que.push(23);
    que.push(55);
    que.push(12);
    que.push(24);
    que.push(88);
    
    que.printQue();

   return 0;
}
