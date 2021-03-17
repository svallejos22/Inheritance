/* File: test.cpp */
// File to test the basic employee class

#include<iostream>
#include <string>
#include "employee.h"
using namespace std;

int main() {
	SalariedEmployee
		se1(001, "Jones", "Booker", "T", 22, 25.50, 1.0),   //full time employee
		se2(002, "Hendrix", "Jimi", "NMI ", 14, 50.75, 1.0),   //full time employee
		se3(003, "Morrison", "Jim", "D", 03, 20.22, 0.50),    //part time employee
		se4(122, "Smith", "John", "T", 32, 32.10, 0.80);     //part time employee

	se1.printEmployee();
	se2.printEmployee();
	se3.printEmployee();
	se4.printEmployee();

	HourlyEmployee
		he1(22, "Gray", "Samantha", "M", 14, 160, 35.23),  //no overtime
		he2(34, "Green", "Michael", "O", 32, 170, 35.23),  //10 hours overtime
		he3(005, "Turner", "Phillip", "A", 03, 160, 25.50);  //no overtime

	he1.printEmployee();
	he2.printEmployee();
	he3.printEmployee();
}
