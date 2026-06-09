#pragma once
#include <initializer_list>
#include <string>
#include <iostream>

/**
 * @brief Класс дека (двусторонней очереди) целых чисел.
 */
class Deque
{
private:
    /**
     * @brief Узел дека.
     */
    struct Node
    {
        int data;       ///< Значение элемента
        Node* prev;     ///< Указатель на предыдущий узел
        Node* next;     ///< Указатель на следующий узел
        Node(const int value);
    };

    Node* head;     ///< Указатель на первый элемент (голова)
    Node* tail;     ///< Указатель на последний элемент (хвост)
    size_t size;    ///< Количество элементов

    void clear();   ///< Очистка дека

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Deque();

    /**
     * @brief Конструктор со списком инициализации.
     */
    Deque(const std::initializer_list<int> list);

    /**
     * @brief Конструктор копирования.
     */
    Deque(const Deque& other);

    /**
     * @brief Конструктор перемещения.
     */
    Deque(Deque&& other) noexcept;

    /**
     * @brief Деструктор.
     */
    ~Deque();

    /**
     * @brief Оператор присваивания копированием.
     */
    Deque& operator=(const Deque& other);

    /**
     * @brief Оператор присваивания перемещением.
     */
    Deque& operator=(Deque&& other) noexcept;

    /**
     * @brief Оператор сдвига влево — извлечь элемент из головы.
     * @note Аналог pop_front, возвращает значение через параметр.
     */
    Deque& operator<<(int& value);

    /**
     * @brief Оператор сдвига вправо — добавить элемент в хвост.
     */
    Deque& operator>>(const int value);

    /**
     * @brief Добавить элемент в конец.
     */
    void push_back(const int value);

    /**
     * @brief Извлечь элемент из конца.
     */
    void pop_back();

    /**
     * @brief Прочитать хвостовой элемент.
     */
    int back() const;

    /**
     * @brief Добавить элемент в начало.
     */
    void push_front(const int value);

    /**
     * @brief Извлечь элемент из начала.
     */
    void pop_front();

    /**
     * @brief Прочитать головной элемент.
     */
    int front() const;

    /**
     * @brief Проверка на пустоту.
     */
    bool empty() const;

    /**
     * @brief Получить размер дека.
     */
    size_t getSize() const;

    /**
     * @brief Преобразование в строку.
     */
    std::string toString() const;

    /**
     * @brief Оператор вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Deque& deque);
};
