#include<iostream>

using namespace std;

class Array
{
private:
    int *array;
    int size;
    int length;

public:
    Array()
    {
        size = 10;

        array = new int[10];

        length = 0;
    }

    Array(int size)
    {
        size = size;

        length = 0;

        array = new int[size];
    }

    ~Array()
    {
        delete [] array;
    }

    void Display();

    void Insert(int index, int x);

    int Delete(int index);
};

void Array::Display()
{
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

void Array::Insert(int index, int x)
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

int Array::Delete(int index)
{
    int x = 0;

    if(index >= 0 && index < length)
    {
        x = array[index];

        for(int i = index; i < length - 1; i ++)
        {
            array[i] = array[i + 1];
        }

        length--;
    }

    return x;
}

int main()
{
    Array array(10);

    array.Insert(0, 5);

    array.Insert(1, 6);

    array.Insert(2, 9);

    cout << endl << "After Insertion, Elements are in List:" << endl << endl;

    array.Display();

    cout << endl << "Deleting Value: " << array.Delete(0) << endl;

    cout << endl << "After Deletion. Elements are in List:" << endl << endl;

    array.Display();

    return 0;
}
