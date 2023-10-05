#pragma once

#include <string>
#include <iostream>
#include <exception>


class MyArray{
public:
    MyArray();
    MyArray(const size_t & n, unsigned char t = 0);
    MyArray(const std::initializer_list<unsigned char> &t);
    MyArray(const std::string &t);

    MyArray(const MyArray& other);//copy
    MyArray(MyArray&& other) noexcept; //move 

    unsigned char& operator[](const int i);
    unsigned char& operator[](const int i)const;
    void push_back(const unsigned char t);

    virtual ~MyArray() noexcept;

    MyArray& operator=(MyArray&& other);
    MyArray& operator=(const MyArray & other);

    size_t getSize();
    unsigned char* getPtr();

private:
    size_t _sizeArray;
    size_t _arrayCapacity;
    unsigned char* _arrayPtr;
};