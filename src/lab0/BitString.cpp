#include "BitString.h"
#include <math.h>

BitString::BitString() {
    
}

BitString::BitString(const std::string& s) {
    size_t sizeOfStr = s.size();
    for(int i = 0; i < sizeOfStr; ++i){
        if(!(s[i] == '0' || s[i] == '1')) 
            throw std::logic_error("not a binary string");
        bitString.push_back(s[i]);
    }
}



void BitString::print() const{
    this->bitString.printArray();
 }

BitString::BitString(const BitString& other) : bitString(std::move(other.bitString)){ }

BitString& BitString::operator=(const BitString& other) {
    if(this == &other)
        return *this;
    
    BitString newString(other);

    bitString = std::move(newString.bitString);

    return *this;
    
}

BitString& BitString::operator or(const BitString& other) {

    MyArray newString = min(this->bitString, other.bitString);

    this->bitString = max(this->bitString, other.bitString);
    
    size_t sizeThis = this->bitString.getSize() - 1;
    size_t sizeNewString = newString.getSize() - 1;

    for(int i = 0; i <= sizeNewString; ++i){
        // 49 - 1; 48 - 0
        unsigned char buf = (this->bitString[sizeThis-i] + newString[sizeNewString-i]);
        if(buf > (INITIAL_VALUE_0 * 2)){
            bitString[i] = INITIAL_VALUE_1;
        }
            
        else{
            (this->bitString)[i] = INITIAL_VALUE_0;
        }
            
    }
    
    return *this;
}

BitString& BitString::operator and(const BitString& other) {

    MyArray newString = min(this->bitString, other.bitString);

    this->bitString = max(this->bitString, other.bitString);

    size_t sizeThis = this->bitString.getSize() - 1;
    size_t sizeNewString = newString.getSize() - 1;

    for(int i = 0; i <= sizeNewString; ++i){
        (this->bitString)[sizeThis-i] = std::min(this->bitString[sizeThis-i], newString[sizeNewString-i]);
    }
    return *this;
}

BitString& BitString::operator ~() {
    
    for(int i = 0; i < this->bitString.getSize(); ++i){
        if((this->bitString)[i] == INITIAL_VALUE_0)
            (this->bitString)[i] = INITIAL_VALUE_1;
        else
            (this->bitString)[i] = INITIAL_VALUE_0;
    }
    return *this;
}

BitString& BitString::operator xor(const BitString& other) {
    MyArray newString = min(this->bitString, other.bitString);

    this->bitString = max(this->bitString, other.bitString);

    size_t sizeThis = this->bitString.getSize() - 1;
    size_t sizeNewString = newString.getSize() - 1;

    for(int i = 0; i <= sizeNewString; ++i){
        if((this->bitString)[sizeThis-i] != newString[sizeNewString-i])
            (this->bitString)[sizeThis-i] = INITIAL_VALUE_1;
        else
            (this->bitString)[sizeThis-i] = INITIAL_VALUE_0;
    }   

    return *this;
}

bool BitString::operator<(const BitString& other) {

    int sizeThis = this->bitString.getSize();

    if(sizeThis == 0 || other.bitString.getSize()==0) throw std::logic_error("comparison of an empty string");
    
    MyArray newString = min(this->bitString, other.bitString);
    this->bitString = max(this->bitString, other.bitString);

    size_t sizeNewString = newString.getSize() - 1;
    int numberOfEquals = 0;

    for(int i = 0; i <= sizeNewString; ++i){
        if(this->bitString[i] > newString[i]) return 0;
        if(this->bitString[i] == newString[i]){
            numberOfEquals++;
            
        }
    }
    if(numberOfEquals == sizeThis) return 0;
    return 1;

 }


bool BitString::operator==(const BitString& other) {
    if(this->bitString.getSize() != other.bitString.getSize()) return 0;

    for(int i = 0; i < other.bitString.getSize(); ++i){
        if(this->bitString[i] != other.bitString[i]) return 0;
    }
    return 1;
}


bool BitString::operator>(const BitString& other) { 

    int sizeThis = this->bitString.getSize();
    int sizeOther = other.bitString.getSize();
    
    if(sizeThis == 0 || other.bitString.getSize()==0) throw std::logic_error("comparison of an empty string");

    MyArray newString = min(this->bitString, other.bitString);
    this->bitString = max(this->bitString, other.bitString);

    size_t sizeNewString = newString.getSize() - 1;
    int numberOfEquals = 0;

    for(int i = 0; i <= sizeNewString; ++i){
        if(this->bitString[i] < newString[i]) return 0;
        if(this->bitString[i] == newString[i]){
            numberOfEquals++;
        }
    }
    if((numberOfEquals == sizeOther) or (sizeThis > sizeOther)){
        return 0;
    } 

    return 1;
}
