#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------- BOOK CLASS ----------------//
class Book
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a)
    {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};

//---------------- MEMBER CLASS ----------------//
class Member
{
public:
    int memberID;
    string name;

    Member(int id, string n)
    {
        memberID = id;
        name = n;
    }
};

//---------------- LIBRARY CLASS ----------------//
class Library
{
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add Book
    void addBook()
    {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "\nBook Added Successfully!\n";
    }

    // Display Books
    void displayBooks()
    {
        if(books.empty())
        {
            cout << "\nNo Books Available.\n";
            return;
        }

        cout << "\n=========== BOOK LIST ===========\n";

        for(Book &b : books)
        {
            cout << "\nBook ID : " << b.bookID;
            cout << "\nTitle   : " << b.title;
            cout << "\nAuthor  : " << b.author;
            cout << "\nStatus  : ";

            if(b.issued)
                cout << "Issued";
            else
                cout << "Available";

            cout << "\n-----------------------------\n";
        }
    }

    // Search Book
   void searchBook()
{
    if (books.empty())
    {
        cout << "\nNo books available.\n";
        return;
    }

    int choice;
    cout << "\n1. Search by Title";
    cout << "\n2. Search by Author";
    cout << "\nEnter Choice: ";
    cin >> choice;
    cin.ignore();

    string key;

    if (choice == 1)
    {
        cout << "Enter Title: ";
        getline(cin, key);

        bool found = false;

        for (Book &b : books)
        {
            if (b.title == key)
            {
                found = true;
                cout << "\nBook Found!";
                cout << "\nID: " << b.bookID;
                cout << "\nAuthor: " << b.author;
                cout << "\nStatus: " << (b.issued ? "Issued" : "Available") << endl;
            }
        }

        if (!found)
            cout << "\nBook not found.\n";
    }
    else if (choice == 2)
    {
        cout << "Enter Author: ";
        getline(cin, key);

        bool found = false;

        for (Book &b : books)
        {
            if (b.author == key)
            {
                found = true;
                cout << "\nBook Found!";
                cout << "\nID: " << b.bookID;
                cout << "\nTitle: " << b.title << endl;
            }
        }

        if (!found)
            cout << "\nBook not found.\n";
    }
}

    // Add Member
    void addMember()
    {
        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "\nMember Added Successfully!\n";
    }

    // Display Members
    void displayMembers()
    {
        if(members.empty())
        {
            cout << "\nNo Members Registered.\n";
            return;
        }

        cout << "\n=========== MEMBER LIST ===========\n";

        for(Member &m : members)
        {
            cout << "\nMember ID : " << m.memberID;
            cout << "\nName      : " << m.name;
            cout << "\n-----------------------------\n";
        }
    }

    // Issue Book
    void issueBook()
    {
        int bookID, memberID;

        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cout << "Enter Member ID: ";
        cin >> memberID;

        bool memberExists = false;

        for(Member &m : members)
        {
            if(m.memberID == memberID)
            {
                memberExists = true;
                break;
            }
        }

        if(!memberExists)
        {
            cout << "\nMember Not Found!\n";
            return;
        }

        for(Book &b : books)
        {
            if(b.bookID == bookID)
            {
                if(b.issued)
                {
                    cout << "\nBook Already Issued!\n";
                    return;
                }

                b.issued = true;
                cout << "\nBook Issued Successfully!\n";
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    // Return Book
    void returnBook()
    {
        int id;

        cout << "\nEnter Book ID: ";
        cin >> id;

        for(Book &b : books)
        {
            if(b.bookID == id)
            {
                if(!b.issued)
                {
                    cout << "\nBook Was Not Issued.\n";
                    return;
                }

                b.issued = false;
                cout << "\nBook Returned Successfully!\n";
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    // Statistics
    void statistics()
    {
        int issued = 0;

        for(Book &b : books)
        {
            if(b.issued)
                issued++;
        }

        cout << "\n========== LIBRARY REPORT ==========\n";
        cout << "Total Books      : " << books.size() << endl;
        cout << "Available Books  : " << books.size() - issued << endl;
        cout << "Issued Books     : " << issued << endl;
        cout << "Total Members    : " << members.size() << endl;
    }
};

//---------------- MAIN FUNCTION ----------------//
int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n      LIBRARY MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Add Member";
        cout << "\n5. Display Members";
        cout << "\n6. Issue Book";
        cout << "\n7. Return Book";
        cout << "\n8. Library Statistics";
        cout << "\n9. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                lib.searchBook();
                break;

            case 4:
                lib.addMember();
                break;

            case 5:
                lib.displayMembers();
                break;

            case 6:
                lib.issueBook();
                break;

            case 7:
                lib.returnBook();
                break;

            case 8:
                lib.statistics();
                break;

            case 9:
                cout << "\nThank You for Using the Library Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}