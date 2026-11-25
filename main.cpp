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
			}
			return 1;
		}
	}



}