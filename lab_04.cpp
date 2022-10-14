#include <iostream>
using namespace std;

class node
{
    private:

    node *next;
    node *prev;
    int data;

    public:

    node(int a = 0,node *n = NULL,node *p = NULL)
    {
        this->data = a;
        this->next = n;
        this->prev = p;
    }
    inline int get_data()
    {
        return this->data;
    }

    friend class DLL;
};
class DLL
{
    private:

    node *head;

    public:

    DLL(node *h = NULL)
    {
        this->head = h;
    }
    void insert(node *p)
    {
        node *temp;
        if(head == NULL)
            head = p;
        else if(p->data <= head->data)
        {
            head->prev = p;
            p->next = head;
            head = p;
        }
        else
        {
            temp = head;
            while(p->data >= temp->data && temp->next != NULL)
            {
               temp = temp->next;
            }
            if(temp->next == NULL && p->data >= temp->data)
            {
                temp->next = p;
                p->prev = temp;
            }
            else
            {
                p->prev = temp->prev;
                p->next = temp;
                temp->prev->next = p;
                temp->prev = p;
            }
        }
    }
    void delete_node(int n)
    {
        node *temp = head,*temp1;
        int i=1;
        if(head->next == NULL)
        {
            delete(temp);
            head = NULL;
        }
        else
        {
            if(n == 1)
            {
                head = head->next;
                delete(temp);
                head->prev = NULL;
            }
            else
            {
                while(i<n)
                {
                    temp1 = temp;
                    temp = temp->next;
                    i++;
                }
                temp1->next->prev = temp1;
                temp->prev->next = temp->next;
                delete(temp);
            }
        }
    }
    void display(int n)
    {
        node *temp = head;
        int i = 0;
        while(i<n)
        {
            cout << temp->data << " ";
            temp = temp->next;
            i++;
        }
        cout << endl;
    }

    DLL merge(DLL list, DLL list2)
    {
        node *temp1 = list.head, *temp2 = list2.head;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data >= temp2->data)
            {
                node *p = new node(temp1->data);
                this->insert(p);
                temp1 = temp1->next;
            }
            else if(temp2->data > temp1->data)
            {
                node *p = new node(temp2->data);
                this->insert(p);
                temp2 = temp2->next;
            }
        }
        while(temp2 != NULL)
        {    
            node *p = new node(temp2->data);
            this->insert(p);
            temp2 = temp2->next;
        }
        while(temp1 != NULL)
        {    
            node *p = new node(temp1->data);
            this->insert(p);
            temp1 = temp1->next;
        }
        return *this;
    }
};

int main()
{
    int ch = 0,count = 0;
    cout << "1.Insert" << endl;
    cout << "2.Delete" << endl;
    cout << "3.Display" << endl;
    cout << "4.Merge" << endl;
    cout << "5.Exit" << endl;

    DLL list,list2,list3,list4;
    while(ch!=5)
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            {
                int data;
                cout << "Enter the data to insert : ";
                cin >> data;
                node *p = new node(data);
                list.insert(p);
                count++;
            }
            break;
            case 2:
            {
                int n;
                cout << "Enter the node's position to delete : ";
                cin >> n;
                if(n > count || n <= 0)
                    cout << "Enter correct position to delete!" << endl;
                else
                {
                    list.delete_node(n);
                    count--;
                }
            }
            break;
            case 3:
            {
                if(count > 0)
                {
                    cout << "The Doubly Link List is : ";
                    list.display(count);
                }
                else
                    cout << "There are no data in the list" << endl;
            }
            break;
            case 4:
            {
                int m,num;
                cout << "Enter the number of data to insert in list-2 : ";
                cin >> m;
                for(int i=0;i<m;i++)
                {
                    cout << "Enter number : ";
                    cin >> num;
                    node *Node = new node(num);
                    list2.insert(Node);
                }
                list3.merge(list,list2);
                cout << "List-1 : " ;
                list.display(count);
                cout << "List-2 : " ;
                list2.display(m);
                cout << "List-3 : " ;
                list3.display(count+m);
            }
            break;
            case 5: break;
            default : cout << "Enter correct choice!";
        }
    }
    return 0;
}