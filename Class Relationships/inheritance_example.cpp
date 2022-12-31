//Author   : Moshirpour M.
//Comments : Scondrianis A.
//Project  : Reviewing C++
//File     : inheritance_example.cpp
//Version  : 0.1
/**
 * Multiple Inheritance Example
*/
#include <iostream>
using namespace std;
// Declaring A as virtual when inheriting from A solves the ambiguity issue
class A {
    public:
        int a;
        A() {
            a = 10;
            cout << "A constructor is called" << endl;
        }
};

//class B: virtual public A {
class B: public A {
    public:
        int b;
        //int a;
        B() {
            b = 20;
            //a = 7;
            cout << "B Constructor is called" << endl;
        }
};

//class C: virtual public A {
class C: public A {
    public:
        int c;
        C() {
            c = 30;
            cout << "C Constructor is called" << endl;
        }
        //call member of A using scope resolution operator
};

class D: public B, C {
    public:
        int d;
        D() {
            d = 40;
            cout << "D constructor called" << endl;
        }
        /*
        void foo() {
            cout << "a is: " << A::a << endl;
        }
        */
};

int main() {
    cout << "Multiple Inheritance Example 1" << endl;
    //Constuctor of A is called
    A myA;
    //Constructor of B and A is called
    B myB;
    //Consturctor of C and A is called
    C myC;
    //Constructor of A, B, A, C and D is called.
    D myD;
    //The next line won't be accepted as it is ambiguous. There are 2 instances of A and we don't know which one to choose.
    //Declare the inheritance of A in class B and C as virtual and the ambiguity is solved 
    //cout << myD.a << endl;
    
    
    //A trick to access the parent's member if you have a in D and A is to type cast the child class as as parent class object.
    //cout << ((A)myD).a << endl;
    //myD.foo();
    return 0;
}