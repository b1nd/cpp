#include <iostream>
#include <sstream>
#include <fstream>
#include "CyclicQueue.h"

using namespace std;

/*
 * Вам небходимо создать очередь с максимальной вместимостью = 100 и написать обработку команд.
 *
 * На вход программе подается файл, в котором содержится любая последовательность из представленных ниже команд,
 * однако гарантируется, что она корректная и не будет вызывать исключительных ситуаций.
 * push n - Добавить в очередь число n (значение n задается после команды). Программа должна вывести 'ok'.
 * pop - Удалить из очереди первый элемент. Программа должна вывести его значение.
 * front - Программа должна вывести значение первого элемента, не удаляя его из очереди.
 * size - Программа должна вывести количество элементов в очереди.
 * clear - Программа должна очистить очередь и вывести 'ok'.
 * exit - Программа должна вывести 'bye' и завершить работу.
 *
 * Весь ввод и вывод осуществляется через файлы.
 *
 * Пример входных данных:
 * push 5
 * push 6
 * size
 * front
 * pop
 * front
 * exit
 *
 * Пример выходных данных:
 * ok
 * ok
 * 2
 * 5
 * 5
 * 6
 * bye
 *
 * Соответственно, помимо реализации очереди, необходимо написать реализацию функции solve,
 * которая принимает на вход 2 аргумента - путь к файлу с тестом и путь к файлу, куда необходимо
 * выводить ответы, и с помощью объекта очереди с capacity = 100 решить задачу.
*/

void solve(const std::string& pathToTest, const std::string& pathToOut) {
    ifstream testFile {pathToTest};
    ofstream outFile {pathToTest};

    CyclicQueue *queue = new CyclicQueue();

    while (!testFile.eof()) {
        string cmd;
        int arg;
        testFile >> cmd;

        if (cmd == "push") {
            testFile >> arg;
            queue->push(arg);
            outFile << "ok";
        } else if (cmd == "pop") {
            outFile << queue->pop();
        } else if (cmd == "size") {
            outFile << queue->size();
        } else if (cmd == "front") {
            outFile << queue->front();
        } else if (cmd == "clear") {
            outFile << "ok";
            queue->clear();
        }
         else if (cmd == "exit") {
            outFile << "bye";
            break;
        }
    }
}

bool check(const string& answerPath, const string& progPath) {
    ifstream inAnswer{answerPath};
    ifstream inProg{progPath};
    bool flag = true;
    while (!inAnswer.eof()) {
        string s1, s2;
        inAnswer >> s1;
        inProg >> s2;
        if (s1 != s2) {
            flag = false;
        }
    }
    if (!inProg.eof()) {
        flag = false;
    }

    return flag;
}

// Первый аргумент командной строки должен содержать полный путь до тестовых данных (test/data)
int main(int argc, char** argv) {
    // if (argc < 2) {
    //     throw logic_error("Program must contain a command line argument to the directory with test data!");
    // }
    const string dataDirPath = "./data";

    for (int i = 1; i <= 16; ++i) {
        const string number = to_string(i);
        const string input = dataDirPath + number;
        const string output = number + ".out";
        const string answer = input + ".a";

        solve(input, output);

        if (check(answer, output)) {
            cout << "Test " << number << " OK" << endl;
        } else {
            cout << "Test " << number << " Fail" << endl;
        }
    }
    return 0;
}
