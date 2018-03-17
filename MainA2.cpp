//Filename:		MainA2.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "SeniorEmployee.h"
#include <iomanip>
#include <map>

class EmployeePaySystem
{
	public:
		EmployeePaySystem ();	//Constructor
		~EmployeePaySystem ();	//Destructor
		
		int main ();			//Function to run the program
	private:
	
	/******************************Variables******************************/
		char option;	//Stores user's option
	
		//Stores the data to create or update the employee objects
		string id, name, address, phoneNo, email, deptNo, oldName;
		double basicPay, bonus, OTPayRate, OTHours, grossPay;
		int bDay, bMonth, bYear;
		
		//Used for searching by gross pay
		double lower, upper;
		
		//Statistical information
		int seniorEmpCount, ordEmpCount;
		double totalSeniorSal, totalOrdSal, totalSal, avgSeniorSal, avgOrdSal, avgSal;
		
		OrdinaryEmployee *oPtr;
		SeniorEmployee *sPtr;
		Employee *ePtr;
		
		map <string, Employee*> empByID;	//Map indexed by employee ID
		pair <string, Employee*> idPair;	//Element of empByID
		map <string, Employee*>::iterator idit;	//Iterator for empByID
		
		//For checking if insertion into empByID is successful
		pair <map <string, Employee*>::iterator, bool> checkIDIdx;
		
		multimap <string, Employee*> empByName;	//Multimap indexed by by employee name
		pair <string, Employee*> namePair;		//Element of empByName
		
		multimap <double, Employee*> empByGrossPay;	//Multimap indexed by employee's gross pay
		pair <double, Employee*> gpPair;			//Element of empByGrossPay
		
		//For getting the first and last positions of the equal range when searching
		//by empByName
		pair <multimap <string, Employee*>::iterator, 
			multimap <string, Employee*>::iterator> nfirstLast;
		
		//For getting the first and last positions of the equal range when searching
		//by empByGrossPay
		pair <multimap <double, Employee*>::iterator, 
			multimap <double, Employee*>::iterator> gpFirstLast;
		
		
	/******************************Functions******************************/
		//Gets the data for an Employee object
		void getStandardEmpInfo (string&, string&, string&, string&, string&, string&, 
								double&, int&, int&, int&);
								
		bool validID (const string);		//Checks if ID is valid
		
		bool validPhoneNo (const string);	//Checks if phoneNo is valid
		
		bool validDOB (const int, const int, const int);//Checks if date of birth is valid
								
		void printByID ();	//Prints the Employees by ID in ascending order
		
		void printByName ();	//Prints the Employees by name in ascending order
		
		void printByGrossPay ();	//Prints the Employees by gross pay in ascending order
		
		void printReverseByID ();	//Prints the Employees by ID in descending order
		
		void printReverseByName ();	//Prints the Employees by name in descending order
		
		void printReverseByGrossPay ();//Prints the Employees by gross pay in descending order
		
		void findAndPrint (const string);	//Finds the employee(s) by name print
		
		//Finds the employee(s) by gross pay range and prints
		void findAndPrint (const double&, const double&);
		
		double getTotalSalaryPaid ();	//Calculates total salary paid for all employees
		
		//Prints the list of senior employee IDs along with their gross pays
		void printSeniorIDGrossPayList ();
		
		//Prints the list of ordinary employee IDs along with their gross pays
		void printOrdIDGrossPayList ();
		
		double getMaxSenEmpSal ();	//Get the maximum senior employee's gross pay
		
		double getMaxOrdEmpSal ();	//Get the maximum ordinary employee's gross pay
		
		double getMinSenEmpSal ();	//Get the minimum senior employee's gross pay
		
		double getMinOrdEmpSal ();	//Get the minimum ordinary employee's gross pay
};

