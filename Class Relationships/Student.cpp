//Author  : Apostolos Scondrianis
//Project : Reviewing C++
//File    : Student.cpp
//Version : 0.1
/**
 * C++ Inheritance simple example
*/
#include "Person.cpp"
class Student: public Person {
    public:
        Student(const char* n, int a, const char* identification);
        Student();
        ~Student();
        void display();
    protected:
        char *id;
};
//Be careful, need to add the call to the overloaded Base class constructor in order to avoid calling the
//default base class constructor
Student::Student(const char* n, int a, const char* identification) : Person(n,a) {
    id = new char[strlen(identification)+1];
    strcpy(id, identification);
}

Student::Student() {
    id = new char[1];
    id[0] = '\0';
}

Student::~Student() {
    delete id;
}

void Student::display() {
    cout << "This student's name is " << Person::name << ", its age is " << age << " and its id is " << id << "." << endl;
}
