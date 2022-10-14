#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Account
{
    protected :

    string id;
    int acc_num;
    double balance;

    public :

    Account(string id, int a_n)
    {
        this->id = id;
        this->acc_num = a_n;
        this->balance = 0;
    }

    friend class Bank;
    friend class Savings;
};
class Bank
{
    protected :

    vector<Account> acc;

    public :

    int search(string i_d)
    {
        int t = -1;
        for(int i=0;i<acc.size();i++)
        {
            if(i_d == acc[i].id)
            {
                t = i;
                break;
            }
        }
        return t;
    }
    int search_num(int num)
    {
        int t = -1;
        for(int i=0;i<acc.size();i++)
        {
            if(num == acc[i].acc_num)
            {
                t = i;
                break;
            }
        }
        return t;
    }
    void add_acc(Account A)
    {
        int t = search(A.id);
        if(t != -1)
            cout << "Customer ID already exist!" << endl;
        else
        {
            acc.push_back(A);
            cout << "Account created with Account Number - " << A.acc_num << endl;
        }
    }
    void credit(int num,double cred)
    {
        int t = search_num(num);
        if(t == -1)
            cout << "Customer ID does not exist!" << endl;
        else
        {
            acc[t].balance += cred;
            cout << "Amount credited Successfully" << endl;
        }
    }
    void debit(int num,double debt)
    {
        int t = search_num(num);
        if(t == -1)
            cout << "Customer ID does not exist!" << endl;
        else
        {
            if(acc[t].balance < debt)
                cout << "Insufficient Balance!" << endl;
            else
            {
                acc[t].balance -= debt;
                cout << "Amount debited Succesfully" << endl;
            }
        }
    }
    void search_details(string i_d,string k)
    {
        int t = search(i_d);
        if(t == -1)
            cout << "There is No " << k << " Account with ID - " << i_d << endl;
        else
        {
            cout << k << " Account :" << endl;
            cout << "   Customer ID : " << acc[t].id << endl;
            cout << "   Account Number : " << acc[t].acc_num << endl;
            cout << "   Balance : " << acc[t].balance << endl;
        }
    }
};
class Savings : public Bank
{
    private : 

    double interest_rate;

    public :

    Savings()
    {
        this->interest_rate = 3.0;
    }
    void change_rate(double i_r)
    {
        this->interest_rate = i_r;
    }
    double calc_interest(int num,double t)
    {
        int k = search_num(num);
        double interest = 0.0;
        if(k == -1)
            cout << "This Account doesn't exist!" << endl;
        else
        {
            interest = (acc[k].balance*t*interest_rate)/100.0;
            cout << "The interest for this Account is : " << interest << endl;
        }

        return interest;
    }
    void calc_update(int num,double t)
    {
        double interest = calc_interest(num,t);
        if(interest != 0.0)
        {
            credit(num,interest);
        }
    }
};
class Checking : public Bank
{
    private :

    double fees;

    public :

