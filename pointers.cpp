//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : pointers.cpp
//Version : 0.1
#include <iostream>
using namespace std;
/**
 * Review of basic Pointer concepts of C++
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

    // Arrays - the name of the array is a pointer to the memory location
    //of the array's first element.
    int c[6] = {4, 2, 3, 1, 8, 11};
    cout << *c;
    cout << c[0];

    //Pointer Arithmetic Legal Operations
    /* Pointer + Integer
    ** Pointer - Integer
    ** Pointer - Pointer
    ** Pointer++, ++Pointer, Pointer--, --Pointer
    ** "Pointer + n" refers to the address of the nth element, from the current address :
    **  pointer + n = current address + n * sizeof(type)
    ** Integer - Pointer is an invalid operation
    */
    double d[3] = {4.5, 6.9, 7.7}; //array of doubles that contains 3 elements
    double* dptr = &d[0]; //a pointer to the begining of the array, i.e., 0th element's memory location
    dptr = dptr +2; //dptr points to the location of the element 2 of the array d, i.e., dptr is equal to &d[2]
    //Pointer1 - Pointer2 : integer value that represents the number of elements between 2 pointers.
    int e[5] = {2, 6, 4, 7, 9};
    int *eptr;
    eptr = e+2;
    int difference = eptr-e;
    //Represents how many memory spaces (n*sizeof(type)) away is the begining of the memory allocation of e[0]
    //from the begining of the memory allocation of e[2]
    cout << "The difference of elements between e[0] and e[2] is : " << difference << "";
    return 0;
}