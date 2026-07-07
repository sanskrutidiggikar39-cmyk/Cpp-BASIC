#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class BankAccount
{
private:
    int accountNo;
    char name[50];
    double balance;

public:
    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNo;

        cin.ignore();
        cout << "Enter Customer Name: ";
        cin.getline(name, 50);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display() const
    {
        cout << "\nAccount Number : " << accountNo;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance << endl;
    }

    int getAccountNo() const
    {
        return accountNo;
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            return false;
        }
        balance -= amount;
        return true;
    }
};

// Create Account
void createNewAccount()
{
    BankAccount acc;

    ofstream outFile("bank.dat", ios::binary | ios::app);

    acc.createAccount();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));

    outFile.close();

    cout << "\nAccount Created Successfully!\n";
}

// Display Account
void displayAccount(int accNo)
{
    BankAccount acc;
    bool found = false;

    ifstream inFile("bank.dat", ios::binary);

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
    {
        if (acc.getAccountNo() == accNo)
        {
            acc.display();
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found)
        cout << "\nAccount Not Found!\n";
}

// Deposit Money
void depositMoney(int accNo, double amount)
{
    BankAccount acc;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
    {
        if (acc.getAccountNo() == accNo)
        {
            acc.deposit(amount);

            int pos = file.tellg();
            file.seekp(pos - sizeof(acc));

            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            cout << "\nAmount Deposited Successfully!\n";
            file.close();
            return;
        }
    }

    cout << "\nAccount Not Found!\n";
    file.close();
}

// Withdraw Money
void withdrawMoney(int accNo, double amount)
{
    BankAccount acc;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
    {
        if (acc.getAccountNo() == accNo)
        {
            if (!acc.withdraw(amount))
            {
                cout << "\nInsufficient Balance!\n";
                file.close();
                return;
            }

            int pos = file.tellg();
            file.seekp(pos - sizeof(acc));

            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            cout << "\nWithdrawal Successful!\n";
            file.close();
            return;
        }
    }

    cout << "\nAccount Not Found!\n";
    file.close();
}

int main()
{
    int choice, accNo;
    double amount;

    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createNewAccount();
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;
            depositMoney(accNo, amount);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;
            withdrawMoney(accNo, amount);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            displayAccount(accNo);
            break;

        case 5:
            cout << "\nThank You for Using the System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
