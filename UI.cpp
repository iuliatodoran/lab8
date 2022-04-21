#include "UI.h"

UI::UI()
{
	monthlyExpenses = Service();
}

UI::UI(const Service& other)
{
	this->monthlyExpenses = other;
}


void UI::run()
{
	bool running = true;

	while (running) {
		string key;

		cout << "Please select your option: \n";

		cout << setw(5) << "A|a		Add an expense to current day: \n";
		cout << setw(5) << "I|i		Insert an expense to a day: \n";
		cout << setw(5) << "ED|ed	Eliminate expenses by day: \n";
		cout << setw(5) << "EF|ef	Eliminate expenses from a day to another day: \n";
		cout << setw(5) << "ET|et	Eliminate expenses by type: \n";
		cout << setw(5) << "C|c		Show current day expenses: \n";
		cout << setw(5) << "S|s		Show all expenses \n";
		cout << setw(5) << "ST|st	Show all expenses for a type \n";
		cout << setw(5) << "GT|gt   Get total expenses for this month: \n";
		cout << setw(5) << "GTM|gtm Get day with maximum expenses: \n";
		cout << setw(5) << "FT|ft	Filter expenses by type \n";
		cout << setw(5) << "FBT|fbt Filter type bigger than a given value: \n";
		cout << setw(5) << "U|u		Undo operation \n";
		cout << setw(5) << "Q|q		Quit \n";

		cin >> key;

		if (key == "A" || key == "a") {
			int price;
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Price: \n"; cin >> price;
			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;

			monthlyExpenses.getAllDays()[monthlyExpenses.getCurrentDay()].addExpense(price, monthlyExpenses.getAllDays()[monthlyExpenses.getCurrentDay()].getTypeByNumber(nrOfType));

			cout << setw(5) << "Month Expense has been added! \n";
		}

		if (key == "I" || key == "i") {
			int day;
			int price;
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Day: \n"; cin >> day;
			cout << setw(5) << "Input Price: \n"; cin >> price;
			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;

			monthlyExpenses.insertByDay(day, dayExpense::getTypeByNumber(nrOfType), price);

			cout << setw(5) << "Month Expense has been added! \n";
		}

		if (key == "ED" || key == "ed") {
			int day;

			cout << setw(5) << "Input Day: \n"; cin >> day;
			monthlyExpenses.elimExpenseByDay(day);

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "EF" || key == "ef") {
			int from, to;

			cout << setw(5) << "Input start day: \n"; cin >> from;
			cout << setw(5) << "Input end day: \n"; cin >> to;

			monthlyExpenses.elimExpenseFromTo(from, to);

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "ET" || key == "et") {
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;

			monthlyExpenses.elimExpenseByType(dayExpense::getTypeByNumber(nrOfType));

			cout << setw(5) << "Month Expense has been removed! \n";
		}

		if (key == "C" || key == "c") {
			int currDay = monthlyExpenses.getCurrentDay();
			cout << "Day " << currDay << '\n';
			Expenses currentExpense = monthlyExpenses.getAllDays()[currDay];
			if (currentExpense.getSize() > 0) {
				for (int i = 0; i < currentExpense.getSize(); i++)
				{
					if (currentExpense.getAll()[i].getType() == menaj)
						cout << "Type is: menaj \n";
					if (currentExpense.getAll()[i].getType() == mancare)
						cout << "Type is: mancare \n";
					if (currentExpense.getAll()[i].getType() == haine)
						cout << "Type is: haine \n";
					if (currentExpense.getAll()[i].getType() == transport)
						cout << "Type is: transport \n";
					if (currentExpense.getAll()[i].getType() == internet)
						cout << "Type is: internet \n";
					cout << currentExpense.getAll()[i].getAmount() << '\n';
				}
			}
			else
				cout << "No expenses \n";
		}

		if (key == "S" || key == "s") {
			for (int i = 0; i < 28; i++) {
				cout << "Day: " << i + 1 << "\n";
				Expenses currentExpenses = monthlyExpenses.getAllDays()[i];
				if (currentExpenses.getSize() > 0) {
					for (int j = 0; j < currentExpenses.getSize(); j++)
					{
						if (currentExpenses.getAll()[j].getType() == menaj)
							cout << "Type is: menaj \n";
						if (currentExpenses.getAll()[j].getType() == mancare)
							cout << "Type is: mancare \n";
						if (currentExpenses.getAll()[j].getType() == haine)
							cout << "Type is: haine \n";
						if (currentExpenses.getAll()[j].getType() == transport)
							cout << "Type is: transport \n";
						if (currentExpenses.getAll()[j].getType() == internet)
							cout << "Type is: internet \n";
						cout << currentExpenses.getAll()[j].getAmount() << '\n';
					}
				}
				else 
					cout << "No expenses \n";
			}
		}

		if (key == "ST" || key == "st") {
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;

			Service filteredByType;
			filteredByType = monthlyExpenses;
			// Make a new service object which will be filtered and then show it's expenses
			filteredByType.filterExpensesByType(dayExpense::getTypeByNumber(nrOfType), monthlyExpenses.getCurrentDay());
			for (int i = 0; i < 28; i++)
			{
				if (filteredByType.getAllDays()[i].getSize() > 0) {
					cout << "Day: " << i << '\n';
					Expenses allCurrentExpenses = filteredByType.getAllDays()[i];
					for (int j = 0; j < allCurrentExpenses.getSize(); j++)
					{
						if (allCurrentExpenses.getAll()[j].getType() != none) {
							cout << "Expense: " << allCurrentExpenses.getAll()[j].getType() << '\n';
							cout << "Amount: " << allCurrentExpenses.getAll()[j].getAmount() << '\n';
						}
					}
				}
			}
		}

		if (key == "GT" || key == "gt") {
			cout << "Total expenses this month are: " << monthlyExpenses.getTotalExpenses() << '\n';
		}

		if (key == "GTM" || key == "gtm") {
			int day = monthlyExpenses.getDayMaxExp();
			cout << "Day with maximum expenses is: " << monthlyExpenses.getAllDays()[day].getSize() << '\n';
		}

		if (key == "FT" || key == "ft") {
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;

			for (int i = 0; i < 28; i++) {
				monthlyExpenses.filterExpensesByType(dayExpense::getTypeByNumber(nrOfType), i);
			}

			cout << "Monthly expenses filtered! \n";
		}

		if (key == "FBT" || key == "fbt") {
			int value;
			typeOfExpense type;
			int nrOfType;

			cout << setw(5) << "Input Type: (menaj = 0, mancare = 1, haine = 2, transport = 3, internet = 4)\n"; cin >> nrOfType;
			cout << setw(5) << "Input value: \n"; cin >> value;

			for (int i = 0; i < 28; i++) {
				monthlyExpenses.filterExpensesByTypeAndAmount(dayExpense::getTypeByNumber(nrOfType), i, value);
			}

			cout << "Monthly expenses filtered! \n";
		}

		if (key == "U" || key == "u") {
			monthlyExpenses.undo();
		}

		if (key == "Q" || key == "q")
			running = false;

		cout << '\n';
	}
}
