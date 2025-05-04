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
  ------------- Abstraction -------------
-> Hiding all unnecessary details & showing only the important parts
 --- using Abstract Classes ---
-> Abstract classes are used to provide a base class from which other classes can be derived.
-> They cannot be instantiated and are meant to be inherited.
-> Abstract classes are typically used to define an interface for derived classes.

 **/

class Shape // abstract class
{
    virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
    public:
    void draw (){
        print("drawing a circle\n");
    }
};

int main()
{
    Circle c1;
    c1.draw();
    return 0;
}