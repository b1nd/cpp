#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

template<class T>
class Node {

private:
    std::vector<T> data;

public:
    Node() = default;

    Node(std::vector<T> data) {
        this->data = data;
    }

    auto getData() {
        return data;
    }

    auto setData(std::vector<T> data) {
        this->data = data;;
    }
};

template<class T>
void writeVector(const std::string&& path, const std::vector<T>&& vector) {
    std::ofstream output{path, std::ofstream::out | std::ofstream::binary};
    // Записываем размер вектора
    int size = vector.size();
    output.write(reinterpret_cast<const char*>(&size), sizeof(T));

    // Записываем элементы вектора
    for (auto& item : vector) {
        output.write(reinterpret_cast<const char*>(&item), sizeof(T));
    }
}

template<class T>
auto readVector(const std::string& path) {
    std::ifstream input{path, std::ifstream::binary};
    std::vector<T> vector;

    // Читаем размер вектора
    int size = 0;
    input.read(reinterpret_cast<char*>(&size), sizeof(size));

    // Читаем элементы вектора
    T item;
    for (int i = 0; i < size; ++i) {
        input.read(reinterpret_cast<char*>(&item), sizeof(T));
        vector.push_back(item);
    }
    return vector;
}

int main() {
    // Инициализируем ноду дерева
    std::vector<int> data = {10, 20, 30};
    Node<int> node(data);

    // Сохраняем в бинарный файл
    writeVector("node", node.getData());

    // Читаем из бинарного файла
    node.setData(readVector<int>("node"));

    for (auto& item : node.getData()) {
        std::cout << item << " ";
    }
}