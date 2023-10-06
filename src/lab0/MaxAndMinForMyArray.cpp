#include "MaxAndMinForMyArray.h"

const MyArray& max(const MyArray& firstArray,const  MyArray& secondArray) {
   return ((firstArray.getSize()) >= (secondArray.getSize())) ? firstArray : secondArray;
}

const MyArray& min( const MyArray& firstArray, const MyArray& secondArray) {
   return ((firstArray.getSize()) >= (secondArray.getSize())) ? secondArray : firstArray;
}
