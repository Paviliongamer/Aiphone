//Aiphone.h

#ifndef AIPHONE_H
#define AIPHONE_H
#include <iostream>
#include <string>
#define MAX 50
#define SMAX 5
using namespace std;

class Aiphone
{
public:
	Aiphone();
	~Aiphone();
	void insert();
	void deleteItem();
	int saiz();
	void update();
	void sort(int);
	void print();
	void search();

	void Push();
	void Pop();
	string TopStack();
	bool Underflow();
	bool Overflow();

private:
	string pname[MAX];
	double pprice[MAX];
	int pquantity[MAX];
	string pcolour[MAX];
	int pyear[MAX];
	int Top;
	string Stack[SMAX];
	int size;
};
#endif

