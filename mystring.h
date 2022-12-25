//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : mystring.h
//Version : 0.1
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
#ifndef MYSTRING_H
#define MYSTRING_H
class MyString {
    private:
        char *str; //pointer to be allocate memory on the heap
        int len; //length of a string
        char *cursor; //tracks characters in a string.
    public:
        MyString(); // Default Constructor
        MyString(int);//implicit type conversion
        MyString(const char *s); //constructor
        MyString(const MyString&); //copy constructor
        //must be constant because if we do s3 = s1 + s2 the result of s1+s2 is an unnamed variable
        MyString& operator =(const MyString& s); //assignment operator
        MyString operator +(const MyString& s); //addition operator overloading
        MyString& operator +=(MyString &s); //plus equals operator overloading
        friend ostream& operator <<(std::ostream& out, const MyString& s);
        friend istream& operator >>(istream& in, MyString & s);
        char& operator [] (int index);
        operator char* (); //Explicit type conversion don't have a return type.
        char operator++();//prefix ++ operator overloading
        char operator--();//prefix -- operator overloading
        char operator++(int);//postfix ++ operator ovelroading
        char operator--(int);//prefix -- operator overloading
        ~MyString(); //destructor -> must clean up after our memory allocations.
        void display();
        const char * getStr() const; //unable to modify the memory outside or inside the function
        const char * getCursor() const;
        int getLen();
        void setStr(const char *);//set str member of MyString
};
#endif