#pragma once
#include <iostream>

enum typeOfExpense {
	menaj,
	mancare,
	haine,
	transport,
	internet,
	none
};

class dayExpense {
public:
	// Constructors
	dayExpense();
	dayExpense(typeOfExpense type, unsigned int amount);
	dayExpense(const dayExpense& other);

	// Getters

	typeOfExpense getType();
	static typeOfExpense getTypeByNumber(int nr);
	unsigned int getAmount();

	// Setters

	void setType(typeOfExpense newType);
	void setAmount(unsigned int newAmount);

	// Operators

	dayExpense& operator=(const dayExpense& other);

private:
	typeOfExpense type;
	unsigned int amount;
};