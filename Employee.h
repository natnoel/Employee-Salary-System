//Filename:		Employee.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include <iostream>
using namespace std;

class Employee
{
	public:
		//Constructor
		Employee ();
	
		//Sets the fields of the Employee object
		virtual void setFields (string, string, string, string, string, string,
						 double, int, int, int);
		
		//Mutator functions
		void setID (const string);
		void setName (const string);
		void setAddress (const string);
		void setPhoneNo (const string);
		void setEmail (const string);
		void setDeptNo (const string);
		
		//Accessor function
		string getID () const;
		string getName () const;
		double getBasicPay () const;
		double getGrossPay () const;
		
		//Calculates the grossPay and netPay based on the CPF contribution rates
		void calculatePay ();
		
		//Calculate the amount of tax the employee is liable
		void calculateTax ();
		
		//Calculates CPF contribution from employee and employer
		//and how it is credited into each account
		void calculateCPF ();
		
		//Displays employee's data
		virtual void displayData () const;
		
		//Checks if employee is of type senior or ordinary
		virtual bool isSenior () const;
		
	protected:
		string empID, name, address, phoneNo, email, deptNo;
		double basicPay, grossPay, netPay, tax, employerCPF, employeeCPF,
				ordinaryAcc, specialAcc, medisaveAcc;
		int bDay, bMonth, bYear, age;
		
		//Computes the age of the employee
		void computeAge ();
};

