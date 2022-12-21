Overloading Operators
=====================
You may provide a set of operators to work with objects of a class you are designing. to achieve this define an operator function.

__Defining the Function__
-------------------------
* An operator function does not need to be a member function, but it must take at least
one class argument. (Prevents overloading behavior of built-in data types)
* A predefined set of C++ operators can be overloaded.
* An overloaded function can be defined the same was as an ordinary member or non member
function, except that a "__operator__" reserved word followed by the operator symbol that
you wish to overload must be used at the function's name.
* The nature of the operator should not be changed, i.e., the overloaded operator cannot
convert a unary operator to a binary operator and vice versa.
* Should your overloaded operator function be a member or non member?
    * If the first parameter of an overloaded function must be an object of another class,
    the function must be a nonmember.
    * If the function needs direct access to the data members, it can also be defined as a friend.
    * The assignment __"="__, subscript __"[]"__, class __"()"__ and member selection __"->"__ 
    operators are required to be defined defined as class members by the C++ language.
* Questions to be asked when overloading operators :
    * Why do we need an operator to be available in the specific class?
    * What type of object is on the left side of an operator, i.e., _object left_ <<
    * What type of object is on the left side of an operator, i.e., << _object right_
    * What should be the arguments of the function?
    * What type of object should be returned from the overloading-operator function and Why?
    * Should the overloaded-operator function be a member or not of the this class and why?
    * Is the operator a Unary or Binary operator? ([] unary or binary?)
    * How does a compiler recognize a post fix operator? What about a prefix operator?<br />
        ```
        //	prefix	
        char	String::operator++()	{

        }
        //	post-fix	
        char	String::operator++(int)	{
            char	ret	=	*cursorM;
            cursorM++;
            return	ret;						
        }
        ```
__Type Conversion__
-------------------
* Constructors with only one argument act as an __implicit type conversion__ operator to convert
the given argument to the type of the class. (C++)
* Explicit type conversion : char* st = (char*) s -> must write an operator called (char *)


