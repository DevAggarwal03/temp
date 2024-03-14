#include <bits/stdc++.h>
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

void insertAtHead(Node* &head, int element){
    Node* temp = new Node(element);
    temp->next = head;
    head = temp;
}

void printInOrder(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        if(temp->next == NULL){
            cout<<temp->data;
            temp = temp->next;
        }
        else{
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        
    }
    cout<<endl;
}

int linkedListLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void printInReverse(Node* &head){
    int lengthOfLL = linkedListLength(head);
    int* arr = new int[lengthOfLL];
    Node* temp = head;
    for(int i = 0; i < lengthOfLL; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }
    for(int i = lengthOfLL-1; i >= 0; i--){
        if(i == 0){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<"->";
        }
    }
    cout<<endl;
}

int main()
{
    Node* newNode = new Node(53);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtHead(head, 88);
    insertAtHead(head, 12);
    insertAtHead(head, 23);
    insertAtHead(head, 63);
    insertAtHead(head, 834);
    cout<<"correct order: ";
    printInOrder(head);
    cout<<"reverse order: ";
    printInReverse(head);
    return 0;
}
