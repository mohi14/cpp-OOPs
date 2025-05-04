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
  ----------- Static Keyword ----------
-> Static Variables
   -> Variables declared as static in a function are created & initialised once for the lifetime of the program. // in Function
   -> Static variables in a class are created & initialised once. They are shared by all the objects of the class. // in Class

-> Static Objects
 **/

 void fun(){
    static int x=0; // init statement -1 run
    print("x: {}\n",x);
    x++;
 }

int main(){
    fun();
    fun();
    fun();
    return 0;
}

