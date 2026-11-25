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

	cout << "Enter the name of your file";
	cin >> filename;

	ifstream inputFile(filename);
	inputFile >> numberOfPeriods;
}