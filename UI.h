#pragma once
#include <iostream>
#include <iomanip>
#include "Expenses.h"
#include "dayExpense.h"
#include "Service.h"
#include <string>
using namespace std;

class UI {
public:
	UI();
	UI(const Service& other);

	void run();

private:
	Service monthlyExpenses;
};