//Filename:		Employee.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Employee.h"
#include <iomanip>

//Constructor
Employee::Employee ()
{
	basicPay = -1;
	grossPay = -1;
	netPay = -1;
	tax = -1;
	employerCPF = -1;
	employeeCPF = -1;
}

//Sets the fields of the employee object
void Employee::setFields (string empID, string name, string address, 
						string phoneNo, string email, string deptNo, double basicPay, 
						int bDay, int bMonth, int bYear)
{
	this -> empID = empID;
	this -> name = name;
	this -> address = address;
	this -> phoneNo = phoneNo;
	this -> email = email;
	this -> deptNo = deptNo;
	this -> basicPay = basicPay;
	this -> bDay = bDay;
	this -> bMonth = bMonth;
	this -> bYear = bYear;
	
	computeAge ();
}

//Mutator functions
//Sets employee ID
void Employee::setID (const string empID)
{
	this -> empID = empID;
}

//Sets name
void Employee::setName (const string name)
{
	this -> name = name;
}

//Sets address
void Employee::setAddress (const string address)
{
	this -> address = address;
}

//Sets phone number
void Employee::setPhoneNo (const string phoneNo)
{
	this -> phoneNo = phoneNo;
}

//Sets email
void Employee::setEmail (const string email)
{
	this -> email = email;
}

//Sets department number
void Employee::setDeptNo (const string deptNo)
{
	this -> deptNo = deptNo;
}

// Computes the employee's age
void Employee::computeAge ()
{
	time_t now;
	struct tm *present;
	
	time (&now);
	present = localtime (&now);
	
	age = (present -> tm_year + 1900) - bYear;	//Present year - year of birth
	
	//Checks if birthday has passed for the year
	if (bMonth > (present -> tm_mon + 1))
		--age;
	else if (bMonth == (present -> tm_mon + 1))
	{
		if (bDay > present -> tm_mday)
			--age;
	}
}
		
//Accessor function
string Employee::getID () const
{
	return empID;
}

string Employee::getName () const
{
	return name;
}

double Employee::getBasicPay () const
{
	return basicPay;
}

double Employee::getGrossPay () const
{
	return grossPay;
}
		
//Calculates the grossPay and netPay based on the CPF contribution rates
void Employee::calculatePay ()
{
	//Nothing written here
}

//Checks if employee is of senior or ordinary type
bool Employee::isSenior () const
{
}
		
//Calculate the amount of tax the employee is liable
void Employee::calculateTax ()
{
	if (netPay < 30000)
		tax = 0;
	else if (netPay < 40000)
		tax = 200;
	else if (netPay < 80000)
		tax = 550;
	else if (netPay < 120000)
		tax = 3350;
	else if (netPay < 160000)
		tax = 7950;
	else if (netPay < 200000)
		tax = 13950;
	else if (netPay < 320000)
		tax = 20750;
	else
		tax = 42350 + (0.2 * (netPay - 320000));
}

//Calculates CPF contribution from employee and employer
//and how it is credited into each account
void Employee::calculateCPF ()
{
	double employerPercentage, employeePercentage,
			ordinaryPercent, specialPercent, medisavePercent;
			
	double amount = grossPay;
	
	if (grossPay / 12 > 4500)
		amount = 4500 * 12;
	
	if (age <= 50)
	{
		employerPercentage = 0.16;
		employeePercentage = 0.2;
		
		if (age <= 35)
		{
			ordinaryPercent = 0.23;
			specialPercent = 0.06;
			medisavePercent = 0.07;
		}
		else if (age <= 45)
		{
			ordinaryPercent = 0.21;
			specialPercent = 0.07;
			medisavePercent = 0.08;
		}
		else
		{
			ordinaryPercent = 0.19;
			specialPercent = 0.08;
			medisavePercent = 0.09;
		}
	}
	else if (age <= 55)
	{
		employerPercentage = 0.12;
		employeePercentage = 0.18;
		
		ordinaryPercent = 0.13;
		specialPercent = 0.08;
		medisavePercent = 0.09;
	}
	else if (age <= 60)
	{
		employerPercentage = 0.09;
		employeePercentage = 0.125;
		
		ordinaryPercent = 0.115;
		specialPercent = 0.01;
		medisavePercent = 0.09;
	}
	else if (age <= 65)
	{
		employerPercentage = 0.065;
		employeePercentage = 0.075;
		
		ordinaryPercent = 0.035;
		specialPercent = 0.01;
		medisavePercent = 0.095;
	}
	else
	{
		employerPercentage = 0.065;
		employeePercentage = 0.05;
		
		ordinaryPercent = 0.01;
		specialPercent = 0.01;
		medisavePercent = 0.095;
	}
	
	employerCPF = employerPercentage * amount;
	employeeCPF = employeePercentage * amount;
	
	ordinaryAcc = amount * ordinaryPercent;
	specialAcc = amount * specialPercent;
	medisaveAcc = amount * medisavePercent;
	
	netPay = grossPay - employeeCPF;
}
		
//Displays employee's data
void Employee::displayData () const
{
	cout<<"Employee ID:\t\t\t"<<empID<<endl
		<<"EmployeeName:\t\t\t"<<name<<endl
		<<"Date of Birth:\t\t\t"<<bDay<<'/'<<bMonth<<'/'<<bYear<<endl
		<<"Age:\t\t\t\t"<<age<<endl
		<<"Address:\t\t\t"<<address<<endl
		<<"Phone number:\t\t\t"<<phoneNo<<endl
		<<"Email:\t\t\t\t"<<email<<endl
		<<"Department number:\t\t"<<deptNo<<endl
		<<"Basic Pay:\t\t\t"<<right<<setw (12)<<basicPay<<endl;
}

