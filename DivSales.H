#pragma once
#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales
{
private:
	double* sales;
	int numPeriods;
	static double corporateTotal;

	void createSalesArray(int size);

public:
	DivSales(int numberOfPeriods);
	~DivSales();
	DivSales(const DivSales& obj);
	DivSales& operator=(const DivSales& right);

	double& operator[](int index);
	const double& operator[](int index) const;

	int getNumPeriods() const;
	double getDivisionTotal() const;

	static double getCorporateTotal();
	static void resetCorporateTotal();
	static void addToCorporateTotal(double amount);
};

#endif