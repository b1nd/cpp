#include <iostream>
#include <set>
#include <fstream>

#include <BinaryTree.h>

using namespace std;

// Первый аргумент командной строки должен содержать полный путь до файла с тестовыми данными из папки test/data
int main(int argc, char** argv) {
    if (argc < 2) {
        throw logic_error("Program must contain a command line path argument to the file with test data!");
    }
    const string testDataPath = argv[1];
    fstream in(testDataPath, ios::in);

    if (!in.is_open()) {
        throw runtime_error("IO Exception");
    }
    const int N = 10000;
    BinaryTree<int> binaryTree;
    set<int> s;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string str;
        int x;
        in >> str;
        if (str == "insert") {
            in >> x;
            if (!binaryTree.search(x)) {
                binaryTree.insert(x);
            }
            s.insert(x);
        }
        if (str == "search") {
            in >> x;
            if (binaryTree.search(x) != (bool) s.count(x))
                cnt++;
        }
        if (str == "min" && !s.empty()) {
            try {
                if (binaryTree.minimum() != *s.begin())
                    cnt++;
            } catch (...) {}
        }
        if (str == "max" && !s.empty()) {
            try {
                auto it = s.end();
                if (binaryTree.maximum() != *(--it))
                    cnt++;
            } catch (...) {}
        }
        if (str == "remove") {
            in >> x;
            binaryTree.remove(x);
            s.erase(x);
        }
        if (binaryTree.size() != s.size()) {
            cnt++;
        }
    }
    if (cnt) {
        cout << "Fail " << cnt;
    } else {
        cout << "OK";
    }
    return 0;
}
