#ifndef CPP_BINARYTREE_H
#define CPP_BINARYTREE_H

/*
 * Вам необходимо реализовать шаблонное бинарное дерево поиска.
 * Перед Вами прототип, в котором предполагается рекурсивная реализация БДП.
 * Однако, если Вы хотите, можете изменить его так, чтобы реализация была через циклы.
 * Однако, нельзя менять шаблон так, чтобы реализация была на массиве, а не на указателях.
 * Тесты делятся на 3 уровня.
 * lvl_1_IS.txt - тест для провреки работоспособности вставки и поиска
 * lvl_2_ISMM.txt - тест для проверки вставки, поиска, нахождения минимума и максимума
 * lvl_3_ISMMD.txt - добавляется проверка на удаление
 * Чтобы запустить тот или иной тест необходимо просто передать программе путь до
 * нужного файла в аргументах командной строки.
 * Помимо реализации БДП ничего писать/менять не нужно.
 *
 */

template<typename T>
struct Node {
    Node* left;
    Node* right;
    T key;

    Node() : left(nullptr), right(nullptr) {};

    explicit Node(T key) : Node() {
        this->key = key;
    };

    ~Node() {
        delete left;
        delete right;
    }
};

template<typename T>
class BinaryTree {
public:
    BinaryTree() : root_(nullptr) {
        size_ = 0;
    };

    ~BinaryTree() {
        delete root_;
    }

    // Вставка элемента по ключу
    void insert(T key);

    // Поиск элемента по ключу
    bool search(T key);

    // Удаление элемента по ключу
    // Необходимо проверить, что такой элемент есть, если нет - ничего не делать
    void remove(T key);

    // Поиск минимума
    // Если дерево пустое - выбрасывать исключение
    T minimum();

    // Поиск максимума
    // Если дерево пустое - выбрасывать исключение
    T maximum();

    int size() const {
        return size_;
    }

private:
    void recursiveInsert(T key, Node<T>* pNode);

    bool recursiveSearch(T key, Node<T>* pNode);

    Node<T>* recursiveRemove(T key, Node<T>* pNode);

    T recursiveMinimum(Node<T>* pNode);

    T recursiveMaximum(Node<T>* pNode);

private:
    Node<T>* root_;
    int size_;
};

#include "BinaryTree.hpp"

#endif //CPP_BINARYTREE_H