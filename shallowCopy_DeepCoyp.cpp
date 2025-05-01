#include <iostream>
#include <format>
#include <string>

using namespace std;

// format-style print()
constexpr void print(const string_view str_fmt, auto&&... args) {
    fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
}

/**
    ------------- Shallow & Deep Copy ------------
-> A shallow copy of an object copies all of the member values from one object to another. 
-> A deep copy, on the other hand, not only copies the member values but also makes copies of any dynamically allocated memory that the members point to.
-> in memory, heap is an area where dynamically allocated memory is stored. Its create problem in shallow copy for dynamic memory. so we use deep copy for dynamic memory allocation.
 
    ------------ Distructor ---------
-> It is used for memory delocation. 
-> If dont delocale memory on the distructor for the dynamic memory, it can create memory leak.
**/

class Student {
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double; // new key word user for dynamically memory allocation.
        *cgpaPtr = cgpa;
      // can written like this also
    // cgpaPtr = new double(cgpa);
    }

    Student(Student &obj){
        this->name = obj.name; 
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
        // can written like this also
        // cgpaPtr = new double(*obj.cgpaPtr);
    }

    // destructor
    ~Student(){
        print("Hi delete everything\n");
        delete cgpaPtr; // can create memory leak if we dont write it.
    }

    void getInfo(){
        print("Name: {}, Cgpa: {}\n", name, *cgpaPtr);
    }
};

int main (){
    Student s1("Mohiuddin", 1.9);
    s1.getInfo();
    Student s2(s1); // Student s2 = s1; it also can copy like this.
    *(s2.cgpaPtr)= 4.5;
    s1.getInfo();
    s2.name = "Mohi";
    s2.getInfo();
    s1.getInfo();

    return 0;
}