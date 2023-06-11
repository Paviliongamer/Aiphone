//Main.cpp
#include <iostream>
using namespace std;
#include "Aiphone.h"

void masuk();
void buang();
void susun();
void ubah();
void cari();
void latest();

Aiphone Phone;

int main()
{
	char choice;

	cout << "Welcome to the Aiphone menu" << endl;
	cout << "What is it that you want to do ?" << endl;
	cout << "1. Insert New Aiphone" << endl;
	cout << "2. Delete Old Aiphone" << endl;
	cout << "3. Update Aiphone's Inventory" << endl;
	cout << "4. Search for an Aiphone" << endl;
	cout << "5. Sorting" << endl;
	cout << "6. Display top 3 latest phone" << endl;
	cout << "7. Exit\n" << endl;
	cout << "Your choice : ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case '1':
		masuk();
		break;
	case '2':
		buang();
		break;
	case '3':
		ubah();
		break;
	case '4':
		cari();
		break;
	case '5':
		susun();
		break;

	case '6':
		latest();
		break;

	case '7':
		cout << "Thanks for using our system" << endl;
		exit(0);

	default:
		cout << "Invalid input. Please try again !" << endl;
		return main();
	}
}

void masuk()
{
	char Loop = 'Y';
	char fix = 0;
	system("cls");
	while (Loop == 'Y' || Loop == 'y')
	{
		Phone.insert();
		cout << endl;
		cout << "Do You Want To Insert Another Phone Info ?" << endl;
		cout << "Enter Y/y to insert or others to stop: ";
		cin >> Loop;
		cout << endl;
	}

	cout << "Do you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;

}

void buang()
{
	char fix = 0;
	system("cls");
	if (Phone.saiz() == 0)
	{
		cout << "Data is empty! Nothing to delete." << endl;
		cout << "Please insert data first" << endl << endl;
		main();
	}
	cout << "\tDelete menu" << endl << endl;
	Phone.print();
	Phone.deleteItem();
	Phone.print();

	cout << "\nDo you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;

}

void susun()
{
	int j;
	char fix;
	system("cls");
	if (Phone.saiz() == 0)
	{
		cout << "Data is empty! Nothing to sort." << endl;
		cout << "Please insert data first" << endl << endl;
		main();
	}
	cout << "1. Sort according to price. \n2. Sort based on quantity." << endl;
	cout << "Your choice : ";
	cin >> j;
	while (j != 1 && j != 2)
	{
		cout << "\nInvalid input. Please try again" << endl << endl;
		cout << "1. Sort according to price. \n2. Sort based on quantity." << endl;
		cout << "Your choice : ";
		cin >> j;
	}
	if (j == 1)
		Phone.sort(j);
	if (j == 2)
		Phone.sort(j);
	cout << endl;
	Phone.print();

	cout << "Do you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;


}

void ubah()
{
	char fix;
	system("cls");
	if (Phone.saiz() == 0)
	{
		cout << "Data is empty! Nothing to update." << endl;
		cout << "Please insert data first" << endl << endl;
		main();
	}
	Phone.update();
	cout << endl;
	cout << "Do you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;

}



void cari()
{
	char fix = 0;
	char i;
	system("cls");
	if (Phone.saiz() == 0)
	{
		cout << "Data is empty! Nothing to search." << endl;
		cout << "Please insert data first" << endl << endl;
		main();
	}
	Phone.search();
	cout << endl;
	cout << "Do you wish to search another phone ? " << endl;
	cout << "Enter any to search, 0 to stop" << endl;
	cout << "Your choice : ";
	cin >> i;
	cout << endl;
	while (i != '0')
	{
		Phone.search();
		cout << "Do you wish to search another phone ? " << endl;
		cout << "Enter any to search, 0 to stop" << endl;
		cout << "Your choice : ";
		cin >> i;
		cout << endl;
	}
	cout << "Do you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;

}


void latest()
{
	int count = 0;
	system("cls");
	if (Phone.saiz() == 0)
	{
		cout << "Data is empty! Nothing to display." << endl;
		cout << "Please insert data first" << endl << endl;
		main();
	}
	Phone.sort(3);
	if (!Phone.Overflow())
		Phone.Push();
	else
		cout << "\nStack is full : can't push item" << endl;
	cout << "The latest models are: " << endl;
	while (!Phone.Underflow() && count < 3)
	{
		cout << "\t" << Phone.TopStack() << endl;
		Phone.Pop();
		count++;
	}
	if (count == 0)
		cout << "\tNo data found" << endl;
	if (Phone.Underflow() && count > 0 && count < 3)
	{
		cout << "\nOnly " << count << " latest model are displayed" << endl;
	}
	cout << endl;

	char fix;
	cout << "Do you want to go back to Aiphone menu ?" << endl;
	cout << "Press any letter to go back to Aiphone menu or a number to stop" << endl;
	cin >> fix;
	if (fix >= 'A' && fix <= 'z')
	{
		system("cls");
		main();
	}
	else
		return;
}