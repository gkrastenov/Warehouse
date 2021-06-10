#pragma once
#include <iostream>

using usi = unsigned short int;

class String
{
private:

    char* data;
    usi length;
    usi capacity;

    void copy(const String&);
    void destroy();
    void resize();
    void resize(usi size);

public:

    String();
    String(const String&);
    String(const char*);
    String(const char);

    void copy(const char*);
    String& operator=(const char*);
    String& operator=(const String&);
    const bool operator==(const String&);

    ~String();

    const bool isEmpty() const;
    usi getLength() const;
    usi getCapacity() const;
    char operator[](usi) const;
    char& operator[](usi);

    void copyString(char*, usi, usi);
    void shrink_to_fit();
    void push_back(const char&);
    void push_back(const char*);
    void push_back(const String&);

    void swap(String);

    friend std::ostream& operator<<(std::ostream& out, const String&);
    friend std::istream& operator>>(std::istream& in, const String&);
};