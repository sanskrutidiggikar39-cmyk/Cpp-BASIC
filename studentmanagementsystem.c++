#include <iostream>
using namespace std;
main 
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    string names[n];
    int marks[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << (i + 1) << ": ";
        cin >> names[i];
        cout << "Enter marks of student " << (i + 1) << ": ";
        cin >> marks[i];
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << names[i] << ", Marks: " << marks[i] << endl;
    }

    return 0;
}