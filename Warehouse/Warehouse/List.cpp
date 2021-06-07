#pragma once
#include <iostream>

using usi = unsigned short int;

template<typename T>
class List
{
private:
    T* data;
    usi size;
    usi capacity;

    void destroy()
    {
        delete[] data;
    }
    void resize()
    {
        capacity += 8;
        T* newBuffer = new T[capacity];
        for (usi i = 0; i < size; i++)
        {
            newBuffer[i] = data[i];
        }
        destroy();
        data = newBuffer;
    }
    void copy(const List<T>& others)
    {
        capacity = others.capacity;
        size = others.size;
        data = new T[capacity];

        for (usi i = 0; i < size; i++)
        {
            data[i] = others.data[i];
        }
    }
public:

    List()
    {
        capacity = 8;
        size = 0;
        data = new T[capacity];
    }
    ~List()
    {
        destroy();
    }

    List(const List<T>& others)
    {
        copy(others);
    }
    List<T>& operator=(const List<T>& others)
    {
        if (this != &others)
        {
            destroy();
            copy(others);
        }
        return *this;
    }

    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << data[i];
        }

    }
    usi getSize() const
    {
        return size;
    }
    usi getCapacity() const
    {
        return capacity;
    }

    T operator[](usi i) const
    {
        if (i < size)
        {
            return data[i];
        }
        else
        {
            std::cout << "Invalid index: " << i;
            throw;
        }
    }

    T& operator[](usi i)
    {
        if (i < size)
        {
            return data[i];
        }
        else
        {
            std::cout << "Invalid index: " << i;
            throw;
        }
    }
    void add(const T& newElem)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = newElem;
    }
    void remove(const T& elem)
    {
        int elementIndex = -1;
        for (size_t i = 0; i < this->size; i++)
        {
            if (data[i] == elem)
            {
                elementIndex = i;
                break;
            }
        }
    }
};