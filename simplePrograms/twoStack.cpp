#include<bits/stdc++.h>
using namespace std;
class TwoStack{

public:

    int *arr;
    int size;
    int top1;
    int top2;

TwoStack(int size){
    this->size = size;
    arr = new int[size];
    top1 = -1;
    top2 = size;
};

void push1(int element){
    if(top2 - top1 == 1){
        cout<<"stack Overflow"<<endl;
    }
    else{
        top1++;
        arr[top1] = element;
    }
}

void push2(int element){
    if(top2 - top1 == 1){
        cout<<"stack Overflow"<<endl;
    }
    else{
        top2--;
        arr[top2] = element;
    }
}

int pop1(){
    if(top1 == -1){
        cout<<"stack underflow"<<endl;
    }
    int topElement = arr[top1];
    top1--;
    return topElement;
}
int pop2(){
    if(top2 == size){
        cout<<"stack underflow"<<endl;
    }
    int topElement = arr[top2];
    top2++;
    return topElement;
}

void peek1(){
    if(top1 == -1){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<arr[top1]<<endl;
    }
}
void peek2(){
    if(top2 == size){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<arr[top2]<<endl;
    }
}
};
int main(){
   
    TwoStack stk(6);
    stk.push1(34);
    stk.push2(44);
    stk.push1(299);
    stk.push2(49);
    stk.peek1();
    stk.peek2();

   return 0;
}