int EmployeePaySystem::main ()
{	 
	do
	{
		cout<<"========================================="<<endl
			<<"=               Main Menu               ="<<endl
			<<"========================================="<<endl
			<<"1. Enter employee's profile"<<endl
			<<"2. Display all employees"<<endl
			<<"3. Find an employee's profile"<<endl
			<<"4. Display summary of payment of salary for all the employees"<<endl
			<<"5. Change employee's profile"<<endl
			<<"6. Delete employee's profile"<<endl
			<<"7. View statistical data"<<endl
			<<"8. Exit"<<endl<<endl
			
			<<"Enter your choice: ";
		cin>>option;
		cout<<"------------------------------------------"<<endl
			<<fixed<<showpoint<<setprecision(2);//To show all money value in dollars and cents
		
		switch (option)
		{
			case '1':	do	//Creating Employee objects or registering employees
						{
							cout<<"1. Enter Ordinary Employee profile"<<endl
								<<"2. Enter Senior Employee profile"<<endl<<endl
								<<"Enter option: ";
								
							cin>>option;
							
							cout<<"------------------------------------"<<endl;
							
							switch (option)
							{
								case '1':	cin.clear ();
											cin.ignore (100, '\n');
											
											getStandardEmpInfo (id, name, address, phoneNo, 
														email, deptNo, basicPay, bDay, 
														bMonth, bYear);
											do
											{
												cout<<"Enter hourly overtime pay rate: ";
												cin>>OTPayRate;
												if (OTPayRate < 0)
													cout<<"Pay rate cannot be negative! "
														<<"Please re-enter"<<endl;
											} while (OTPayRate < 0);	//Data validation
											
											do
											{
												cout<<"Enter overtime hours: ";
												cin>>OTHours;
												if (OTHours < 0)
													cout<<"OT hour cannot be negative"
														<<"Please re-enter"<<endl;
											} while (OTHours < 0);	//Data validation
											
											do
											{
												cout<<"Enter yearly bonus: ";
												cin>>bonus;
												if (bonus < 0)
													cout<<"Bonus cannot be negative!"
														<<"Please re-enter"<<endl;
											} while (bonus < 0);	//Data validation
											
											cout<<endl;
											
											oPtr = new OrdinaryEmployee;
											
											oPtr -> setFields (id, name, address, phoneNo, 
													email, deptNo, basicPay, bDay, bMonth, 
													bYear, OTPayRate, OTHours, bonus);
													
											oPtr -> calculatePay ();
											cout<<"Pay calculated!"<<endl;
											
											ePtr = oPtr;
											
											break;
											
								case '2':	cin.clear ();
											cin.ignore (100, '\n');
											
											getStandardEmpInfo (id, name, address, phoneNo, 
														email, deptNo, basicPay, bDay, 
														bMonth, bYear);
											do
											{	 	 	 
												cout<<"Enter performance bonus: ";
												cin>>bonus;
												
												if (bonus < 0)
													cout<<"Bonus cannot be negative!"
														<<"Please re-enter"<<endl;
											} while (bonus < 0);	//Data validation
											cout<<endl;
											
											sPtr = new SeniorEmployee;

											sPtr -> setFields (id, name, address, phoneNo, 
														email, deptNo, basicPay, bonus, bDay, 
														bMonth, bYear);
														
											sPtr -> calculatePay ();
											cout<<"Pay calculated!"<<endl;

											ePtr = sPtr;
											
											break;
											
								default:	cout<<"Invalid entry!"<<endl;
							}
							
							if (option == '1' || option == '2')
							{
								idPair.first = id;
								idPair.second = ePtr;
											
								checkIDIdx = empByID.insert (idPair);
											
								if (checkIDIdx.second)	//Inserts into map empByID
								{
									cout<<"Entry inserted successfully!"<<endl
										<<"ID index updated!"<<endl;
									
									//Inserts into the empByName map	  
									namePair.first = name;
									namePair.second = ePtr;
									empByName.insert (namePair);
									cout<<"Name index updated!"<<endl;
									
									//Inserts into the empByGrossPay map			
									gpPair.first = ePtr -> getGrossPay ();
									gpPair.second = ePtr;
									empByGrossPay.insert (gpPair);
									cout<<"Gross pay index updated!"<<endl;
									
									//Updates the employee count and 
									//total gross pay of each type
									if (ePtr -> isSenior ())
									{
										totalSeniorSal += ePtr -> getGrossPay ();
										seniorEmpCount++;
									}
									else
									{
										totalOrdSal += ePtr -> getGrossPay ();
										ordEmpCount++;
									}
								}
								else	//If unable to insert into empByID map
								{
									cout<<"Employee ID "<<id<<" already exist! "
										<<"Entry not inserted!"<<endl;
								}
								
								cout<<endl;
							}
							
							cout<<endl<<"Do you want to continue? (Y/N or y/n):";
							cin>>option;
							cout<<"------------------------------"<<endl;
												
							if (option != 'Y' && option != 'y' && 
								option != 'N' && option != 'n')
								cout<<"Invalid entry! Returning to main menu..."<<endl;
								
						} while (option == 'Y' || option == 'y');
						
						break;
						
			case '2':	do	//Displays all the employees
						{
							cout<<"1. Display employees by ID (ascending order)"<<endl
								<<"2. Display employees by name (ascending order)"<<endl
								<<"3. Display employees by gross pay (ascending order)"<<endl
								<<"4. Display employees by ID (descending order)"<<endl
								<<"5. Display employees by name (descending order)"<<endl
								<<"6. Display employees by gross pay (descending order)"<<endl
								<<endl<<"Please enter you option: ";
							cin>>option;
							
							cout<<"-------------------------------"<<endl;
							
							switch (option)
							{
								case '1':	printByID ();
											break;
											
								case '2':	printByName ();
											break;
											
								case '3':	printByGrossPay ();
											break;
											
								case '4':	printReverseByID ();
											break;
											
								case '5':	printReverseByName ();
											break;
								
								case '6':	printReverseByGrossPay ();
											break;
											
								default:	cout<<"Invalid option!"<<endl;
							}
							
							cout<<endl<<"There are "<<empByID.size ()<<" employees registered"
								<<endl;
							
							cout<<endl<<"Do you want to continue? (Y/N or y/n):";
							cin>>option;
							cout<<"------------------------------"<<endl;
												
							if (option != 'Y' && option != 'y' && 
								option != 'N' && option != 'n')
								cout<<"Invalid entry! Returning to main menu..."<<endl;
								
						} while (option == 'Y' || option == 'y');
			
						break;
						
			case '3':	try	//Finds a particular employee or a particular group of employees
						{
							if (empByID.size () == 0)	//If no employees in records
								throw exception ();
							do
							{
								cout<<"1. Find employee by ID"<<endl
									<<"2. Find employee by name"<<endl
									<<"3. Find employee by gross pay"<<endl<<endl
									<<"Enter your option: ";
								cin>>option;
								cout<<"-------------------------"<<endl;
								cin.clear ();
								cin.ignore (100, '\n');
								
								switch (option)
								{
									case '1':	try
												{
													cout<<"Enter employee's ID: ";
													getline (cin, id);
													cout<<"-----------------------"<<endl;
													idit = empByID.find (id);
													if (idit == empByID.end ())
														throw id;	//If it does not exist
														
													idit -> second -> displayData ();
												}
												catch (string badID)
												{
													cout<<"Employee "<<badID
														<<" does not exist in records!"<<endl;
												}
												break;
												
									case '2':	try
												{
													cout<<"Enter employee's name: ";
													getline (cin, name);
													cout<<"-------------------------"<<endl;
													findAndPrint (name);
												}
												catch (string badName)
												{
													cout<<"Employee with name "<<badName
														<<" does not exist in records!"<<endl;
												}
												
												break;
												
									case '3':	try
												{
													cout<<"Enter lower bound gross pay: ";
													cin>>lower;	//Minimum gross pay
													cout<<"Enter upper bound gross pay: ";
													cin>>upper;	//Maximum gross pay
													cout<<"---------------------------------"<<endl;
													findAndPrint (lower, upper);
												}
												catch (exception e)
												{
													cout<<"Lower bound is higher "
														<<"than upper bound!"
														<<endl;
												}
												break;
												
									default:	cout<<"Invalid option!"<<endl;
								}
								
								cout<<endl<<"Do you want to find another employee profile?"
									<<" (Yy/Nn): ";
								cin>>option;
								
								if (option != 'Y' && option != 'y' && 
									option != 'N' && option != 'n')
									cout<<"Invalid entry! Returning to main menu..."<<endl;
							} while (option == 'Y' || option == 'y');
						}
						catch (exception e)
						{
							cout<<"There are no employees registered!"<<endl;
						}
																
						break;
			
			case '4':	//Displays summary of what company has to pay the employees
						totalSal = getTotalSalaryPaid ();
						totalOrdSal = totalSal - totalSeniorSal;
						ordEmpCount = empByID.size () - seniorEmpCount;
						
						printSeniorIDGrossPayList ();
						cout<<"--------------------------------------------------------"<<endl
							<<"Total payment for Senior employee's salary  = "
							<<totalSeniorSal<<endl<<endl
							<<"Number of Senior employees: "<<seniorEmpCount<<endl<<endl<<endl;
							
						printOrdIDGrossPayList ();
						cout<<"--------------------------------------------------------"
							<<endl<<"Total payment for Ordinary employee's salary  = "
							<<totalOrdSal<<endl<<endl
							<<"Number of Ordinary employees: "<<ordEmpCount<<endl<<endl<<endl
							<<"Total amount company pays = "<<totalSal<<endl;

						break;
			
			case '5':	//Changes some of the employee details
						if (empByID.size () != 0)	//If there exist some records
						{
							do
							{
								cout<<"Enter the ID of the employee profile to be changed: ";
								cin.clear ();
								cin.ignore (100, '\n');
								getline (cin,id);
								cout<<endl;
								try
								{
									idit = empByID.find (id);
									if (idit == empByID.end ())	//If ID not found
										throw id;
											
									idit -> second -> displayData ();
									cout<<endl;
									cout<<"Which field(s) do you wish to change?"<<endl
										<<"1. Name"<<endl
										<<"2. Address"<<endl
										<<"3. Phone number"<<endl
										<<"4. Email address"<<endl
										<<"5. Department Number"<<endl<<endl
										<<"Enter your option: ";
									cin>>option;
									cout<<"------------------------"<<endl;
									cin.clear ();
									cin.ignore (100, '\n');
									switch (option)
									{
										case '1':	cout<<"Enter new name: ";
													getline (cin, name);
													
													//Deleting element in empByName
													oldName = idit -> second -> getName ();
													nfirstLast = empByName.equal_range (oldName);
													while (nfirstLast.first -> second -> getID () != id)
														nfirstLast.first++;
													empByName.erase (nfirstLast.first);
													
													idit -> second -> setName (name);
													cout<<"Change successfully!"<<endl;
													
													//Inserting updated element to empByName
													namePair.first = name;
													namePair.second = idit -> second;
													empByName.insert (namePair);
													cout<<"Updated name index"<<endl;
													break;
													
										case '2':	cout<<"Enter new address: ";
													getline (cin, address);
													idit -> second -> setAddress (address);
													cout<<"Change successfully!"<<endl;
													break;
													
										case '3':	do
													{
														cout<<"Enter new phone number: ";
														getline (cin, phoneNo);
													} while (!validPhoneNo (phoneNo));
													idit -> second -> setPhoneNo (phoneNo);
													cout<<"Change successfully!"<<endl;
													break;
													
										case '4':	cout<<"Enter new email address: ";
													getline (cin, email);
													idit -> second -> setEmail (email);
													cout<<"Change successfully!"<<endl;
													break;
													
										case '5':	cout<<"Enter new department number: ";
													getline (cin, deptNo);
													idit -> second -> setDeptNo (deptNo);
													cout<<"Change successfully!"<<endl;
													break;
													
										default:	cout<<"Invalid option!"<<endl;
									}
								}
								catch  (string badID)
								{
									cout<<"Employee with ID "<<badID<<" not found in records!"
										<<endl;
								}
								cout<<endl<<"Do you still want to change an employee profile?"
									<<" (Yy/Nn): ";
								cin>>option;
							
								if (option != 'Y' && option != 'y' && 
									option != 'N' && option != 'n')
									cout<<"Invalid entry! Returning to main menu..."<<endl;
										
								cout<<endl;
							} while (option == 'Y' || option == 'y');
						}
						else
							cout<<"There are no employees registered"<<endl;
						break;
						
			case '6':	try	//Deletes an employee object
						{
							if (empByID.size () == 0)	//If no employee objects in records
								throw exception ();
							do
							{
								cout<<"Enter the ID of the employee you wish to delete: ";
								cin>>id;
								cout<<endl;
								idit = empByID.find (id);
								try
								{
									if (idit == empByID.end ())	//If ID not found
										throw exception ();
										
									idit -> second -> displayData ();
									cout<<endl<<"Are you sure you want to delete this employee?"
										<<" (Yy/Nn): ";	//Confirmation / double check
									cin>>option;
									cout<<endl;
									
									if (option == 'Y' || option == 'y')	//Deleting employee
									{
										//Stores the name and gross pay
										name = idit -> second -> getName ();
										grossPay = idit -> second -> getGrossPay ();
										
										//Deletes from empByName multimap
										nfirstLast = empByName.equal_range (name);
										while (nfirstLast.first -> second -> getID () != id)
											nfirstLast.first++;
										empByName.erase (nfirstLast.first);
										cout<<"Removed from name index"<<endl;
										
										//Deletes from empByGrossPay multimap
										gpFirstLast = empByGrossPay.equal_range (grossPay);
										while (gpFirstLast.first -> second -> getID () != id)
											gpFirstLast.first++;
										empByGrossPay.erase (gpFirstLast.first);
										cout<<"Removed from gross pay index"<<endl;
										
										//Updates count and total salary
										if (idit -> second -> isSenior () == true)
										{
											totalSeniorSal -= idit -> second -> getGrossPay ();
											seniorEmpCount--;
										}
										else
										{
											totalOrdSal -= idit -> second -> getGrossPay ();
											ordEmpCount--;
										}
										
										delete idit -> second;	//Frees the memory
										cout<<"Deleted employee "<<id<<" object"<<endl;
										
										empByID.erase (idit);	//Deletes from empByID map
										cout<<"Removed from ID index"<<endl;
										
									}
									else
									{
										if (option != 'N' && option != 'n')
											cout<<"Invalid option!"<<endl;
											
										cout<<"Employee not deleted"<<endl;
									}
								}
								catch (exception e)
								{
									cout<<"Employee do not exist!"<<endl;
								}
								
								if (empByID.size () == 0)	//If size reaches 0 after deletion
									throw exception ();
								
								cout<<endl<<"Do you still want to delete an employee profile?"
									<<" (Yy/Nn): ";
								cin>>option;
								cout<<endl;
								
								if (option != 'Y' && option != 'y' && 
									option != 'N' && option != 'n')
									cout<<"Invalid entry! Returning to main menu..."<<endl;
							} while (option == 'Y' || option == 'y');
						}
						catch (exception e)
						{
							cout<<"There are no employees registered!"<<endl;
						}
						break;
						
			case '7':	//Displays the statistical information
						totalSal = getTotalSalaryPaid ();
						
						cout<<"Total senior employees =\t"<<seniorEmpCount<<endl
							<<"Total ordinary employees =\t"<<ordEmpCount<<endl
							<<"Total employees:\t\t"<<empByID.size ()<<endl<<endl;

						if (seniorEmpCount != 0)
						{
							avgSeniorSal = totalSeniorSal / seniorEmpCount;
							cout<<"Average senior employee's yearly salary = "<<avgSeniorSal<<endl
								<<"Maximum senior employee's yearly salary = "
								<<getMaxSenEmpSal ()<<endl
								<<"Minimum senior employee's yearly salary = "
								<<getMinSenEmpSal ()<<endl<<endl;
						}
						if (ordEmpCount != 0)
						{
							avgOrdSal = totalOrdSal / ordEmpCount;
							cout<<"Average ordinary employee's yearly salary = "<<avgOrdSal
								<<endl
								<<"Maximum ordinary employee's yearly salary = "
								<<getMaxOrdEmpSal ()<<endl
								<<"Minimum ordinary employee's yearly salary = "
								<<getMinOrdEmpSal ()<<endl;
						}
						if (empByID.size () != 0)
						{
							avgSal = totalSal / empByID.size ();
							cout<<"Average employee's yearly salary = "<<avgSal<<endl;
						}
							
						break;
			
			case '8':	cout<<"Have a nice day :)"<<endl;	//Exits system
						break;
						
			default:	cout<<"Invalid option!"<<endl;
		}
		cout<<"------------------------------------------"<<endl;
		
	} while (option != '8');
	

	
	return 0;
}

