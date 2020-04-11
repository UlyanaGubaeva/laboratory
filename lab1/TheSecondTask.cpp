#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//	Gubaeva U.M.

struct sList
{
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
	void deleteDublicate()
	{
		sList *tempI = 0;
		for (sList *i = first; i; i = i->next)
		{
			bool isDublicate = false;
			sList *tempJ = first;
			for (sList *j = first; j; j = j->next)
			{
				if (i->data == j->data && i != j)
				{
					tempJ->next = j->next;
					delete j;
					j = tempJ;
					isDublicate = true;
				}
				tempJ = j;
			}
			tempI = i;
		}
	}
};

int main()
{
	List list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(5);
	list.add(1);
	list.add(4);
	list.add(2);
	list.add(6);
	cout << "Source list: ";
	list.show();
	list.deleteDublicate();
	cout << "The list without duplicates: ";
	list.show();
}
