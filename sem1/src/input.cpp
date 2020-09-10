#include <iostream>

using namespace std;

int main() {
    int x;
    double y;

    cout << "Input int" << endl;
    cin >> x;
    cout << "Input double" << endl;
    cin >> y;
    cout << "sum: " << x + y << endl;

    cout << "Input int and double separated by space" << endl;
    cin >> x >> y;
    cout << "sum: " << x + y << endl;

    char c;
    cout << "Input char" << endl;
    cin >> c;
    cout << "char: " << c << endl;

    return 0;
}