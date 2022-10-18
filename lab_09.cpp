#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public :

    Node *next;
    char data;

    Node(char a)
    {
        this->data = a;
        this->next = NULL;
    }
};
class Queue
{
    private :

    Node *front,*rear;

    public :

    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void Enqueue(char x)
    {
        Node *temp = new Node(x);
        if(front == NULL && rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    char Dequeue()
    {
        char t;
        if(front == NULL && rear == NULL)
            cout << "Queue is Empty!" << endl;
        else
        {
            Node *temp1 = front;
            front = front->next;
            t = temp1->data;
            delete temp1;
        }

        return t;
    }
    friend Queue pop_queue(Queue q1);
    friend void conversion(string s);
};

Queue pop_queue(Queue q1)
{
    Queue q2;
    while(q1.front != q1.rear)
    {
        q2.Enqueue(q1.front->data);
        char c = q1.Dequeue();
    }
    return q2;
}
int value(char x)
{
    if(x == '^')
        return 3;
    else if(x == '/' || x == '*')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return -1;
}

void conversion(string s)
{
    string p;
    Queue q1;
    int l = s.size();
    int i = 0;
    while(i < l)
    {
        if(s[i] == '(')
            q1.Enqueue(s[i]);
        else if(s[i] == ')')
        {
            while(q1.rear->data != '(')
            {
                p = p+q1.rear->data;
                q1 = pop_queue(q1);
            }
            q1 = pop_queue(q1);
        }
        else if(s[i] == '^' || s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-')
        {
            if(q1.rear == NULL)
                q1.Enqueue(s[i]);
            else if(q1.rear->data == '(')
                q1.Enqueue(s[i]);
            else if(value(q1.rear->data) < value(s[i]))
                q1.Enqueue(s[i]);
            else
            {
                if(value(q1.rear->data) >= value(s[i]) || q1.front != NULL)
                {
                    p = p+q1.rear->data;
                    q1 = pop_queue(q1);
                    q1.Enqueue(s[i]);
                }
            }
        }
        else
            p = p+s[i];
        i++;
    }
    while(q1.front != NULL)
    {
        p = p+q1.rear->data;
        q1 = pop_queue(q1);
    }
    cout << "Postfix string is : " << p << endl;
}
int value_char(char k)
{
    if((k>=65 && k<=90) || (k>=97 && k<=122))
        return 1;
    else if(k == '^' || k == '/' || k == '*' || k == '+' || k == '-')
        return 2;
    else if(k == '(')
        return 3;
    else if(k == ')')
        return 4;
    else
        return 5;
}
string checking(string s)
{
    int br = 0,i;
    try
    {
        if(value_char(s[0]) == 5 || value_char(s[0]) == 2 || s.size() == 1)
        {
            throw 0;
        }
        else
        {
            for(i=0;i<s.size()-1;i++)
            {
                int t = value_char(s[i]);
                if(value_char(s[i]) == 5)
                    throw 0;
                if(value_char(s[i]) == value_char(s[i+1]))
                {
                    if(s[i]!='(' || s[i]!=')')
                        throw 0;
                }
                if(br == -1)
                    throw 0;
                if(s[i] == '(')
                    br++;
                if(s[i] == ')')
                    br--;
                if((s[i] == '(' && value_char(s[i+1]) != 1 && value_char(s[i+1]) != 3) || (s[i] == ')' && value_char(s[i-1]) != 1  && value_char(s[i-1]) != 4))
                    throw 0;
                if(i>0 && s[i] == '(' && value_char(s[i-1]) == 1)
                    throw 0;
            }
            if(s[i] == ')' && value_char(s[i-1]) != 1  && value_char(s[i-1]) != 4)
                throw 0;
            if(s[i] == ')')
                br--;
            if(br != 0)
                throw 0;
        } 
    }
    catch(int ex)
    {
        if(ex == 0)
            cout << "Invalid Expression!" << endl;
            s = "\0";
    }
    return s;
}
int main()
{
    string infix = "\0";
    cout << "1. Get Infix Expression" << endl;
    cout << "2. Print Infix Expression" << endl;
    cout << "3. Print Postfix Expression" << endl;
    cout << "4. Exit" << endl;
    int choice;
    while(choice != 4)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter the Infix string : ";
            cin >> infix;
            infix = checking(infix);
        }
        else if(choice == 2)
        {
            if(infix == "\0")
                cout << "Please get the Infix string and try again!" << endl;
            else
                cout << "The infix string is : " << infix << endl;
        }
        else if(choice == 3)
        {
            if(infix == "\0")
                cout << "Please get the Infix string and try again!" << endl;
            else
                conversion(infix);
        }
        else if(choice != 4)
            cout << "Invalid choice!" << endl;
    }

    return 0;
}