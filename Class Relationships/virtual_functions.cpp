//Author  : Professor Moshirpour
//Project : Reviewing C++
//File    : virtual_functions.cpp
//Version : 0.1
#include <iostream>
using namespace std;

class Parent {
    public:
        Parent() {
            cout << "Default constructor in Parent" << endl;
        }
        void bar () {
            cout << "bar in Parent" << endl;
        }
        virtual void foo() {
            cout << "foo in Parent" << endl;
        }
        //Pure virtual function, the base class does not need to provide an implementation (Abstract Class)
        //If you uncomment the next line, you are not able to have instances of the Parent Class.
        //virtual void fun() = 0;
        void someFunctionInParent() {
            cout << "Calling someFunctionInParent" << endl;
        }
};

class Child: public Parent {
    public:
        Child() {
            cout << "Default constructor in Child" << endl;
        }
        void bar () {
            cout << "bar in Child" << endl;
        }
        void foo() {
            cout << "foo in Child" << endl;
        }
        void fun() {
            cout << "fun in Child" << endl;
        }
        void someFunctionInChild() {
            cout << "Calling someFunctionInChild" << endl;
        }
};

int main() {
    cout << "Hello World" << endl;
    //Object p1 is of type Parent. It is constructed on the stack.
    //Default constructor of Parent class is called.
    Parent p1;
    // c1 is an object of type Child. It is constructed on the stack.
    //Default constructor of Child class which calls the Default constructor of Parent immediately.
    Child c1;
    //No constructor is called for c2. This is because c2 is a pointer and NOT an instance of an object.
    Child *childPtr;
    p1.bar();
    c1.bar();
    Parent *parentPtr;
    parentPtr = &c1;
    //Even though c1 is of type child, the bar implementation of the parent is called. No Polymorphism binding happens.
    //If there was no bar function in the parent, it would choose the one in the child class.
    parentPtr->bar();
    //If it is a virtual function, polymorphism binding happens. Dynamic binding at runtime.
    parentPtr->foo();
    //The next line will work in the case of Parent being an abstract class, even though it's a pointer of type Parent.
    //parentPtr->fun();
    //The next line does not work. This is because there is no definition in the Parent class (no knowledge of 
    //someFunctionInChild). Therefore, there is no binding
    //parentPtr->someFunctionInChild();
    //But, if we call it from a Child object, it works!!
    c1.someFunctionInChild();
    //The child has access of the functions defined in parent! This works because the Child class inherits all members and
    //functions of the Parent Class.
    c1.someFunctionInParent();
};