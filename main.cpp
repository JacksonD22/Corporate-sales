#include "DivSales.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
using namespace std;

int main() {
	const int NUM_DIVISIONS = 6;
	string filename;
	int numberOfPeriods;

	cout << "Enter the name of your file\n";
	cin >> filename;

	ifstream inputFile(filename);
	if (!inputFile) {
		cout << "ERROR, file doesnt exixst\n";
		return 1;
	}

	inputFile >> numberOfPeriods;
	if (inputFile.fail() || numberOfPeriods <= 0) {
		cout << "ERROR, number of periods is invalid\n";
		return 1;
	}

	DivSales divisions[NUM_DIVISIONS] =
	{
	   DivSales(numberOfPeriods),
	   DivSales(numberOfPeriods),
	   DivSales(numberOfPeriods),
	   DivSales(numberOfPeriods),
	   DivSales(numberOfPeriods),
	   DivSales(numberOfPeriods)
	};

	DivSales::resetCorporateTotal();

	for (int division = 0; division < NUM_DIVISIONS; division++) {
		for (int period = 0; period < numberOfPeriods; period++) {
			inputFile >> divisions[division][period];
			if (inputFile.fail() || divisions[division][period] <= 0) {
				cout << "ERROR, invalid value\n";
				return 1;
			}
		}

		DivSales::addToCorporateTotal(divisions[division].getDivisionTotal());
	}

	cout << fixed << setprecision(2);
	
	for (int period = 0; period < numberOfPeriods; period++)
	{
		cout << "Period" << (period + 1) << ":";
		for (int division = 0; division < NUM_DIVISIONS; division++) {
			cout << setw(12) << divisions[division][period];
		}
		cout << endl;
	}

	for (int division = 0; division < NUM_DIVISIONS; division++) {
		cout << "Division total:" << (division + 1) << "$" << divisions[division].getDivisionTotal() << endl;
	}

	cout << "Corporate total: " << DivSales::getCorporateTotal() << endl;

	//Copy constructor
	DivSales copy1 = divisions[0];
	copy1[0] = 1;
	cout << "copy1[0] = " << copy1[0] << ", divisions[0][0] = " << divisions[0][0] << endl;

	//Copy assignment
	DivSales other(numberOfPeriods + 3);
	other = divisions[0];
	other[1] = 2;
	cout << "other[1] = " << other[1] << ", divisions[0][1] = " << divisions[0][1] << endl;

	//self assignment
	DivSales& same = divisions[0];
	divisions[0] = same;
	cout << "divisions[0][0] = " << divisions[0][0] << endl;

	return 0;
}