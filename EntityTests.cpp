#include "EntityTests.h"

void EntityTests::runAllTests()
{
	creationTest();
	gettersSettersTest();
}

int EntityTests::creationTest()
{
	dayExpense expense1 = dayExpense();

	assert(expense1.getAmount() == 0);
	assert(expense1.getType() == none);

	return 0;
}

int EntityTests::gettersSettersTest()
{
	dayExpense expense1 = dayExpense();
	assert(expense1.getAmount() == 0);
	assert(expense1.getType() == none);

	expense1.setAmount(100);
	expense1.setType(menaj);

	assert(expense1.getAmount() == 100);
	assert(expense1.getType() == menaj);

	return 0;
}
