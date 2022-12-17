//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : main.cpp
//Version : 0.1
#include <iostream>
using namespace std;
/**
 * Review of basic concepts of C++
*/
int main()
{
  int a, b; //declare integers a, b
  int & ref = b; //reference, ie, alias for b
  int * ptr = &a; //pointer to the memory location of integer variable a
  int * & refpter = ptr;
  //assign the value 4 to the memory location that ptr "refers to", i.e., to the memory location of the variable a
  *ptr = 4;
  //ref = 8, so basically b = 8. (no pointer operations, just a reference)
  ref = 8;
  //reference, i.e., alias for the integer pointer "ptr"
  *refpter = 23;
  return 0;
}