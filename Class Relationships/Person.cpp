//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : Person.cpp
//Version : 0.1
/**
 * C++ Inheritance simple example
*/
#include <cstring>
#include <iostream>
using namespace std;
class Person {
    public:
        Person(const char* n, int a);
        Person();
        virtual ~Person();
        virtual void display();
    protected:
        int age;
        char *name;
};
Person::Person(const char *n, int a) {
    age = a;
    name = new char[(strlen(n)+1)];
    strcpy(name, n);

}
Person::Person() {
    age = 0;
    name = new char[1];
    name[0] = '\0';
}
Person::~Person() {
    delete name;
}
void Person::display() {
    cout << "This Person's name is " << name << " and its age is " << age << "."<< endl;
}