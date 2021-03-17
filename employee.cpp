/* employee.cpp*/
#include <iostream>
#include <iomanip>
#include <string>
#include "employee.h"
using namespace std;

// constructor
Employee::Employee(long id, const string& last, const string& first, 
	const string& initial, int dept)
{
	myIdNum = id;
	myLastName = last;
	myFirstName = first;
	myMiddleInitial = initial;
	myDeptCode = dept;
	
}
// Accessor function defintions
void Employee::setIdNum(const long  id)
{
	myIdNum = id;
}
// get id number
long Employee::getIdNum() const
{
	return myIdNum;
}
// set last name
void Employee::setLastName(const string& last)
{
	myLastName = last;
}
// return last name
string Employee::getLastName() const
{
	return myLastName;
}
// set first name
void Employee::setFirstName(const string& first)
{
	myFirstName = first;
}
// return first name
string Employee::getFirstName() const
{
	return myFirstName;
}
// set middle initial
void Employee::setMiddleInitial(const string& last)
{
	myMiddleInitial = last;
}
// return middle initial
string Employee::getMiddleInitial() const
{
	return myMiddleInitial;
}
// set department code
void Employee::setDeptCode(const int dc)
{
	myDeptCode = dc;
}
// get department code
int Employee::getDeptCode() const
{
	return myDeptCode;
}
// print Employee information
void Employee::printEmployee()
{
	cout << endl;
	cout << "Employee ID Number: " << getIdNum() << endl;
	cout << "Name: " << getLastName() << ", " << getFirstName() << " " <<
		getMiddleInitial() << "." << endl;
	cout << "Dept Code: " << getDeptCode() << endl;
}

                   /*SALARIED EMPLOYEE*/
//Constructor
SalariedEmployee::SalariedEmployee(long id, const string& last, const string& first,
	const string& initial, int dept, double hourlyRate, double type)
	: Employee (myIdNum, myLastName, myFirstName, myMiddleInitial, myDeptCode),
	_myHourlyRate(hourlyRate), _workerType(type)
{
	setIdNum(id);
	setLastName(last);
	setFirstName(first);
	setMiddleInitial(initial);
	setDeptCode(dept);
	setHourlyRate(hourlyRate);
	setWorkerType(type);
}
//Getters
double SalariedEmployee::getHourlyRate() const 
{
	return _myHourlyRate;
}
double SalariedEmployee::getWorkerType() const
{
	return _workerType;
}

//Setters
void SalariedEmployee::setHourlyRate(const double hourlyRate) 
{
	_myHourlyRate = hourlyRate;
}
void SalariedEmployee::setWorkerType(const double type)
{
	_workerType = type;
}
//Methods
double SalariedEmployee::salaryCalculation(const double hourlyRate, double type) const 
{
	double employeeType = type;
	double rate = hourlyRate;
	double yearlySalary;
	double monthlySalary;

	if (employeeType == 1)   //Full Time Employee
	{  
		yearlySalary = rate * 8 * 260;     //Unadjusted Salary (52 wks * 5 working day = 260 days)
		monthlySalary = yearlySalary / 12;
	}
	else      //Part-Time Employee
	{
		yearlySalary = rate * 8 * 260;  //Unadjusted Salary (52 wks * 5 working day = 260 days)
		monthlySalary = (yearlySalary / 12) * employeeType;
	}

	return monthlySalary;
}
void SalariedEmployee::printEmployee()
{
	cout << endl;
	cout << "Employee ID Number: " << getIdNum() << endl;
	cout << "Name: " << getLastName() << ", " << getFirstName() << " " <<
		getMiddleInitial() << "." << endl;
	cout << "Dept Code: " << getDeptCode() << endl;
	cout << "Monthly Salary: $" << SalariedEmployee::salaryCalculation(getHourlyRate(), getWorkerType()) << endl;
}

                             /*HOURLY EMPLOYEE*/
HourlyEmployee::HourlyEmployee(long id, const string& last, const string& first,
	const string& initial, int dept, double hoursWorked, double hourlyRate)
	: Employee(myIdNum, myLastName, myFirstName, myMiddleInitial, myDeptCode),
	_myHoursWorked(hoursWorked), _myHourlyRate(hourlyRate)
{
	setIdNum(id);
	setLastName(last);
	setFirstName(first);
	setMiddleInitial(initial);
	setDeptCode(dept);
	setHoursWorked(hoursWorked);
	setHourlyRate(hourlyRate);
}
//Getters
double HourlyEmployee::getHoursWorked() const
{
	return _myHoursWorked;
}

double HourlyEmployee::getHourlyRate() const
{
	return _myHourlyRate;
}
//Setters
void HourlyEmployee::setHoursWorked(const double hoursWorked)
{
	_myHoursWorked = hoursWorked;
}
void HourlyEmployee::setHourlyRate(const double hourlyRate)
{
	_myHourlyRate = hourlyRate;
}
//Methods
double HourlyEmployee::salaryCalculation(double hoursWorked, double hourlyRate) const
{
	double hours = hoursWorked;
	double rate = hourlyRate;  
	double monthlySalary;

	if (hoursWorked <= 160) //normal 40hr work week or less
	{
		monthlySalary = hours * rate;
	}
	else
	{ 
		double baseSalary = 160 * rate; //normal salary paid for 40hr work week
		double overtimeHrs = hours - 160;
		double overtimeRate = rate * 1.5;
		double overtimePay = overtimeRate * overtimeHrs;
		monthlySalary = baseSalary + overtimePay;
	}
	return monthlySalary;
}
void HourlyEmployee::printEmployee()
{
	cout << endl;
	cout << "Employee ID Number: " << getIdNum() << endl;
	cout << "Name: " << getLastName() << ", " << getFirstName() << " " <<
		getMiddleInitial() << "." << endl;
	cout << "Dept Code: " << getDeptCode() << endl;
	cout << "Monthly Salary: $" << HourlyEmployee::salaryCalculation(getHoursWorked(), getHourlyRate()) << endl;
}