//Constructor
EmployeePaySystem::EmployeePaySystem ()
{
	seniorEmpCount = 0;	//Initialises count and total salary
	ordEmpCount = 0;
	totalSeniorSal = 0;
	totalOrdSal = 0;	   
}

//Destructor frees the memory occupied by Employee objects
EmployeePaySystem::~EmployeePaySystem ()
{
	for (idit = empByID.begin (); idit != empByID.end (); idit++)
	{
		id = idit -> second -> getID ();
		delete idit -> second;
		cout<<"Employee object with ID "<<id<<" deleted"<<endl;
	}
}

//Gets the input for creating an Employee object
void EmployeePaySystem::getStandardEmpInfo (string& id, string& name, string& address, 
						string& phoneNo, string& email, string& deptNo, 
						double& basicPay, int& bDay, int& bMonth, int& bYear)
{
	char dummy;
	
	do
	{
		cout<<"Enter Employee ID: ";
		getline (cin, id);
	} while (!validID (id));	//Data validation
	
	cout<<"Enter name: ";
	getline (cin, name);
	cout<<"Enter address: ";
	getline (cin, address);
	
	do
	{
		cout<<"Enter phone number: ";
		getline (cin, phoneNo);
	} while (!validPhoneNo (phoneNo));	//Data validation
	
	cout<<"Enter email address: ";
	getline (cin, email);
	cout<<"Enter department number: ";
	getline (cin, deptNo);
	
	do
	{
		cout<<"Enter basic pay: ";
		cin>>basicPay;
		
		if (basicPay < 0)
			cout<<"Basic pay cannot be negative! Please re-enter"<<endl;
	} while (basicPay < 0);	//Data validation
	
	do
	{
		cout<<"Enter date of birth (DD/MM/YYYY): ";
		cin>>bDay>>dummy>>bMonth>>dummy>>bYear;
	} while (!validDOB (bDay, bMonth, bYear));	//Data validation
}

