#include <iostream>

using namespace std;

// 0 = false
// не 0 = true
int main() {
    int i = 123;
    bool boolean = i;

    cout << "boolean: " << boolean << endl;

    if (boolean) {
        cout << "boolean is true" << endl;
    }

    if (0) {
        cout << 0 << endl;
    } else if (true) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    cout << (true ? 'a' : 'b') << endl << endl;

    for (int i = 0; i < 3; ++i) {
        // Скрывает локальную переменную i выше
        cout << "i: " << i << endl;
    }
    cout << endl;

    for (int i = 0, j = 0; i < 4 && j < 3; ++i, cout << "j: " << j++ << endl);

    cout << endl;

    for (int c = 0; c < 5; ++c) {
        if (c == 3) continue;
        cout << "c: " << c << endl;
    }
    cout << endl;

    for (int k = 0; k < 5; ++k) {
        if (k == 3) break;
        cout << "k: " << k << endl;
    }
    cout << endl;

    bool flag = true;
    while (flag) {
        cout << "flag: " << boolalpha << flag << noboolalpha << endl;
        flag = false;
    }

    do {
        cout << "once!" << endl;
    } while (false);

    int a = 3;
    cout << "a = ";
    switch (a) {
        case 5:
            cout << 5;
            break;
        case 4:
        case 3:
        case 2:
            cout << "from 2 to 4";
            break;
        case 1:
            cout << 1;
            break;
        default:
            cout << "below 1";
    }
    cout << endl;

    return 0;
}