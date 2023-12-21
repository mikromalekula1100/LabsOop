#pragma once

#include <iostream>

class Visitor{
public:
    virtual void visit(ConcreteElementA& element) = 0;

};