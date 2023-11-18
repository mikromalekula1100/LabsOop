#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <memory>


template <typename T>

class Array{

private:
    size_t _sizeArray;
    size_t _arrayCapacity;
    
    shared_ptr<T[]> _arrayPtr;

public:
    Array();
    Array(const size_t &, const T&);
    Array(const std::initializer_list<T> &);
    

    Array(const Array<T>&);
    Array(Array<T>&&) noexcept; 

    T& operator[](const int);
    const T& operator[](const int)const;
    void push_back(const T&);
 
    virtual ~Array() noexcept;

    Array& operator=(Array<T>&&);
    Array& operator=(const Array<T>&);
    
    bool operator==(const Array<T>&) const;

    size_t getSize() const;
    
    void printArray() const;
    
    void erase(size_t);

};

Array()->Array<int>;
// ----------------------------------------------------------------------------------------------------------
// ------------------implementation--------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------



template <typename T>
Array<T>::Array() : _sizeArray{0}, _arrayPtr{nullptr}, _arrayCapacity{0}{}

template <typename T>
Array<T>::Array(const size_t& n, const T& obj) : _sizeArray{n}, _arrayCapacity{n*2} {

    _arrayPtr = shared_ptr<T[]>(new T(n*2));
    

    for(int i = 0; i < n; ++i)
        _arrayPtr[i] = obj;
    
}

template <typename T>
Array<T>::Array(const std::initializer_list<T>& list) {

    _arrayPtr = shared_ptr<T[]>(new T[list.size()*2]);
    

    size_t i{0};

    for(auto& j : list)
        _arrayPtr[i++] = j;

    _sizeArray = list.size();
    _arrayCapacity = list.size()*2;

}

template <typename T>
const T& Array<T>::operator[](const int i) const {
    if(i < 0 or i > (_sizeArray-1)){
        throw std::logic_error("out of range");
    } 
    return _arrayPtr[i];
}

template <typename T>
T& Array<T>::operator[](const int i)  {
    if(i < 0 or i > (_sizeArray-1)) throw std::logic_error("out of range for const object");
    return _arrayPtr[i];
}

template <typename T>
void Array<T>::push_back(const T& elem) {
    if(_sizeArray == 0){
        _arrayPtr = shared_ptr<T[]>(new T[1]);
        _arrayCapacity = 1;
    }

    else{
        if(_sizeArray == _arrayCapacity){


            shared_ptr<T[]> New = _arrayPtr;

            _arrayPtr = shared_ptr<T[]>(new T[(this->_arrayCapacity)*2]);
            
            for(int i = 0; i < _sizeArray; ++i)
                _arrayPtr[i] = New[i];
            
            _arrayCapacity *= 2;
        }
    }
    
    this->_arrayPtr[_sizeArray] = elem;
    _sizeArray += 1;
}

template <typename T>
Array<T>::~Array() noexcept {}

template <typename T>
bool Array<T>::operator==(const Array<T>& other) const{ 
    if(this->_sizeArray != other._sizeArray) return false;

    for(int i = 0; i < other._sizeArray; ++i){
        if(this->_arrayPtr[i] != other[i]){
            return false;
        }
    }
            
    return true;
}

template <typename T>
size_t Array<T>::getSize() const { return _sizeArray; }



template <typename T>
void Array<T>::printArray() const{

    for(int i = 0; i < this->_sizeArray; ++i){

        std::cout<<this->_arrayPtr[i];
    }
    
    std::cout<<std::endl;
}

template <typename T>
inline void Array<T>::erase(size_t index) {
    
    if(index < 0 || index >= _sizeArray) {
        throw std::out_of_range("Index out of range");
    }

    for(size_t i = index; i < _sizeArray - 1; ++i) {
        _arrayPtr[i] = _arrayPtr[i + 1];
    }

    --_sizeArray;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _sizeArray(other._sizeArray), _arrayCapacity(other._sizeArray * 2){
    // std::cout << "Copy constructor" << std::endl;

    _arrayPtr = shared_ptr<T[]>(new T[_sizeArray]);

    for(int i = 0; i < _sizeArray; ++i)
        _arrayPtr[i] = other._arrayPtr[i];
    
}
template <typename T>
Array<T>::Array(Array<T>&& other) noexcept : _sizeArray(other._sizeArray), _arrayPtr(move(other._arrayPtr)), _arrayCapacity(other._arrayCapacity){
    other._sizeArray = 0;
    other._arrayCapacity = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& other) { 
     
    Array newArray(std::move(other));

    _arrayPtr = move(newArray._arrayPtr);
    _sizeArray = newArray._sizeArray;
    _arrayCapacity = newArray._arrayCapacity;
    return *this;

}

template <typename T>

Array<T>& Array<T>::operator=(const Array<T>& other) {

    if (this == &other)
        return *this;

   
    _sizeArray = other._sizeArray;
    _arrayCapacity = other._arrayCapacity;

    this->_arrayPtr = shared_ptr<T[]>(new T[_arrayCapacity]);

    for (int i = 0; i < _sizeArray; ++i)
             _arrayPtr[i] = other[i];

    return *this;
}
