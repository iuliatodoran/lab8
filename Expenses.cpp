#include "Expenses.h"
#include "dayExpense.h"
#include <iostream>

Expenses::Expenses()
{
	this->day = 0;
	this->total = 0;
	this->nrOfExpenses = 0;
	this->dayExpenses = new dayExpense[0]{};
}

Expenses::Expenses(const Expenses& other)
{
	delete[] dayExpenses;
	this->total = other.total;
	this->nrOfExpenses = other.nrOfExpenses;
	this->day = other.day;
	this->dayExpenses = new dayExpense[nrOfExpenses]{};

	for (int i = 0; i < nrOfExpenses; i++)
		dayExpenses[i] = other.dayExpenses[i];
}

Expenses::Expenses(int currentDay)
{
	this->day = currentDay;
	this->nrOfExpenses = 0;
	this->total = 0;
	this->dayExpenses = new dayExpense[0]{};
}

Expenses::~Expenses()
{
	delete[] this->dayExpenses;
}

dayExpense* Expenses::getAll()
{
	return dayExpenses;
}

unsigned int Expenses::getSize()
{
	return this->nrOfExpenses;
}

unsigned int Expenses::getTotal()
{
	return this->total;
}

unsigned int Expenses::getCurrentDay()
{
	return this->day;
}

void Expenses::setDay(int newDay)
{
	this->day = newDay;
}

Expenses& Expenses::operator=(const Expenses& other)
{
	delete[] this->dayExpenses;
	this->nrOfExpenses = other.nrOfExpenses;
	this->day = other.day;
	this->total = other.total;
	this->dayExpenses = new dayExpense[nrOfExpenses]{};

	for (int i = 0; i < nrOfExpenses; i++) {
		this->dayExpenses[i] = other.dayExpenses[i];
	}

	return *this;
}

void Expenses::addExpense(int money, typeOfExpense type) {
	this->total += money;

	// Allocate space for new expense
	dayExpense* newExpenses = new dayExpense[nrOfExpenses + 1];

	for (int i = 0; i < nrOfExpenses; i++)
		newExpenses[i] = this->dayExpenses[i];

	delete[] dayExpenses;
	nrOfExpenses = nrOfExpenses + 1;
	dayExpenses = new dayExpense[nrOfExpenses];
	newExpenses[nrOfExpenses - 1] = dayExpense(type, money);
	
	// Assign new values
	for (int i = 0; i < nrOfExpenses; i++)
		dayExpenses[i] = newExpenses[i];
	
	delete[] newExpenses;
}
void Expenses::elimExpenseByType(typeOfExpense type)
{
	// count how many expenses of type are
	unsigned int nr = 0;
	for (int i = 0; i < nrOfExpenses; i++)
		if (this->dayExpenses[i].getType() == type)
			nr++;

	// create new expenses
	dayExpense* newExpenses = new dayExpense[nr]{};
	this->total = 0;
	for (int i = 0, j = 0; i < nrOfExpenses; i++)
		if (this->dayExpenses[i].getType() == type) {
			newExpenses[j++] = dayExpenses[i];
			this->total += dayExpenses[i].getAmount();
		}

	delete[] this->dayExpenses;
	this->nrOfExpenses = nr;
	dayExpenses = new dayExpense[nrOfExpenses];

	for (int i = 0; i < nrOfExpenses; i++)
		this->dayExpenses[i] = newExpenses[i];
}

unsigned int Expenses::getTotalExpensesByType(typeOfExpense type)
{
	unsigned int total = 0;
	for (int i = 0; i < nrOfExpenses; i++)
		if (dayExpenses[i].getType() == type)
			total += dayExpenses[i].getAmount();

	return total;
}