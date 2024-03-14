#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int num)
    {
        if (top == size - 1)
        {
            cout << "stack overflow";
        }
        else
        {
            top = top + 1;
            arr[top] = num;
        }
    }

    int pop()
    {
        int poppedEle;
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            poppedEle = arr[top];
            top--;
        }
        return poppedEle;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    Stack stk(4);

    if (stk.isEmpty())
    {
        cout << "the stack is empty" << endl;
    }
    else
    {
        cout << "the stack is not empty" << endl;
    }

    stk.push(5);
    stk.peek();
    stk.push(45);
    stk.push(64);
    stk.peek();

    if (stk.isEmpty())
    {
        cout << "the stack is empty" << endl;
    }
    else
    {
        cout << "the stack is not empty" << endl;
    }

    int topElePop = stk.pop();
    cout << topElePop << endl;
    stk.peek();
}
