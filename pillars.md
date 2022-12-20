Elements of Object Oriented Design (OOD)
====================
- Abstraction
- Encapsulations/Information Hiding
- Hierarchy
- Modularity

Abstraction
-----------
* Abstraction is a technique of dealing with complex systems. We make a simplified model of a complex system.
* Problem : Deciding upon the right set of abstractios for a given domain
    * Ignore inessential details
    * Focus on the outside view of an object
    * The Class Data Type is how we implement abstraction in the context of OOD.
* If you find yourself having too many members in one class that form sets of related members, it is possibble that you 
could create a new class for each set of related members and then have instances of those clases as a members instead.

Encapsulation
-------------
* C++ hides information at two different levels :
    * Separation of outside view of an object from its inside view (secretes). Implementation detail
    of the objects and the current values of its data are hidden. (Interface of methods is public)
    * Data is hidden and invisible to other objects (Re-implementation inside an object's capsule does not affect other objects
    that interact with it)

Modularity
-------------
* The property of a system decomposed into a set of cohesive and loosely coupled modules.
* A class/object is the lowest level of modularity in an object-oriented paradigm.
* At the higher-level, modules are __physical containters__ in which _classes_ and _objects_ are placed.
* A module has an __interface__ (description) and a __body__ (implementation)
    * Changing the body requires recompiling just that module.
    * Changing the interface requires recompiling the module, plus all other modules that depend on the interface.
