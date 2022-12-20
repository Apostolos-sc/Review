//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : functions.cpp
//Version : 0.1
/**
 * Reviewing functions
 * 1.Function arguments may have default values.
 * 2.The right most initialized argument should be supplied with a default initializer
 *   before any argument to its left may "default initialized".
 * 3.Initialize arguments either at the function prototype or at the function definitions.
 *   Not both.
 * 
*/
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
void fun(int h=24, int w = 80, char c = ' '); //prototype function

void fun(int h, int w, char c) {
    cout << "The height is : " << h << ", the width is : " << w << ", and your favorite character is : " << c << ".";
    cout << "\n";
}
using namespace std;
int main() {
    fun(); // prints : The height is : 24, the width is : 80, and your favorite character is :  .
    fun(2); // prints : The height is : 2, the width is : 80, and your favorite character is :  .
    fun(2, 8); // prints The height is : 2, the width is : 8, and your favorite character is :  .
    fun(2, 8, 'B'); // prints The height is : 2, the width is : 8, and your favorite character is :  B.
    return 0;
}