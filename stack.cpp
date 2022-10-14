#include <iostream>
using namespace std;

#define size 5
class stack
{
    int arr[size];
    int top;

    public:
    stack()
    {
        top = -1;
    }

    bool isfull()
    {
        if(top == size-1)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
    void push(int num)
    {
        if(isfull())
            cout<<"The stack is full\n";
        else
        {
            top++;
            arr[top] = num;
        }
    }
    int pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty!!\n";
            return -1;
        }
        else
        {
            int num = arr[top];
            top--;
            return num;
        }
    }
    int peek()
    {
        int pe;
        if(isempty())
            cout <<"Stack is empty!!\n";
        else
            pe = arr[top];

        return pe;  
    }
    void display()
    {
        for(int i=0;i<=top;i++)
            cout << arr[i] << endl;
    }
};