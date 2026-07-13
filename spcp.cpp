#include <iostream>
using namespace std;
int main() {
    int cp;
    cout<< "Enter Cost Price : "; 
    cin >> cp;
    int sp;
    cout<< "Enter Selling Price : "; 
    cin >> sp;
    if (sp > cp) {
        cout << "Profit" << endl;
        cout << "Profit = " << sp - cp << endl;
    } else if (sp < cp) {
        cout << "Loss" << endl;
        cout << "Loss = " << cp - sp << endl;
    } else {
        cout << "No Profit No Loss" << endl;
    }
    return 0;
}