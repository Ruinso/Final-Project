#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Employee{

  public:
  string Name;
  string role;
  Employee(){

  }

  void setName(string m){
    Name = m;
  }

  string getName(){
    return Name; 
  }

  void setRole(string r){
    role = r;
  }

  string getRole(){
    return role; 
  }
  
};