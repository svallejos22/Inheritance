/* employee.h	*/
#ifndef EMPLOYEE
#define EMPLOYEE
#include <string>
using namespace std;

                   /*BASE CLASS*/
class Employee 
{
protected:
	long  myIdNum;			//Employee id number
	string myLastName;		//Employee last name
	string myFirstName;		//Employee first name
	string myMiddleInitial;	//Employee middle intial
	int myDeptCode;			//Department code

public:
	Employee(long = 0, const string & = "", const string & = "", const string & = "", int = 0);	// constructor
	//Getters
	long getIdNum() const;				// get id number
	string getLastName() const;			// return last name
	string getFirstName() const;			// return first name
	string getMiddleInitial() const;		// return set middle initial
	int getDeptCode() const;				// get department code
	//Setters
	void setIdNum(const long);			// set id number
	void setLastName(const string&);	// set last name
	void setFirstName(const string&);	// set first name
	void setMiddleInitial(const string&);	// set middle initial
	void setDeptCode(const int);			// set department code
	//Methods
	virtual void printEmployee();	// Passes down to all objects that are inherited
};

                   /*DERIVED CLASS*/
class SalariedEmployee:public Employee 
{
private:
	double _myHourlyRate;
	double _workerType;
public:

	SalariedEmployee(long = 0, const string & = "", const string & = "",
		const string & = "", int = 0, double = 0, double = 0);    	//Parameterized Default Constructor
	//Getters
	double getHourlyRate() const;
	double getWorkerType() const;
	//Setters
	void setHourlyRate(const double);
	void setWorkerType(const double);
	//Methods
	double salaryCalculation(double hourlyRate, double type) const;
	void printEmployee();
};

                   /*DERIVED CLASS*/
class HourlyEmployee : public Employee
{
private:
	double _myHoursWorked;
	double _myHourlyRate;
public:
	//Parameterized Default Constructor
	HourlyEmployee(long = 0, const string & = "", const string & = "",
		const string & = "", int =0, double = 0, double = 0);
	//Gettters
	double getHoursWorked() const;
	double getHourlyRate() const;
	//Setters
	void setHoursWorked(double hoursWorked);
	void setHourlyRate(double hourlyRate);
	//Methods
	double salaryCalculation(double hoursWorked, double hourlyRate) const;
	void printEmployee();
};
#endif