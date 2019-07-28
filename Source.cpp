//Sinclair Community College
//Functions Coding Assignment
//Kevin Gowsell
//April 14th, 2019

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

const int numberOfCodes = 1000;
int productCodes[numberOfCodes];


void addCodes() //add new product codes to the array
{
	char moreCodes = 'y';
	int count = 0;
	
	for (int count = 0; count < numberOfCodes; count++)
	{
		while (moreCodes == 'y' || moreCodes == 'Y')
		{
			cout << "Enter the new code: ";
			cin >> productCodes[count];
			count++;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter y to add more codes: "; 
			cin >> moreCodes;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
			
	}	cout << endl;
	return;

}

void removeCode() //remove produce codes from the array
{
	int codeChoice = 0;
	int x, del, i, count;

	cout << "Chose the product code you want to remove: ";
	cin >> codeChoice;
	x = std::distance(productCodes, std::find(productCodes, productCodes + 1000, codeChoice));
	cout << "Index of:" << x << endl;
	for (int j = x; j < (numberOfCodes - 1); j++)
		{
			productCodes[j] = productCodes[j + 1];
		}
	cout << "Your code was successfully removed." << endl;
	return;
}

void printArray()
{
	//for (int count = 0; count < numberOfCodes; count++)
	cout << endl;
	for(int val : productCodes)
	{
		if (val != 0)
		{
			cout << "Product Code: " << val << endl;

		}
		
		//cout << "Product Code: " << productCodes << endl;
	}
	cout << endl;
}

int main() // defines produce code array and menu
{
	char menuSelect = '0';

	//Title 
	cout << "X, Y & Zilch's Product Code Management Application" << endl;
	cout << endl;

	for (int count = 0; count < numberOfCodes; count++)
		{
			productCodes[count] = 0;
		}

	//Menu
	while (menuSelect != '4')
	{
		cout << "Enter 1 to add codes" << endl;
		cout << "Enter 2 to remove code" << endl;
		cout << "Enter 3 to display product codes" << endl;
		cout << "Enter 4 to exit" << endl;
		cout << "Menu Selection: "; 
		cin >> menuSelect;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (menuSelect)
		{
		case '1':
			addCodes();
			break;
		case '2':
			removeCode();
			break;
		case '3':
			printArray();
			break;
		case '4':
			system("pause");
			return 0;
		}
	}
}