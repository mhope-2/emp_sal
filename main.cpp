// A C++ program that processes employees and their pays

#include <iostream>
#include <string>
using namespace std;


// Employee name prompt
string getEmployeeName() {
  cout <<"Enter the name of the employee: ";
  string name;
  
  while (!(cin >> name)){
    cout <<"Error: Enter a string: ";
    // clear old input
    cin.clear();
    cin.ignore(123, '\n');
    cin >> name;
  }
  return name;
}

// Houry pay rate prompt
float getHourlyPayRate() {
  float hourlyPayRate;
  cout << "Enter the hourly pay rate: ";
  while(!(cin >> hourlyPayRate)){
     cout <<"Error: Enter a float: ";
    
    //clear old output
    cin.clear();
    cin.ignore(123, '\n');
    cin >> hourlyPayRate;
  }
  
  return hourlyPayRate;
}

// Prompt to enter the hours worked for 5 days
float getHoursWorked() {
  float totalHoursWorked = 0.0;
  float hoursWorked;
  
  for (int i=1; i<=5; i++) {
    cout<<"Enter the number of hours worked for Day "<<i <<": "<< endl;
    while(!(cin >> hoursWorked)){
      cout<<"Error: Enter a float";
      cin >> hoursWorked;
    }
    totalHoursWorked += hoursWorked;
  }
  
return totalHoursWorked;
}


// Calculates and returns the gross pay
double caculateGrossPay(float hourlyPayRate, float totalHoursWorked) {
  double grossPay = hourlyPayRate * totalHoursWorked;
  return grossPay;
}

// Calculates and returns withholdings
double calculateEmployeeWithholding(double employeeGrossPay){
  double stateTax = (1.25/100) * employeeGrossPay;
  double FICA = (7.65/100) * employeeGrossPay;
  double federalTax;

  if(employeeGrossPay < 500){
    federalTax = (15/100) * employeeGrossPay;
  } else {
    federalTax = (25/100) * employeeGrossPay;
  }

  return stateTax + FICA + federalTax;
}


int main(){
  
  while(true){
    string employeeName = getEmployeeName();
    if (employeeName == "done"){
      break;
    }
    
    float employeeHourlyPayRate = getHourlyPayRate();
    float totalHoursWorked = getHoursWorked();
  
    double employeeGrossPay = caculateGrossPay(employeeHourlyPayRate, totalHoursWorked);
    double employeeTotalWithholding = calculateEmployeeWithholding(employeeGrossPay); // 26536.8
    double employeeNetPay = employeeGrossPay - employeeTotalWithholding;
  
    
    cout <<"======= PAYROLL =======" << endl;
    cout <<"Employee Name: "<<employeeName << endl;
    cout <<"Gross Pay: $"<<employeeGrossPay << endl;
    cout <<"Employee Total Withholding: $"<< employeeTotalWithholding<< endl;
    cout<<"Employee Net Pay: $"<< employeeNetPay << endl;
    cout<<"\n" <<endl;
  }
  
  return 0;
}
