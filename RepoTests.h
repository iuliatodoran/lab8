#pragma once
#include <iostream>
#include <cassert>
#include "Expenses.h"
#include "dayExpense.h"

class RepoTests {
public:
	static void runAllTests();
	static int creationTest();
	static int gettersTest();
	static int featuresTests();
};