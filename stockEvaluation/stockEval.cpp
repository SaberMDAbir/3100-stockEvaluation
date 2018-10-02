//MD Abir A. Choudhury
//021618
//CIS 3100 - E4: Stock Valuation
//Difficulty Level: Medium 
//Concept: Math Formulas

#include <iostream>
#include <math.h>
#include <istream>

using namespace std;

int main()
{
	//Intro Output
	cout << "Welcome to Stock Valuation v3.2\n";
	cout << "===============================\n\n";

	int choice = 0;
	int numYears = 0;
	double earningsPerShare = 0.0;
	double rateOfReturn = 0.0;
	double present = 0.0;
	double growth = 0.0;

	do {
		//Processing
		//Give user the option to choose
		cout << "Method 1: Zero Growth\n";
		cout << "Method 2: Constant Growth\n";
		cout << "Method 3: Limited Growth\n";
		cout << "Which method do you want to use? \n";
		cout << "If you wish to exit, then input '-1'\n";
		cin >> choice;

		//Decision Statements
		if (choice == 1) {
			//user inputs Earnings per share and desired rate of return
			cout << "Enter the current year's earnings per share: \n";
			cin >> earningsPerShare;
			cout << "Enter the desired rate of return: \n";
			cin >> rateOfReturn;

			//Compute the present fair value of the stock
			//P = E/R
			present = earningsPerShare / rateOfReturn;

			//Output
			cout << "The present fair market value of this stock is " << present << endl;
		}

		else if (choice == 2) {
			//Input 
			cout << "Enter the current years earnings per share: \n";
			cin >> earningsPerShare;
			cout << "Enter the desired rate of return: \n";
			cin >> rateOfReturn;
			cout << "Enter the growth rate of earnings: \n";
			cin >> growth;

			//Compute
			//P = E/(R-G)
			present = earningsPerShare / (rateOfReturn - growth);

			//Output
			cout << "The present fair market price of the stock is " << present << endl;
		}

		else if (choice == 3) {
			//Input 
			cout << "Enter the current year's earnings per share: \n";
			cin >> earningsPerShare;
			cout << "Enter the desired rate of return: \n";
			cin >> rateOfReturn;
			cout << "Enter the growth rate of earnings: \n";
			cin >> growth;
			cout << "Enter the number of years earnings will grow (N) - it must be less than 50: \n";
			cin >> numYears;
			
			if (numYears > 50 || numYears < 0) {
				cout << "Please input a valid number for the number of years.\n";
				cin.ignore(256, '\n') >> numYears;
			}

			//Calculating
			double totalUpTo = 0;
			double totalAfter = 0;
			double overallTotal = 0;
			//calculating the px up to year N
			for (int i = 1; i < numYears; i++) {
				totalUpTo = (earningsPerShare * (pow(1 + growth, i))) / (pow(1 + rateOfReturn, i));
			}
			//calculating the px after year N
			for (int i = numYears + 1; i < 50; i++) {
				totalAfter = (earningsPerShare * (pow(1 + growth, numYears))) / (pow(1 + rateOfReturn, i));
			}
			//calculating the sum
			overallTotal = totalUpTo + totalAfter;
			present = overallTotal;

			//Output
			cout << "The present fair market price of the stock is " << present << endl;
		}

		//Give an option to continue
		char option;
		cout << "Would you like to compute another one? (y/n) \n";
		cin >> option;
		
		if (option == 'y') {
			continue;
		}
		else {
			break;
		}
	} while (choice != -1);

	//Thank the user
	cout << "Thank you for using our system for your selfish purposes.\n";

	system("PAUSE");
	return 0;
}