#pragma once

#include <string>
#include <iostream>
#include "MyArray.h"
#include "MaxAndMinForMyArray.h"

class BitString{
public:
    BitString();
    BitString(const std::string& s);
    BitString(const BitString& other);

    BitString& operator =(const BitString & other);
    BitString& operator or(const BitString & other);
    BitString& operator and(const BitString & other);
    BitString& operator xor(const BitString & other);
    BitString& operator ~();

    bool operator <(const BitString & other);
    bool operator ==(const BitString & other);
    bool operator >(const BitString & other);

    void print();
private:    
    MyArray bitString;
  
};