    Checking()
    {
        fees = 7.5;
    }
    void update_fees(double f)
    {
        this->fees = f;
        cout << "Updated Successfully" << endl;
    }
    void print_fees()
    {
        cout << "Current fees for Checking Accounts is : " << this->fees << endl;
    }
    inline double get_fees()
    {
        return this->fees;
    }

};
int main()
{
    int choice = 0, sav = 100, check = 200;
    Savings s;
    Checking c;
    cout << "1. Open Account (Savings or Checking Account)" << endl;
    cout << "2. Credit (Savings or Checking Account)" << endl;
    cout << "3. Debit (Savings or Checking Account)" << endl;
    cout << "4. Change/Update Interest rate (Savings Account)" << endl;
    cout << "5. Calculate Interest (Savings Account - Print)" << endl;
    cout << "6. Calculate and Update Principle Amount with Interest (Savings Account - Credit)" << endl;
    cout << "7. Change/Update Fee Amount (Checking Account)" << endl;
    cout << "8. Print Checking Fee (Checking Account)" << endl;
    cout << "9. Search Customer Details" << endl;
    cout << "10. Exit" << endl;
    while(choice != 10)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice == 1)
        {
            int ci;
            cout << "Enter 1 to open Savings Account\n 2 to open Cheching Account : ";
            cin >> ci;
            string id;
            cout << "Enter the ID : ";
            cin >> id;
            if(ci == 1)
            {
                Account A(id,sav);
                s.add_acc(A);
                sav++;
            }
            else if(ci == 2)
            {
                Account A(id,check);
                c.add_acc(A);
                check++;
            }
            else
                cout << "Invalid Choice!" << endl;
        }
        else if(choice == 2)
        {
            string num;
            cout << "Enter the Account Number to Credit : ";
            cin >> num;
            double cred;
            cout << "Enter the Amount to Credit : ";
            cin >> cred;
            if(cred <= 0)
                cout << "Invalid Amount!" << endl;
            else
            {
                if(num[0] == '1')
                {
                    s.credit(stod(num),cred);
                }
                else if(num[0] == '2')
                {
                    if(cred < 50.0)
                        cout << "Insufficient Amount to credit!\nMinimum amount to credit in Checking Account is 50/-" << endl;
                    else
                    {
                        cred -= c.get_fees();
                        c.credit(stod(num),cred);
                    }
                }
                else
                    cout << "This Account doesn't exist!" << endl;
            }
        }
        else if(choice == 3)
        {
            string num;
            cout << "Enter the Account Number to Debit : ";
            cin >> num;
            double debt;
            cout << "Enter the Amount to Debit : ";
            cin >> debt;
            if(debt <= 0)
                cout << "Invalid Amount!" << endl;
            else
            {
                if(num[0] == '1')
                {
                    s.debit(stoi(num),debt);
                }
                else if(num[0] == '2')
                {
                    if(debt < 50.0)
                        cout << "Insufficient Amount to Debit!\nMinimum amount to Debit in Checking Account is 50/-" << endl;
                    else
                    {
                        debt += c.get_fees();
                        c.debit(stoi(num),debt);
                    }
                }
                else
                    cout << "This Account doesn't exist!" << endl;
            }
        }
        else if(choice == 4)
        {
            double i_r;
            cout << "Enter the interest rate to update : ";
            cin >> i_r;
            s.change_rate(i_r);
        }
        else if(choice == 5)
        {
            double t;
            cout << "Enter the time period to calculate interest (in years, for Ex: 1.0) : ";
            cin >> t;
            if(t < 0)
                cout << "Invalid Input!" << endl;
            else
            {
                string num;
                cout << "Enter the Account Number : ";
                cin >> num;
                if(num[0] == '1')
                    s.calc_interest(stoi(num),t);
                else
                    cout << "No such Savings Account exist!" << endl;
            }
        }
        else if(choice == 6)
        {
            double t;
            cout << "Enter the time period to calculate interest (in years, for Ex: 1.0) : ";
            cin >> t;
            if(t < 0)
                cout << "Invalid Input!" << endl;
            else
            {
                string num;
                cout << "Enter the Account Number : ";
                cin >> num;
                if(num[0] == '1')
                    s.calc_update(stoi(num),t);
                else
                    cout << "No such Savings Account exist!" << endl;
            }
        }
        else if(choice == 7)
        {
            double fee;
            cout << "Enter the Fees Amount to Update : ";
            cin >> fee;
            c.update_fees(fee);
        }
        else if(choice == 8)
            c.print_fees();
        else if(choice == 9)
        {
            string id;
            cout << "Enter the Customer ID to Display the details : ";
            cin >> id;
            s.search_details(id,"Savings");
            c.search_details(id,"Checking");
        }
        else if(choice > 10)
            cout << "Enter the correct choice!" << endl;
        else
            return 0;
    }

    return 0;
}