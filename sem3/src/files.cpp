#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/// Базовые типы для работы с потоками
// Для всех типов потоков существует поток с префиксом 'w' для работы с wchar_t
// istream: считывает данные с потока
// ostream: записывает данные в поток
// iostream: считывает и записывает данные в поток
/// Потоки для работы с файлами (наследуют базовые)
// ifstream: для чтения с файла
// ofstream: для записи в файл
// fstream: совмещает запись и чтение
int main() {
    /* ios::in: файл открывается для ввода (чтения).
     * Может быть установлен только для объекта ifstream или fstream.
     * ios::out: файл открывается для вывода (записи). При этом старые данные удаляются.
     * Может быть установлен только для объекта ofstream или fstream.
     * ios::app: файл открывается для дозаписи. Старые данные не удаляются.
     * ios::ate: после открытия файла перемещает указатель в конец файла.
     * ios::trunc: файл усекается при открытии. Может быть установлен, если также установлен режим out.
     * (выбирается по умолчанию, если флаг out указан, а флаги ate и арр - нет)
     * ios::binary: файл открывается в бинарном режиме.
     */
    ofstream out;
    const string fileName = "rewrite.txt";
    out.open(fileName);
    if (out.is_open()) {
        out << "Hello World!\n" << "Some new line." << endl;
    }
    out.close();

    ifstream in;
    in.open(fileName);
    if (in.is_open()) {
        cout << fileName << ":" << endl;
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }

    ////// Append file
    const string appendFileName = "append.txt";
    fstream appendOut;
    // открытие файла для дозаписи, | устанавливает несколько режимов
    appendOut.open(appendFileName, ios::out | ios::app);
    if (appendOut.is_open()) {
        appendOut << "Append line." << endl;
    }
    appendOut.close();

    fstream appendIn;
    appendIn.open(appendFileName, ios::in);
    if (appendIn.is_open()) {
        cout << appendFileName << ":" << endl;
        while (!appendIn.eof()) {
            string s;
            appendIn >> s;
            cout << s << " ";
        }
        cout << endl;
    }

    ////// in and out stream
    fstream fs;
    fs.open("io.txt", ios::out);
    fs.close();
    fs.open("io.txt", ios::in | ios::out);
    if (fs.is_open()) {
        fs << "Hello world" << endl;
        // g - input, p - output
        cout << "tellg: " << fs.tellg() << endl;
        cout << "tellp: " << fs.tellp() << endl;
        // Сместиться в начало файла после записи
        fs.seekg(0, ios_base::beg);
        string s;
        fs >> s;
        cout << s << endl;
    }

    return 0;
}