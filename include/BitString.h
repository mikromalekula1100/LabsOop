#pragma once

#include <string>
#include <iostream>
#include "MyArray.h"

class BitString{
public:
    BitString();
    BitString(const std::string& s);
    BitString(const BitString& other);
    BitString& operator=(const BitString & other);
    void print();
private:    
    MyArray bitString;
  
};