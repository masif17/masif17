/*
 * Class: CMSC140 CRN 30373
 * Instructor: Rabiha Kayed
 * Project<number> 4
 * Description: (Give a brief description for Project)
 * This project will validate through every employee entered to see the 
 average number of absents by the employees of company
 it will also show the error messeges as needed
 * Due Date: 4/15/2024
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Malaika Asif
*/



#include <iostream>
#include <fstream>        //to create files
#include <iomanip>        //later to calculate average, setpersicion

using namespace std;

ofstream outputFile;


//function prototypes 
int getNumOfEmployees();
int getTotalDaysAbsent(int numOfEmp);
double calculateAvgDaysAbsent(int numOfEmp, int totalDaysAbsent);


int main()
{
	//opening the outfile where all the information will be saved
	outputFile.open("employeeAbsences.txt");

	//making sure the file has opened successfully
	if (!outputFile) {
		cout << "Error in opening file" << endl;
		return 1;
	}




	//number of empolyees
	int numOfEmp = getNumOfEmployees();

	//total number of absent by employees
	int totalDaysAbsent = getTotalDaysAbsent(numOfEmp);

	//calculating the average of days absent
	double avgDaysAbsent = calculateAvgDaysAbsent(numOfEmp, totalDaysAbsent);

	//closing the file
	outputFile.close();
	cout << "File, employeeAbsences has updated!" << endl;
	cout << "Programmer = Malaika Asif" << endl;
	cout << "CMSC 140" << endl;
	cout << "Due Date: 4/15/2024" << endl;


	return 0;

}

int getNumOfEmployees()
{
	int numOfEmp;
	do {
		cout << "Enter the number of employees in the company:";
		cin >> numOfEmp;

		//input validation
		if (numOfEmp < 1) {
			cout << "Invalid input, Number of Employees must be atleast 1, try again" << endl;
		}
	} while (numOfEmp < 1);
	return numOfEmp;
}


int getTotalDaysAbsent(int numOfEmp)
{

	outputFile << "EMPLOYEE ABSENCE REPORT" << endl;
	outputFile << "Employee ID      Days Absent" << endl;

	int totalDaysAbsent = 0;
	for (int employee = 0; employee < numOfEmp; employee++) {
		int employeeID, daysAbsent;
		cout << "Enter the employee's ID:";
		cin >> employeeID;
		cout << "Enter absent days for employee " << employeeID << ":";
		cin >> daysAbsent;
	


	//input validation
		while (daysAbsent < 0) {
			cout << "Number of days absent can not be negative, try again:";
			cin >> daysAbsent;
		}


		//writing the inputs into the file we created

		outputFile << setw(10) << employeeID << setw(10) << daysAbsent << endl;
		totalDaysAbsent += daysAbsent;
	}

	outputFile << "The " << numOfEmp << " employees were absent for a total of " << totalDaysAbsent << " days." << endl;
	return totalDaysAbsent;


}

double calculateAvgDaysAbsent(int numOfEmp, int totalDaysAbsent)
{
	double averageDaysAbsent = static_cast <double>(totalDaysAbsent) / numOfEmp;

	//updating the file with average
	outputFile << "Average days absent per employee: " << fixed << setprecision(2) << averageDaysAbsent << endl;
	outputFile << "File, employeeAbsences has updated!" << endl;
	outputFile << "Programmer = Malaika Asif" << endl;
	outputFile << "CMSC 140" << endl;
	outputFile << "Due Date: 4/15/2024" << endl;

	return averageDaysAbsent;
	
}

