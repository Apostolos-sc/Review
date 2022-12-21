//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : objects.cpp
//Version : 0.1
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.cpp"
using namespace std;
/**
 * Review of basic Object concepts of C++
 * An instance of a class can be initialized with another instance of the same class.
 * Aclass a;
 * Aclass a2 = a1; //Initialization - Every data member of instance a1 will be copied into instance a2.
 * Aclass a3;
 * a1 = a3 //Assignment
 * Memory leaks can cause issues, you need to be aware how dynamic allocation in C++ works.
*/
int main() {
    String *p = NULL;
    p = fun();
    delete p; //deallocate dynamically allocated memory
    return 0;
}