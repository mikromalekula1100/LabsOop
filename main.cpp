#include <iostream>
#include "MyArray.h"
#include "BitString.h"
#include <vector>




int main(){

    BitString a("11000011111");
    BitString b("10111");
    b = a;
    b.print();
}

