#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int age;
    string course;
    float marks;
};

vector<Student> students;

void loadStudents()
{
    students.clear();

    ifstream file("students.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        Student s;
        string temp;

        getline(ss, temp, ',');
        s.rollNo = stoi(temp);

        getline(ss, s.name, ',');

        getline(ss, temp, ',');
        s.age = stoi(temp);

        getline(ss, s.course, ',');

        getline(ss, temp);
        s.marks = stof(temp);

        students.push_back(s);
    }

    file.close();
}

void saveStudents()
{
    ofstream file("students.txt");

    for (Student s : students)
    {
        file << s.rollNo << ","
             << s.name << ","
             << s.age << ","
             << s.course << ","
             << s.marks << endl;
    }

    file.close();
}

void addStudent()
{
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    for (Student st : students)
    {
        if (st.rollNo == s.rollNo)
        {
            cout << "Roll Number already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, s.course);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    saveStudents();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    if (students.empty())
    {
        cout << "\nNo Records Found!\n";
        return;
    }

    cout << "\n========== STUDENT RECORDS ==========\n";

    for (Student s : students)
    {
        cout << "\nRoll No : " << s.rollNo << endl;
        cout << "Name    : " << s.name << endl;
        cout << "Age     : " << s.age << endl;
        cout << "Course  : " << s.course << endl;
        cout << "Marks   : " << s.marks << endl;
        cout << "------------------------------\n";
    }
}

void searchStudent()
{
    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    for (Student s : students)
    {
        if (s.rollNo == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll No : " << s.rollNo << endl;
            cout << "Name    : " << s.name << endl;
            cout << "Age     : " << s.age << endl;
            cout << "Course  : " << s.course << endl;
            cout << "Marks   : " << s.marks << endl;
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void updateStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    for (Student &s : students)
    {
        if (s.rollNo == roll)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Course: ";
            cin.ignore();
            getline(cin, s.course);

            cout << "Enter New Marks: ";
            cin >> s.marks;

            saveStudents();

            cout << "\nStudent Updated Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void deleteStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].rollNo == roll)
        {
            students.erase(students.begin() + i);
            saveStudents();
            cout << "\nStudent Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

int main()
{
    loadStudents();

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}