#include<iostream>
#include<list>
using namespace std;
template<typename T>
class Queue
{
    private :
        list<T>l;
    public :
        Queue(){}
        void enqueue(T x)
        {
            l.push_back(x);
        }
        void dequeue()
        {
            try
            {
                if(l.size()==0)
                    throw 1;
            }
            catch(int a)
            {
                cout<<"Queue is Underflow"<<endl;
                return;
            }
            l.pop_front();
        }
        T front()
        {
            return l.front();
        }
        T rear()
        {
            return l.back();
        }
        T size()
        {
            return l.size();
        }
        friend void inftopost(string inf);
        friend Queue<char> pop_queue(Queue<char> q1);
};
int precedence(char a)
{
    if(a=='/' || a=='*')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}
Queue<char> pop_queue(Queue<char> q1)
{
    Queue<char> q2;
    while(q1.front() !=q1.rear())
    {
        q2.enqueue(q1.front());
        q1.dequeue();
    }
    return q2;
}
void inftopost(string inf)
{
    Queue<char> q;
    string pos="";
    for(int i=0;i<inf.length();i++)
    {
        char c=inf[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            pos+=c;
        }
        else
        {
            while(q.size()!=0 && precedence(inf[i])<=precedence(q.rear()))
            {
                pos+=q.rear();
                q=pop_queue(q);
            }
            q.enqueue(c);
        }
    }
    while(q.size()!=0)
    {
        pos+=q.rear();
        q=pop_queue(q);
    }
    cout<<"Postfix expression :"<<pos<<endl;
}
int check_char(char a)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || a=='+' || a=='-' || a=='/' || a=='*')
        return 1;
    else 
        return -1;
}
void check_exp(string s)
{
    if(s[0]=='+' || s[0]=='-' || s[0]=='/' || s[0]=='*')
        throw 0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(check_char(s[i])!=1)
            throw i;
        else if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && ((s[i+1]>='a' && s[i+1]<='z') || (s[i+1]>='A' && s[i+1]<='Z')))
            throw i;
        else if(precedence(s[i])!=-1 && precedence(s[i+1])!=-1)
            throw i;
    }
    if(check_char(s.length()-1)!=1)
        throw (int)s.length()-1;
    else if(precedence(s[s.length()-1])!=-1)
        throw (int)s.length()-1;
}
int main()
{
    cout<<"1.Get Infix Expression"<<endl;
    cout<<"2.Print Infix Expression"<<endl;
    cout<<"3.Print Postfix Expression"<<endl;
    cout<<"4.Exit"<<endl;
    int ch;
    Queue<char> q1,q2;
    string exp="";
    while(ch!=4)
    {
        cout<<"Enter your choice :";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter the infix expression :";
            cin>>exp;
            try
            {
                check_exp(exp);
            }
            catch(int x )
            {
                cout<<"Invalid expression :"<<exp<<endl;
                cout<<"                    ";
                for(int i=0;i<x;i++)
                    cout<<" ";
                cout<<"^^"<<endl;
                exp="";
            }
        }
        else if(ch==2)
        {
            if(exp=="")
                cout<<"please enter infix expression first"<<endl;
            else
                cout<<"Infix expression :"<<exp<<endl;
        }
        else if(ch==3)
        {
            if(exp=="")
                cout<<"please enter infix expression first"<<endl;
            else
                inftopost(exp);
        }
        else if(ch==4)
        {
            break;
        }
        else
            cout<<"Enter correct choice"<<endl;
    }
    return 0;
}