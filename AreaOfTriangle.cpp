#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float base, height, area, perimeter;
    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << "Enter the height of the triangle: ";
    cin >> height;
    area = 0.5 * base * height;
    perimeter = base + height + sqrt(base * base + height * height);
    cout << "The area of the triangle is: " << area << endl;
    cout << "The perimeter of the triangle is: " << perimeter << endl
    cout<< "Thank You!!" << endl; 
    return 0;
}
