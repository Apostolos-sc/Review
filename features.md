Friends
=======
* Components of a program that can be friends to a class :
    * A global function, visible by a class.
    * A member function of other classes in the program, visible to the class.
    * Another class, visible by a class.
* When should we make a class friend of another class ? (Questions)
    * Which class needs to have permission to access the private data members of another class?
    * Which class is __aggregating__ the object of the other class?
        * The __aggregated__ class must appear first in the file or its header file in order to be 
        included in the file that contains the definition of the __aggregating__ class.
    * What are the implications of the order of classes?
    * Is there a forward declaration of a class needed?
    * Where should the friend declaration appear?
    * Are we referring to the right function? (Consider global functions with the same name)

Static Member
=============
* A static class member acts as a global object among the objects of the same class.
* Information hiding can still be enforced.
* A static data member is not entered into programs global name space.
* A static data member is initialized outside the class definition.
* A static data member can be a constant or a class object.
* Static data member initialization should happen in the implementation part (.cpp not .h files)
* Member functions that accesses only a static member of a class may also be declared as static.
* A static member function does not have a "this" pointer.
* A static member function may be invoked through a class object or a pointer to a class or can 
be accessed directly even if no class object is declared.