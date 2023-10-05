 #include <iostream>
using namespace std;
class bank
{
    int accNo;
    char name[30];
    long balance;

public:
    void openAccount()
    {
        cout << "enter the account Number\n";
        cin >> accNo;
        cout << "enter the name of the account holder\n";
        cin >> name;
        cout << "enter the balance to start the account\n";
        cin >> balance;
    }
    void showAccounts()
    {
        cout << "account number: " << accNo << "\n";
        cout << "account holder name: " << name << "\n";
        cout<<"you have: "<<balance<<" in your account\n";
    }
    void deposit()
    {
        long amt;
        cout << "enter the amount to deposit\n";
        cin >> amt;
        balance = balance + amt;
    }
    void withdraw()
    {
        long amt;
        cout << "enter the amount to withdraw" << endl;
        cin >> amt;
        if (amt > balance)
        {
            cout << "you do not have enough balance" << endl;

        }
        else
        {
            balance = balance - amt;
        }
    }
    int search(int);
};
int bank::search(int a)
{
    if (accNo == a)
    {

        return (1);
    }
    return (0);
}

int main()
{
    int i = -1, j = 0, flag = 0;
    bank h[100];
    int choice;

    do
    {
        cout << "press 1 for creating the account\n";
        cout << "press 2 for showing all accounts\n";
        cout << "press 3 for crediting your account\n";
        cout << "press 4 for withdrawing the account\n";
        cout << "press 5 for showing information of the particular account\n";
        cout << "press 0 to exit\n";
        cout << "ent1er your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "have a nice day!\n";
            break;
        case 1:
            i++;
            h[i].openAccount();
            break;
        case 2:

            for (int j = 0; j <= i; j++)
            {
                h[j].showAccounts();
            }
            break;
        case 3:
             int a;
            cout << "please enter the account number for depositing\n";
            cin >> a;
            for (j=0; j <= i; j++)
            {
                flag = h[j].search(a);
                if (flag)
                {
                    h[j].deposit();
                    flag=0;
                   break;
                }
            }
            break;
            case 4:
            cout << "please enter the account number for withdraw\n";
            cin >> a;
            for (j=0; j <= i; j++)
            {
                flag = h[j].search(a);
                if (flag)
                {
                    h[j].withdraw();
                    flag=0;
                    break;

                }
            }
            break;
        case 5:

            cout << "please enter the account number for searching\n";
            cin >> a;
            for (j=0; j <= i; j++)
            {
                flag = h[j].search(a);
                if (flag)
                {
                    h[j].showAccounts();
                    flag=0;
                    break;
                }
            }
        break;
        }
    } while (choice != 0);
}
