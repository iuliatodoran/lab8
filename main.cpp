#include <iostream>
#include "Expenses.h"
#include "UI.h"
#include "EntityTests.h"
#include "RepoTests.h"
#include "ServiceTest.h"

using namespace std;

int main() {
	// Run tests
	EntityTests::runAllTests();
	RepoTests::runAllTests();
	ServiceTest::runAllTests();

	Service monthlyExpenses = Service();
	UI presentation = UI(monthlyExpenses);

	presentation.run();

	return 0;
}