//Filename:		SeniorEmployee.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "SeniorEmployee.h"
#include <iomanip>

//Constructor
SeniorEmployee::SeniorEmployee ()
{
	performanceBonus = 0;
}

//Sets the field of an SeniorEmployee object	
void SeniorEmployee::setFields (string empID, string name, string address, 
						string phoneNo, string email, string deptNo, double basicPay, 
						double perfomanceBonus, int bDay, int bMonth, int bYear)
{
	Employee::setFields (empID, name, address, phoneNo, email, deptNo, basicPay, 
						bDay, bMonth, bYear);
	
	this -> performanceBonus = performanceBonus;
}

//Calculates the gross pay and net pay of the senior employee
void SeniorEmployee::calculatePay ()
{
	grossPay = performanceBonus + basicPay;
	
	calculateCPF ();
	calculateTax ();
}

//Returns true is this is SeniorEmployee class
bool SeniorEmployee::isSenior () const
{
	return true;
}

//Displays the senior employee's data
void SeniorEmployee::displayData () const
{
	cout<<"Senior Employee"<<endl;
	
	Employee::displayData ();
	
	cout<<"Performance Bonus:\t\t"<<right<<setw (12)<<performanceBonus<<endl
		<<"Gross pay:\t\t\t"<<setw (12)<<grossPay<<endl
		<<"Employer's CPF contribution:\t"<<setw (12)<<employerCPF<<endl
		<<"Employee's CPF contribution:\t"<<setw (12)<<employeeCPF<<endl
		<<"Net Pay:\t\t\t"<<setw (12)<<netPay<<endl
		<<"Tax:\t\t\t\t"<<setw (12)<<tax<<endl
		<<ordinaryAcc<<" into Ordinary Account, "<<endl
		<<specialAcc<<" into Special Account, "<<endl
		<<medisaveAcc<<" into Medisave Account"<<endl;
}

