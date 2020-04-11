#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

//	Gubaeva U.M.

struct sList
{
public:
	int data;
	sList *next;
};

class List
{
	sList *first;
public:
	List() : first() {}
	void add(int x)
	{
		{
			sList *curr = new sList;
			curr->data = x;
			curr->next = first;
			first = curr;
		}
	}
	void show()
	{
		sList *curr = first;
		while (curr)
		{
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << endl;
	}
	int findElement(int count) 
	{
		sList *el1 = first;
		sList *el2 = first;
		int c = 0;
		while (el1)
		{
			if (c >= count)
				el2 = el2->next;
			el1 = el1->next;
			c++;
		}
		if (c <= count)  cout << "Invalid number. The first element will be output \n";
		return el2->data;
	}
};

int main()
{
	List list;
	srand(time(NULL));
	int minVal = 0, maxVal = 100, length = 10;
	for (int j = 0; j < length; j++)
	{
		list.add(rand() % (maxVal - minVal + 1) + minVal);
	}
	list.show();
	int num;
	cout << "Enter the element number \n";
	cin >> num;
	cout << list.findElement(num) << endl;
}

