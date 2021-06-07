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

public:

    List()
    {
        capacity = 8;
        size = 0;
        data = new T[capacity];
    }

    List(const List<T>& others)
    {
        copy(others);
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

    List<T>& operator=(const List<T>& others)
    {
        if (this != &others)
        {
            destroy();
            copy(others);
        }
        return *this;
    }

    ~List()
    {
        destroy();
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

    bool isEmpty() const
    {
        return size == 0;
    }

    void push_back(const T& newElem)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = newElem;
    }

    void pop_back()
    {
        T* toDelete = data[size - 1];
        delete toDelete;
        size--;
    }
};