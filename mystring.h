//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : mystring.h
//Version : 0.1
#ifndef MYSTRING_H
#define MYSTRING_H
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
#endif