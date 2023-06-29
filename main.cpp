/*�������:
����������� ��������� �����, �������������� ������������ ������ �������������,
������������ � ��������� ������ ��� ����������� ������ point2d (�����������).
�������� ������������ ��������� �������.
����������� ������: ����������� �� ���������, ����������� �����������, ����������,
��������� �������� �������� ������� �� �������, ������ ����������� �������� � ������ �� �������,
����������� �������� �����-������, ����� ����������� ������� ����������.
������������������ ������ ���� ������� ������.
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
    // ����������� �� ���������
    DynamicArray() : m_size(0), m_data(nullptr) {}

    // ����������� �����������
    DynamicArray(DynamicArray<T> &&other) : m_size(other.m_size), m_data(other.m_data)
    {
        other.m_size = 0;
        other.m_data = nullptr;
    }

    // ����������
    ~DynamicArray()
    {
        delete[] m_data;
    }

    // ��������� �������� �������� ������� �� �������
    T &operator[](int index)
    {
        return m_data[index];
    }

    // ������ ����������� �������� � ������ �� �������
    void write(int index, T value)
    {
        m_data[index] = value;
    }

    // �������� �����-������
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

    // �������� ������
    friend std::ostream &operator<<(std::ostream &os, const DynamicArray<T> &arr)
    {
        for (int i = 0; i < arr.m_size; i++)
        {
            os << arr[i] << " ";
        }
        os << std::endl;
        return os;
    }

    // ����� ����������� ������� ����������
    void quickSort()
    {
        std::sort(m_data, m_data + m_size);
    }

    // ����� ���������� ������ �������
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

    std::cout << "������ ����� �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "������ ������������ �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "������ �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << stringArr[i] << " ";
    }
    std::cout << std::endl;

    // ��������� �������
    intArr.quickSort();
    doubleArr.quickSort();
    stringArr.quickSort();

    std::cout << "��������������� ������ ����� �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "��������������� ������ ������������ �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "��������������� ������ �����: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << stringArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}