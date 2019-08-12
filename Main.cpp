#include "Backpack.h"

// help input functions
int readIntValue(const char * VarName)
{
	while(true)
	{
		try
		{
			string Var;
			cout << "Enter fruit's " << VarName << ": ";
			cin >> Var;
			return stoi(Var);
		}
		catch(exception& ex)
		{
			cout << "Invalid variable type" << endl;
		}
	}
}


Fruit getFruitInfo()
{
	string Name;
	cout << "Enter fruit's name: ";
	getline(cin, Name);
	
	// check if entered string contains only letters
	while(!regex_match(Name, regex("^[A-Za-z]+$")))
	{
		cout << "Please, use only letters of English alphabet." << endl;
		cout << "Enter fruit's name: ";
		getline(cin, Name);
	}

	int Weight = readIntValue("weight");
	int Price = readIntValue("price");
	int Count = readIntValue("count");

	return Fruit(Name, Weight, Price, Count);
}


// main
void main()
{
	Backpack bp("../fruits.txt");	// use relative path

	cout << "Reading from file..." << endl;
	bp.readFile();
	
	while(true)
	{
		cout << "What do you want to do next?" << endl;
		cout << "0.Reset to default" << endl;
		cout << "1.Add new fruit" << endl;
		cout << "2.Remove existing fruit" << endl;
		cout << "3.See what in your backpack" << endl;
		cout << "Any other key to exit..." << endl;

		char answer = _getch();

		switch(answer)
		{
			case '0':
			{
				cout << "Reseting to default..." << endl;
				bp.clear();
				bp.readFile();
				break;
			}
			case '1':
			{
				cout << "Adding new fruit..." << endl;
				bp.add(&getFruitInfo());
				break;
			}
			case '2':
			{
				cout << "Removing fruit..." << endl;
				if(!bp.remove(&getFruitInfo()))
					cout << "There is no such fruit or number of fruits exceeds existing number" << endl;
				break;
			}
			case '3':
			{
				cout << "Showing info..." << endl;
				bp.printAll();
				break;
			}
			default:
				return;
		}
	}
}
