//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : mystring.cpp
//Version : 0.1
#include "mystring.h"
//Implementation of class String
MyString::MyString() {
    len = 0;
    str = new char[1];
    cursor = str;
    assert(str != 0);
    strcpy(str, "\0");
}
//implicit type conversion
MyString::MyString(int stringSize) {
    len = stringSize;
    str = new char[len+1];
    cursor = str;
}
//explicit conversion, no return type
MyString::operator char*() {
    char* charArray = new char[len+1];
    strcpy(charArray, str);
    return charArray; //do not return str if you want to protect your MyString object.
}
MyString::MyString(const char *s) {
    len = strlen(s);
    str = new char[len+1];
    assert(str != 0);
    strcpy(str, s);
    cursor = str;
}

MyString::MyString(const MyString& s) {
    //Copy Constructor
    len = s.len;//length of the string s
    str = new char[len+1];//need enough space for null terminator
    assert(str != 0);//make sure memory was allocated.
    strcpy(str, s.str);
    cursor = str;
}
//Overloaded operator +
MyString MyString::operator+(const MyString& s) {
    MyString temp;
    temp.len = len + s.len;
    delete [] temp.str; //clean the default allocated memory.
    temp.str = new char[temp.len+1]; //allocate memory of length len+1
    strcpy(temp.str, str); //copy the content of the left string of the operator + to the temp String
    strcat(temp.str, s.str); //append the contents of the string s on top of the left side of the string.
    temp.cursor = str;
    return temp;
}

//Overloaded operator =
MyString& MyString::operator=(const MyString& s) {
    //make sure we aren't trying to assign the object to itself.
    if(this != &s) {
        delete [] str; //deallocate old str memory
        len = s.len;
        str = new char[len+1];//allocate new memory
        strcpy(str, s.str);//copy string
        cursor = str;
    }
    return *this;
}

//Overloaded operator +=
MyString& MyString::operator+=(MyString& s) {
    len += s.len; //add the length of the right hand side to the length of the lhs
    char *temp = new char[len+1];//dynamic allocation of the character array
    assert(temp != 0); //check if memory was allocated
    strcpy(temp, str); //copy lhs into temp
    strcat(temp, s.str); //concatinate rhs in temp
    delete [] str; //delete old str member
    str = new char[len+1]; //assign the dynamically created location to str
    str = temp;
    cursor = temp;
    return *this;
}

//Overloading operator <<
ostream& operator <<(std::ostream& out, const MyString& s) {
    out << s.str;
    return out;
}

//Overloading operator >>
istream& operator >>(istream& in, MyString & s) {
    //no input check, assume the user will give a good input
    cout << "Give the length of the string" << endl;
    cin >> s.len;
    delete s.str;
    s.str = new char[s.len+1];
    cout << "Give your string." << endl;
    cin >> s.str;
    s.str[s.len] = '\0';
    return in;
}

//overloading [] operator
char& MyString::operator [] (int index) {
    assert(index >= 0 && index < len);
    return str[index];
}
//prefix ++ overloaded operator
char MyString::operator++() {
    if (cursor == (str+len-1)) {
        //set cursor at the begining of the string, we are the end of the string
        cursor = str;
    } else {
        //increment cursor by 1 memory position
        cursor++;
    }
    char charAfterIncrement = *cursor;
    return charAfterIncrement;
}
//prefix -- overloaded operator
char MyString::operator--() {
    if (cursor == str) {
        //set cursor at the end of the string, we are the begining of the string
        cursor = str+len-1;
    } else {
        //decrement cursor by 1 memory position
        cursor--;
    }
    char charAfterDecrement = *cursor;
    return charAfterDecrement;
}
//postfix ++ overloaded operator
char MyString::operator++(int) {
    char charBeforeIncrement = *cursor;
    if (cursor == (str+len-1)) {
        //set cursor at the begining of the string, we are the end of the string
        cursor = str;
    } else {
        //increment cursor by 1 memory position
        cursor++;
    }
    return charBeforeIncrement;
}
//postfix -- overloaded operator
char MyString::operator--(int) {
    char charBeforeDecrement = *cursor;
    if (cursor == str) {
        //set cursor at the end of the string, we are the begining of the string
        cursor = str+len-1;
    } else {
        //decrement cursor by 1 memory position
        cursor--;
    }
    return charBeforeDecrement;
}
int MyString::getLen() {
    return len;
}
const char * MyString::getCursor() const {
    return cursor;
}
//Getter for str member
const char * MyString::getStr() const {
    return str;
}

//setter for str member
void MyString::setStr(const char *s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len+1];
    assert(str != 0);
    strcpy(str, s);
}

//MyString Destructor
MyString::~MyString() {
    len = 0;
    delete [] str;
}

void MyString::display() {
    cout << "The string that this object contains is " << str << " and has length of " << len << "."; 
}
MyString * fun() {
    MyString s1; //object stored in stack same as s2
    MyString s2("XY"); // "XY" is stroed in string constant area before assigned to the object s2
    MyString *s3 = NULL;
    MyString *s4 = NULL;
    s3 = new MyString("AD"); //dynamically created object - stored in free store
    s4 = new MyString("TD"); //dynamically created object - stored in free store
    return s3;
    //we have a memory leak here because we can't access the memory location of s3 again
    //we need to make sure that we handle memory correctly, i.e., delete s4.
}