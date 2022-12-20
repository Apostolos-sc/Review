#include <iostream>
#include <cassert>
#include <cstring>
#include <mystring.h>
using namespace std;
//Implementation of class String
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
    //we need to make sure that we handle memory correctly, i.e., delete s4.
}