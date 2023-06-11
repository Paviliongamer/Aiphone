//Aiphone.cpp

#include <iostream>
using namespace std;
#include "Aiphone.h"

Aiphone::Aiphone()
{
	size = 0;
	Top = -1;
}

Aiphone::~Aiphone()
{}

int Aiphone::saiz()
{
	return size;
}

void Aiphone::Push()
{
	int s = 0;
	while (s != saiz())
	{
		Top++;
		Stack[Top] = pname[s];
		s++;
	}
}

void Aiphone::Pop()
{
	Top--;
}

string Aiphone::TopStack()
{
	return Stack[Top];
}

bool Aiphone::Underflow()
{
	return (Top == -1);
}

bool Aiphone::Overflow()
{
	return (Top == MAX - 1);
}

void Aiphone::insert()
{
	string name;
	double price;
	int quantity;
	string colour;
	int year;

	if (size == MAX)
	{
		cout << "**There is no more place left*\n";
		return;
	}
	cout << "Insert Phone Info:\n" << endl;
	cout << "Name : ";
	cin.ignore();
	getline(cin, name);
	cout << "Price : ";
	cin >> price;
	cout << "Quantity : ";
	cin >> quantity;
	cout << "Year Model : ";
	cin >> year;
	cin.ignore();
	cout << "Colour : ";
	getline(cin, colour);

	pname[size] = name;
	pprice[size] = price;
	pquantity[size] = quantity;
	pyear[size] = year;
	pcolour[size] = colour;
	size++;
}

void Aiphone::deleteItem()
{
	int i, elem, j, found = 0;
	if (size == 0)
	{
		cout << "***No more item to be deleted***\n";
		return;
	}
	cout << "Which Element Do You Want To Be Deleted ? ";
	cin >> j;
	if (j<0 || j>MAX)
	{
		cout << "Invalid input\n";
	}
	else
	{
		for (int i = j; i < MAX - 1; i++)
		{
			pname[i] = pname[i + 1];
			pprice[i] = pprice[i + 1];
			pquantity[i] = pquantity[i + 1];
			pcolour[i] = pcolour[i + 1];
			pyear[i] = pyear[i + 1];
		}
		size--;
	}
}

void Aiphone::print()
{
	cout << "List content :" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Element  : " << i << endl;
		cout << "Name     : " << pname[i] << endl;
		cout << "Price    : " << pprice[i] << endl;
		cout << "Quantity : " << pquantity[i] << endl;
		cout << "Year Model : " << pyear[i] << endl;
		cout << "Colour   : " << pcolour[i] << endl;
		cout << endl;
	}
}

void Aiphone::sort(int choice)
{
	int current, walker, tempq, temy;
	string tempname, tempcolour;
	double temprice;
	bool sorted;

	switch (choice) {
	case 1:
		for (current = 0, sorted = false; current <= size - 1 && !sorted; current++)
		{
			for (walker = size - 1, sorted = true; walker > current; walker--)
			{
				if (pprice[walker] < pprice[walker - 1])
				{
					sorted = false;
					temprice = pprice[walker];
					tempq = pquantity[walker];
					tempname = pname[walker];
					tempcolour = pcolour[walker];
					temy = pyear[walker];

					pprice[walker] = pprice[walker - 1];
					pquantity[walker] = pquantity[walker - 1];
					pname[walker] = pname[walker - 1];
					pcolour[walker] = pcolour[walker - 1];
					pyear[walker] = pyear[walker - 1];


					pprice[walker - 1] = temprice;
					pquantity[walker - 1] = tempq;
					pname[walker - 1] = tempname;
					pcolour[walker - 1] = tempcolour;
					pyear[walker - 1] = temy;



				}
			}
		}
		break;

	case 2:
		for (current = 0, sorted = false; current <= size - 1 && !sorted; current++)
		{
			for (walker = size - 1, sorted = true; walker > current; walker--)
			{
				if (pquantity[walker] < pquantity[walker - 1])
				{
					sorted = false;
					temprice = pprice[walker];
					tempq = pquantity[walker];
					tempname = pname[walker];
					tempcolour = pcolour[walker];
					temy = pyear[walker];


					pprice[walker] = pprice[walker - 1];
					pquantity[walker] = pquantity[walker - 1];
					pname[walker] = pname[walker - 1];
					pcolour[walker] = pcolour[walker - 1];
					pyear[walker] = pyear[walker - 1];


					pprice[walker - 1] = temprice;
					pquantity[walker - 1] = tempq;
					pname[walker - 1] = tempname;
					pcolour[walker - 1] = tempcolour;
					pyear[walker - 1] = temy;
				}
			}
		}
		break;

	case 3:
		for (current = 0, sorted = false; current <= size - 1 && !sorted; current++)
		{
			for (walker = size - 1, sorted = true; walker > current; walker--)
			{
				if (pyear[walker] < pyear[walker - 1])
				{
					sorted = false;
					temprice = pprice[walker];
					tempq = pquantity[walker];
					tempname = pname[walker];
					tempcolour = pcolour[walker];
					temy = pyear[walker];


					pprice[walker] = pprice[walker - 1];
					pquantity[walker] = pquantity[walker - 1];
					pname[walker] = pname[walker - 1];
					pcolour[walker] = pcolour[walker - 1];
					pyear[walker] = pyear[walker - 1];


					pprice[walker - 1] = temprice;
					pquantity[walker - 1] = tempq;
					pname[walker - 1] = tempname;
					pcolour[walker - 1] = tempcolour;
					pyear[walker - 1] = temy;
				}
			}
		}
		break;
	}

}





