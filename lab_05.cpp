#include <iostream>
#include <cmath>
using namespace std;

class coordinates
{
    private:

    int xnum;
    int ynum;

    public:

    coordinates(int x = 0, int y = 0)
    {
        this->xnum = x;
        this->ynum = y;
    }
    void display()
    {
        cout << "(" << xnum << "," << ynum << ")" << endl;
    }
    void operator ~()
    {
        if(xnum < 0)
            xnum = -xnum;
        if(ynum < 0)
            ynum = -ynum;
    }
    coordinates operator -(coordinates p)
    {
        coordinates temp;
        temp.xnum = xnum - p.xnum;
        temp.ynum = ynum - p.ynum;

        return temp;
    }
    void operator ^(int x)
    {
        this->xnum = pow(xnum,x);
        this->ynum = pow(ynum,x);
    }
    int sum()
    {
        int k = 0;
        k = this->xnum + this->ynum;

        return k;
    }
    friend ostream & operator <<(ostream &out, coordinates &c);
    friend istream & operator >>(istream &in,coordinates &c);
};
ostream & operator <<(ostream &out, coordinates &c)
{
    out << "Point : "<< "(" << c.xnum << "," << c.ynum << ")" << endl;

    return out;
}
istream & operator >>(istream &in,coordinates &c)
{
    in >> c.xnum;
    in >> c.ynum;

    return in;
}
int main()
{
    int choice = 0;
    coordinates c1,c2,c3,temp;

    cout << "1.Set Point" << endl;
    cout << "2.Display Point" << endl;
    cout << "3.Display Length" << endl;
    cout << "4.Check Right Triangle" << endl;
    cout << "5.Exit" << endl;

    while(choice != 5)
    {
        cout << "\nEnter your choice : ";
        cin >> choice;
        if(choice == 1)
        {
            int x,y;
            cout << "Enter the first point : ";
            cin >> c1;
            ~c1;
            cout << "Enter the second point : ";
            cin >> c2;
            ~c2;
            cout << "Enter the third point : ";
            cin >> c3;
            ~c3;
        }
        else if(choice == 2)
        {
            int n;
            cout << "Enter the point number to display : ";
            cin >> n;
            if(n == 1)
                cout << c1;
            else if(n == 2)
                cout << c2;
            else if(n == 3)
                cout << c3;
            else
                cout << "Enter the correct choice!";
            
        }
        else if(choice == 3)
        {
            int a=0,b=0;
            cout << "Enter the point numbers to find the length : ";
            cin >> a >> b;
            if(a == b)
                cout << "Distance : 0";
            if((a == 1 && b ==2) || (a == 2 && b ==1))
            {
                temp = c1-c2;
                temp^2;
                cout << "Distance : " << sqrt(temp.sum());
            }
            else if((a == 3 && b ==2) || (a == 2 && b ==3))
            {
                temp = c2-c3;
                temp^2;
                cout << "Distance : " << sqrt(temp.sum());
            }
            else if((a == 1 && b ==3) || (a == 3 && b ==1))
            {
                temp = c3-c1;
                temp^2;
                cout << "Distance : " << sqrt(temp.sum());  
            }
            else
                cout << "Enter the correct numbers!";
        }
        else if(choice == 4)
        {
            coordinates t1, t2, t3;

            t1 = c1-c2;
            t2 = c2-c3;
            t3 = c3-c1;
            t1^2;
            t2^2;
            t3^2;

            if(t1.sum()+t2.sum()==t3.sum() || t3.sum()+t2.sum()==t1.sum() || t1.sum()+t3.sum()==t2.sum())
            {
                cout << "Given points form a Right Angled Triangle";
            }
            else
            {
                cout << "Given points do not form a Right Angled Triangle";
            }
        }
    }

    return 0;
}