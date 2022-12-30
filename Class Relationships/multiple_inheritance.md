# Multiple Inheritance
A class is derived from more than one parent.
## Order of Construction
The constructor member initialization list controls only the values that are used to initialized
the base classes, not the order in which the base classes are constructed. The base class 
constructors are called in the order in which they appear in the class derivation list. For example,
in ``` class C : public B, public A {} ``` the constructor of class B is called first and then the
constructor of class A is called.
## Possible Ambiguity Error
Although a base class may legally appear only once in a derivation list, a base class data member 
can appear multiple times within a derivation hierarchy that form a diamond shape. This means that
a member ambuigity could be caused. If a class Called A with a member called a is a base class for 
B and C, and B and C are base class from which a class D is derived, D will contain two copies of
the member a of class A. To avoid this problem class A must be declared __virtual__ for classes B 
and C. A __virtual class__ must be initialized by its most derived class. In our example, the 
constructor of D is responsible to invoke the constructors of classes A, B, and C.
```
class A { ... };
class B : virtual public A { ... };
class C : virtual public A { ... };
clas D: public B, public C { ... };
```
## Types of Base Classes (3)
1. __Public__ :  The inherited members of a public base class maintain their access level within the
derived class.
2. __Protected__ : The access level of public members of a protected base class will change to 
protected within the derived class.
3. __Private__ : The access level of __public__ and __protected__ members of a private class will 
change to private within the derived class.
## Exempting Individual Members
Starting with ISO, C++11, the class designer can exempt individual members of a class from the effect 
of nonpublic derivation by using the __"using"__ keyword.
## Inheritance of operators and functions
A derived class inherits all the member functions of each of its base classes. A child class needs to
have its own constructors (including copy constructor), and possibly destructor, and assignment
operators to manage tasks such as memory management for its own data members (not those inherited from 
the base classes)
## Derived Class Copy Constructor
If a derived class explicitly defines its own copy constructor, the definition completely overrides the
default definition, and is responsible for copying its base class component.
## Derived Class Assignment Operator
If a derived class explicitly defines its own assignment operator, the definition completely overrides 
the default definition, and is responsible for copying its base class component. 
``` 
Derived& Derived::operator =(const Derived& rhs) {}
```
## Derived Class Destructor
A Derived Class' destructor is never responsible for destroying the members of the base object. The
compiler will always implicitly invoke the destructor of the base part of the derived object.
```
~Derived() {//~Base() is automatically called}
```
# Polymorphism
The ability to hide many different implementations behind a single interface. In Objected Oriented 
languages, polymorphism is the property that different objects may react to the same message differently. 
Polymorphism in C++ is implemented using pure virtual functions, which in turn render a class as 
__Abstract__.

# Realization (UML)
A realization relationship is a relationship between two model elements, in which one model element (the 
client) realizes (accepts to implement or execute) the behavior that the other mode element (the supplier)
specifies.
# Realization (Java)
__Interfaces__ give Java some of the power of __multiple inheritance__, however, there is no code reuse, 
since each class must reimplement the methods. A reference of an interface type can refer to the instances 
of any classes that implement that interface.
# Realization (C++)
In C++ in order to implement realization we must use __Abstract Classes__ which only contain pure virtual 
methods.

## __Why an Interface ?__
1. Any class derived from the "pure" Abstract Class (Interface) must implement all of the methods of the base
class.
2. Interface pointers can be passed to functions and classes thereby we can call the functions o fthe derived 
class from there itself.
## __Rules__
1. Declare only pure virtual functions (No definition)
2. For pure virtual funtions assign only 0.
3. Cannot create an instance of the class.
4. We can create a pointer to the instance of the derived class with a reference of a base abstract class.