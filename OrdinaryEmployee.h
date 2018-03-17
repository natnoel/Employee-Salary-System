//Filename:		OrdinaryEmployee.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Employee.h"

class OrdinaryEmployee: public Employee
{
	public:
		//Constructor
		OrdinaryEmployee ();
		
		//Instantiated with yearly bonus
		OrdinaryEmployee (double);
		
		//Instantiated with an hour overtime pay rate, overtime hours and yearly bonus
		OrdinaryEmployee (double, double, double);	
	
		//Sets the fields of the OrdinaryEmployee object
		virtual void setFields (string, string, string, string, string, string, double, 
						int, int, int, double, double, double);
		
		//Calculates ordinary employee's gross pay and net pay
		void calculatePay ();
		
		//Returns false as this is an OrdinaryEmployee class
		virtual bool isSenior () const;
		
		//Displays ordinary emplyee's data
		void displayData () const;
		
	private:
		double OTPayRate, OTHours, yearlyBonus;
};

