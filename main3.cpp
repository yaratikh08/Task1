#include <iostream>
#include "Deque.h"

int main()
{
    Deque deque{ 2, 3, 4 };

    deque.push_front(1);   // [1, 2, 3, 4]
    deque.push_back(5);    // [1, 2, 3, 4, 5]

    std::cout << "Deque: " << deque << std::endl;
    std::cout << "Front: " << deque.front() << std::endl;
    std::cout << "Back:  " << deque.back() << std::endl;

    deque.pop_front();     // [2, 3, 4, 5]
    deque.pop_back();      // [2, 3, 4]
    std::cout << "After pop_front and pop_back: " << deque << std::endl;

    // Оператор >> — добавить в хвост
    deque >> 10 >> 20;
    std::cout << "After >> 10 >> 20: " << deque << std::endl;

    // Оператор << — извлечь из головы
    int val = 0;
    deque << val;
    std::cout << "Extracted from front: " << val << std::endl;
    std::cout << "Deque now: " << deque << std::endl;

    // Копирование
    Deque copy = deque;
    std::cout << "Copy: " << copy << std::endl;

    return 0;
}
