#include "Service.h"

Service::Service()
{
	this->currentDay = 0;
	this->allDays = new Expenses[28]{};
	this->previousForm = new Expenses[28]{};
}

Service::Service(unsigned int currentDay)
{
	this->currentDay = currentDay;
	this->allDays = new Expenses[28]{};
	this->previousForm = new Expenses[28]{};
}

Service::~Service()
{
	delete[] allDays;
	delete[] previousForm;
}

Service& Service::operator=(const Service& other)
{
	this->currentDay = other.currentDay;
	
	for (int i = 0; i < 28; i++)
		this->allDays[i] = other.allDays[i];

	return *this;
}

unsigned int Service::getCurrentDay()
{
	return this->currentDay;
}

void Service::insertByDay(unsigned int day, typeOfExpense type, int amount)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	allDays[day].addExpense(amount, type);
}

void Service::elimExpenses()
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	this->allDays[currentDay] = Expenses(currentDay);
}

void Service::elimExpenseByDay(unsigned int day)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	this->allDays[day] = Expenses(currentDay);
}

void Service::elimExpenseFromTo(unsigned int from, unsigned int to)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	for (int i = from; i < to; i++)
		this->elimExpenseByDay(i);
}

void Service::elimExpenseByType(typeOfExpense type)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	for (int i = 0; i < 28; i++)
		allDays[i].elimExpenseByType(type);
}

void Service::filterExpensesByType(typeOfExpense type, unsigned int day)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	allDays[day].elimExpenseByType(type);
}

void Service::filterExpensesByTypeAndAmount(typeOfExpense type, unsigned int day, int amount)
{
	for (int i = 0; i < 28; i++)
		this->previousForm[i] = this->allDays[i];
	allDays[day].elimExpenseByType(type);
	for (int i = 0; i < 28; i++)
		if (allDays[i].getTotal() > amount)
			allDays[day] = Expenses();
}

void Service::undo()
{
	for (int i = 0; i < 28; i++)
		this->allDays[i] = this->previousForm[i];
}

int Service::getTotalExpenses()
{
	int total = 0;
	for (int i = 0; i < 28; i++)
		total += allDays[i].getTotal();

	return total;
}

int Service::getDayMaxExp()
{
	int maxDay = 0;
	int maxExp = 0;

	for (int i = 0; i < 28; i++)
		if (allDays[i].getTotal() > maxExp) {
			maxExp = allDays[i].getTotal();
			maxDay = i;
		}

	return maxDay;
}

Expenses* Service::getAllDays()
{
	return allDays;
}
