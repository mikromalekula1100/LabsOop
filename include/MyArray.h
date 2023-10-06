#pragma once

#include <string>
#include <iostream>
#include <exception>

const unsigned char INITIAL_VALUE_0 = 48;
const unsigned char INITIAL_VALUE_1 = 49;

class MyArray{
public:
    MyArray();
    MyArray(const size_t & n, unsigned char t = INITIAL_VALUE_0);
    MyArray(const std::initializer_list<unsigned char> &t);
    MyArray(const std::string &t);

    MyArray(const MyArray& other);//copy
    MyArray(MyArray&& other) noexcept; //move 

    unsigned char& operator[](const int i);
    const unsigned char& operator[](const int i)const;
    void push_back(const unsigned char t);
 
    virtual ~MyArray() noexcept;

    MyArray& operator=(MyArray&& other);
    MyArray& operator=(const MyArray & other);

    size_t getSize() const;
    unsigned char* getPtr() const;

    void printArray();
    // MyArray& max(MyArray& other);
    // MyArray& min(MyArray& other);

private:
    size_t _sizeArray;
    size_t _arrayCapacity;
    unsigned char* _arrayPtr;
};