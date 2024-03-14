#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int front;
    int *arr;
    int size;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int element){
        if(rear == size-1){
            cout<<"Queue is overflow"<<endl;
        }
        else if(rear == -1 && front == -1){
            rear = front = 0;
        }
        else{
            rear = rear + 1;
        }
        arr[rear] = element;
    }

    int dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is underflow"<<endl;
            return -1;
        }
        else if(rear == front){
            int val = arr[front];
            rear = front = -1;
            return val;
        }
        else{
            int val = arr[front];
            front = front + 1;
            return val;
        }
    }

    void makeEmpty(){
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == rear == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(front == 0 && rear == size - 1){
            return true;
        }
        return false;
    }

};

int main(){
   Queue que(5);
   que.enqueue(34);
   que.enqueue(54);
   cout<<que.dequeue()<<endl;
   if(que.isEmpty()){
    cout<<"The que is empty"<<endl;
   }
   else{
    cout<<"The que is not empty"<<endl;
   }

   if(que.isFull()){
    cout<<"The que is Full"<<endl;
   }
   else{
    cout<<"The que is not Full"<<endl;
   }

   return 0;
}
