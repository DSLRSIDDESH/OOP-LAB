#include <iostream>
using namespace std;

class Time1
{
    private:

        int hrs;
        int mins;
        int secs;

    public:

        Time1()
        {
            hrs = 0;
            mins = 0;
            secs = 0;
        } 

        void set_time(int hours, int minutes, int seconds)
        {
            if( hours<24 && minutes<60 && seconds<60 && hours>=0 && minutes>=0 && seconds>=0 )
            {    
                hrs = hours;
                mins = minutes;
                secs = seconds;
            }
            else
            {
                cout << "Wrong Input" << endl;
            }
        }

        int get_h()
        {
            return hrs;
        }
        int get_m()
        {
            return mins;
        }
        int get_s()
        {
            return secs;
        }
        ~Time1()
        {
        }
        
};
void st(Time1 t);
void ut(Time1 t);
void ist(Time1 t);
void pst(Time1 t);
int main()
{
    Time1 t;
    int choice = 0;

    cout << "1.Set Time" << endl;
    cout << "2.Print Standard Time (AM or PM)" << endl;
    cout << "3.Print Universal Time (24 hours)" << endl;
    cout << "4.Print Indian Start Time (24 hours)" << endl;
    cout << "5.Print Pacific Standard Time (AM or PM)" << endl;
    cout << "6.Exit" << endl;

    while(choice != 6)
    {
        cout << "Enter choice: ";
        cin >> choice ;

        switch(choice)
        {
            case 1: 
                int h, m, s;
                cout << "Enter time in hrs, mins, secs (24 Hrs format):  ";
                cin >> h >> m >> s;
                t.set_time(h, m, s);
                break;
            case 2:
                st(t);
                break;
            case 3:
                ut(t);
                break;
            case 4:
                ist(t);
                break;
            case 5:
                pst(t);
                break;
            case 6:
                break;
            default :
                cout << "Choose the correct one!!" << endl; 
        }
    }
}
void st(Time1 t)
{
    int h = t.get_h();
    string a;
    if(h < 12)
        a = "AM";
    else if(h > 12)
    {
        a = "PM";
        h = h-12;
    }
    else
        a = "PM";
    cout << "Standard Time: "<< h << ":" << t.get_m() << ":" << t.get_s() << " " << a << endl;
}
void ut(Time1 t)
{
    cout << "Universal Time: "<< t.get_h() << ":" << t.get_m() << ":" << t.get_s() << endl;
}
void ist(Time1 t)
{
    int m = t.get_m();
    int h = t.get_h();
    m = m+30;
    if(m > 60)
    {
        m = m - 60;
        h = (h+1)%24;
    }
    h = (h+5)%24;
    cout << "Indian Standard Time: "<< h << ":" << m << ":" << t.get_s() << endl;
}
void pst(Time1 t)
{
    int h = t.get_h();
    h = (h-8)%24;
    if(h<0)
    {
        h = h+24;
    }
    string a;
    if(h < 12)
        a = "AM";
    else if(h > 12)
    {
        a = "PM";
        h = h-12;
    }
    else
        a = "PM";
    cout << "Pacific Standard Time: "<< h << ":" << t.get_m() << ":" << t.get_s() << " " << a << endl;
}