/*Задание:
Разработать шаблонный класс, обрабатывающий динамический массив целочисленных,
вещественных и строковых данных или экземпляров класса point2d (именованных).
Значения генерируются случайным образом.
Разработать методы: конструктор по умолчанию, конструктор перемещения, деструктор,
получение значения элемента массива по индексу, запись переданного элемента в массив по индексу,
перегрузить оператор ввода-вывода, метод реализующий быструю сортировку.
Продемонстрировать работу всех методов класса.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <typename T>
class DynamicArray
{
public:
    // Конструктор по умолчанию
    DynamicArray() : m_size(0), m_data(nullptr) {}

    // Конструктор перемещения
    DynamicArray(DynamicArray<T> &&other) : m_size(other.m_size), m_data(other.m_data)
    {
        other.m_size = 0;
        other.m_data = nullptr;
    }

    // Деструктор
    ~DynamicArray()
    {
        delete[] m_data;
    }

    // Получение значения элемента массива по индексу
    T &operator[](int index)
    {
        return m_data[index];
    }

    // Запись переданного элемента в массив по индексу
    void write(int index, T value)
    {
        m_data[index] = value;
    }

    // Оператор ввода-вывода
    friend std::istream &operator>>(std::istream &is, DynamicArray<T> &arr)
    {
        int size;
        is >> size;
        arr.resize(size);
        for (int i = 0; i < size; i++)
        {
            is >> arr[i];
        }
        return is;
    }

    // Оператор вывода
    friend std::ostream &operator<<(std::ostream &os, const DynamicArray<T> &arr)
    {
        for (int i = 0; i < arr.m_size; i++)
        {
            os << arr[i] << " ";
        }
        os << std::endl;
        return os;
    }

    // Метод реализующий быструю сортировку
    void quickSort()
    {
        std::sort(m_data, m_data + m_size);
    }

    // Метод изменяющий размер массива
    void resize(int size)
    {
        T *newData = new T[size];
        int minSize = std::min(m_size, size);
        for (int i = 0; i < minSize; i++)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_size = size;
    }

private:
    int m_size;
    T *m_data;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    DynamicArray<int> intArr;
    intArr.resize(5);
    for (int i = 0; i < 5; i++)
    {
        intArr[i] = rand() % 100;
    }

    DynamicArray<double> doubleArr;
    doubleArr.resize(5);
    for (int i = 0; i < 5; i++)
    {
        doubleArr[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    DynamicArray<std::string> stringArr;
    stringArr.resize(5);
    for (int i = 0; i < 5; i++)
    {
        std::string str;
        for (int j = 0; j < 5; j++)
        {
            str += static_cast<char>(rand() % 26 + 'a');
        }
        stringArr[i] = str;
    }

    std::cout << "Массив целых чисел: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив вещественных чисел: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив строк: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << stringArr[i] << " ";
    }
    std::cout << std::endl;

    // Сортируем массивы
    intArr.quickSort();
    doubleArr.quickSort();
    stringArr.quickSort();

    std::cout << "Отсортированный массив целых чисел: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отсортированный массив вещественных чисел: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отсортированный массив строк: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << stringArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}