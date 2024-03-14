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

void deleteDuplicates(Node* &head){
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;

        while(ptr2->next != NULL){
            if(ptr1 == ptr2->next){
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dup;
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int main(){

    Node* newNode = new Node(54);
    Node* head = newNode;

    insertAtHead(head, 83);
    insertAtHead(head, 58);
    insertAtHead(head, 23);
    insertAtHead(head, 83);
    insertAtHead(head, 54);
    insertAtHead(head, 2);
    insertAtHead(head, 23);
    insertAtHead(head, 66);
    cout<<"before: ";
    printInOrder(head);

    deleteDuplicates(head);

    cout<<"after: ";
    printInOrder(head);
    

   return 0;
}
