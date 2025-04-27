#include <iostream>
#include <string>
#include <format>
#include <vector>

using namespace std;

// format-style print()
constexpr void print(const string_view str_fmt, auto&&... args) {
    fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
}
// constexpr void print(const std::string_view str_fmt, auto&&... args) {
//     fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
// }

/**  
 ---- Access Specifiers ----
 Private -> data & methods accessible inside class
 Public -> data & methods accessible to everyont
 Protected -> data & methods accessible inside class & to its derived class

**/

class Teacher {
    // attributes / data members
    private:
        double salary;
    
    public:
        string name;
        string subject;
        string dept;
        int roomNo;
        vector<string> classes; 

    // member functions / methods

    void changeDept(string newDept){
        dept = newDept;
    }
    //setter
    void setSalary(double s){
        salary = s;
    }
    //getter
    double getSalary(){
        return salary;
    }
    void displayClassess (){
        for(string c: classes){
            print("{}\n",c);
        }
    }

}; 


int main(){
  Teacher t1;

  t1.name = "Mohiuddin";
  t1.subject = "C++";
  t1.dept = "EEE";
  t1.roomNo = 6;
  t1.classes = {"Programming", "Engineering", "Semiconductor"};
  t1.setSalary(25000);
  t1.displayClassess();


    print("Name: {}, Subject: {}, DepartMent: {}, Room: {}, Salary: {}\n", t1.name, t1.subject, t1.dept, t1.roomNo, t1.getSalary());
    
}