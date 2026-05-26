#include "Deque.h"
#include <sstream>
#include <stdexcept>

/* ================= Node ================= */
Deque::Node::Node(const int value)
    : data(value), prev(nullptr), next(nullptr)
{
}

/* ================= Constructors ================= */
Deque::Deque()
    : head(nullptr), tail(nullptr), size(0)
{
}

Deque::Deque(const std::initializer_list<int> list)
    : head(nullptr), tail(nullptr), size(0)
{
    for (int value : list)
        push_back(value);
}

Deque::Deque(const Deque& other)
    : head(nullptr), tail(nullptr), size(0)
{
    Node* current = other.head;
    while (current)
    {
        push_back(current->data);
        current = current->next;
    }
}

Deque::Deque(Deque&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

/* ================= Destructor ================= */
Deque::~Deque()
{
    clear();
}

/* ================= Private ================= */
void Deque::clear()
{
    Node* current = head;
    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/* ================= Operators ================= */
Deque& Deque::operator=(const Deque& other)
{
    if (this != &other)
    {
        clear();
        Node* current = other.head;
        while (current)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

Deque& Deque::operator=(Deque&& other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

Deque& Deque::operator<<(int& value)
{
    value = front();
    pop_front();
    return *this;
}

Deque& Deque::operator>>(const int value)
{
    push_back(value);
    return *this;
}

/* ================= Public ================= */
void Deque::push_back(const int value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void Deque::pop_back()
{
    if (empty())
        throw std::out_of_range("Deque is empty");

    Node* toDelete = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete toDelete;
    size--;
}

int Deque::back() const
{
    if (empty())
        throw std::out_of_range("Deque is empty");
    return tail->data;
}

void Deque::push_front(const int value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void Deque::pop_front()
{
    if (empty())
        throw std::out_of_range("Deque is empty");

    Node* toDelete = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete toDelete;
    size--;
}

int Deque::front() const
{
    if (empty())
        throw std::out_of_range("Deque is empty");
    return head->data;
}

bool Deque::empty() const
{
    return size == 0;
}

size_t Deque::getSize() const
{
    return size;
}

std::string Deque::toString() const
{
    std::ostringstream ss;
    Node* current = head;
    while (current)
    {
        ss << current->data;
        if (current->next)
            ss << " ";
        current = current->next;
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Deque& deque)
{
    os << deque.toString();
    return os;
}
