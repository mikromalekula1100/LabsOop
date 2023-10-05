#include "MyArray.h"

MyArray::MyArray() : _sizeArray{0}, _arrayPtr{nullptr}, _arrayCapacity{0}{
    std::cout << "Default constructor" << std::endl;
}

MyArray::MyArray(const size_t& n, unsigned char t) : _sizeArray{n}, _arrayCapacity{n*2} {
    std::cout << "Fill constructor" << std::endl;
    _arrayPtr = new unsigned char [n*2];
    for(int i = 0; i < n; ++i)
        _arrayPtr[i] = t;
    
}

MyArray::MyArray(const std::initializer_list<unsigned char>& t) {
    std::cout << "Initializer list constructor" << std::endl;
    _arrayPtr = new unsigned char [t.size()*2];
    size_t i{0};
    for(auto& j : t)
        _arrayPtr[i++] = j;
    _sizeArray = t.size();
    _arrayCapacity = t.size()*2;

}

MyArray::MyArray(const std::string& t) {
    std::cout << "Copy string constructor" << std::endl;
    _sizeArray = t.size();
    _arrayCapacity = t.size() * 2;
    _arrayPtr = new unsigned char[_sizeArray*2];
    for(int i = 0; i < _sizeArray; ++i)
        _arrayPtr[i] = t[i];

}

unsigned char& MyArray::operator[](const int i) const {
    if(i < 0 or i > (_sizeArray-1)) throw std::logic_error("out of range");
    return *(_arrayPtr + i);
}

unsigned char& MyArray::operator[](const int i)  {
    if(i < 0 or i > (_sizeArray-1)) throw std::logic_error("out of range");
    return *(_arrayPtr + i);
}


void MyArray::push_back(const unsigned char t) {
    if(_sizeArray == 0){
        _arrayPtr = new unsigned char[1];
        _arrayCapacity = 1;
    }
    else{
        if(_sizeArray == _arrayCapacity){
            unsigned char* New = _arrayPtr;

            _arrayPtr = new unsigned char[(this->_arrayCapacity)*2];
            
            for(int i = 0; i < _sizeArray; ++i)
                *(_arrayPtr + i) = *(New+i);
            
            delete[] New;
            New = nullptr;
            _arrayCapacity *= 2;
        }
    }
    
    *((this->_arrayPtr) + _sizeArray) = t;
    _sizeArray += 1;
}

MyArray::~MyArray() noexcept {
    std::cout << "destructor"<<std::endl;
    if(_sizeArray > 0){
        delete[](_arrayPtr);
        _arrayPtr = nullptr;
        _sizeArray = 0;
    }
}

size_t MyArray::getSize() { return _sizeArray; }

unsigned char* MyArray::getPtr() { return _arrayPtr; }

MyArray::MyArray(const MyArray& other) : _sizeArray(other._sizeArray), _arrayCapacity(other._sizeArray * 2){
    std::cout << "Copy constructor" << std::endl;

    _arrayPtr = new unsigned char[_sizeArray];

    for(int i = 0; i < _sizeArray; ++i)
        _arrayPtr[i] = other._arrayPtr[i];
    
}

MyArray::MyArray(MyArray&& other) noexcept : _sizeArray(other._sizeArray), _arrayPtr(other._arrayPtr), _arrayCapacity(other._arrayCapacity){
    std::cout << "Move constructor" << std::endl;
    other._arrayPtr = nullptr;
    other._sizeArray = 0;
    other._arrayCapacity = 0;
}


//перемещающий оператор присваивания
MyArray& MyArray::operator=(MyArray&& other) { 
    std::cout << "move =" << std::endl;
    
    MyArray newArray(std::move(other));

    _arrayPtr = newArray._arrayPtr;
    _sizeArray = newArray._sizeArray;
    _arrayCapacity = newArray._arrayCapacity;
    newArray._arrayPtr = nullptr;
    return *this;

}

//копирующий оператор присваивания 
MyArray& MyArray::operator=(const MyArray& other) {
    std::cout << "copy =" << std::endl;

    if (this == &other)
        return *this;

    delete[] (_arrayPtr);
    _sizeArray = other._sizeArray;
    _arrayCapacity = other._arrayCapacity;
    this->_arrayPtr = new unsigned char[_arrayCapacity];
    for (int i = 0; i < _sizeArray; ++i)
             _arrayPtr[i] = other[i];

    return *this;
}


