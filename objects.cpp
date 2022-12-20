//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : objects.cpp
//Version : 0.1
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
//Definition of class String
class String {
    char *str; //pointer to be allocate memory on the heap
    int len; //length of a string
    public:
    String(); // Default Constructor
    String(char *s); //constructor
    String(const String&); //copy constructor
    String& String::operator=(String& S); //assignment operator
    ~String(); //destructor -> must clean up after our memory allocations.
    void display();
};
String::String() {
    len = 0;
    str = new char[1];
    assert(str != 0);
    str = "\0";
}
String::String(char *s) {
    len = strlen(s);
    str = new char[len+1];
    assert(str != 0);
    strcpy(str, s);
}

String::String(const String &s) {
    //Copy Constructor
    len = s.len;//length of the string s
    str = new char[len+1];//need enough space for null terminator
    assert(str != 0);//make sure memory was allocated.
    strcpy(str, s.str);
}

String & String::operator=(String &s) {
    //make sure we aren't trying to assign the object to itself.
    if(this != &s) {
        delete [] str; //deallocate old str memory
        len = s.len;
        str = new char[len+1];//allocate new memory
        strcpy(str, s.str);//copy string
    }
    return *this;
}
String::~String() {
    len = 0;
    delete [] str;
}
void String::display() {
    cout << "The string that this object contains is " << str << " and has length of " << len << "."; 
}
String * fun() {
    String s1; //object stored in stack same as s2
    String s2("XY"); // "XY" is stroed in string constant area before assigned to the object s2
    String *s3 = NULL;
    String *s4 = NULL;
    s3 = new String("AD"); //dynamically created object - stored in free store
    s4 = new String("TD"); //dynamically created object - stored in free store
    return s3;
    //we have a memory leak here because we can't access the memory location of s3 again
    //we need to make sure that we handle memory correctly, i.e., delete s3.
}
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