//Checks if ID is valid
bool EmployeePaySystem::validID (const string id)
{
	bool isValid = true;
	if (empByID.count (id) == 1)
	{
		cout<<"Employee ID "<<id<<" already exist! Please re-enter ID"<<endl;
		isValid = false;
	}

	return isValid;
}

//Checks if phone number is valid
bool EmployeePaySystem::validPhoneNo (const string phoneNo)
{
	bool isValid = true;
	if (phoneNo.size () != 8)
	{
		cout<<"Phone number must be 8 digits! Please re-enter"<<endl;
		isValid = false;
	}
	else
	{
		for (int i = 0; i < phoneNo.size () && isValid == true; i++)
		{
			if (!isdigit (phoneNo.at (i)))
			{
				cout<<"Phone number must be numeric! Please re-enter"<<endl;
				isValid = false;
			}
		}
	}
	
	return isValid;
}

//Checks if date of birth is valid
bool EmployeePaySystem::validDOB (const int bDay, const int bMonth, const int bYear)
{
	bool isValid = true;
	
	if (bDay < 1 || bDay > 31)	//Checks for out of range day
	{
		cout<<"Invalid day entered! Please re-enter"<<endl;
		isValid = false;
	}
	else if (bMonth < 1 || bMonth > 12)	//Checks for out of range month
	{
		cout<<"Invalid month entered! Please re-enter"<<endl;
		isValid = false;
	}
	else if ((bMonth == 4 || bMonth == 6|| bMonth == 9|| bMonth == 11)
			 && (bDay == 31))	//Checks for months that have more than 30 days
	{
		cout<<"This day do not exist in the month! Please re-enter"<<endl;
		isValid = false;
	}
	else
	{
		int febMax, yrsFromALeapYr;
		
		yrsFromALeapYr = 2008 - bYear;
		
		if (yrsFromALeapYr % 4)
			febMax = 28;
		else
			febMax = 29;
		
		if (bMonth == 2 && bDay > febMax)	//Checks for possible leap years
		{
			cout<<"This day do not exist! Please re-enter"<<endl;
			isValid = false;
		}
		else
		{
			time_t now;
			struct tm *present;
			
			time (&now);
			present = localtime (&now);
			
			if	((bYear > present -> tm_year + 1900) || 
				(bYear == present -> tm_year + 1900 && bMonth > present -> tm_mon + 1) ||
				(bYear == present -> tm_year + 1900 && bMonth == present -> tm_mon + 1
				&& bDay > present -> tm_mday))	//Checks if date is in the future
			{
				cout<<"Date is in the future! Please re-enter"<<endl;
				isValid = false;
			}
		}
	}
	
	return isValid;
}


