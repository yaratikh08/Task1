#include <clocale>
#include <iostream>
#include <limits>
#include <string>

#include "ConstantGenerator.h"
#include "FunctionGenerator.h"
#include "RandomGenerator.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

namespace
{
    const std::string PROMPT_ROWS = "Введите количество строк: ";
    const std::string PROMPT_COLUMNS = "Введите количество столбцов: ";
    const std::string PROMPT_MODE = "Заполнение: 1 - случайное, 2 - клавиатура, 3 - константа: ";
    const std::string PROMPT_TASK = "Задание: 1 или 2: ";
    const std::string PROMPT_ELEMENT = "Введите элемент: ";
    const std::string PROMPT_CONSTANT = "Введите постоянное значение: ";
    const std::string ERROR_INPUT = "Ошибка ввода.\n";
    const std::string ERROR_SIZE = "Размеры матрицы должны быть положительными.\n";
    const std::string ERROR_MODE = "Неизвестный режим заполнения.\n";
    const std::string TITLE_TASK1 = "После задания 1 (минимальный элемент каждой строки заменён нулём):\n";
    const std::string TITLE_TASK2 = "После задания 2 (удалены столбцы с нечётным положительным элементом):\n";
}

enum class GenerationMode
{
    Random = 1,
    Keyboard = 2,
    Constant = 3
};

enum class TaskMode
{
    First = 1,
    Second = 2
};

bool readInt(const std::string& message, int& value)
{
    std::cout << message;

    if (std::cin >> value)
    {
        return true;
    }

    std::cout << ERROR_INPUT; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

template <typename Task>
void printAndSolve(Task& task, const std::string& title)
{
    std::cout << "\nИсходная матрица:\n" << task.getMatrix() << '\n';
    task.solve();
    std::cout << "\n" << title << task.getMatrix() << '\n';
}

template <typename Generator>
int runTask(
    const int rows,
    const int columns,
    Generator& generator,
    const TaskMode taskMode
)
{
    if (taskMode == TaskMode::First)
    {
        Task1 task(rows, columns, generator);
        printAndSolve(task, TITLE_TASK1); 
        return 0;
    }

    if (taskMode == TaskMode::Second)
    {
        Task2 task(rows, columns, generator);
        printAndSolve(task, TITLE_TASK2); 
        return 0;
    }

    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int rows{};
    int columns{};
    int modeValue{};
    int taskValue{};

    if (!readInt(PROMPT_ROWS, rows) ||
        !readInt(PROMPT_COLUMNS, columns) ||
        !readInt(PROMPT_MODE, modeValue) ||
        !readInt(PROMPT_TASK, taskValue))
    {
        return 1;
    }

    if (rows <= 0 || columns <= 0)
    {
        std::cout << ERROR_SIZE; 
        return 1;
    }

    const auto mode = static_cast<GenerationMode>(modeValue);
    const auto taskMode = static_cast<TaskMode>(taskValue);

    switch (mode)
    {
    case GenerationMode::Random:
    {
        RandomGenerator generator(-10, 10);
        return runTask(rows, columns, generator, taskMode);
    }
    case GenerationMode::Keyboard:
    {
        FunctionGenerator generator([] {
            int value{};
            readInt(PROMPT_ELEMENT, value); 
            return value;
            });
        return runTask(rows, columns, generator, taskMode);
    }
    case GenerationMode::Constant:
    {
        int value{};

        if (!readInt(PROMPT_CONSTANT, value))
        {
            return 1;
        }

        ConstantGenerator generator(value);
        return runTask(rows, columns, generator, taskMode);
    }
    default:
        std::cout << ERROR_MODE;
        return 1;
    }
}
