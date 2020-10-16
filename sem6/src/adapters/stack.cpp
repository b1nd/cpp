#include <iostream>
#include <stack>

using namespace std;

// адаптеры не поддерживают итераторы -> и алгоритмы из std недоступны
int main() {
    stack<int> st{{1, 2, 3}};
    st.push(4);
    cout << "st.top(): " << st.top() << endl;
    st.pop();
    cout << "st.size() after pop: " << st.size() << endl;
    cout << "st.top() after pop: " << st.top() << endl;
}