Class Relationships
===================
Three types of relationships :
- Association
- Aggregation/Composition
- Inheritance

Association
-----------
***
The association relationship expresses a semantic relationship between two
classes. They are weekly connected, i.e., they are merely associates with no hierarchy between them.
- All objects have their own life-cycle.
- There is no ownership.
- There is no whole-part relationship.

If inheritance or aggregation/composition do not apply, it is most likely a simple association relationship.
For diagrams, the association of two classes should be labeled.(use active or passive voice)

Aggregation
-----------
***
An aggregation represents an assymetric association, in which one of the classes plays a more important
role than the other one. The following criteria imply an aggregation
- A class is part of another
- The objects of one class are subordinates of the objects of another class.

An aggregation denotes a whole/part hierarchy with the ability to navigate from the whole (aggregate) to
its parts (attributes). In C++ the part is normally being referenced to either a pointer or by a reference.

Composition
-----------
***
A strong type of aggregation. An aggregation in which when deleting the whole the part is also deleted is called 
a composition. The "part" objects are usually created in the constructor of the container class. In C++ a 
composition often implies the dynamic allocation of memory for the object of the "part". If the lifetime of the 
"part" does not depend on the class with which it has a relationship, then it is a simple aggregation. Consider 
a car object and an engine object. Does the lifetime of an engine depend on the car? Can we move the engine to 
another car object if the original car object is destroyed? Those are questions to be considered when defining 
relationships between classes.

Inheritance
-----------
***
A relationship among classes where a subclass inherits the structure and behavior of its super-class.
- Defines the "is a" or generalization/specialization hierachy.
- Structure : Instance Variables.
- Behavior : Instance Methods.

In C++ single and multiple inheritance are supported. In order to __derive__ (inherit from) a class the following 
two extensions to the class syntax are necessary :
- The class heading is modified to allow a derivation list of classes from which to inherit members.
- An additional class level, that of __protected__, is provided. A protected class member behaves as a public 
member to a derived class. 
    ```
    class Cat : public Animal {
        protected:
        //data members
    };```

### __Base Class Design__
***
The syntax for defining a base class is the same as an ordinary class with two exceptions:
- Members intended to be inherited but not intended to be public are declared as __protected__ members.
- __Virtual Functions__ are member functions whose implementation depends on representational details of 
subsequent derivations that are unknown at the time of the base class design.

### __Inherited Member Access__
***
The derived class member functions can have access to inherited members directly or by using the scope 
resolution operator. In most cases, the use of the __class scope operator__ is redundant. There are two
cases where using scope resolution operator is necessary :
- When an inherited member's name is reused in the derived class.
- When two or more base classes define an inherited member with the same name.

### __Base Class Initialization__
***
A member initialization list is used to pass arguments to a base class constructor. The tag name of a 
base class is specified, follwed by its argument list enclosed in parentheses. Look in the Person and
Student example in this folder.

### __Relationship between Base and Derived Class__
***
A derived class can be assigned to any of its public classes without requiring an explicit cast. This 
is possible because simply a Derived class is a Base class with additional members/functionalities. By
casting it as a Base Class object we are hiding its derived members/functionalities. If you wish to
cast a Base Class Object as a Derived class object you must define an "explicit cast operator" in your
Derived Class.

### __Virtual Functions__
***
- A __virtual function__ is a special function invoked through a public base class reference or pointer
and it is bound dynamically at run time.
- The instance invoked is determined by the class type of the actual object addressed by the pointer or
reference.
- Resolution of a virtual function is transparent to the user.
- It is specified by prefacing a function declaration with the keyword.
- The class that declares a function as virtual must :
    - Provide a definition for the function, which serves as the default instance for subsequent derived 
    classes, or
    - Declare it as pure virtual and the class will be considered as an abstract class. Instances of
    this class cannot be created. If a derived class of an abstract base class doesn't define the
    function then it will also be considered an abstract class.
- The redefinition of a virtual function must match exactly the name, signature and the return type of
the base class instance.
- The use of keyword virtual is optional (implicitly handled by the compiler)
- If the redefinition of a virtual function does not match exactly the function return type and signature,
it is not handled as virtual. Any subsequent derived classes may still redefine the virtual function.
- You may define a null instance of virtual function if you wish a derived object to not have the function
handler.
- __Virtual Destructor__ :
    A destructor should be usally declared virtual if it is responsible to remove an allocated memory.
    - This is to avoid undefined behavior or a memory leak.
    - The keyword virtual implies a late binding. (Inheirted classes a reminded to redefine this function
    to do their own cleanup.)
    - The mechanical details of why you need a virtual destructor when someone says delete using a Base pointer that is pointing at a Derived object. When you say delete p, and the class of p has a virtual destructor, the destructor that gets invoked is the one associated with the Derived Object, not necessarily the one associated with the type of the pointer.
## Some Interesting Facts
***
1. A class is __abstract__ if it has at least one pure virtual function.
2. There can be pointers and references of abstract class type.
3. Not overriding a pure virtual function in a Derived Class, renders the Derived Class an Abstract Class.
4. An Abstract class can have constructors.
5. An abstract class in C++ can be defined using struct keyword. 
    ```
    struct shapeClass {
        virtual void Draw() = 0;
    }
    ```