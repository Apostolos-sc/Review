//Author    : Moshirpour M.
//Commnents : Scondrianis A.
//Project   : Reviewing C++
//File      : inheritance_example.cpp
//Version   : 0.1
/**
 * Multiple Inheritance Example 2
*/
#include <iostream>
using namespace std;

//In a real design Animal would ideally be Abstract. I would need to have at least 1 pure virtual function.
class Animal {
    protected:
        int a;
    public:
        Animal(int x):a(x) {
            cout << "Animal Constructor is called" << endl;
        }
        //Need virtual if I want to maintain polymorphism
        //Declare virtual on the top Level and then polymorphism works for all levels of inheritance
        void virtual foo() {
            cout << "foo in Animal" << endl;
        }
        int getA() const {
            return a;
        }
};

class Bear: public virtual Animal {
    protected:
        int b;
    public :
        Bear(int x, int y): b(x), Animal(y) {
            cout << "Bear Constructor is called." <<endl;
        }
        void foo() {
            cout << "foo in Bear" << endl;
        }
        int getB() const {
            return b; 
        }
};
class Raccoon: public virtual Animal {
    protected:
        int r;
    public:
        Raccoon(int x, int y): r(x), Animal(y) {
            cout << "Racoon constructor is called" << endl;
        }
        void foo() {
            cout << "foo in Raccoon" << endl;
        }
        int getR() const {
            return r;
        }
};
class Panda: public Bear, public Raccoon {
    protected:
        int p;
    public:
        Panda(int x, int y, int z, int w, int u, int q): Bear(x, y), Raccoon(z, w), p(u), Animal(q) {
            cout << "Panda Constructor is called." << endl;
        }
        void foo() {
            cout << "foo in Panda" << endl;
        }
        int getP() const {
            return p;
        }
};
class BlackPanda: public Panda {
    protected:
        int bp;
    public:
        BlackPanda(int x, int y, int z, int w, int u, int q, int r): Panda(x, y, z, w, u, q), Animal(q), bp(r) {
            cout << "Black Panda Constructor is called." << endl;
        }
        void foo() {
            cout << "foo in Black Panda is called." << endl;
        }
        int getBp() const {
            return bp;
        }
};
int main() {
    cout << "Multiple Inheritance Example 2" << endl;
    Panda p1(1, 2, 3, 4, 5, 6);

    Animal *a = new Bear(10, 20);
    Animal *a1 = new Panda(10, 20, 23, 3, 4, 5);
    Bear *b = new Panda(10, 40, 50, 60, 70, 80);
    //if foo is not declared virtual, the next line will print foo in Animal, prints foo in Bear
    a->foo();
    //Prints foo in Panda
    a1->foo();
    //Prints foo in Panda
    b->foo();
    cout << p1.getA() << endl;
    cout << "-------------" << endl;
    //Black Panda constructs Panda and Animal, Panda constructs Bear and Raccoon. When creating
    //the Black Panda object neither Bear, Raccoon, nor Panda creates an Animal Object. The 
    //Black Panda object does this.
    BlackPanda bp1(1,2,3,4,5,6,7);
    cout << bp1.getA() << endl;
    return 0;
}