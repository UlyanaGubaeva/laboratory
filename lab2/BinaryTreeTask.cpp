#include "pch.h"
#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

void CreateMinimalBST(int start[], int first, int last)
{
	BinaryTree *tree = new BinaryTree();
	int count = (last - first) / 2;
	if ((last - first) % 2 > 0)
		tree->Insert(start[count++]);
	else tree->Insert(start[count]);

	for (int i = count + 1; i <= last; i++)
		tree->Insert(start[i]);
	for (int i = count - 1; i >= first; i--)
		tree->Insert(start[i]);
	tree->PrintValue();
}

int main() 
{
	//Task 1
	BinaryTree *tree = new BinaryTree();
	tree->Insert(9);
	tree->Insert(11);
	tree->Insert(7);
	tree->Insert(8);
	tree->Insert(10);
	tree->Insert(2);
	tree->Insert(1);
	tree->Insert(13);
	tree->PrintValue();
	cout << tree->Search(8)-> getValue() << "\n";
	cout << tree->Search(9)-> getRight() -> getValue() << "\n";
	delete tree;

	//Task 2
	int start[9] = { 1,5,6,8,11,14,18,36,97 };
	CreateMinimalBST(start, 0, 8);
}