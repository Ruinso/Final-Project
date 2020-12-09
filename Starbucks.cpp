#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Employee.cpp"

using namespace std;


map <string,string> shift;//map object to create and store shifts
vector <Employee> staff;//vector object to keep track of the 10 employees


void assignShift(string name, string role){//assigns the employee and role to the map
  shift.insert(pair<string, string> (name, role));
}

void fireSpace(){//erases employees who should be fired DOESN'T WORK but I tried
  staff.clear();
}

void clockOut(){
  shift.clear();
}

void printRoles(){//prints the map contents
  cout << "Roles" << "\n";
  for(const auto & kvpair:shift){
    cout << kvpair.first << ":" << "\t" << kvpair.second << "\n"; 
  }
}

void hireSpace(Employee m1,Employee m2,Employee m3,Employee m4,Employee m5){//used for hiring the employees
  string sludge;//generic input string
  string role;//what job employee will fulfill 
  string name;//name of employee
  cout << "Enter a name for the shift supervisor" << "\n";
  cin >> sludge;
  m1.setName(sludge);//adds a name to the employee object
  name = m1.getName();//assigns that name to a string
  role = "Shift supervisor";//role the employee is being hired for
  m1.setRole(role);
 
  staff.push_back(m1);//puts newly entered employee into the vector

  role = "Main barista";
  cout << "Enter a name for the main barista" << "\n";
  cin >> sludge;
  m2.setName(sludge);
  m2.setRole(role);
  staff.push_back(m2);
  name = m2.getName();
 
  cout << "Enter a name for the bar barista" << "\n";
  cin >> sludge;
  m3.setName(sludge);
  role = "Bar barista";
  m3.setRole(role);
  name = m3.getName();

  staff.push_back(m3);
  cout << "Enter a name for the DTO barista" << "\n";
  cin >> sludge;
  m4.setName(sludge);
  name = m4.getName();
  role = "DTO barista";
  m4.setRole(role);

  staff.push_back(m4);
  cout << "Enter a name for the window barista" << "\n";
  cin >> sludge;
  role = "Window barista";
  m5.setName(sludge);
  m5.setRole(role);
  name = m5.getName();

  staff.push_back(m5);
}



void initialBatch(){//initial batch of employees
  Employee m1;
  Employee m2;
  Employee m3;
  Employee m4;
  Employee m5;
  hireSpace(m1,m2,m3,m4,m5); 
}

void newBatch(){//second batch of employees
  cout << "Hiring 5 new partners..." << "\n";
  Employee m6;
  Employee m7;
  Employee m8;
  Employee m9;
  Employee m10;
  hireSpace(m6,m7,m8,m9,m10); 
}

void printStaff(){//prints out a list of the staff
  for(int i = 0; i <= staff.size();i++){
    cout << staff[i].getName() << "\n";
    cout << staff[i].getRole() << "\n";
  }
}

void shiftBuilder(){//builds the shifts around the currently hired staff
  string sludge;
  string name;
  string role;
  string compare;
  cout << "Welcome to the shift builder, remember all names are case sensitive" << "\n";
  cout << "Current staff: " << "\n";
  printStaff();
  cout << "Please assign a shift supervisor" << "\n";
  cin >> sludge;
  for(int x = 0; x <= staff.size(); x++){//searches through the staff vector and assigns it to the shift map
    if(staff[x].getName() == sludge){
      name = staff[x].getName();
      role = "Shift supervisor";
      assignShift(name,role);
    }else if(staff[x].getName() != sludge){
      cout << "searching..." << "\n";
    }
  }
  cout << "Please assign a main barista" << "\n";
  cin >> sludge;
  for(int x = 0; x <= staff.size(); x++){
    if(staff[x].getName() == sludge){
      name = staff[x].getName();
      role = "Main barista";
      assignShift(name,role);
    }else if(staff[x].getName() != sludge){
      cout << "searching..." << "\n";
    }
  }
  cout << "Please assign a bar barista" << "\n";
  cin >> sludge;
  for(int x = 0; x <= staff.size(); x++){
    if(staff[x].getName() == sludge){
      name = staff[x].getName();
      role = "Bar barista";
      assignShift(name,role);
    }else if(staff[x].getName() != sludge){
      cout << "searching..." << "\n";
    }
  }
  cout << "Please assign a DTO barista" << "\n";
  cin >> sludge;
  for(int x = 0; x <= staff.size(); x++){
    if(staff[x].getName() == sludge){
      name = staff[x].getName();
      role = "DTO barista";
      assignShift(name,role);
    }else if(staff[x].getName() != sludge){
      cout << "searching..." << "\n";
    }
  }
  cout << "Please assign a Window barista" << "\n";
  cin >> sludge;
  for(int x = 0; x <= staff.size(); x++){
    if(staff[x].getName() == sludge){
      name = staff[x].getName();
      role = "Window barista";
      assignShift(name,role);
    }else if(staff[x].getName() != sludge){
      cout << "searching..." << "\n";
    }
  }
  printRoles();
}

void menu(){//basic menu that acts as a hub for my various functions
    int sludge;
    string firee;
  cout << "Welcome to Starbucks Shift manager" << "\n" << "Please select an object below to continue" << "\n";
  cout << "1. Hire staff" << "\n";
  cout << "2. Print available staff" << "\n";
  cout << "3. Build a shift" << "\n";
  cout << "4. Fire staff" << "\n";
  cout << "5. Hire more staff" << "\n";
  cout << "6. Clear shift" << "\n";
  cin >> sludge;
  switch(sludge){
    case 1:
      initialBatch();
      break;
    case 2:
      printStaff();
      break;
    case 3:
      shiftBuilder();
      break;
    case 4:
      fireSpace();
      printStaff();
      break;
    case 5:
      newBatch();
      break;
    case 6:
      clockOut();
      break;

  }

}

int main() {//continuous shift building capabilities 
  do{
    menu();
  }while(0 < 1);
}

//source http://www.cplusplus.com/reference/map/map/
//used for really figuring out how to use maps the most effecient way.
//source https://www.cplusplus.com/reference/vector/vector/erase/
//used for the firing feature in the program