//Prints employees by ID in ascending order
void EmployeePaySystem::printByID ()
{
	for (map <string, Employee*>::iterator idit = empByID.begin (); idit != empByID.end ();
		idit++)
	{
		idit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Prints employees by name in ascending order
void EmployeePaySystem::printByName ()
{
	for (multimap <string, Employee*>::iterator nameit = empByName.begin (); 
		nameit != empByName.end (); nameit++)
	{
		nameit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Prints employees by gross pay in ascending order
void EmployeePaySystem::printByGrossPay ()
{
	for (multimap <double, Employee*>::iterator gpit = empByGrossPay.begin (); 
		gpit != empByGrossPay.end (); gpit++)
	{
		gpit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Prints employees by ID in descending order
void EmployeePaySystem::printReverseByID ()
{
	for (map <string, Employee*>::reverse_iterator idit = empByID.rbegin (); 
		idit != empByID.rend (); idit++)
	{
		idit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Prints employees by name in descending order
void EmployeePaySystem::printReverseByName ()
{
	for (multimap <string, Employee*>::reverse_iterator nameit = empByName.rbegin (); 
		nameit != empByName.rend (); nameit++)
	{
		nameit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Prints employees by gross pay in descending order
void EmployeePaySystem::printReverseByGrossPay ()
{
	for (multimap <double, Employee*>::reverse_iterator gpit = empByGrossPay.rbegin (); 
		gpit != empByGrossPay.rend (); gpit++)
	{
		gpit->second->displayData ();
		cout<<"-----------------------------------------------"<<endl;
	}
}

//Finds employee(s) by name and prints
void EmployeePaySystem::findAndPrint (const string name)
{
	nfirstLast = empByName.equal_range (name);
										
	if (nfirstLast.first == nfirstLast.second)
		throw name;
		
	cout<<empByName.count (name)<<" records found!"<<endl<<endl;
	while (nfirstLast.first != nfirstLast.second)
	{
		nfirstLast.first -> second -> displayData ();
		nfirstLast.first++;
	}
}

//Finds employee(s) by gross pay and prints
void EmployeePaySystem::findAndPrint (const double& lower, const double& upper)
{
	int count = 0
	;
	pair <multimap <double, Employee*>::iterator, 
			multimap <double, Employee*>::iterator> lowerFirstLast;
	
	pair <multimap <double, Employee*>::iterator, 
			multimap <double, Employee*>::iterator> upperFirstLast;
			
	lowerFirstLast = empByGrossPay.equal_range (lower);
	upperFirstLast = empByGrossPay.equal_range (upper);
	
	if (lower > upper)	//If minimum gross pay is higher than maximum gross pay
		throw exception ();
	
	while (lowerFirstLast.first != upperFirstLast.second)
	{
		lowerFirstLast.first -> second -> displayData ();
		cout<<"--------------------------------"<<endl;
		lowerFirstLast.first++;
		count++;
	}
	cout<<endl<<count<<" records found"<<endl;
}

//Calculates total gross pay of all the employees
double EmployeePaySystem::getTotalSalaryPaid ()
{
	double totalSal = 0;
	
	for (map <string, Employee*>::iterator idit = empByID.begin (); idit != empByID.end ();
		idit++)
	{
		totalSal = totalSal + idit -> second -> getGrossPay ();
	}
	
	return totalSal;
}

//Prints the list of senior employee's id and gross pay
void EmployeePaySystem::printSeniorIDGrossPayList ()
{
	cout<<"Senior Employee"<<endl
		<<"==============="<<endl
		<<"ID\t\tGross Pay"<<endl
		<<"------------------------------------"<<endl;

	for (map <string, Employee*>::iterator idit = empByID.begin (); idit != empByID.end ();
		idit++)
	{
		if (idit -> second -> isSenior () == true)
			cout<<right<<idit -> second -> getID ()<<"\t\t"
				<<setw (9)<<idit -> second -> getGrossPay ()<<endl;
	}
	cout<<"-------------------------------------"<<endl;
}

//Prints the list of ordinary employee's id and gross pay
void EmployeePaySystem::printOrdIDGrossPayList ()
{
	cout<<"Ordinary Employee"<<endl
		<<"================="<<endl
		<<"ID\t\tGross Pay"<<endl
		<<"------------------------------------"<<endl;

	for (map <string, Employee*>::iterator idit = empByID.begin (); idit != empByID.end ();
		idit++)
	{
		if (idit -> second -> isSenior () == false)
			cout<<right<<idit -> second -> getID ()<<"\t\t"
				<<setw (9)<<idit -> second -> getGrossPay ()<<endl;
	}
	cout<<"-------------------------------------"<<endl;
}

//Get maximum senior employee gross pay
double EmployeePaySystem::getMaxSenEmpSal ()
{
	multimap <double, Employee*>::reverse_iterator p = empByGrossPay.rbegin ();
	
	while (!p -> second -> isSenior ())
		p++;
		
	return p -> second -> getGrossPay ();
}

//Get maximum ordinary employee gross pay
double EmployeePaySystem::getMaxOrdEmpSal ()
{
	multimap <double, Employee*>::reverse_iterator p = empByGrossPay.rbegin ();
	
	while (p -> second -> isSenior ())
		p++;
		
	return p -> second -> getGrossPay ();
}

//Get minimum senior employee gross pay
double EmployeePaySystem::getMinSenEmpSal ()
{
	multimap <double, Employee*>::iterator p = empByGrossPay.begin ();
	
	while (!p -> second -> isSenior ())
		p++;
		
	return p -> second -> getGrossPay ();
}

//Get minimum ordinary employee gross pay
double EmployeePaySystem::getMinOrdEmpSal ()
{
	multimap <double, Employee*>::iterator p = empByGrossPay.begin ();
	
	while (p -> second -> isSenior ())
		p++;
		
	return p -> second -> getGrossPay ();
}

int main ()
{
	EmployeePaySystem eps;
	eps.main ();
	
	return 0;
}

