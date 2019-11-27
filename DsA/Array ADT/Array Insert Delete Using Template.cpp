#include<iostream>

using namespace std;

template<class T>

class Array
{
private:
    T *array;
    int size;
    int length;

public:
    Array()
    {
        size = 10;

        array = new T[10];

        length = 0;
    }

    Array(int size)
    {
        size = size;

        length = 0;

        array = new T[size];
    }

    ~Array()
    {
        delete []array;
    }

    void Display();

    void Insert(int index, T x);

    T Delete(int index);
};

template<class T>
void Array<T>::Display()
{
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    if(index >= 0 && index <= length)
    {
        for(int i = length - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }

        array[index] = x;

        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x = 0;

    if(index >= 0 && index < length)
    {
        x = array[index];

        for(int i = index; i < length - 1; i++)
        {
            array[i] = array[i + 1];
        }

        length--;
    }

    return x;
}

int main()
{
    Array<char>array(10);

    array.Insert(0, 'a');

    array.Insert(1, 'b');

    array.Insert(2, 'c');

    cout << endl << "After Insertion, Elements in List:" << endl;

    array.Display();

    cout << endl << "Deleting Element from List: " << array.Delete(1) << endl;

    cout << endl << "After Deletion, Elements in List:" << endl;

    array.Display();

    return 0;
}

