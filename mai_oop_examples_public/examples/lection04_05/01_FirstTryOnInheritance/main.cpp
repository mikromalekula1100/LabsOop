#include <iostream>

using namespace std;

class Person
{
public:
    Person(std::string name): name{name}
    { std::cout << "dafault" << std::endl; }
    Person(const Person& p) {
        std::cout << "COPY" << std::endl;
        name = p.name;
    }

    Person(Person&& p) {
        std::cout << "COPY1" << std::endl;
        name = p.name;
    }

    std::string name;
private:
};

Person foo() {
    Person p("bla");
    std::cout << &p << endl;
    return p;
}


  
int main()
{
    Person p(foo());

    std::cout << p.name << std::endl;
    cout << &p << endl;
}