#include <iostream>
#include <vector>
using namespace std;

class Student
{
    protected :

    string name;
    string roll;

    public :

    Student()
    {}
    Student(string n, string r)
    {
        this->name = n;
        this->roll = r;
    }

    inline string get_roll()
    {
        return this->roll;
    }

    virtual void display() = 0;
};
class pg_student : virtual public Student
{
    protected :

    string course1,course2,course3;

    public :

    pg_student()
    {}
    pg_student(string n, string r, string c1, string c2, string c3) : Student(n, r)
    {
        this->course1 = c1;
        this->course2 = c2;
        this->course3 = c3;
    }
    void display()
    {
        cout << "\tCourse-1 : " << course1 <<endl;
        cout << "\tCourse-2 : " << course2 <<endl;
        cout << "\tCourse-3 : " << course3 <<endl;
    }
};
class research_student : virtual public Student
{
    protected :

    string course_1;
    string research_area;

    public :

    research_student()
    {}
    research_student(string n, string r, string c1, string r_a) : Student(n, r)
    {
        this->course_1 = c1;
        this->research_area = r_a;
    }

    void display()
    {
        cout << "\tCourse-1 : " << course_1 <<endl;
        cout << "\tResearch Area : " << research_area <<endl;
    }
};
class TA : public pg_student, public research_student
{
    protected :

    string course_assigned;
    string role;

    public :

    TA(string n, string r, string c1, string c2, string c3,string c_a, string ro) : pg_student(n, r, c1, c2, c3), Student(n, r)
    {
        this->course_assigned = c_a;
        this->role = ro;
    }
    TA(string n, string r, string c1, string r_a, string c_a, string ro) : research_student(n, r, c1, r_a), Student(n, r)
    {
        this->course_assigned = c_a;
        this->role = ro;
    }
    void display()
    {
        cout << "Details of Student having Roll Number : " << roll << endl;
        cout << "\tName : " << name << endl;
        cout << "\tRoll Number : " << roll << endl;
        cout << "\tCourse Assigned : "  << course_assigned << endl;
        cout << "\tRole : " << role << endl;
        if(role == "PG_Student")
            pg_student::display();
        else
            research_student::display();
    }

    friend void search(vector<TA> b,string r);
};
void search(vector<TA> b,string r)
{
    int t = 0;
    for(int i=0;i<b.size();i++)
    {
        if(b[i].roll == r)
        {
            t = 1;
            b[i].display();
            break;
        }
    }
    if(t == 0)
        cout << "Roll Number not found!" << endl;
}
int main()
{
    vector<TA> b;

    cout << "1. Set details\n2. Display\n3. Exit" << endl;
    int choice;
    while(choice != 3)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice == 1)
        {
            string na,rol,c_a;
            cout << "Enter Name : ";
            cin >> na;
            cout << "Enter Roll Number : ";
            cin >> rol;
            int t = 0;
            for(int i=0;i<b.size();i++)
            {
                if(b[i].get_roll() == rol)
                {
                    t = 1;
                    break;
                }
            }
            if(t == 0)
            {
                cout << "Enter the course assigned : ";
                cin >> c_a;
                int c;
                cout << "Enter 1 to set PG Student Details\n2 to set Research Student Details : ";
                cin >> c;
                if(c == 1)
                {
                    string c1,c2,c3;
                    cout << "Enter course-1,course-2,course-3 : ";
                    cin >> c1 >> c2 >> c3;
                    if(c1 != c_a && c2 != c_a && c3 != c_a)
                    {
                        TA obj(na,rol,c1,c2,c3,c_a,"PG_Student");
                        b.push_back(obj);
                    }
                    else
                        cout << "Some of the Courses matched with Course Assigned. Try Again!" << endl;
                }
                else if(c == 2)
                {
                    string c1,r_a;
                    cout << "Enter course-1 and research Area : ";
                    cin >> c1 >> r_a;
                    if(c1 == c_a)
                        cout << "Course-1 matched with course assigned. Try again!" << endl;
                    else
                    {
                        TA obj(na,rol,c1,r_a,c_a,"Research_Student");
                        b.push_back(obj);
                    }
                }
                else
                    cout << "Invalid Input!" << endl;
            }
            else
                cout << "This Roll Number Already Exist. Try new one!" << endl;
        }
        else if(choice == 2)
        {
            string rol;
            cout << "Enter the Roll Number to Search : ";
            cin >> rol;
            search(b,rol);
        }
        else if(choice != 3)
            cout << "Enter the correct Input" <<endl;
        else if(choice == 3)
            return 0;
    }

    return 0;
}