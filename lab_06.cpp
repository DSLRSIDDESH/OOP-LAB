#include <iostream>
using namespace std;

class Node
{
    Node *next;
    int data;
    
    public:
    
    Node(int a=0, Node *n = NULL)
    {
        this->data = a;
        this->next = n;
    }
    inline int get_data()
    {
        return this->data;
    }
    
    friend class CLL;
};

class CLL
{
    private:
    
    Node *head;
    Node *tail;
    
    public:
    
    CLL(Node *h = NULL,Node *t = NULL)
    {
        this->head = h;
        this->tail = t;
    }
    void insert(int n,Node *p)
    {
        Node *temp = head;
        if(head == NULL)
        {
            head = tail = p;
            tail->next = head;
        }
        if(n == 1)
        {
            p->next = head;
            head = p;
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
            if(p->next == head)
            tail = p;
        }
    }
    void insert(Node *p)
    {
        if(head == NULL)
        {
            head = tail = p;
            tail->next = head;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
        tail->next = head;
    }
    void del(int n)
    {
        Node *temp,*temp1;
        temp = head;
        if(temp->next == NULL)
        {
            delete(temp);
            head = NULL;
        }
        if(n == 1)
        {
            tail->next = head->next;
            head = head->next;
            delete(temp);
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                temp = temp->next;
            }
            temp1 = temp->next;
            if(temp1->next == head)
            {
                tail = temp;
                temp->next = head;
            }
            else
                temp->next = temp1->next;
            delete(temp1);
        }
    }
    void del()
    {
        Node *temp = head;
        if(temp->next == NULL)
        {
            delete(temp);
            head = NULL;
        }
        else
        {
            while(temp->next->next != head)
            {
                temp = temp->next;
            }
            temp->next = head;
            delete(tail);
            tail = temp;
        }
    }
    void search(int n)
    {
        Node *temp = head;
        int c = 0,t = 0;
        while(temp!=NULL)
        {
            if(temp->data == n)
            {
                cout << "Position : " << c+1 << endl;
                t = 1;
                break;
            }
            temp =temp->next;
            c++;
        }
        if(t == 0)
            cout << "No element matched with the input!" << endl;
    }
    void display(int n)
    {
        Node *temp = head;
        for(int i=0;i<n;i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    int count = 0,choice = 0;
    CLL list;
    cout << "1.Insert\n2.Delete\3.Search\n4.Display\n5.Exit" ;
    while(choice != 5)
    {
        cout << "\nEnter the choice : ";
        cin >> choice;
        if(choice == 1)
        {
            int data,ch;
            cout << "1)Insert at any position\n2)Insert at end\nEnter : ";
            cin >> ch;
            cout << "Enter the data : ";
            cin >> data;
            Node *p = new Node(data);
            if(ch == 1)
            {
                int n;
                cout << "Enter the position to insert : ";
                cin >> n;
                if(n <= count+1 || n == 1)
                {
                    list.insert(n,p);
                    count++;
                }
                else
                    cout << "Invalid position" << endl;
            }
            else if(ch == 2)
            {    
                list.insert(p);
                count++;
            }
            else
            {
                cout << "Enter the correct choice!" << endl;
            }
        }
        else if(choice == 2)
        {
            int n,ch;
            cout << "1)Delete at any position\n2)Delete at end\nEnter : ";
            cin >> ch;
            if(ch == 1)
            {
                cout << "Enter the position to delete : ";
                cin >> n;
                if(n <= count || n == 1)
                {
                    list.del(n);
                    count--;
                }
                else
                    cout << "Invalid position" << endl;
            }
            else if(ch == 2)
            {    
                list.del();
                count--;
            }
            else
            {
                cout << "Enter the correct choice!" << endl;
            }
        }
        else if(choice == 3)
        {
            if(count == 0)
            cout << "No elemnt in the List!" << endl;
            else
            {
                int n;
                cout << "Enter the number to search : ";
                cin >> n; 
                list.search(n); 
            }
        }
        else if(choice == 4)
        {
            cout << "List : ";
            list.display(count);
        }
        else if(choice != 5)
        {
            cout << "Enter the correct choice!" << endl;
        }
    }

    return 0;
}