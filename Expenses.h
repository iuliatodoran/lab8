#pragma once
#include "dayExpense.h"
#include <iostream>

class Expenses : public dayExpense {
public:
	// Constructors
	Expenses();
	Expenses(const Expenses& other);
	Expenses(int currentDay);

	// Destructor
	~Expenses();

	// Getters
	dayExpense* getAll();
	unsigned int getSize();
	unsigned int getTotal();
	unsigned int getCurrentDay();

	// Setters
	void setDay(int newDay);

	// Operators
	Expenses& operator=(const Expenses& other);

	void addExpense(int money, typeOfExpense type);

	void elimExpenseByType(typeOfExpense type);

	unsigned int getTotalExpensesByType(typeOfExpense type);
	

private:
	dayExpense *dayExpenses;
	unsigned int day, nrOfExpenses, total;
};