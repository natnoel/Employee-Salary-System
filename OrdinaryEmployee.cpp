//Filename:		OrdinaryEmployee.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "OrdinaryEmployee.h"
#include <iomanip>

//Constructor
OrdinaryEmployee::OrdinaryEmployee ()
{
	OTPayRate = 0, OTHours = 0, yearlyBonus = 0;
}

//Instantiated with yearly bonus
OrdinaryEmployee::OrdinaryEmployee (double yearlyBonus)
{
	this -> yearlyBonus = yearlyBonus;
}

//Instantiated with an hour overtime pay rate, overtime hours and yearly bonus
OrdinaryEmployee::OrdinaryEmployee (double OTPayRate, double OTHours, double yearlyBonus)
{
	this -> OTPayRate = OTPayRate;
	this -> OTHours = OTHours;
	this -> yearlyBonus = yearlyBonus;
}

//Sets the fields of the OrdinaryEmployee object
void OrdinaryEmployee::setFields (string empID, string name, string address, 
						string phoneNo, string email, string deptNo, double basicPay, 
						int bDay, int bMonth, int bYear,
						double OTPayRate, double OTHours, double yearlyBonus)
{
	Employee::setFields (empID, name, address, phoneNo, email, deptNo, basicPay, 
						bDay, bMonth, bYear);
	
	this -> OTPayRate = OTPayRate;
	this -> OTHours = OTHours;
	this -> yearlyBonus = yearlyBonus;
}
		
//Calculates ordinary employee's gross pay and net pay (overrides Employee class)
void OrdinaryEmployee::calculatePay ()
{
	grossPay = basicPay + (OTPayRate * OTHours) + yearlyBonus;
	
	calculateCPF ();
	calculateTax ();
}

//Since this is an OrdinaryEmployee class, it returns true
bool OrdinaryEmployee::isSenior () const
{
	return false;
}

//Displays the ordinary employee's data
void OrdinaryEmployee::displayData () const
{
	cout<<"Ordinary Employee"<<endl;

	Employee::displayData ();
	
	cout<<"OT pay rate:\t\t\t"<<right<<setw (12)<<OTPayRate<<endl
		<<"OT hours:\t\t\t"<<setw (12)<<OTHours<<endl
		<<"Yearly Bonus:\t\t\t"<<setw (12)<<yearlyBonus<<endl
		<<"Gross pay:\t\t\t"<<setw (12)<<grossPay<<endl
		<<"Employer's CPF contribution:\t"<<setw (12)<<employerCPF<<endl
		<<"Employee's CPF contribution:\t"<<setw (12)<<employeeCPF<<endl
		<<"Net Pay:\t\t\t"<<setw (12)<<netPay<<endl
		<<"Tax:\t\t\t\t"<<setw (12)<<tax<<endl
		<<ordinaryAcc<<" into Ordinary Account, "<<endl
		<<specialAcc<<" into Special Account, "<<endl
		<<medisaveAcc<<" into Medisave Account"<<endl;
}

