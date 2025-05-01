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
   ---------- Inheritance --------
-> When properties & member functions of base class are passed on to the derived class.
-> Its use for code reuseability
-> virtual function is a member function that you expect to be redefined in derived classes.
   ---------- Mode of Inheritance --------
 -------------------------------------------------------------
 Parent Class | Derived Class | Derived Class | Derived Class
 -------------------------------------------------------------
              | Private Mode  | Protected Mode | Public Mode
 -------------------------------------------------------------
 Private      | Not Inherited | Not Inherited  | Not Inherited
 -------------------------------------------------------------
 Protected    | Private       | Protected      | Protected
 -------------------------------------------------------------
 Public       | Private       | Protected      | Public
 -------------------------------------------------------------
 
 -> private -> access only within the class itself, not accessible in derived classes, used to stricly encapsulate data.
 -> protected -> accessible within the class itself and in derived classes, Not accessible from outside the class hierarchy, Used when you want derived classes to access the member, but still keep it hidden from the rest of the code.


  ----------- Types of Inheritance -------------
-> Single Inheritance
-> Multi-level Inheritance
-> Multiple Inheritance
-> Hierarical Inheritance (multiple children)
-> Hybrid Inheritance

**/

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // Person()
    // {
    //     print("This id parent constructor....\n");
    // }
    ~Person()
    {
        print("This id parent destructor....\n");
    }
};

class Student : public Person // can be class Student : private Person, class Student : protected Person
{
public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age)
    {
        this->rollno = rollno;
        print("This is child constructor....\n");
    }
    ~Student()
    {
        print("This is child destructor....\n");
    }
    void getInfo()
    {
        print("Name: {}, Age: {}, RollNumber: {}\n", name, age, rollno);
    }
};

class Tea {
    protected:
        string teaName;
        int servings;
    public:
        Tea(string name, int serve): teaName(name), servings(serve){
            cout << "Tea constructor called " << teaName << endl;
        }

        virtual void brew() const { 
            cout << "Brewing " << teaName << " with generic method" << endl;
        }
        virtual void serve() const {
            cout << "Serving " << servings << " cup of tea with generic method" << endl;
        }

        virtual ~Tea(){
            cout << "Tea destructor called for " << teaName << endl;
        }

    
};

class GreenTea: public Tea {
    public:
        GreenTea(int serve): Tea("Green Tea", serve){
            cout << "Green tea constructor called" << endl;
        }

        void brew() const override {
            cout << "Brewing" << teaName << " by steeping green tea leaves" << endl;
        }

        ~GreenTea(){
            cout << "Green tea constructor called " << endl;
        }
};

class MasalaTea : public Tea {
    public: 
        MasalaTea(int serve) : Tea("Masala Tea", serve){
            cout << "MasalaTea constructor called" << endl;
        }

        void brew() const override final {
            cout << "Brewing" << teaName << " with spices and milk" << endl;
        }

        ~MasalaTea(){
            cout << "Masala tea desctrutor called" << endl;
        }
};

int main()
{
    Student s1("Mohiuddin", 27, 3625);

    s1.getInfo();

    Tea* tea1 = new GreenTea(2);
    Tea* tea2 = new MasalaTea(3);

    tea1->brew();
    tea2->serve();

    tea2->brew();
    tea2->serve();

    delete tea1;
    delete tea2;


    return 0;
}