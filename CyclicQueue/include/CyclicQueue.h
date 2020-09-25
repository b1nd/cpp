#ifndef CPP_CYCLICQUEUE_H
#define CPP_CYCLICQUEUE_H

/*
 * Зацикленная очередь - некоторая модификация обычной очереди,
 * которая позволяет по максимуму использовать отведенную ей память.
 * Допустим, у нас есть зацикленная очередь, в которую можно поместить максимум 6 элементов.
 * Сделаем следующую последовательность команд:
 * push(1)
 * push(2)
 * push(3)
 * push(4)
 * push(5)
 * Массив внутри очереди будет выглядеть так: [1, 2, 3, 4, 5, ?]
 * Теперь удалим первые 3 элемента:
 * pop()
 * pop()
 * pop()
 * Массив выглядит так:
 * [?, ?, ?, 4, 5, ?]
 * Если добавить еще 3 элемента:
 * push(6)
 * push(7)
 * push(8)
 * То массив станет выглядеть так:
 * [7, 8, ?, 4, 5, 6]
 * То есть массив внутри зацикливается и, после того, как элементы достигли его конца, они вставляются в начало.
 */
class CyclicQueue {
public:
    CyclicQueue();

    explicit CyclicQueue(int capacity);

    CyclicQueue(const CyclicQueue& other);

    ~CyclicQueue();

    CyclicQueue& operator=(const CyclicQueue& other);

    int size() const;

    void push(int item);

    int pop();

    int front() const;

    void clear();

private:
    int* arr_;
    int capacity_, size_, left_, right_;
};

#endif //CPP_CYCLICQUEUE_H
