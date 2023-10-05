#include "BitString.h"

BitString::BitString() {
    
}

BitString::BitString(const std::string& s) {
    size_t sizeOfStr = s.size();

    for(int i = 0; i < sizeOfStr; ++i){
        if(!(s[i] == '0' || s[i] == '1')) throw std::logic_error("not a binary string");
        bitString.push_back(s[i]);
    }
}



void BitString::print() {
    size_t sizeBstring= bitString.getSize();
    if(sizeBstring == 0) std::cout<<" "<<std::endl;
    else{
        for(int i = 0; i < sizeBstring; ++i)
            std::cout<<bitString[i];
        std::cout<<std::endl;    
    }
}

BitString::BitString(const BitString& other) : bitString(std::move(other.bitString)){ }

BitString& BitString::operator=(const BitString& other) {
    if(this == &other)
        return *this;
    
    BitString newString(other);

    bitString = std::move(newString.bitString);

    return *this;
    
}
