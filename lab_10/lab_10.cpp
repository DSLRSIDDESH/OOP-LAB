#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>

queue<char> pop_queue(queue<char> q1)
{
    queue<char> q2;
    while(q1.front() != q1.back())
    {
        q2.push(q1.front());
        q1.pop();
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
    queue<char> q1;
    int l = s.size();
    int i = 0;
    while(i < l)
    {
        if(s[i] == '(')
            q1.push(s[i]);
        else if(s[i] == ')')
        {
            while(q1.back() != '(')
            {
                p = p+q1.back();
                q1 = pop_queue<char>(q1);
            }
            q1 = pop_queue<char>(q1);
        }
        else if(s[i] == '^' || s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-')
        {
            if(q1.empty())
                q1.push(s[i]);
            else if(q1.back() == '(')
                q1.push(s[i]);
            else if(value(q1.back()) < value(s[i]))
                q1.push(s[i]);
            else
            {
                if(value(q1.back()) >= value(s[i]) || !q1.empty())
                {
                    p = p+q1.back();
                    q1 = pop_queue<char>(q1);
                    q1.push(s[i]);
                }
            }
        }
        else
            p = p+s[i];
        i++;
    }
    while(!q1.empty())
    {
        p = p+q1.back();
        q1 = pop_queue<char>(q1);
    }
    cout << "Postfix string is : " << p << endl;
}
int value_char(char k)
{
    if((k>=65 && k<=90) || (k>=97 && k<=122))
        return 1;
    else if(k == '/' || k == '*' || k == '+' || k == '-')
        return 2;
    else
        return 5;
}
string checking(string s)
{
    int i;
    try
    {
        if(value_char(s[0]) != 1 || s.size() == 1)
            throw 0;
        else
        {
            for(i=0;i<s.size()-1;i++)
            {
                int t = value_char(s[i]);
                if(value_char(s[i]) == 5)
                    throw 0;
                if(value_char(s[i]) == value_char(s[i+1]))
                    throw 0;
                if(s[i] == '(')
                    throw 0;
                if(s[i] == ')')
                    throw 0;
            }
            if(s[s.size()-1] == ')' || s[s.size()-1] == '(' || value_char(s[s.size()-1]) != 1)
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