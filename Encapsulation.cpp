#include <iostream>
#include <format>
#include <string>

using namespace std;

/**
        ------------- Encapsulation -------------
-> Encapsulation is wrapping up of data & member functions in a single unit called class.
-> Encapsulation helps to hiding data. by making data private with access-specifier.

        ------------- Constructor -------------
-> Special method invoked automatically at time of object creation. Used for Initialisation.
   -> Same name as class
   -> Constructor doesn't have a return type
   -> Only called once (automatically), at object creation
   -> Declare constructor as public not private
   -> Memory allocation happens when constructor is called
-> Types of constructor
   -> Non-parameterized constructor
   -> Parameterized constructor
   -> copy constructor -> Special Constructor (default) used to copy properties of one object into another.

-> different types of constructor called constructor overloading. It is an example of polymorphism. 

-> (this) is a special pointer in C++ that points to the current object.
   -> this->prop is same as *(this).prop.

**/



// format-style print()
constexpr void print(const string_view str_fmt, auto&&... args) {
    fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
}

class Account {
    private:
        double balance;
        string password;  // data hiding
    public:
        string accoundId;
        string username;
       

};

class Teacher {
    private:
        double salary;
    
    public:
        string name;
        string subject;
        string dept;

    // non-parameterized consturctor
        Teacher(){
            print("Hi, I am constructor\n");
            dept = "EEE";
        }
    
    // patameterized
        Teacher(string name, string dept, string subject, double salary){
            this->name = name;
            this->dept = dept;
            this->subject = subject;
            this->salary = salary;
        }
    // copy constructor
        Teacher(Teacher &orgObj){
            print("I am a copy constructor\n");
            this->name = orgObj.name;
            this->dept = orgObj.dept;
            this->subject = orgObj.subject;
            this->salary = orgObj.salary;
        }

        void getInfo(){
            print("Name: {}\n", name);
            print("Subject: {}\n", subject);
            print("Department: {}\n", dept);
            print("Salary: {}\n", salary);
        }


}; 

int main(){
    // Teacher t1;

    // t1.name = "Mohiuddin";
    // t1.subject = "C++";
    // print("Name: {}, Subject: {}, DepartMent: {}, \n", t1.name, t1.subject, t1.dept );

    Teacher t1("Mohiuddin", "EEE", "C++", 25000);
    // t1.getInfo();

    Teacher t2(t1); //copy constructor ->invoke, if we dont make custom copy constructor, compailer make a default copy constructor.
    t2.getInfo();



}
