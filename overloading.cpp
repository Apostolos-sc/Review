//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : overloading.cpp
//Version : 0.1
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.cpp"
int main() {
    MyString s1("ABC"); //create string with members str -> "ABC\0" and len 3
    MyString s2("XY"); //create string with members str -> "XY\0" and len 2
    MyString s3; // create string with members -> "\0" and len 0 -> Default constructor
    s1 += s2; // += overloaded operator, result of s1+s2 stored in s1
    cout << s1.getStr() << endl; //print s1 after performing s1 += s2
    //We have overloaded the operator << and now we can pass s1 to an object << and it calls the overloaded function
    cout << s1 << endl; //test overloaded operator << with object s1
    MyString s6;
    //overloaded operator s6 example. Should write some code to make sure the user inputs the length of a string properly.
    //try this with "7" as the length of input and tester as the string
    cin >> s6; 
    //this should print The length of the inputted string is 7, if 7 was inputted.
    cout << "The length of the inputted string is : " << s6.getLen() << endl;
    //This should print tester.
    cout << s6 << endl;
    //implicit type conversion create a MyString object that has a character array of 100 dynamically allocated.
    MyString s5 = 100; 
    //create a new MyString with a char Array "Hello World!"
    MyString s10("Hello World!");
    //convert it to a character array explicitly.
    char* myCharArray = (char *)s10;
    //print the character array.
    cout << myCharArray << endl;
    for(int i = 0; i < s10.getLen(); i++) {
        //post fix operator test.
        cout << s10++ << endl;
    }
    //This should print : The character contained at the location that the cursos points to is : H.
    cout << "The character contained at the location that the cursos points to is : " << *s10.getCursor() << "." <<endl;
}