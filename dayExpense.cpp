#include "dayExpense.h"
#include <iostream>

dayExpense::dayExpense()
{
	type = none;
	amount = 0;
}

dayExpense::dayExpense(typeOfExpense type, unsigned int amount)
{
	this->type = type;
	this->amount = amount;
}

dayExpense::dayExpense(const dayExpense& other)
{
	this->type = other.type;
	this->amount = other.amount;
}

typeOfExpense dayExpense::getType()
{
	return this->type;
}

typeOfExpense dayExpense::getTypeByNumber(int nr)
{
	if (nr == 0)
		return menaj;
	if (nr == 1)
		return mancare;
	if (nr == 2)
		return haine;
	if (nr == 3)
		return transport;
	if (nr == 4)
		return internet;
	else
		return none;
}

unsigned int dayExpense::getAmount()
{
	return this->amount;
}

void dayExpense::setType(typeOfExpense newType)
{
	this->type = newType;
}

void dayExpense::setAmount(unsigned int newAmount)
{
	this->amount = newAmount;
}


dayExpense& dayExpense::operator=(const dayExpense& other)
{
	this->type = other.type;
	this->amount = other.amount;

	return *this;
}
