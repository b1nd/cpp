#include <string> // добавление std::string
#include <iostream>

using namespace std;

int main() {
    // \0 - нулевой символ конца символьного массива
    const char letters[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // Эквивалент, в конце неявный \0
    const char* helloArray = "hello";
    cout << "letters: " << letters << endl;
    cout << "helloArray: " << helloArray << endl;

    // Стандартное объявление строки
    string helloWorld = "Hello, world!";
    cout << "string helloWorld: " << helloWorld << endl;

    string lettersString = letters;
    cout << "lettersString: " << lettersString << endl;

    ////// Конструкторы string
    // По умолчанию = ""
    string emptyString;
    if (emptyString.empty()) {
        cout << "emptyString is empty!" << emptyString << endl;
    }

    string hhh(3, 'h');
    // Константная ссылка на строку
    const string& hhhRef = hhh;
    // Полная копия строки
    string hhhCopy = hhh;
    string hhhCopy2 = hhhCopy;
    // После перемещения hhhCopy2 ее лучше не использовать!
    string moveConstructor(move(hhhCopy2));

    cout << "hhh: " << hhh << endl;
    cout << "hhhRef: " << hhhRef << endl;
    cout << "hhhCopy: " << hhhCopy << endl;
    cout << "hhhCopy2 after move: " << hhhCopy2 << endl;
    cout << "moveConstructor: " << moveConstructor << endl;

    string initial("Initial string");
    string cutInitial(initial, 8, 3);
    cout << "Initial string size: " << initial.size() << endl;
    cout << "string(\"Initial string\", 8, 3): " << cutInitial << endl;

    ////// Конкатенация строк
    string hello = "hello";
    string world = "world";
    string hello_world = hello + " " + world; // hello world
    cout << "hello_world: " << hello_world << endl;

    string acc;
    acc += hello;
    cout << "acc append hello: " << acc << endl;
    acc += " ";
    acc += world;
    cout << "acc append space append world: " << acc << endl;

    ////// Сравнение строк
    // Сравнение строк регистрозависимое
    cout << "hello == string(\"hello\"): " << (hello == string("hello")) << endl;
    cout << "hello == string(\"Hello\"): " << (hello == string("Hello")) << endl;
    cout << "hello != world: " << (hello != world) << endl;

    ////// Индексатор строк
    cout << "hello[2]: " << hello[2] << endl;
    hello[1] = 'a';
    cout << "hello after hello[1] = 'a': " << hello << endl;

    ////// Ввод строк
    string name;
    cout << "Input your name: " << endl;
    // Считает полностью строку
    getline(cin, name);
    cout << "Your name: " << name << endl;

    string newName;
    cout << "Again input your name:" << endl;
    // Считает только подстроку до пробела
    cin >> newName;
    cout << "Your name: " << newName << endl;

    return 0;
}