//Filename:		SeniorEmployee.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "OrdinaryEmployee.h"

class SeniorEmployee: public Employee
{
	public:
		//Empty constructor
		SeniorEmployee ();
		
		//Sets the field of an SeniorEmployee object
		virtual void setFields (string, string, string, string phoneNo, string, string, 
						double, double, int, int, int);
						
		//Calculates the gross pay and net pay of the senior employee
		void calculatePay ();
		
		//Return true as this is SeniorEmployee class
		virtual bool isSenior () const;
		
		//Displays the senior employee's data
		virtual void displayData () const;
		
	private:
		double performanceBonus;
};

