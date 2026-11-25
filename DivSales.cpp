#include  "DivSales.H"
#include <stdexcept>
using namespace std;

double DivSales::corporateTotal = 0;

void DivSales::createSalesArray(int size) {
	numPeriods = size;
	sales = new double[size];
	
	for (int i = 0; i < size; i++) {
		sales[i] = 0;
	}
}

DivSales::~DivSales() {
	delete[] sales;
	sales = nullptr;
}

DivSales::DivSales(const DivSales& obj) {
	numPeriods = obj.numPeriods;
	sales = new double[numPeriods];

	for (int i = 0; i < numPeriods; i++)
		sales[i] = obj.sales[i];
}

DivSales& DivSales::operator = (const DivSales& right) {
	if (this != &right)
	{
		double* newSales = new double[right.numPeriods];

		for (int i = 0; i < right.numPeriods; i++)
			newSales[i] = right.sales[i];

		delete[] sales;

		numPeriods = right.numPeriods;
		sales = newSales;
	}
	return *this;
}

int DivSales::getNumPeriods() const {
	return numPeriods;
}

double DivSales::getDivisionTotal() const {
	double total = 0;
	for (int i = 0; i < numPeriods; i++)
		total += sales[i];

	return total;
}

double DivSales::getCorporateTotal() {
	return corporateTotal;
}

void DivSales::addToCorporateTotal(double amount) {
	corporateTotal += amount;
}

void DivSales::resetCorporateTotal() {
	corporateTotal = 0;
}
DivSales::DivSales(int numberOfPeriods) {
	if (numberOfPeriods <= 0)
		throw out_of_range("Invalid");
	createSalesArray(numberOfPeriods);
}


double& DivSales::operator[](int index) {
	if (index < 0 || index >= numPeriods)
		throw out_of_range("Invalid");

	return sales[index];
}

const double& DivSales::operator[](int index) const {
	if (index < 0 || index >= numPeriods)
		throw out_of_range("Invalid");

	return sales[index];
}