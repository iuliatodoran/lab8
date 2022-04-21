#pragma once
#include "dayExpense.h"
#include "Expenses.h"
#include <iostream>

class Service : public Expenses {
public:
	Service();
	Service(unsigned int currentDay);

	~Service();

	Service& operator=(const Service& other);

	unsigned int getCurrentDay();

	void insertByDay(unsigned int day, typeOfExpense type, int amount);

	void elimExpenses();
	void elimExpenseByDay(unsigned int day);
	void elimExpenseByType(typeOfExpense type);
	void elimExpenseFromTo(unsigned int from, unsigned int to);

	int getTotalExpenses();
	int getDayMaxExp();
	Expenses* getAllDays();

	void filterExpensesByType(typeOfExpense type, unsigned int day);
	void filterExpensesByTypeAndAmount(typeOfExpense type, unsigned int day, int amount);

	void undo();

private:
	unsigned int currentDay;
	Expenses* previousForm;
	Expenses* allDays;
};