void Aiphone::update()
{
	int u;
	cout << "Choose one of this below" << endl;
	cout << "1. Update price. \n2. Update quantity." << endl;
	cout << "Your choice : ";
	cin >> u;
	while (u != 1 && u != 2)
	{
		cout << "\nInvalid input. Please try again" << endl << endl;
		cout << "1. Sort according to price. \n2. Sort based on quantity." << endl;
		cout << "Your choice : ";
		cin >> u;
	}

	if (u == 1)
	{
		int temp;
		int e;
		cout << "Choose which element's price to update\n" << endl;
		print();
		cout << endl;
		cout << "\nYour choice: ";
		cin >> e;
		cout << endl;
		while (e >= size)
		{
			cout << "\nInvalid input. Please try again" << endl << endl;
			cout << "Choose which one's price to update\n" << endl;
			print();
			cout << endl;
			cout << "\nYour choice: ";
			cin >> e;
		}

		cout << "Update price for " << pname[e] << endl;
		cout << "Old price = " << pprice[e] << endl;
		cout << "New price : ";
		cin >> temp;
		pprice[e] = temp;
		cout << "Price for " << pname[e] << " is updated" << endl;
	}

	if (u == 2)
	{
		int temp;
		int e;
		cout << "Choose which element's quantity to update\n" << endl;
		print();
		cout << endl;
		cout << "\nYour choice: ";
		cin >> e;
		cout << endl;
		while (e >= size)
		{
			cout << "\nInvalid input. Please try again" << endl << endl;
			cout << "Choose which element's quantity to update\n" << endl;
			print();
			cout << endl;
			cout << "\nYour choice: ";
			cin >> e;
		}

		cout << "Update quantity for " << pname[e] << endl;
		cout << "Old quantity = " << pquantity[e] << endl;
		cout << "New quantity : ";
		cin >> temp;
		pquantity[e] = temp;
		cout << "Quantity for " << pname[e] << " is updated" << endl;
	}

}



void Aiphone::search()
{
	string target;
	int locWanted;
	int index = 0;
	bool found = false;
	cout << "Insert the phone name you want, or 0 to stop: ";
	cin.ignore();
	getline(cin, target);
	while (index < MAX - 1)
	{
		if (pname[index] != target)
			index++;
		else
		{
			found = true;
			locWanted = index;
			break;
		}
	}
	if (found) {
		cout << "\t" << target << " is found" << endl << endl;
		cout << "Phone Details" << endl;
		cout << "Name     : " << pname[locWanted] << endl;
		cout << "Price    : " << pprice[locWanted] << endl;
		cout << "Quantity : " << pquantity[locWanted] << endl;
		cout << "Year Model : " << pyear[locWanted] << endl;
		cout << "Colour   : " << pcolour[locWanted] << endl;
		cout << endl;

	}
	else
		cout << "\tPhone Not Found in stock " << endl << endl;;

}





