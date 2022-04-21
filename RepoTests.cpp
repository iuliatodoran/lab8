#include "RepoTests.h"

void RepoTests::runAllTests()
{
	creationTest();
	gettersTest();
	featuresTests();
}

int RepoTests::creationTest()
{
	Expenses expenses = Expenses();

	assert(expenses.getSize() == 0);
	assert(expenses.getCurrentDay() == 0);

	for (int i = 0; i < expenses.getSize(); i++)
	{
		assert(expenses.getAll()[i].getAmount() == 0);
		assert(expenses.getAll()[i].getType() == none);
	}
	return 0;
}

int RepoTests::gettersTest()
{
	Expenses expenses = Expenses();

	typeOfExpense type = mancare;
	expenses.addExpense(100, type);

	assert(expenses.getAll()[0].getAmount() == 100);

	return 0;
}

int RepoTests::featuresTests()
{
	Expenses expenses = Expenses();

	typeOfExpense type1 = mancare;
	typeOfExpense type2 = internet;

	// Add tests
	expenses.addExpense(150, type1);
	expenses.addExpense(200, type2);

	assert(expenses.getAll()[0].getAmount() == 150);
	assert(expenses.getAll()[1].getAmount() == 200);

	assert(expenses.getAll()[0].getType() == type1);
	assert(expenses.getAll()[1].getType() == type2);

	// Modify tests

	expenses.elimExpenseByType(type1);
	assert(expenses.getSize() == 1);
	expenses.elimExpenseByType(type2);
	assert(expenses.getSize() == 0);

	return 0;
}
