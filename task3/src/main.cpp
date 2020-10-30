#include <vector>
#include <algorithm>
#include <iostream>
#include "Timer.h"

int main() {
    using namespace std;

    vector<int> values(1000000, 1);

    Timer t;
    t.start();
    sort(values.begin(), values.end());
    t.stop();

    // default - nanoseconds
    cout << t.result() << " nanoseconds" << endl;
    cout << t.result<chrono::milliseconds>() << " milliseconds" << endl;

    return 0;
}