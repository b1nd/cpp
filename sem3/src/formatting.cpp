#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    ////// C-style formatting
    const int i = 10;
    const double d = 12.2346;
    const string s = "some string";

    printf("integer: %i, double: %f, string: %s\n", i, d, s.c_str());
    printf("integer: %05d, double: %.3f,\nstring:%20s\n", i, d, s.c_str());

    cout << "--------------------" << endl;

    ////// ostream formatting
    // Флаги форматирования
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << "108 hex: " << 108 << endl;
    cout.unsetf(ios::hex);
    cout.setf(ios::dec);

    // Манипуляторы форматирования
    stringstream ss;
    ss << "integer: " << setw(5) << setfill('0') << i
       << ", double: " << fixed << setprecision(3) << d
       << ",\nstring:" << setw(20) << setfill(' ') << s;

    const string formattedString = ss.str();
    cout << formattedString << endl;

    return 0;
}