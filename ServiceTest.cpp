#include "ServiceTest.h"

void ServiceTest::runAllTests()
{
	creationTest();
	gettersSettersTest();
	featuresTests();
}

int ServiceTest::creationTest()
{
	Service newService = Service();
	assert(newService.getCurrentDay() == 0);

	return 0;
}

int ServiceTest::gettersSettersTest()
{
	Service newService = Service(2);
	newService.getAllDays()[0].addExpense(200, menaj);

	assert(newService.getCurrentDay() == 2);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 200);
	assert(newService.getAllDays()[0].getAll()[0].getType() == menaj);

	return 0;
}

int ServiceTest::featuresTests()
{
	Service newService = Service();

	// insert
	newService.insertByDay(0, menaj, 200);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 200);
	assert(newService.getAllDays()[0].getAll()[0].getType() == menaj);

	// elim
	newService.elimExpenseByDay(0);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 0);

	newService.insertByDay(0, menaj, 200);
	newService.elimExpenseByType(internet);

	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 0);

	newService.insertByDay(0, menaj, 200);
	newService.insertByDay(1, menaj, 200);

	newService.elimExpenseFromTo(0, 2);

	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 0);
	assert(newService.getAllDays()[1].getAll()[0].getAmount() == 0);

	// get day with max expenses
	newService.insertByDay(0, menaj, 200);
	newService.insertByDay(1, internet, 400);

	assert(newService.getDayMaxExp() == 1);

	// get total expenses
	assert(newService.getTotalExpenses() == 600);

	// filters
	newService.filterExpensesByType(menaj, 1);
	assert(newService.getAllDays()[1].getAll()[0].getAmount() == 0);
	assert(newService.getAllDays()[0].getAll()[0].getType() == menaj);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 200);

	newService.filterExpensesByTypeAndAmount(menaj, 0, 300);
	assert(newService.getAllDays()[0].getAll()[0].getType() == menaj);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 200);

	newService.filterExpensesByTypeAndAmount(internet, 0, 100);
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 0);

	// undo
	newService.undo();
	assert(newService.getAllDays()[0].getAll()[0].getAmount() == 200);

	return 0;
}
