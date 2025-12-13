#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

/**
* @brief проверяет корректно ли выделена память под массив
* @param arr - проверяемый массив
*/
void check_pointer(const int* arr);

/**
* @brief считывает значение введённое с клавиатуры, с проверкой ввода
* @return число
*/
int Input(void);

/**
* @brief проверяет промежуток на корректность
* @param min - нижняя граница промежутка
* @param max - верхняя граница промежутка
*/
void checkINTERVAL(const int min, const int max);

/**
* @brief заполняет массив элементами, которые задаёт пользователь
* @param arr - массив, который будет заполнен
* @param size - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_Manual(int* arr, const size_t size, const int min, const int max);

/**
* @brief заполняет массив случайными элементами
* @param arr - массив, который будет заполнен
* @param size - размер массива
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void get_Random(int* arr, const size_t size, const int min, const int max);

/**
* @brief проверяет, лежит ли число в заданном промежутке
* @param input - число
* @param min - нижняя граница промежутка, в котором будут заданы числа
* @param max - верхняя граница промежутка, в котором будут заданы числа
*/
void checkInt(const int input, const int min, const int max);

/**
* @brief выводит массив на экран
* @param arr - массив, который будет выведен
* @param size - размер массива
*/
void printArr(const int* arr, const size_t size);

/**
* @brief копирует массив
* @param arr - массив, который будет скопирован
* @param size - размер массива
* @return скопированный массив
*/
int* defCopyarray(const int* arr, const size_t size);

/**
* @brief изменяет массив согласно условию №1
* @param arr - массив
* @param size - размер массива
* @return изменённый массив
*/
int* defTaskOne(int* arr, const size_t size);

/**
* @brief выводит индексы согласно условию №2
* @param arr - массив
* @param size - размер массива
*/
void defTaskTwo(const int* arr, const size_t size);

/**
* @brief находит пары согласно условию №3
* @param arr - массив
* @param size - размер массива
*/
int* defTaskThree(int* arr, const size_t size);

/**
* @brief Проверяет что переменная не меньше единицы
* @param input - значение проверяемой переменной
*/
void checkSize(const int input);

/**
* @brief считает элементы, кратные своему индексу (0 элемент считается как кратный)
* @param arr - массив
* @param size - размер массива
* @return количество подсчитанных элементов
*/
const int getCheck(const int* arr, const size_t size);

/**
* @param CHOISE_ONE - выбор ручного заполнения
* @param CHOISE_TWO - выбор заполнения случайными числами
* @param TASK_ONE - выбор выполнения 1 задания
* @param TASK_TWO - выбор выполнения 2 задания
* @param TASK_THREE - выбор выполнения 3 задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief точка входа в программу
* @return 0 или 1 в зависимости от корректности выполнения
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");

    printf("Введите количество элементов массива: ");
    size_t size = (size_t)Input();
    checkSize(size);

    int* mainARR = calloc(size, sizeof(int));
    check_pointer(mainARR);

    printf("Введите минимальное возможное число в массиве: ");
    const int min = Input();
    printf("Введите максимальное возможное число в массиве: ");
    const int max = Input();
    checkINTERVAL(min, max);
    printf("\nМассив из %zu строк будет заполнен числами в диапазоне [%d;%d]\n\n", size, min, max);

    printf("Как будет заполнен массив?\n%d - Ручное заполнение\n%d - Автоматическое заполнение\n", CHOISE_ONE, CHOISE_TWO);
    int choiseOne = Input();

    switch (choiseOne)
    {
    case CHOISE_ONE:
        get_Manual(mainARR, size, min, max);
        break;

    case CHOISE_TWO:
        get_Random(mainARR, size, min, max);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(mainARR);
        exit(1);
    }

    int* copyARR = defCopyarray(mainARR, size);
    check_pointer(copyARR);
    printArr(copyARR, size);

    printf("\nКакие будут преобразования?\n%d - Заменить первый отрицательный элемент массива нулем.\n%d - Вставить число К после всех элементов, кратных своему номеру.\n%d - Из элементов массива D сформировать массив A той же размерности по правилу: если номер четный, то значение элемента находится по формуле Ai = (i-1)*Di, а если нечетный, то по формуле Ai = Di*i*2.\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int choiseTwo = Input();

    switch (choiseTwo)
    {
    case TASK_ONE:
        defTaskOne(copyARR, size);
        printArr(copyARR, size);
        break;

    case TASK_TWO:
        defTaskTwo(copyARR, size);
        break;

    case TASK_THREE:
        defTaskThree(copyARR, size);
        printArr(copyARR, size);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(mainARR);
        free(copyARR);
        exit(1);
    }

    free(mainARR);
    free(copyARR);
    return 0;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error Ошибка выделения памяти\n");
        exit(1);
    }
}

int Input(void)
{
    int output = 0;
    if (!scanf_s("%d", &output))
    {
        fprintf(stderr, "Error Ошибка ввода\n");
        exit(1);
    }
    return output;
}

void checkINTERVAL(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error Ошибка ввода промежутка\n");
        exit(1);
    }
}

void get_Manual(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);

    for (size_t i = 0; i < size; i++)
    {
        printf("\narr[%zu] = ", i);
        arr[i] = Input();
        checkInt(arr[i], min, max);
    }
}

void get_Random(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}



void checkInt(const int input, const int min, const int max)
{
    if (input<min || input>max)
    {
        fprintf(stderr, "Error Ошибка ввода числа, оно должно лежать в указаном промежутке\n");
        exit(1);
    }
}

void printArr(const int* arr, const size_t size)
{
    check_pointer(arr);

    printf("Массив: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%5d\n", arr[i]);
    }
}

int* defCopyarray(const int* arr, const size_t size)
{
    check_pointer(arr);

    int* copyarr = calloc(size, sizeof(int));
    check_pointer(copyarr);

    for (size_t i = 0; i < size; i++)
    {
        copyarr[i] = arr[i];
    }

    return copyarr;
}

int* defTaskOne(int* arr, const size_t size)
{
    check_pointer(arr);

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = 0;
            break;
        }
    }

    return arr;
}

void defTaskTwo(const int* arr, const size_t size)
{
    check_pointer(arr);

    printf("\nЗадайте число k: ");
    int k = Input();

    const size_t newsize = size + getCheck(arr, size);
    int* newarr = calloc(newsize, sizeof(int));
    check_pointer(newarr);
    printf("%d", newsize);
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (j < newsize)
        {
            newarr[j++] = arr[i];
        }
        else
        {
            fprintf(stderr, "Error Выход за пределы массива");
            exit(1);
        }


        if (i == 0 || arr[i] % i == 0)
        {
            if (j < newsize)
            {
                newarr[j++] = k;
            }
            else
            {
                fprintf(stderr, "Error Выход за пределы массива");
                exit(1);
            }
        }
    }


    printf("\n");
    printArr(newarr, newsize);
    free(newarr);
}

int* defTaskThree(int* arr, const size_t size)
{
    check_pointer(arr);

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[i] = (i - 1) * arr[i];
        }
        else
        {
            arr[i] = arr[i] * i * 2;
        }
    }

    return arr;
}

const int getCheck(const int* arr, const size_t size)
{
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (i == 0 || arr[i] % i == 0)
        {
            count++;
        }
    }
    return count;
}

void checkSize(const int input)
{
    if (input < 1)
    {
        fprintf(stderr, "Error\nЧисло должно быть не меньше 1");
        exit(1);
    }
}

