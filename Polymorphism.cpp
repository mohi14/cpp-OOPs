#include <iostream>
#include <format>
#include <string>

using namespace std;

// format-style print()
constexpr void print(const string_view str_fmt, auto &&...args)
{
    fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
}

/**
  --------------- Polymorphism -------------
-> Polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used. -> constructor overloading is using more than one constructor.
    -> Compile Time Polymorphism -> constructor overloading, function overloading-> same function different parameters., operator overloading
    -> Run Time Polymorphism
       -> Function Overriding -> Parent & Child both contain the same function with different implementation, The parent class function is said to be overridden.
       -> Virtual Fuctions -> Its a member function that you expect to be redefined in derived classes.
            -> Virtual functions are Dynamic in nature.
            -> Defined by keyword "virtual" inside a base class and are always declared with a base class and overridden in a child class.
            -> A virtual function is called during Runtime.


 **/

class Student
{
public:
    string name;
    Student()
    {
        print("Non - parameterized\n");
    }
    Student(string name)
    {
        this->name = name;
        print("Parameterized\n");
    }
};
class Print
{
public:
    void show(int x)
    {
        print("Int: {}\n", x);
    } // function overloading
    void show(char ch)
    {
        print("char: {}\n", ch);
    }
};

class Parent
{
public:
    void getInfo()
    {
        print("Parent class\n");
    }
    virtual void hello(){
        print("Hello from parent\n");
    }
};

class Child : public Parent
{
public:
    void getInfo()
    {
        print("Child class\n");
    };
    void hello(){
        print("Hello from child\n");
    }

};

int main()
{
    // Student s1;
    Student s1("Mohi");
    Print p1;
    p1.show('&');

    Parent a1;
    a1.getInfo();

    Child c1;
    c1.hello();
    return 0;
}